/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:49:15 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/17 11:02:37 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal {
public:
	// ---------- Constructors / Destructor ----------

	Cat(void);
	Cat(const Cat& copy);
	~Cat(void);

	// ---------- Overloading Operators Methods -------

	Cat& operator=(const Cat& copy);

	// ---------- Getter and Setter Methods ------------

	std::string getType();

	// ---------- Member Methods -----------------------

	virtual void makeSound();

protected:
	// ---------- Protected Data Members ---------------------
	std::string _type;

private:
	// ---------- Private Data members -------------------------
};

#endif // DOG_HPP
