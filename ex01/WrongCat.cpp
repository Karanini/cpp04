/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:43:23 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/17 11:06:52 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->WrongAnimal::_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &copy) {
		this->WrongAnimal::operator=(copy);
	}
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "MEEOOOOWWW" << std::endl;
}
