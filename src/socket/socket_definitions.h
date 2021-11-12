#ifndef SOCKET_CONTEXT_H
#define SOCKET_CONTEXT_H

// common includes
#include <cassert>


// windows
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")


// testing variables

#define TCPIP_PACKET_MAX_SIZE 65536 

// settings of sockets
#define DEFAULT_BUFLEN 4096
#define DEFAULT_PORT "8080"

#if defined(_WIN32) && !defined(__linux__)

namespace Addrinfo {

	enum aiflags {
		FLAG_AI_PASSIVE = 0x01,
		FLAG_AI_CANONNAME = 0x02,
		FLAG_AI_NUMERICHOST = 0x04,
		FLAG_AI_ALL = 0x0100,
		FLAG_AI_ADDRCONFIG = 0x0400,
		FLAG_AI_V4MAPPED = 0x0800,
		FLAG_AI_NON_AUTHORITATIVE = 0x04000,
		FLAG_AI_SECURE = 0x08000,
		FLAG_AI_RETURN_PREFERRED_NAMES = 0x010000,
		FLAG_AI_FQDN = 0x00020000,
		FLAG_AI_FILESERVER = 0x00040000
	};

	enum aifamily {
		FAM_AF_UNSPEC = 0,		// The address family is unspecified.
		FAM_AF_INET = 2,			// The Internet Protocol version 4 (IPv4)address family.
		FAM_AF_NETBIOS = 17,	// The NetBIOS address family.This address family is only supported if a Windows Sockets provider for NetBIOS is installed.
		FAM_AF_INET6 = 23,		// The Internet Protocol version 6 (IPv6)address family.
		FAM_AF_IRDA = 26,		// The Infrared Data Association(IrDA) address family.This address family is only supported if the computer has an infrared portand driver installed.
		FAM_AF_BTH = 32,		// The Bluetooth address family.This address family is only supported if a Bluetooth adapter is installed on Windows Server 2003 or later.
	};

	enum aisocktype {
		TYPE_SOCK_STREAM = 1,
		TYPE_SOCK_DGRAM = 2,
		TYPE_SOCK_RAW = 3,
		TYPE_SOCK_RDM = 4,
		TYPE_SOCK_SEQPACKET = 5,
	};

	enum aiprotocol {
		PROTOCOL_TCP = 6,
		PROTOCOL_UDP = 17,
		PROTOCL_RM = 113,
	};

} // namespace addinfo

#elif defined(__linux__) && !defined(_WIN32)

// linux tools 
#endif


#endif // !1