/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:45:03 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/18 15:52:24 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter {
public:
	// ---------- Constructors / Destructor ----------

	Character(void);
	Character(const Character& copy);
	~Character(void);

	// ---------- Overloading Operators Methods -------

	Character& operator=(const Character& copy);

	// ---------- Getter and Setter Methods ------------

	// ---------- Member Methods -----------------------

protected:
	// ---------- Protected Data Members ---------------------

private:
	// ---------- Private Data members -------------------------
	AMateria *_inventory[4];
};

#endif // CHARACTER_HPP
