/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:07:11 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/26 18:23:54 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
public:
	// ---------- Constructors / Destructor ----------

	MateriaSource(void);
	MateriaSource(const MateriaSource& copy);
	~MateriaSource(void);

	// ---------- Overloading Operators Methods -------

	MateriaSource& operator=(const MateriaSource& copy);

	// ---------- Getter and Setter Methods ------------

	// ---------- Member Methods -----------------------

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);

protected:
	// ---------- Protected Data Members ---------------------

private:
	// ---------- Private Data members -------------------------

	AMateria *_MateriaSourceTab[4];
};

#endif // MATERIASOURCE_HPP
