//============================================================================
// Name        : serieBoost.cpp
// Author      : Daniel Gaviño
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

#include "SimpleSerial.h"
#include "protocoloV.h"

using namespace std;
using namespace boost;

int main(int argc, char* argv[])
{
	try
	{
/*
		uint8_t datos[33] =
		{ 0x02, 0x10, 0x41, 0x22, 0x10, 0x46, 0x1e, 0, 0, 0x14, 0x83, 0, 0, 0,
				0x10, 0x51, 0x10, 0x58, 0, 0, 0x10, 0x44, 0x10, 0x5a, 0x10,
				0x42, 0x60, 0x10, 0x41, 0xba, 0x8b, 0x5e, 0x1a };
*/

		// Puesta en hora
		uint8_t datos[] ={0x2,0x10,0x41,0x22,0x10,0x46,0x1e,0x10,
				0x46, 0x0,0x66,0xc6,0x20,0x35,0x10,0x42, 0,
				0x10,0x47,0x70,0x76,0x60,0xc5,0x1a};

		char c;
		size_t long_datos=sizeof(datos)/sizeof(datos[0]);
		cout << "log datos:" << long_datos << endl;

		SimpleSerial serial("/dev/ttyS1", 2400);

		serial.write(datos, long_datos);


		cout << "read:";
		while (true)
		{
			c = serial.read();
			printf("%x ", static_cast<char>(c));
		}
		cout << endl;

	} catch (boost::system::system_error& e)
	{
		cout << "Error: " << e.what() << endl;
		return 1;
	}

	return 0;
}
