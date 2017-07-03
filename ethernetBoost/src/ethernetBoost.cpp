//
// client.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2013 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>

#include "ClienteTCP.h"






int main()
{

	TCP::ClienteTCP cliente_tcp;

	cliente_tcp.Configurar();

	cliente_tcp.Enviar();
/*
	asio::streambuf receive_buffer;
	asio::read(socket, receive_buffer, asio::transfer_all(), error);

	if (error && error != asio::error::eof)
	{
		std::cout << "receive failed: " << error.message() << std::endl;
	}
	else
	{
		const char* data = asio::buffer_cast<const char*>(
				receive_buffer.data());
		std::cout << data << std::endl;
	}
*/
	return 0;
}
