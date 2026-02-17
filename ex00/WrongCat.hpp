/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:49:15 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/17 11:02:37 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	// ---------- Constructors / Destructor ----------

	WrongCat(void);
	WrongCat(const WrongCat& copy);
	~WrongCat(void);

	// ---------- Overloading Operators Methods -------

	WrongCat& operator=(const WrongCat& copy);

	// ---------- Getter and Setter Methods ------------

	// ---------- Member Methods -----------------------

	void makeSound() const;

protected:
	// ---------- Protected Data Members ---------------------

private:
	// ---------- Private Data members -------------------------
};

#endif // WRONGCAT_HPP
