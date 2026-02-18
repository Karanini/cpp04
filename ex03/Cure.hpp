/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:57:36 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/18 15:04:35 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include "AMateria.hpp"

class Cure : public AMateria {
public:
	// ---------- Constructors / Destructor ----------

	Cure(void);
	Cure(const Cure& copy);
	~Cure(void);

	// ---------- Overloading Operators Methods -------

	Cure& operator=(const Cure& copy);

	// ---------- Getter and Setter Methods ------------

	// ---------- Member Methods -----------------------

	virtual Cure* clone() const override;
	virtual void use(ICharacter& target) override;

protected:
	// ---------- Protected Data Members ---------------------

private:
	// ---------- Private Data members -------------------------
};

#endif // CURE_HPP
