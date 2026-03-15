/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:25:01 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/03/15 15:04:34 by bkaras-g         ###   ########.fr       */
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

	std::cout << "\n\\----------------Creating copy with hero inventory full, nothing unequipped-----------------/\n\n";
	Character *copy_full = new Character(hero);
	use_all_Materias(*copy_full);

	hero.unequip(0);
	hero.unequip(1);
	hero.unequip(1);
	hero.equip(icePtr3);
	hero.equip(curePtr3);

	use_all_Materias(hero);

	hero.unequip(2);

	use_all_Materias(hero);

	std::cout << "\\---------------Character copy constructor + assignment operator tests------------/" << std::endl;
	std::cout << "\\--------------------Full inventory + 3 items on the floor------------/" << std::endl;
	Character *copy = new Character(*copy_full);
	use_all_Materias(*copy);

	std::cout << "\\---------------Character copy constructor + assignment operator tests------------/" << std::endl;
	std::cout << "\\--------------------Inventory half full------------/" << std::endl;
	copy_full->unequip(2);
	copy_full->unequip(0);
	Character *half_life = new Character(*copy_full);
	use_all_Materias(*half_life);

	std::cout << "\\---------------Character copy constructor + assignment operator tests------------/" << std::endl;
	std::cout << "\\--------------------Inventory empty------------/" << std::endl;
	copy_full->unequip(1);
	copy_full->unequip(3);
	Character *empty_soul = new Character(*copy_full);
	use_all_Materias(*empty_soul);


	delete empty_soul;
	delete half_life;
	delete copy;
	delete copy_full;

	std::cout << '\n';
	std::cout << "\\---------------MateriaSource learnMateria() and createMateria() tests------------/" << std::endl;
	MateriaSource *src = new MateriaSource();
	std::cout << '\n';

	std::cout << "Learning Materias..." << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
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
	delete m4;
	delete src;

	std::cout << "\n---------- ADDITIONAL FLOOR & ASSIGNMENT TESTS ----------\n" << std::endl;
	{
		Character *bob = new Character("Bob");
		bob->equip(new Ice());
		bob->equip(new Cure());
		bob->unequip(0); // Ice on floor
		bob->unequip(1); // Cure on floor

		std::cout << "Assigning Bob to Jim" << std::endl;
		Character jim("Jim");
		jim = *bob; // Deep copy should clone floor as well

		std::cout << "Deleting Bob, Jim should still have cloned floor/items" << std::endl;
		delete bob;

		// Testing deep copy with unequip
		jim.equip(new Ice());
		jim.unequip(0); // Should be added to Jim's floor
	}

	std::cout << "\n---------- TEST DEEP COPY AND INDEPENDENCE ----------\n" << std::endl;
	{
		Character a("A");
		a.equip(new Ice());
		Character b(a);
		a.unequip(0); // A's inventory is now empty, Ice is on floor
		b.equip(new Cure()); // B's inventory has 1 Ice, 1 Cure

		std::cout << "A's name: " << a.getName() << std::endl;
		std::cout << "B's name: " << b.getName() << std::endl;

		std::cout << "A use(0, b): "; a.use(0, b); // Should do nothing (empty after unequip)
		std::cout << "B use(0, a): "; b.use(0, a); // Should use Ice
		std::cout << "B use(1, a): "; b.use(1, a); // Should use Cure
	}
	std::cout << "\n end of the line \n" << std::endl;
}
