#pragma once
//https://stackoverflow.com/questions/52727565/client-in-c-use-gethostbyname-or-getaddrinfo
//#include <string.h>
//#include <winsock2.h>
//#include <windows.h>
//#include <WS2tcpip.h>
//#include <iostream>
//#include <vector>
//#include <locale>
//#include <sstream>
//using namespace std;
//#pragma comment(lib,"ws2_32.lib")
////#define _WINSOCK_DEPRECATED_NO_WARNINGS
//
//string website_HTML;
//locale local;
//void get_Website(string url);
//char buffer[10000];
//int i = 0;
//
//
////****************************************************
//
//int main(void) {
//
//    get_Website("www.stackoverflow.com");
//
//    cout << website_HTML;
//
//    cout << "\n\nPress ANY key to close.\n\n";
//    cin.ignore(); cin.get();
//
//
//    return 0;
//}
//
////****************************************************
//
//void get_Website(string url) {
//    WSADATA wsaData;
//    SOCKET Socket;
//    SOCKADDR_IN SockAddr;
//    int lineCount = 0;
//    int rowCount = 0;
//    struct hostent* host;
//    string get_http;
//
//
//    get_http = "GET / HTTP/1.1\r\nHost: " + url + "\r\nConnection: close\r\n\r\n";
//
//    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
//        cout << "WSAStartup failed.\n";
//        system("pause");
//        //return 1;
//    }
//
//    Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//    //host = gethostbyname(url.c_str());
//    host = getaddrinfo(url.c_str());
//
//    SockAddr.sin_port = htons(80);
//    SockAddr.sin_family = AF_INET;
//    SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);
//
//    if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0) {
//        cout << "Could not connect";
//        system("pause");
//        //return 1;
//    }
//    send(Socket, get_http.c_str(), strlen(get_http.c_str()), 0);
//
//    int nDataLength;
//    while ((nDataLength = recv(Socket, buffer, 10000, 0)) > 0) {
//        int i = 0;
//        while (buffer[i] >= 32 || buffer[i] == '\n' || buffer[i] == '\r') {
//
//            website_HTML += buffer[i];
//            i += 1;
//        }
//    }
//
//    closesocket(Socket);
//    WSACleanup();
//
//}



//#undef UNICODE
//
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <stdio.h>
//#pragma comment (lib, "Ws2_32.lib")
//
////https://learn.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-getaddrinfo?f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(getaddrinfo)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue
//int main(int argc, char** argv)
//{
//    //-----------------------------------------
//    // Declare and initialize variables
//    WSADATA wsaData;
//    int iResult;
//    INT iRetval;
//
//    DWORD dwRetval;
//
//    int i = 1;
//
//    struct addrinfo* result = nullptr;
//    struct addrinfo* ptr = nullptr;
//    struct addrinfo hints;
//
//    struct sockaddr_in* sockaddr_ipv4;
//    //    struct sockaddr_in6 *sockaddr_ipv6;
//    LPSOCKADDR sockaddr_ip;
//
//    char ipstringbuffer[46];
//    DWORD ipbufferlength = 46;
//
//    // Validate the parameters
//    if (argc != 3) {
//        printf("usage: %s <hostname> <servicename>\n", argv[0]);
//        printf("getaddrinfo provides protocol-independent translation\n");
//        printf("   from an ANSI host name to an IP address\n");
//        printf("%s example usage\n", argv[0]);
//        printf("   %s www.contoso.com 0\n", argv[0]);
//        return 1;
//    }
//
//    // Initialize Winsock
//    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//    if (iResult != 0) {
//        printf("WSAStartup failed: %d\n", iResult);
//        return 1;
//    }
//
//    //--------------------------------
//    // Setup the hints address info structure
//    // which is passed to the getaddrinfo() function
//    ZeroMemory(&hints, sizeof(hints));
//    hints.ai_family = AF_UNSPEC;
//    hints.ai_socktype = SOCK_STREAM;
//    hints.ai_protocol = IPPROTO_TCP;
//
//    printf("Calling getaddrinfo with following parameters:\n");
//    printf("\tnodename = %s\n", argv[1]);
//    printf("\tservname (or port) = %s\n\n", argv[2]);
//
//    //--------------------------------
//    // Call getaddrinfo(). If the call succeeds,
//    // the result variable will hold a linked list
//    // of addrinfo structures containing response
//    // information
//    dwRetval = getaddrinfo(argv[1], argv[2], &hints, &result);
//    if (dwRetval != 0) {
//        printf("getaddrinfo failed with error: %d\n", dwRetval);
//        WSACleanup();
//        return 1;
//    }
//
//    printf("getaddrinfo returned success\n");
//
//    // Retrieve each address and print out the hex bytes
//    for (ptr = result; ptr != nullptr; ptr = ptr->ai_next) {
//
//        printf("getaddrinfo response %d\n", i++);
//        printf("\tFlags: 0x%x\n", ptr->ai_flags);
//        printf("\tFamily: ");
//        switch (ptr->ai_family) {
//        case AF_UNSPEC:
//            printf("Unspecified\n");
//            break;
//        case AF_INET:
//            printf("AF_INET (IPv4)\n");
//            sockaddr_ipv4 = (struct sockaddr_in*)ptr->ai_addr;
//            printf("\tIPv4 address %s\n",
//                inet_ntoa(sockaddr_ipv4->sin_addr));
//            break;
//        case AF_INET6:
//            printf("AF_INET6 (IPv6)\n");
//            // the InetNtop function is available on Windows Vista and later
//            // sockaddr_ipv6 = (struct sockaddr_in6 *) ptr->ai_addr;
//            // printf("\tIPv6 address %s\n",
//            //    InetNtop(AF_INET6, &sockaddr_ipv6->sin6_addr, ipstringbuffer, 46) );
//
//            // We use WSAAddressToString since it is supported on Windows XP and later
//            sockaddr_ip = (LPSOCKADDR)ptr->ai_addr;
//            // The buffer length is changed by each call to WSAAddresstoString
//            // So we need to set it for each iteration through the loop for safety
//            ipbufferlength = 46;
//            iRetval = WSAAddressToString(sockaddr_ip, (DWORD)ptr->ai_addrlen, nullptr,
//                ipstringbuffer, &ipbufferlength);
//            if (iRetval)
//                printf("WSAAddressToString failed with %u\n", WSAGetLastError());
//            else
//                printf("\tIPv6 address %s\n", ipstringbuffer);
//            break;
//        case AF_NETBIOS:
//            printf("AF_NETBIOS (NetBIOS)\n");
//            break;
//        default:
//            printf("Other %ld\n", ptr->ai_family);
//            break;
//        }
//        printf("\tSocket type: ");
//        switch (ptr->ai_socktype) {
//        case 0:
//            printf("Unspecified\n");
//            break;
//        case SOCK_STREAM:
//            printf("SOCK_STREAM (stream)\n");
//            break;
//        case SOCK_DGRAM:
//            printf("SOCK_DGRAM (datagram) \n");
//            break;
//        case SOCK_RAW:
//            printf("SOCK_RAW (raw) \n");
//            break;
//        case SOCK_RDM:
//            printf("SOCK_RDM (reliable message datagram)\n");
//            break;
//        case SOCK_SEQPACKET:
//            printf("SOCK_SEQPACKET (pseudo-stream packet)\n");
//            break;
//        default:
//            printf("Other %ld\n", ptr->ai_socktype);
//            break;
//        }
//        printf("\tProtocol: ");
//        switch (ptr->ai_protocol) {
//        case 0:
//            printf("Unspecified\n");
//            break;
//        case IPPROTO_TCP:
//            printf("IPPROTO_TCP (TCP)\n");
//            break;
//        case IPPROTO_UDP:
//            printf("IPPROTO_UDP (UDP) \n");
//            break;
//        default:
//            printf("Other %ld\n", ptr->ai_protocol);
//            break;
//        }
//        printf("\tLength of this sockaddr: %d\n", ptr->ai_addrlen);
//        printf("\tCanonical name: %s\n", ptr->ai_canonname);
//    }
//
//    freeaddrinfo(result);
//    WSACleanup();
//
//    return 0;
//}