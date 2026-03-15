/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:15:57 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/03/15 17:00:51 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "--- SUBJECT TEST: Array of animals ---" << std::endl;
	Animal *animals[10];
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	std::cout << '\n';
	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
	}

	std::cout << "\n--- DEEP COPY TEST: Dog ---" << std::endl;
	Dog *dogA = new Dog();
	dogA->setIdea(0, "I want a bone");
	dogA->setIdea(1, "I want to sleep");

	Dog *dogB = new Dog(*dogA);
	std::cout << '\n';
	std::cout << "dogA idea 0: " << dogA->getIdea(0) << std::endl;
	std::cout << "dogB idea 0: " << dogB->getIdea(0) << std::endl;
	std::cout << '\n';

	dogA->setIdea(0, "I want to play");
	std::cout << "After changing dogA idea 0..." << std::endl;
	std::cout << "dogA idea 0: " << dogA->getIdea(0) << std::endl;
	std::cout << "dogB idea 0: " << dogB->getIdea(0) << " (should still be 'I want a bone')" << std::endl;
	std::cout << '\n';

	*dogB = *dogA;
	std::cout << "After dogB = dogA..." << std::endl;
	std::cout << "dogB idea 0: " << dogB->getIdea(0) << " (should now be 'I want to play')" << std::endl;

	delete dogA;
	delete dogB;

	std::cout << "\n--- DEEP COPY TEST: Cat ---" << std::endl;
	Cat *catA = new Cat();
	catA->setIdea(0, "I want fish");

	Cat *catB = new Cat();
	*catB = *catA;
	std::cout << '\n';
	std::cout << "catA idea 0: " << catA->getIdea(0) << std::endl;
	std::cout << "catB idea 0: " << catB->getIdea(0) << std::endl;
	std::cout << '\n';

	catA->setIdea(0, "I want to catch a bird");
	std::cout << "After changing catA idea 0..." << std::endl;
	std::cout << "catA idea 0: " << catA->getIdea(0) << std::endl;
	std::cout << "catB idea 0: " << catB->getIdea(0) << " (should still be 'I want fish')" << std::endl;

	delete catA;
	delete catB;

	return 0;
}
