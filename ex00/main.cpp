#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	
	std::cout << std::endl;
	
	const WrongAnimal* a = new WrongCat();
	const WrongCat* b = new WrongCat();
	
	std::cout << std::endl;
	
	std::cout << a->getType() << " " << std::endl;
	a->makeSound();
	std::cout << b->getType() << " " << std::endl;
	b->makeSound();
	
	std::cout << std::endl;
	
	delete b;
	delete a;
	delete i;
	delete j;
	delete meta;
	return 0;
}