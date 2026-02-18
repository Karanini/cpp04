/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:28:20 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/18 14:50:59 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class AMateria {
public:
	// ---------- Constructors / Destructor ----------

	AMateria(void);
	AMateria(std::string const & type);
	AMateria(const AMateria& copy);
	~AMateria(void);

	// ---------- Overloading Operators Methods -------

	AMateria& operator=(const AMateria& copy);

	// ---------- Getter and Setter Methods ------------

	std::string const & getType() const;

	// ---------- Member Methods -----------------------

	virtual AMateria* clone() const = 0;
	// virtual void use(ICharacter& target);

protected:
	// ---------- Protected Data Members ---------------------
	std::string _type;

private:
	// ---------- Private Data members -------------------------
};

#endif // AMATERIA_HPP
