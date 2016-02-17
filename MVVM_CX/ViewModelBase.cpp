#include "pch.h"
#include "ViewModelBase.h"

using namespace MVVM_CX;
using namespace ViewModel;
using namespace Common;

using namespace Windows::UI::Xaml::Navigation;

ViewModelBase::ViewModelBase() : _onNavigatedToCommand(nullptr), _onNavigatedFromCommand(nullptr) {
	//
}

ViewModelBase::~ViewModelBase() {
	_onNavigatedToCommand = nullptr;
	_onNavigatedFromCommand = nullptr;
}

RelayCommand^ ViewModelBase::OnNavigatedToCommand::get() {
	if (_onNavigatedToCommand == nullptr) {
		_onNavigatedToCommand = ref new RelayCommand(
			[this](Object^) -> bool
			{
				return true;
			},
			[this](Object^ e) -> void
			{
				OnNavigatedTo(dynamic_cast<NavigationEventArgs^>(e));
			}
		);
	}

	return _onNavigatedToCommand;
}

RelayCommand^ ViewModelBase::OnNavigatedFromCommand::get() {
	if (_onNavigatedFromCommand == nullptr) {
		_onNavigatedFromCommand = ref new RelayCommand(
			[this](Object^) -> bool
			{
				return true;
			},
			[this](Object^ e) -> void
			{
				OnNavigatedFrom(dynamic_cast<NavigationEventArgs^>(e));
			}
		);
	}

	return _onNavigatedFromCommand;
}

void ViewModelBase::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) {
	//
}

void ViewModelBase::OnNavigatedFrom(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) {
	//
}