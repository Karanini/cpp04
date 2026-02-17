/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:49:15 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/17 11:56:35 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
public:
	// ---------- Constructors / Destructor ----------

	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& copy);
	virtual ~WrongAnimal(void);

	// ---------- Overloading Operators Methods -------

	WrongAnimal& operator=(const WrongAnimal& copy);

	// ---------- Getter and Setter Methods ------------

	std::string const getType() const;

	// ---------- Member Methods -----------------------

	void makeSound() const;

protected:
	// ---------- Protected Data Members ---------------------
	std::string _type;

private:
	// ---------- Private Data members -------------------------
};

#endif // WRONGANIMAL_HPP
