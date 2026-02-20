/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:58:47 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/18 15:10:46 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(void) : AMateria()
{
	std::cout << "Cure default constructor called" << std::endl;
	this->AMateria::_type = "cure";
}

Cure::Cure(const Cure& copy) : AMateria()
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = copy;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& copy)
{
	std::cout << "Cure assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.ICharacter::getName() << "'s wounds *" << std::endl;
}
