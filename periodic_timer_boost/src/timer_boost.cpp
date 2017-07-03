//============================================================================
// Name        : timer_boost.cpp
// Author      : Daniel Gaviño
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int value = 0;

boost::asio::io_service io;
boost::posix_time::seconds interval(1); // 1 second
boost::asio::deadline_timer timer(io, interval);


void funcion_ejecutar()
{
static int value=0;
value++;
std::cout << value << std::endl;
}

void work_for_io_service(const boost::system::error_code& /*e*/)
{
	funcion_ejecutar();

	timer.expires_at(timer.expires_at() + interval);

	timer.async_wait(work_for_io_service);
}

int main()
{

	std::cout << "Using Boost "
	          << BOOST_VERSION / 100000     << "."  // major version
	          << BOOST_VERSION / 100 % 1000 << "."  // minor version
	          << BOOST_VERSION % 100                // patch level
	          << std::endl;

	std::cout << "Inicio\n";

	timer.async_wait(work_for_io_service);

	io.run();

	std::cout << "fin del programa";

	return 0;
}
