/*
 This file is part of cpp-ethereum.
 
 cpp-ethereum is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 cpp-ethereum is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
 */
/** @file NetListenHandler.cpp
 * @author Alex Leverington <nessence@gmail.com>
 * @author Gav Wood <i@gavwood.com>
 * @date 2014
 */

#pragma once

#include <thread>
#include "NetConnection.h"
#include "Common.h"

namespace dev
{
	
class NetConnection;
	
/**
 * @brief Interface for handling Network service connections.
 *
 * @todo Random sequence initialization.
 */
class NetListenHandler
{
public:
	NetListenHandler(boost::asio::ip::tcp::endpoint _ep);
	~NetListenHandler();

	// template...
//	/// Will be passed incoming data-messages.
//	virtual void dataMsgHandler(NetMsg& _msg) { return; }
//	
//	/// Will be passed incoming service-messages.
//	virtual void serviceMsgHandler(NetMsg& _msg) { return; }

private:
	NetMsgSequence nextDataSequence();

	std::atomic<NetMsgSequence> m_localDataSequence;
	
	boost::asio::io_service m_io;
	boost::asio::ip::tcp::acceptor m_acceptor;
	std::thread m_ioThread;

	std::atomic<bool> m_stopped;
	std::mutex x_stopped;
	
};
	
}

