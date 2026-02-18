/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:25:01 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/18 17:42:19 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

void use_all_Materias(Character someGuy)
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
	Ice *icePtr3 = icePtr2->clone();
	Cure *curePtr3 = curePtr3->clone();

	Character hero = Character("hero");
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
}
