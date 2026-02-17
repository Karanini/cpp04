/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:15:57 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/02/17 12:16:17 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;

	Dog dog;
	Cat cat;
	Animal &rAnimalDog = dog;
	Animal &rAnimalCat = cat;
	std::cout << "dog is a " << dog.getType() << " " << std::endl;
	std::cout << "cat is a " << cat.getType() << " " << std::endl;
	std::cout << "rAnimalDog is a " << rAnimalDog.getType() << " " << std::endl;
	std::cout << "rAnimalCat is a " << rAnimalCat.getType() << " " << std::endl;
	rAnimalCat.makeSound();
	rAnimalDog.makeSound();
	return (0);
}
