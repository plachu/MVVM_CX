#include "pch.h"
#include "RelayCommand.h"

using namespace MVVM_CX;
using namespace Common;

using namespace std;
using namespace Platform;

RelayCommand::RelayCommand(function<bool(Object^)> canExecuteCallback, function<void(Object^)> executeCallback) : _canExecuteCallback(canExecuteCallback),
																												  _executeCallback(executeCallback)
{
	//
}

void RelayCommand::RaiseCanExecuteChanged()
{
	CanExecuteChanged(this, nullptr);
}

RelayCommand::~RelayCommand()
{
	_canExecuteCallback = nullptr;
	_executeCallback = nullptr;
}

bool RelayCommand::CanExecute(Object^ parameter)
{
	return (_canExecuteCallback)(parameter);
}

void RelayCommand::Execute(Object^ parameter)
{
	return (_executeCallback)(parameter);
}


