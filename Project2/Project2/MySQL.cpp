#include <iostream>
#include "MySQL.h"



void MySQL::queryValues()
{
	String^ constring = L"datasource=localhost;port=3306;username=root;password=Light33!";
	MySqlConnection^ connection = gcnew MySqlConnection(constring);

	int temperature;
	int dewPoint;
	int noise;
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT temperature, dew_point, noise FROM deskegg_test.data;", connection);
	MySqlDataReader^ myReader;


	try {
		connection->Open();
		myReader = cmdDataBase->ExecuteReader();
		while (myReader->Read())
		{
			temperature = myReader->GetInt16(myReader->GetOrdinal("temperature"));
			dewPoint = myReader->GetInt16(myReader->GetOrdinal("dew_point"));
			noise = myReader->GetInt16(myReader->GetOrdinal("noise"));

			Console::Write(temperature);
			Console::Write(dewPoint);
			Console::Write(noise);
			Console::Write("\n");
		}
		connection->Close();
	}
	catch (Exception^ex) {
		Console::Write("Data Base Error");
	}
}

void MySQL::insertValues( String^ temperature, String^ dewPoint, String^ dust, String^ humidity, String^ light)
{
	String^ constring = L"datasource=localhost;port=3306;username=root;password=Light33!";
	MySqlConnection^ connection = gcnew MySqlConnection(constring);

	try {
		connection->Open();
		MySqlCommand^command = gcnew MySqlCommand("INSERT INTO deskegg_test.data (temperature, dew_point, dust, humidity, ambient_light) values  (" + temperature + ", " + dewPoint + ", " + dust + ", " + humidity + ", " + light +");", connection);
		Console::Write("DataBase Opened	\n");
		command->ExecuteNonQuery();
		Console::Write("Saved\n");
	}
	catch (Exception^ex) {
		Console::Write("DataBase Error\n");
	}
	connection->Close();
}