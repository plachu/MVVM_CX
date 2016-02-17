#include "pch.h"
#include "SecondViewModel.h"

using namespace MVVM_CX;
using namespace ViewModel;
using namespace Model;

using namespace Windows::UI::Xaml::Navigation;

SecondViewModel::SecondViewModel() : ViewModelBase(), _person(nullptr)
{
	//
}

void SecondViewModel::OnNavigatedTo(NavigationEventArgs^ e) {
	ViewModelBase::OnNavigatedTo(e);
	Person = static_cast<Model::Person^>(e->Parameter);
}

void SecondViewModel::OnNavigatedFrom(NavigationEventArgs^ e) {
	//
}

Person^ SecondViewModel::Person::get() {
	return _person;
}

void SecondViewModel::Person::set(Model::Person^ item) {
	if (_person != item) {
		_person = item;
		OnPropertyChanged(getCallerName(__FUNCTION__));
	}
}