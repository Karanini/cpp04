/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:29:12 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/20 16:48:41 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) : _type("default")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = copy;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

/*
* Does nothing because while assigning a Materia to another,
copying the type doesn’t make sense.
*/
AMateria& AMateria::operator=(const AMateria& copy)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria use() function called. Nothing happens, try to use it with an inherited class object." << std::endl;
	(void)target;
}

