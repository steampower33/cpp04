#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void my_leaks_handler()
{
	system("leaks ex01");
}

int main()
{
	// Animal 배열 선언 및 Dog Cat 2개씩 설정
	const Animal* a[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			a[i] = new Dog();
		else
			a[i] = new Cat();
	}

	std::cout << std::endl;

	// 각 배열에 설정한 객체들이 올바르게 설정되어있는지 확인
	for (int i = 0; i < 4; i++)
	{
		std::cout << a[i]->getType() << std::endl;
		a[i]->makeSound();
	}
	
	std::cout << std::endl;

	// 각 배열에 존재하는 객체 소멸
	for (int i = 0; i < 4; i++)
		delete a[i];

	std::cout << std::endl;

	std::cout << "[깊은 복사 확인 - Dog]" << std::endl;
	Dog* d = new Dog();
	Dog* d_dup = new Dog();

	std::cout << std::endl;

	d->getBrain()->setIdeas("SET IDEAS!!!!!!!!!!", 5);
	std::cout << "String is " << d->getBrain()->getIdeas(5) << std::endl;
	std::cout << "address is " << d->getBrain() << std::endl;
	std::cout << "String is " << d_dup->getBrain()->getIdeas(5) << std::endl;
	std::cout << "address is " << d_dup->getBrain() << std::endl;

	std::cout << std::endl;

	*d_dup = *d;

	std::cout << std::endl;

	std::cout << "String is " << d->getBrain()->getIdeas(5) << std::endl;
	std::cout << "address is " << d->getBrain() << std::endl;
	std::cout << "String is " << d_dup->getBrain()->getIdeas(5) << std::endl;
	std::cout << "address is " << d_dup->getBrain() << std::endl;

	std::cout << std::endl;

	delete d_dup;
	delete d;

	std::cout << std::endl;

	std::cout << "[깊은 복사 확인 - Cat]" << std::endl;
	Cat* c = new Cat();
	Cat* c_dup = new Cat();

	std::cout << std::endl;

	c->getBrain()->setIdeas("SET IDEAS!!!!!!!!!!", 5);
	std::cout << "String is " << c->getBrain()->getIdeas(5) << std::endl;
	std::cout << "address is " << c->getBrain() << std::endl;
	std::cout << "String is " << c_dup->getBrain()->getIdeas(5) << std::endl;
	std::cout << "address is " << c_dup->getBrain() << std::endl;

	std::cout << std::endl;

	*c_dup = *c;

	std::cout << std::endl;

	std::cout << "String is " << c->getBrain()->getIdeas(5) << std::endl;
	std::cout << "address is " << c->getBrain() << std::endl;
	std::cout << "String is " << c_dup->getBrain()->getIdeas(5) << std::endl;
	std::cout << "address is " << c_dup->getBrain() << std::endl;

	std::cout << std::endl;

	delete c_dup;
	delete c;
	// atexit(my_leaks_handler);

	return 0;
}