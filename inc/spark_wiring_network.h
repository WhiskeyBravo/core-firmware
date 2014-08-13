/**
 ******************************************************************************
 * @file    spark_wiring_network.h
 * @author  Satish Nair, Timothy Brown
 * @version V1.0.0
 * @date    18-Mar-2014
 * @brief   Header for spark_wiring_network.cpp module
 ******************************************************************************
  Copyright (c) 2013 Spark Labs, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
  ******************************************************************************
 */

#ifndef __SPARK_WIRING_NETWORK_H
#define __SPARK_WIRING_NETWORK_H

#include "spark_wiring.h"

// portability macro, thanks to this http://stackoverflow.com/questions/295120/c-mark-as-deprecated/21265197#21265197
// for inspiration, mine takes a second argument
#ifdef __GNUC__
#define DEPRECATED(reason, func) func __attribute__ ((deprecated))
#elif defined(_MSC_VER)
#define DEPRECATED(reason, func) __declspec(deprecated) func
#else
#pragma message("WARNING: You need to implement DEPRECATED for this compiler")
#define DEPRECATED(reason, func) func
#endif


//Retained for compatibility and to flag compiler warnings as build errors
class NetworkClass
{
public:
	DEPRECATED("Please use WiFi.macAddress() instead", uint8_t* macAddress(uint8_t* mac) );
	DEPRECATED("Please use WiFi.localIP() instead", IPAddress localIP() );
	DEPRECATED("Please use WiFi.subnetMask() instead", IPAddress subnetMask() );
	DEPRECATED("Please use WiFi.gatewayIP() instead", IPAddress gatewayIP() );
	DEPRECATED("Please use WiFi.SSID() instead", char* SSID() );
	DEPRECATED("Please use WiFi.RSSI() instead", int8_t RSSI() );
	DEPRECATED("Please use WiFi.ping() instead", uint32_t ping(IPAddress remoteIP) );
	DEPRECATED("Please use WiFi.ping() instead", uint32_t ping(IPAddress remoteIP, uint8_t nTries) );

	DEPRECATED("Please use WiFi.connect() instead", static void connect(void) );
	DEPRECATED("Please use WiFi.disconnect() instead", static void disconnect(void) );
	DEPRECATED("Please use WiFi.connecting() instead", static bool connecting(void) );
	DEPRECATED("Please use WiFi.ready() instead", static bool ready(void) );
};

extern NetworkClass Network;

#endif
