#include "pch.h"
#include "MainViewModel.h"

using namespace MVVM_CX;
using namespace Common;
using namespace Model;
using namespace ViewModel;

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml::Navigation;

MainViewModel::MainViewModel() : ViewModelBase(), _selectedPerson(nullptr)
{
	_people.push_back(ref new Person("Adrian", "P³achecki"));
	_people.push_back(ref new Person("Kamil", "Bukaf"));
	_people.push_back(ref new Person("Mateusz", "Kêpiñski"));
	_people.push_back(ref new Person("Adrian", "Kajetan"));
}

void MainViewModel::OnNavigatedTo(NavigationEventArgs^ e) {
	//
}

void MainViewModel::OnNavigatedFrom(NavigationEventArgs^ e) {
	//
}

PersonVector MainViewModel::People::get() {
	return _people.empty() ? nullptr : ref new Vector<Person^>(_people);
}

Person^ MainViewModel::SelectedPerson::get() {
	return _selectedPerson;
}

void MainViewModel::SelectedPerson::set(Person^ item) {
	if (_selectedPerson != item) {
		_selectedPerson = item;
		OnPropertyChanged(getCallerName(__FUNCTION__));
	}
}

RelayCommand^ MainViewModel::GoToSecondPageCommand::get() {
	if (_goToSecondPageCommand == nullptr) {
		_goToSecondPageCommand = ref new RelayCommand(
			[this](Object^) -> bool 
			{
				return true;
			},
			[this](Object^ e) -> void 
			{
				App::NavigationService->NavigateTo(PageType::SECOND);
			}
		);
	}

	return _goToSecondPageCommand;
}

