#pragma once
#include "ViewModelBase.h"
#include "MainViewModel.h"
#include "SecondViewModel.h"

namespace MVVM_CX 
{
	namespace ViewModel
	{
		[Windows::UI::Xaml::Data::Bindable]
		public ref class ViewModelLocator sealed
		{
		public:
			ViewModelLocator();
			property ViewModelBase^ MainViewModel
			{
				ViewModelBase^ get();
			}
			property ViewModelBase^ SecondViewModel
			{
				ViewModelBase^ get();
			}

		private:
			ViewModelBase ^_main;
		};
	}
}

