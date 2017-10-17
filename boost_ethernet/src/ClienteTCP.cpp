/*
 * ClienteTCP.cpp
 *
 *  Created on: 13 mar. 2017
 *      Author: dani
 */

#include "ClienteTCP.h"

#include <iostream>

namespace TCP {

using namespace boost::asio;

ClienteTCP::ClienteTCP() :
		socket(io_service) {
	// TODO Auto-generated constructor stub

}

ClienteTCP::~ClienteTCP() {
	// TODO Auto-generated destructor stub
}

void ClienteTCP::Configurar() {

	socket.connect(
			ip::tcp::endpoint(ip::address::from_string("10.15.43.11"), 6000));
}

void ClienteTCP::Enviar() {
	const std::string msg = "D1T1";

	write(socket, buffer(msg), error);

	if (error) {
		std::cout << "send failed: " << error.message() << std::endl;
	} else {
		std::cout << "send correct!" << std::endl;
	}
}

} /* namespace TCP */
