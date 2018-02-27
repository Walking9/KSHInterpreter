//
// Created by brunon on 18-2-27.
//

#ifndef KSHINTERPRETER_IFCONFIG_H
#define KSHINTERPRETER_IFCONFIG_H

#include <ifaddrs.h>
#include <stddef.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <memory.h>

int ksh_ifconfig() {
    char ip[16];
    struct ifaddrs *ifAddrPtr;
    getifaddrs(&ifAddrPtr);
    while (ifAddrPtr != NULL) {
        if (ifAddrPtr->ifa_addr->sa_family == AF_INET) {
            inet_ntop(AF_INET, &((struct sockaddr_in *)ifAddrPtr->ifa_addr)->sin_addr, ip, INET_ADDRSTRLEN);
            printf("%s\tIP Address:%s\n", ifAddrPtr->ifa_name, ip);
        }
        ifAddrPtr = ifAddrPtr->ifa_next;
    }
    //free ifaddrs
    freeifaddrs(ifAddrPtr);
    return 0;
}

#endif //KSHINTERPRETER_IFCONFIG_H
