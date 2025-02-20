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
