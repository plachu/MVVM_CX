#include "pch.h"
#include "ViewModelLocator.h"

using namespace MVVM_CX;
using namespace ViewModel;

ViewModelLocator::ViewModelLocator()
{
	_main = ref new ViewModel::MainViewModel();
}

ViewModel::ViewModelBase^ ViewModelLocator::MainViewModel::get()
{
	return _main;
}

ViewModel::ViewModelBase^ ViewModelLocator::SecondViewModel::get()
{
	return ref new ViewModel::SecondViewModel();
}
