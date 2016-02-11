#pragma once
#include "BindableBase.h"


namespace MVVM_CX 
{
	namespace Model
	{
		[Windows::UI::Xaml::Data::Bindable]
		public ref class Person sealed : public Common::BindableBase
		{
		internal:
			Person();
			Person(Platform::String^ name, Platform::String^ surname);

		public:
			property Platform::String^ Name {
				Platform::String^ get();
				void set(Platform::String^ value);
			}
			property Platform::String^ Surname {
				Platform::String^ get();
				void set(Platform::String^ value);
			}

		private:
			Platform::String ^_name, ^_surname;
		};
	}
}