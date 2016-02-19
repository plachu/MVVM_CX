#pragma once

#include "PageType.h"
#include <stack>


namespace MVVM_CX
{
	namespace Common 
	{
		namespace WUC = Windows::UI::Core;
		namespace WUXC = Windows::UI::Xaml::Controls;
		namespace WUXI = Windows::UI::Xaml::Interop;
		namespace WPUI = Windows::Phone::UI::Input;

		public ref class NavigationService sealed : WUXC::INavigate
		{
		public:
			NavigationService(WUXC::Frame^ frame);
			virtual bool Navigate(WUXI::TypeName sourcePageType);
			void NavigateTo(PageType type);
			void NavigateTo(PageType type, Platform::Object^ parameter);
			void NavigateToHome();
			void NavigateBack();

		private:
			void UpdateBackButtonVisibility();
			void OnBackRequested(Platform::Object^ sender, WUC::BackRequestedEventArgs^ e);
			void OnHardwareButtonBackPressed(Platform::Object^ sender, WPUI::BackPressedEventArgs^ e);

		private:
			WUXC::Frame^ _frame;
			std::stack<WUXI::TypeName> _pageStack;
			std::map<PageType, WUXI::TypeName> _pages;
		};
	}
}