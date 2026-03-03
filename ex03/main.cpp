/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:25:01 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/26 17:55:20 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void use_all_Materias(Character &someGuy)
{
	std::cout << '\n';
	for (int i = 0; i < 4; i++)
		someGuy.use(i, someGuy);
	std::cout << '\n';
}

int main(void)
{
	Ice *icePtr1 = new Ice();
	Cure *curePtr1 = new Cure();
	Ice *icePtr2 = new Ice();
	Cure *curePtr2 = new Cure();
	std::cout << '\n';

	std::cout << "\\---------------Ice and Cure clone() + copy constructor + assignment operator tests------------/" << std::endl;
	Ice *icePtr3 = icePtr2->clone();
	Cure *curePtr3 = curePtr2->clone();
	std::cout << '\n';

	Character hero = Character("hero");
	std::cout << '\n';
	std::cout << "\\---------------inventory equip() and unequip() + use() tests------------/" << std::endl;
	hero.equip(icePtr1);
	hero.equip(curePtr1);
	hero.equip(icePtr2);
	hero.equip(curePtr2);
	hero.equip(icePtr3);
	hero.equip(curePtr3);

	use_all_Materias(hero);

	hero.unequip(0);
	hero.unequip(1);
	hero.unequip(1);
	hero.equip(icePtr3);
	hero.equip(curePtr3);

	use_all_Materias(hero);

	hero.unequip(3);
	hero.equip(icePtr1);

	use_all_Materias(hero);

	std::cout << "\\---------------Character copy constructor + assignment operator tests------------/" << std::endl;
	std::cout << "\\--------------------Full inventory------------/" << std::endl;
	Character *copy = new Character(hero);
	use_all_Materias(*copy);

	std::cout << "\\---------------Character copy constructor + assignment operator tests------------/" << std::endl;
	std::cout << "\\--------------------Inventory half full------------/" << std::endl;
	hero.unequip(2);
	hero.unequip(0);
	Character *half_life = new Character(hero);
	use_all_Materias(*half_life);

	std::cout << "\\---------------Character copy constructor + assignment operator tests------------/" << std::endl;
	std::cout << "\\--------------------Inventory empty------------/" << std::endl;
	hero.unequip(1);
	hero.unequip(3);
	Character *empty_soul = new Character(hero);
	use_all_Materias(*empty_soul);

	std::cout << "\\---------------Assignment operator tests------------/" << std::endl;
	std::cout << "\\--------------------Origin inventory half full------------/" << std::endl;
	delete empty_soul;
	empty_soul = half_life;
	use_all_Materias(*empty_soul);

	delete empty_soul;
	// delete half_life;
	std::cout << '\n';
	delete copy;
	std::cout << '\n';
	std::cout << "\\---------------MateriaSource learnMateria() and createMateria() tests------------/" << std::endl;
	MateriaSource *src = new MateriaSource();
	std::cout << '\n';

	std::cout << "Learning Materias..." << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	src->learnMateria(curePtr1);
	std::cout << '\n';

	std::cout << "Creating Materias from source..." << std::endl;
	AMateria *m1 = src->createMateria("ice");
	AMateria *m2 = src->createMateria("cure");
	AMateria *m3 = src->createMateria("ice");
	AMateria *m4 = src->createMateria("cure");
	std::cout << '\n';

	std::cout << "Trying to create unknown type..." << std::endl;
	AMateria *m5 = src->createMateria("fireball");
	(void)m5;
	std::cout << '\n';

	std::cout << "Learning when full..." << std::endl;
	src->learnMateria(new Ice());
	std::cout << '\n';

	delete m1;
	delete m2;
	delete m3;
	(void)m4;
	// delete m4;
	delete src;
	std::cout << '\n';
	delete icePtr1;
	std::cout << '\n';
	delete icePtr2;
	std::cout << '\n';
	delete icePtr3;
	std::cout << '\n';
	delete curePtr1;
	std::cout << '\n';
	delete curePtr2;
	std::cout << '\n';
	delete curePtr3;
}
