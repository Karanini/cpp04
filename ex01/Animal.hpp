/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:49:15 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/17 15:58:34 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
public:
	// ---------- Constructors / Destructor ----------

	Animal(void);
	Animal(const Animal& copy);
	virtual ~Animal(void);

	// ---------- Overloading Operators Methods -------

	Animal& operator=(const Animal& copy);

	// ---------- Getter and Setter Methods ------------

	std::string const getType() const;

	// ---------- Member Methods -----------------------

	virtual void makeSound() const;

protected:
	// ---------- Protected Data Members ---------------------
	std::string _type;

private:
	// ---------- Private Data members -------------------------
};

#endif // ANIMAL_HPP
