/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:15:57 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/17 14:56:09 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* copy_i(i);
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "Expected cat sound:";
	i->makeSound(); //will output the cat sound!
	std::cout << "Expected cat sound:";
	copy_i->makeSound();
	std::cout << "Expected dog sound:";
	j->makeSound();
	delete j;
	j = i;
	std::cout << "Expected cat sound:";
	j->makeSound();
	std::cout << "Expected Animal sound:";
	meta->makeSound();
	delete i;
	delete meta;
	std::cout << '\n';

	Dog dog;
	Cat cat;
	Animal &rAnimalDog = dog;
	Animal &rAnimalCat = cat;
	std::cout << "dog is a " << dog.getType() << " " << std::endl;
	std::cout << "cat is a " << cat.getType() << " " << std::endl;
	std::cout << "rAnimalDog is a " << rAnimalDog.getType() << " " << std::endl;
	std::cout << "rAnimalCat is a " << rAnimalCat.getType() << " " << std::endl;
	std::cout << "Expected cat sound:";
	rAnimalCat.makeSound();
	std::cout << "Expected dog sound:";
	rAnimalDog.makeSound();
	std::cout << '\n';

	WrongCat wrong_cat;
	WrongAnimal &rWrongAnimalCat = wrong_cat;
	std::cout << "wrong_cat is a " << wrong_cat.getType() << " " << std::endl;
	std::cout << "rWrongAnimalCat is a " << rWrongAnimalCat.getType() << " " << std::endl;
	std::cout << "Expected WrongAnimal sound:";
	rWrongAnimalCat.makeSound();
	std::cout << '\n';
	return (0);
}
