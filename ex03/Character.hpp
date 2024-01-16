#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(const std::string& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();
	const std::string& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
	std::string _name;
	AMateria* _inventory[4];
};

#endif