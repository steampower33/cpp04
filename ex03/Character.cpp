#include "Character.hpp"

Character::Character() {
	_name = "";
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(const std::string& name) {
	_name = name;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(const Character& other) {
	*this = other;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other)
	{
		_name = other.getName();
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];

			if (other._inventory[i])
				_inventory[i] = (other._inventory[i])->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

const std::string& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (0 <= idx && idx < 4)
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& other) {
	if (0 <= idx && idx < 4 && _inventory[idx])
		_inventory[idx]->use(other);
}
