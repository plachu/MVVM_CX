#pragma once
#include "MainViewModel.h"

namespace MVVM_CX 
{
	namespace ViewModel
	{
		[Windows::UI::Xaml::Data::Bindable]
		public ref class ViewModelLocator sealed
		{
		public:
			ViewModelLocator();
			property MainViewModel^ MainViewModel
			{
				ViewModel::MainViewModel^ get();
			}

		private:
			ViewModel::MainViewModel^ _viewModel;
		};
	}
}

