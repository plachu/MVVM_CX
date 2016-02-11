#include "pch.h"
#include "Person.h"
#include <sstream>

using namespace MVVM_CX;
using namespace Model;

using namespace Platform;

Person::Person()
{
	//
}

Person::Person(String^ name, String^ surname)
{
	Name::set(name);
	Surname::set(surname);
}

String^ Person::Name::get()
{
	return _name;
}

void Person::Name::set(String^ value) 
{
	if (value != nullptr) {
		_name = value;
		OnPropertyChanged(getCallerName(__FUNCTION__));
	}
}

String^ Person::Surname::get()
{
	return _surname;
}

void Person::Surname::set(String^ value)
{
	if (value != nullptr) {
		_surname = value;
		OnPropertyChanged(getCallerName(__FUNCTION__));
	}
}