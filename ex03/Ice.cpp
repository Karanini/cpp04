/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:58:47 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/20 17:01:27 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice(void) : AMateria()
{
	std::cout << "Ice default constructor called" << std::endl;
	this->AMateria::_type = "ice";
}

Ice::Ice(const Ice& copy) : AMateria()
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = copy;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& copy)
{
	std::cout << "Ice assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.ICharacter::getName() << std::endl;
}
