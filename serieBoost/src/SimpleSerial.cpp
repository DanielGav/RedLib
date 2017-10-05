/*
 * SimpleSerial.cpp
 *
 *  Created on: 1 mar. 2017
 *      Author: dani
 */

#include "SimpleSerial.h"

using namespace boost;

SimpleSerial::SimpleSerial(std::string port, unsigned int baud_rate) :
		io(), serial(io, port)
{
	serial.set_option(asio::serial_port_base::baud_rate(baud_rate));
	//serial.set_option(asio::serial_port_base::character_size);
	//serial.set_option(asio::serial_port_base::flow_control);
	//serial.set_option(asio::serial_port_base::parity);
	//serial.set_option(asio::serial_port_base::stop_bits);

}

SimpleSerial::~SimpleSerial()
{

}

/**
 * Blocks until a line is received from the serial device.
 * Eventual '\n' or '\r\n' characters at the end of the string are removed.
 * \return a string containing the received line
 * \throws boost::system::system_error on failure
 */
std::string SimpleSerial::readLine()
{
	//Reading data char by char, code is optimized for simplicity, not speed
	char c;
	std::string result;
	for (;;)
	{
		asio::read(serial, asio::buffer(&c, 1));
		switch (c)
		{
		case '\r':
			break;
		case '\n':
			return result;
		default:
			result += c;
		}
	}
}

char SimpleSerial::read()
{
	char c;

	asio::read(serial, asio::buffer(&c, 1));

	return c;
}

void SimpleSerial::writeString(std::string s)
{
	boost::asio::write(serial, boost::asio::buffer(s.c_str(), s.size()));
}


void SimpleSerial::write(uint8_t* command,size_t size_command)
{

	boost::asio::write(serial, boost::asio::buffer(command,size_command));
}
