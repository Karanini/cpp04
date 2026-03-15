/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:43:23 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/17 11:06:52 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->Animal::_type = "Cat";
	this->_brain = new Brain();
}

/*
* we are not using `*this = copy` here because `this->brain` contains garbage
values after init, so it would have caused segfaults in `operator=()`.
So we init the object directly here.
*/
Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*copy._brain);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &copy) {
		this->Animal::operator=(copy);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}

std::string Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

void Cat::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

void Cat::makeSound() const
{
	std::cout << "MEEOOOOWWW" << std::endl;
}
