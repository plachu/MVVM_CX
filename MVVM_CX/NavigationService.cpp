#include "pch.h"
#include "NavigationService.h"
#include "MainPage.xaml.h"
#include "SecondPage.xaml.h"

using namespace MVVM_CX;
using namespace Common;

using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Interop;

NavigationService::NavigationService(Frame^ frame)
{
	if (_frame != nullptr) {
		return;
	}

	_frame = frame;
	SystemNavigationManager::GetForCurrentView()->BackRequested += ref new Windows::Foundation::EventHandler<BackRequestedEventArgs ^>(this, &Common::NavigationService::OnBackRequested);

	_pages.emplace(PageType::MAIN, TypeName(MVVM_CX::MainPage::typeid));
	_pages.emplace(PageType::SECOND, TypeName(MVVM_CX::SecondPage::typeid));
}

bool NavigationService::Navigate(TypeName sourcePageType)
{
	return false;
}

void NavigationService::NavigateTo(PageType type)
{
	TypeName& pageType = _pages.at(type);

	if (!_pageStack.empty() && _pageStack.top().Equals(pageType)) {
		return;
	}

	_pageStack.push(pageType);
	_frame->Navigate(pageType, nullptr);
	UpdateBackButtonVisibility();
}


void NavigationService::NavigateTo(PageType type, Platform::Object^ parameter) 
{
	TypeName& pageType = _pages.at(type);

	if (!_pageStack.empty() && _pageStack.top().Equals(pageType)) {
		return;
	}

	_pageStack.push(pageType);
	_frame->Navigate(pageType, parameter);
	UpdateBackButtonVisibility();
}

void NavigationService::NavigateToHome() 
{
	while (_frame->CanGoBack) {
		_frame->GoBack();
	}
}

void NavigationService::NavigateBack() 
{
	if (_frame->CanGoBack) {
		_frame->GoBack();
	}

	_pageStack.pop();
	UpdateBackButtonVisibility();
}

void NavigationService::UpdateBackButtonVisibility() 
{
	SystemNavigationManager::GetForCurrentView()->AppViewBackButtonVisibility = _frame->CanGoBack ? AppViewBackButtonVisibility::Visible : AppViewBackButtonVisibility::Collapsed;
}

void NavigationService::OnBackRequested(Object^ sender, BackRequestedEventArgs^ e)
{
	NavigateBack();
}