/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:25:01 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/24 11:40:52 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
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
}
