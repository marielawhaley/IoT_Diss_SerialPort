#pragma once
#include <array>
#include "MySQL.h"


//using namespace std;
using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;
using namespace System::Collections;

ref class serialPort
{

public:
	//SerialPort _serialPort;
	serialPort();
	static void DataReceivedHandler(Object^ sender, SerialDataReceivedEventArgs^ e);
	static void ErrorReceivedHandler(Object^ sender, SerialErrorReceivedEventArgs^ e);
	static String^ getValues(int i);

private:
	static SerialPort^ _serialPort;
	static MySQL my_sql;
	static bool _continue;
	static array< String^>^ dataArray;
};

