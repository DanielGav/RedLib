/*
 * ClienteTCP.h
 *
 *  Created on: 13 mar. 2017
 *      Author: dani
 */

#ifndef CLIENTETCP_H_
#define CLIENTETCP_H_

#include <boost/asio.hpp>

namespace TCP
{

class ClienteTCP
{
private:
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket socket;
	boost::system::error_code error;
public:
	ClienteTCP();
	virtual ~ClienteTCP();
	void Configurar();
	void Enviar();
};

} /* namespace TCP */

#endif /* CLIENTETCP_H_ */
