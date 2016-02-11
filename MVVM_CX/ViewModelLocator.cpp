#include "pch.h"
#include "ViewModelLocator.h"

using namespace MVVM_CX;
using namespace ViewModel;

ViewModelLocator::ViewModelLocator()
{
	_viewModel = ref new ViewModel::MainViewModel();
}

ViewModel::MainViewModel^ ViewModelLocator::MainViewModel::get()
{
	return _viewModel;
}