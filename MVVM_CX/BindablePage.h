#pragma once

namespace MVVM_CX 
{
	namespace Common 
	{
		public ref class BindablePage : Windows::UI::Xaml::Controls::Page
		{
		public:
			virtual ~BindablePage();

		internal:
			BindablePage();

		protected:
			virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
			virtual void OnNavigatedFrom(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
		};
	}
}


