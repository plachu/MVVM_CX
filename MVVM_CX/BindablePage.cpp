#include "pch.h"
#include "BindablePage.h"

using namespace MVVM_CX;
using namespace Common;
using namespace ViewModel;

using namespace Windows::UI::Xaml::Navigation;

BindablePage::BindablePage()
{
	//
}

BindablePage::~BindablePage()
{
	//
}

void BindablePage::OnNavigatedTo(NavigationEventArgs ^ e)
{
	Page::OnNavigatedTo(e);

	auto vm = dynamic_cast<ViewModelBase^>(this->DataContext);

	if (vm != nullptr) {
		vm->OnNavigatedToCommand->Execute(e);
	}
}

void BindablePage::OnNavigatedFrom(NavigationEventArgs ^ e)
{
	Page::OnNavigatedFrom(e);

	auto vm = dynamic_cast<ViewModelBase^>(this->DataContext);
	
	if (vm != nullptr) {
		vm->OnNavigatedFromCommand->Execute(e);
	}
}