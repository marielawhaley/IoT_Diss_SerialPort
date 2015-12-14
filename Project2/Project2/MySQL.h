#pragma once

using namespace System;
//using namespace std;
using namespace MySql::Data::MySqlClient;

ref class MySQL
{
public:
	void insertValues(String^ temperature, String^ dewPoint, String^ dust, String^ humidity, String^ light);

private:
	void queryValues();

};

