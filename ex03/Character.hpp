/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:45:03 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/20 16:23:32 by michel_32        ###   ########.fr       */
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
	Character(std::string const &name);
	Character(const Character& copy);
	~Character(void);

	// ---------- Overloading Operators Methods -------

	Character& operator=(const Character& copy);

	// ---------- Getter and Setter Methods ------------

	virtual std::string const & getName() const  ;

	// ---------- Member Methods -----------------------

	virtual void equip(AMateria* m)  ;
	virtual void unequip(int idx)  ;
	virtual void use(int idx, ICharacter& target)  ;

protected:
	// ---------- Protected Data Members ---------------------

private:
	// ---------- Private Data members -------------------------
	AMateria *_inventory[4];
	std::string _name;
};

#endif // CHARACTER_HPP
