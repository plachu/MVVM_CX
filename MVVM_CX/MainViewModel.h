#pragma once
#include "BindableBase.h"
#include "RelayCommand.h"
#include "Person.h"

namespace MVVM_CX 
{
	namespace ViewModel
	{
		namespace WFC = Windows::Foundation::Collections;

		[Windows::UI::Xaml::Data::Bindable]
		public ref class MainViewModel sealed : public Common::BindableBase
		{
		public:
			MainViewModel();
			property WFC::IObservableVector<Model::Person^>^ People
			{
				WFC::IObservableVector<Model::Person^>^ get();
			}
			property Model::Person^ SelectedPerson
			{
				Model::Person^ get();
				void set(Model::Person^ item);
			}
			property Common::RelayCommand^ GoToSecondPageCommand
			{
				Common::RelayCommand^ get();
			}

		private:
			std::vector<Model::Person^> _people;
			Model::Person^ _selectedPerson;
			Common::RelayCommand^ _goToSecondPageCommand;
		};
	}
}
