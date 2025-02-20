# include "ATarget.hpp"

ATarget::~ATarget(void)
{
	return ;
}

ATarget::ATarget(std::string type) : type(type)
{
	return ;
}

const std::string &	ATarget::getType(void) const
{
	return (this->type);
}

void	ATarget::getHitBySpell(const ASpell &input)
{
	std::cout << this->type << " has been " << input.getEffects() << "!" << std::endl;
	return ;
}