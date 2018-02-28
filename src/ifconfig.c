//
// Created by brunon on 18-2-27.
//

#include <stdio.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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

int main(int argc, char*argv[]){
    printf("ksh-shell:\n");
	ksh_ifconfig();
    return 0;
}
