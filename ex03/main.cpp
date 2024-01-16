#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <unistd.h>

void my_leaks_handler()
{
	system("leaks ex03");
}

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	AMateria* ice;
	AMateria* cure;
	tmp = src->createMateria("ice");
	ice = tmp;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	cure = tmp;
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	me->unequip(1);
	delete ice;
	delete cure;
	delete bob;
	delete me;
	delete src;
	atexit(my_leaks_handler);
	return 0;
}