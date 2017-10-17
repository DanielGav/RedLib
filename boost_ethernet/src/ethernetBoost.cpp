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

	return 0;
}
