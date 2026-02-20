/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:57:36 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/20 16:46:59 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include "AMateria.hpp"

class Ice : public AMateria {
public:
	// ---------- Constructors / Destructor ----------

	Ice(void);
	Ice(const Ice& copy);
	~Ice(void);

	// ---------- Overloading Operators Methods -------

	Ice& operator=(const Ice& copy);

	// ---------- Getter and Setter Methods ------------

	// ---------- Member Methods -----------------------

	virtual Ice* clone() const  ;
	virtual void use(ICharacter& target)  ;

protected:
	// ---------- Protected Data Members ---------------------

private:
	// ---------- Private Data members -------------------------
};

#endif // ICE_HPP
