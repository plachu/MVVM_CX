#pragma once
#include "ViewModelBase.h"
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
			property ViewModelBase^ MainViewModel
			{
				ViewModel::ViewModelBase^ get();
			}

		private:
			ViewModel::ViewModelBase^ _viewModel;
		};
	}
}

