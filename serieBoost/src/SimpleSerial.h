/*
 * SimpleSerial.h
 *
 *  Created on: 1 mar. 2017
 *      Author: dani
 */

#ifndef SIMPLESERIAL_H_
#define SIMPLESERIAL_H_

#include <boost/asio.hpp>

class SimpleSerial
{

private:
	boost::asio::io_service io;
	boost::asio::serial_port serial;

public:
	/**
	 * Constructor.
	 * \param port device name, example "/dev/ttyUSB0" or "COM4"
	 * \param baud_rate communication speed, example 9600 or 115200
	 * \throws boost::system::system_error if cannot open the
	 * serial device
	 */
	SimpleSerial(std::string port, unsigned int baud_rate);



	~SimpleSerial();

	/**
	 * Write a string to the serial device.
	 * \param s string to write
	 * \throws boost::system::system_error on failure
	 */
	void writeString(std::string s);

	/**
	 * Blocks until a line is received from the serial device.
	 * Eventual '\n' or '\r\n' characters at the end of the string are removed.
	 * \return a string containing the received line
	 * \throws boost::system::system_error on failure
	 */
	std::string readLine();

	char read();

	void write(uint8_t* command,size_t size_command);

};

#endif /* SIMPLESERIAL_H_ */
