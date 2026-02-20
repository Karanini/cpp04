/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:28:20 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/20 16:48:28 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
class ICharacter;

class AMateria {
public:
	// ---------- Constructors / Destructor ----------

	AMateria(void);
	AMateria(const AMateria& copy);
	virtual ~AMateria(void);

	// ---------- Overloading Operators Methods -------

	AMateria& operator=(const AMateria& copy);

	// ---------- Getter and Setter Methods ------------

	std::string const &getType() const;

	// ---------- Member Methods -----------------------

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	// ---------- Protected Data Members ---------------------
	std::string _type;

private:
	// ---------- Private Data members -------------------------
};

#endif // AMATERIA_HPP
