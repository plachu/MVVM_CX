#pragma once
#include "BindableBase.h"
#include "RelayCommand.h"

namespace MVVM_CX 
{
	namespace ViewModel 
	{
		namespace WUXN = Windows::UI::Xaml::Navigation;

		public ref class ViewModelBase : public Common::BindableBase
		{
		public:
			virtual ~ViewModelBase();
			property Common::RelayCommand^ OnNavigatedToCommand 
			{
				Common::RelayCommand^ get();
			}
			property Common::RelayCommand^ OnNavigatedFromCommand
			{
				Common::RelayCommand^ get();
			}
			 
		internal:
			ViewModelBase();
			virtual void OnNavigatedTo(WUXN::NavigationEventArgs^ e);
			virtual void OnNavigatedFrom(WUXN::NavigationEventArgs^ e);

		protected private:
			Common::RelayCommand^ _onNavigatedToCommand;
			Common::RelayCommand^ _onNavigatedFromCommand;
		};
	}
}
