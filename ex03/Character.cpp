/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:45:00 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/18 15:55:43 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(void)
{
	std::cout << "Character default constructor called" << std::endl;
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

Character& Character::operator=(const Character& copy)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &copy) {
		// copy data members here
	}
	return (*this);
}
