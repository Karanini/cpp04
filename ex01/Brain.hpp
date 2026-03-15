/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:54:15 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/03/15 16:55:52 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
public:
	// ---------- Constructors / Destructor ----------

	Brain(void);
	Brain(const Brain& copy);
	~Brain(void);

	// ---------- Overloading Operators Methods -------

	Brain& operator=(const Brain& copy);

	// ---------- Getter and Setter Methods ------------

	std::string getIdea(int index) const;
	void setIdea(int index, std::string idea);

	// ---------- Member Methods -----------------------

protected:
	// ---------- Protected Data Members ---------------------

private:
	// ---------- Private Data members -------------------------
	std::string _ideas[100];
};

#endif // BRAIN_HPP
