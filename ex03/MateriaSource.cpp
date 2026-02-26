/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:06:48 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/26 18:26:45 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_MateriaSourceTab[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
        this->_MateriaSourceTab[i] = NULL;
	*this = copy;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
        delete this->_MateriaSourceTab[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &copy) {
		for (int i = 0; i < 4; i++)
		{
			delete this->_MateriaSourceTab[i];
			if (copy._MateriaSourceTab[i])
				this->_MateriaSourceTab[i] = copy._MateriaSourceTab[i]->clone();
		}
	}
	return (*this);
}
