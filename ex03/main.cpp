/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:25:01 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/18 17:30:38 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

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
}
