/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:43:23 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/17 11:22:41 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &copy) {
		*this = copy;
	}
	return (*this);
}

std::string const Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "Animal makes a pure animal sound, the sound of the origins, the sound of the first animal..." << std::endl;
}
