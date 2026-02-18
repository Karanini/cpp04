/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:45:00 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/18 17:40:52 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(void) : _name("default")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
}

Character::Character(std::string const &name) : _name(name)
{
	std::cout << "Character subject constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
}


Character::Character(const Character& copy)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = copy;
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
}

/*
Any copy
(using copy constructor or copy assignment operator) of a Character must be deep.
During copy, the Materias of a Character must be deleted before the new ones are added
to their inventory.
*/
Character& Character::operator=(const Character& copy)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy.getName();
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = copy._inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

/*
They equip the Materias in the first empty
slot they find, in the following order: from slot 0 to slot 3.
If they try to add a Materia to
a full inventory, or use/unequip a non-existent Materia, nothing should happen (but bugs
are still forbidden).
*/
void Character::equip(AMateria* m)
{
	int	slot = 0;

	while(this->_inventory[slot])
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

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
	{
		std::cout << "Error: wrong slot number or empty slot." << std::endl;
		return ;
	}
	std::cout << this->_inventory[idx]->getType() << " unequipped from slot number " << idx << std::endl;
	//save the unequiped Materia : array of 1000 AMaterias or list ?
	this->_inventory[idx] = nullptr;
}

/*
The use(int, ICharacter&) member function will have to use the Materia at the
slot[idx], and pass the target parameter to the AMateria::use function.
*/
void Character::use(int idx, ICharacter& target)
{
	AMateria *materia;

	if (idx < 0 || idx > 3 || !this->_inventory[idx])
	{
		std::cout << "Error: wrong slot number or empty slot." << std::endl;
		return ;
	}
	materia = this->_inventory[idx];
	materia->AMateria::use(target);
}
