#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void my_leaks_handler()
{
	system("leaks ex00");
}

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* a = new WrongCat();
	std::cout << a->getType() << " " << std::endl;
	a->makeSound();


	delete a;
	delete i;
	delete j;
	delete meta;
	// atexit(my_leaks_handler);
	return 0;
}