#include "Fwoosh.hpp"

Fwoosh::~Fwoosh()
{
	return ;
}

Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed")
{
	return ;
}

Fwoosh *	Fwoosh::clone(void)
{
	return (new Fwoosh());
}