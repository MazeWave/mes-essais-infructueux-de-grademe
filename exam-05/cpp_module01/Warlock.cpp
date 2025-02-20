#include "Warlock.hpp"

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
	return ;
};

Warlock::Warlock(const std::string &name, const std::string &title)
{
	this->name = name;
	this->title = title;

	std::cout << this->name << ": This looks like another boring day." << std::endl;

	return ;
};

void	Warlock::introduce(void) const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
	return ;
}

const std::string	&Warlock::getName(void) const
{
	return (this->name);
}

const std::string	&Warlock::getTitle(void) const
{
	return (this->title);
}

void	Warlock::setName(const std::string &name)
{
	this->name = name;
	return ;
}

void	Warlock::setTitle(const std::string &title)
{
	this->title = title;
	return ;
}

void	Warlock::learnSpell(ASpell *input)
{
	// For no duplicates
	for (unsigned short i = 0; i < this->spells.size(); i++)
	{
		if (this->spells[i]->getName() == input->getName())
			return ;
	}

	this->spells.push_back(input->clone());
	return ;
}

void	Warlock::forgetSpell(std::string name)
{
	for (unsigned short i = 0; i < this->spells.size(); i++)
	{
		if (this->spells[i]->getName() == name)
		{
			delete this->spells[i];
			this->spells.erase(this->spells.begin() + i);
			return ;
		}
	}
	return ;
}

void	Warlock::launchSpell(std::string name, ATarget &input)
{
	for (unsigned short i = 0; i < this->spells.size(); i++)
	{
		if (this->spells[i]->getName() == name)
		{
			this->spells[i]->launch(input);
			return ;
		}
	}
	return ;
}