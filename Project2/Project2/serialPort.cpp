#include "serialPort.h"
//#include "MySQL.h"
#include <iostream>

serialPort::serialPort() 
{
	//Thread^ readThread = gcnew Thread(gcnew ThreadStart(serialPort::Read));
	_serialPort = gcnew SerialPort();
	_continue = true;
	dataArray = gcnew array<String^>(5);

	_serialPort->PortName = "COM3";
	_serialPort->BaudRate = 9600;
	_serialPort->Parity = Parity::None;
	_serialPort->DataBits = 8;
	_serialPort->StopBits = StopBits::One;
	_serialPort->Handshake = Handshake::None;

	_serialPort->ReadTimeout = 10000;
	_serialPort->RtsEnable = true;
	_serialPort->DtrEnable = true;
	_serialPort->DataReceived += gcnew SerialDataReceivedEventHandler(DataReceivedHandler);

	_serialPort->Open();
	if (_serialPort->IsOpen)
	{
		Console::WriteLine("Serial Port open");		
	}
	_serialPort->ErrorReceived += gcnew SerialErrorReceivedEventHandler(ErrorReceivedHandler);
}

void  serialPort::DataReceivedHandler(Object^ sender, SerialDataReceivedEventArgs^ e)
{
	SerialPort^ sp = (SerialPort^)sender;
	String^ indata = _serialPort->ReadLine();
	Console::Write(indata);
	Char delimiter = ',';
	dataArray = indata->Split(delimiter);

	my_sql.insertValues(dataArray[0], dataArray[1], dataArray[2], dataArray[3], dataArray[4]);
}

String^ serialPort::getValues(int i)
{
	String ^ data;
	if (i < 3)
	{
		 data = dataArray[i];
	}
	return data;
}


  void serialPort::ErrorReceivedHandler(Object^sender, SerialErrorReceivedEventArgs^e)
{
	Console::WriteLine("Data error:");  
}

