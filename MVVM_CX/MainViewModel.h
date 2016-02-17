#pragma once
#include "RelayCommand.h"
#include "Person.h"

namespace MVVM_CX 
{
	namespace ViewModel
	{
		typedef Windows::Foundation::Collections::IObservableVector<Model::Person^>^ PersonVector;
		
		[Windows::UI::Xaml::Data::Bindable]
		public ref class MainViewModel sealed : public ViewModelBase
		{
		public:
			MainViewModel();
			property PersonVector People
			{
				PersonVector get();
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
