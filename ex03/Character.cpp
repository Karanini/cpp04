/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:45:00 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/03/15 15:57:25 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(void) : _name("default")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_floor = new AMateria*[1]; //allocating an array of pointers to AMateria
	this->_floor[0] = NULL;
	this->_floorSize = 1;
}

Character::Character(std::string const &name) : _name(name)
{
	std::cout << "Character subject constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_floor = new AMateria*[1]; //allocating an array of pointers to AMateria
	this->_floor[0] = NULL;
	this->_floorSize = 1;
}

/*
Need to init the inventory slots to NULL, so that the assignment operator
overload won't crash when calling `delete` on the slots. In c++11 it would have been
possible to call the default constructor (delegating constructor). But this option
is not possible in c++98 required by the subject.
*/
Character::Character(const Character& copy)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
	this->_floor = new AMateria*[1]; //allocating an array of pointers to AMateria
	this->_floor[0] = NULL;
	this->_floorSize = 1;
	*this = copy;
}

/*
The destructor handles the deletes of the inventory and floor Materias. This implies that
the Materias can be equipped only once and by a unique Character. Once unequipped, they stay
on the floor until the end of the program.
This technical choice is necessary to avoid situations too complex to handle that would very
probably leed to double deletes problems: Materias equipped by several Characters, Materia
in the inventory and the floor at the same time (if we unequip then equip again), etc.
*/
Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
        delete this->_inventory[i];
	for (int i = 0; i < this->_floorSize; i++)
		delete this->_floor[i];
	delete[] this->_floor;
}

/*
Subject: "Any copy
(using copy constructor or copy assignment operator) of a Character must be deep.
During copy, the Materias of a Character must be deleted before the new ones are added
to their inventory."
Deep copy of the inventory and also the floor: deleting the old floor before making
room for the copied one.
*/
Character& Character::operator=(const Character& copy)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy.getName();

		//copy inventory
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			if (copy._inventory[i])
				this->_inventory[i] = copy._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}

		//delete old floor
		for (int i = 0; i < this->_floorSize; i++)
			delete this->_floor[i];
		delete[] this->_floor;

		//create new floor and transfer copy's floor into it
		this->_floorSize = copy._floorSize;
		this->_floor = new AMateria*[this->_floorSize];
		for (int i = 0; i < this->_floorSize; i++)
		{
			if (copy._floor[i])
				this->_floor[i] = copy._floor[i]->clone();
			else
				this->_floor[i] = NULL;
		}
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

/*
Subject: They equip the Materias in the first empty
slot they find, in the following order: from slot 0 to slot 3.
If they try to add a Materia to
a full inventory, or use/unequip a non-existent Materia, nothing should happen (but bugs
are still forbidden).

Appart from the full inventory check, this function also checks if the materia is already
equipped, to avoid double deletes.
*/
void Character::equip(AMateria* m)
{
	if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == m)
        {
            std::cout << "Materia already equipped!" << std::endl;
            return;
        }
    }

	int slot = 0;
	while(this->_inventory[slot] && slot < 4)
		slot++;
	if (slot == 4)
	{
		std::cout << "Your inventory is full!" << std::endl;
		return ;
	}
	else
	{
		std::cout << m->getType() << " added to slot number " << slot << std::endl;
		this->_inventory[slot] = m;
	}
}

int Character::check_inventory(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Error: wrong slot number." << std::endl;
		return (1);
	}
	if (!this->_inventory[idx])
	{
		std::cout << "Empty slot!" << std::endl;
		return (1);
	}
	return (0);
}

void Character::unequip(int idx)
{
	if (this->check_inventory(idx))
		return ;
	std::cout << this->_inventory[idx]->getType() << " unequipped from slot number " << idx << std::endl;
	this->_floorSize++;
	AMateria **NewFloor = new AMateria*[this->_floorSize];
	for (int i = 0; i < this->_floorSize - 1; i++)
		NewFloor[i] = this->_floor[i];
	delete[] this->_floor;
	NewFloor[this->_floorSize - 1] = this->_inventory[idx];
	this->_floor = NewFloor;
	this->_inventory[idx] = NULL;
}

/*
The use(int, ICharacter&) member function will have to use the Materia at the
slot[idx], and pass the target parameter to the AMateria::use function.
*/
void Character::use(int idx, ICharacter& target)
{
	AMateria *materia;

	if (this->check_inventory(idx))
		return ;
	materia = this->_inventory[idx];
	materia->use(target);
}
