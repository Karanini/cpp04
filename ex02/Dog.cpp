/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:43:23 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/17 11:06:52 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include "Brain.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->Animal::_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*copy._brain);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &copy) {
		this->Animal::operator=(copy);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}

std::string Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

void Dog::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

void Dog::makeSound() const
{
	std::cout << "WOUF WOUF" << std::endl;
}
