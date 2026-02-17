/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:49:15 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/17 11:02:37 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"

class Dog : public Animal {
public:
	// ---------- Constructors / Destructor ----------

	Dog(void);
	Dog(const Dog& copy);
	~Dog(void);

	// ---------- Overloading Operators Methods -------

	Dog& operator=(const Dog& copy);

	// ---------- Getter and Setter Methods ------------

	std::string getType();

	// ---------- Member Methods -----------------------

	virtual void makeSound() const;

protected:
	// ---------- Protected Data Members ---------------------
	std::string _type;

private:
	// ---------- Private Data members -------------------------
};

#endif // DOG_HPP
