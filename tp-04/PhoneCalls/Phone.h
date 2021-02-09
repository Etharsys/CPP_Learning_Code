#pragma once

#include "Person.h"

class Phone
{
protected:
	Phone(const Person& owner)
		: _owner { owner }
	{}

	virtual void ring() const { _owner.answer_phone(); }

protected:
	const Person& _owner;
};
