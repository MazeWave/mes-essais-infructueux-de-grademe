#include "Dummy.hpp"

Dummy::~Dummy(void)
{
	return ;
}

Dummy::Dummy(void) : ATarget("Target Practice Dummy")
{
	return ;
}
Dummy *	Dummy::clone(void)
{
	return (new Dummy());
}