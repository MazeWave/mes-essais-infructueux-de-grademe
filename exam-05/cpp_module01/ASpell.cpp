# include "ASpell.hpp"

ASpell::~ASpell()
{
	return ;
}

ASpell::ASpell(std::string name, std::string effects) : name(name), effects(effects)
{
	return ;
}

const std::string	ASpell::getName(void) const
{
	return (this->name);
}

const std::string	ASpell::getEffects(void) const
{
	return (this->effects);
}

void	ASpell::launch(ATarget &input)
{
	input.getHitBySpell(*this);
	return ;
}