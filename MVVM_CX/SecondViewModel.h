#pragma once
#include "Person.h"

namespace MVVM_CX
{
	namespace ViewModel
	{
		[Windows::UI::Xaml::Data::Bindable]
		public ref class SecondViewModel sealed : public ViewModelBase
		{
		public:
			SecondViewModel();
			property Model::Person^ Person
			{
				Model::Person^ get();
				void set(Model::Person^ item);
			}

		internal:
			void OnNavigatedTo(WUXN::NavigationEventArgs^ e) override;
			void OnNavigatedFrom(WUXN::NavigationEventArgs^ e) override;

		private:
			Model::Person^ _person;
		};
	}
}

