#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>

int main() {
    int sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock_raw < 0) {
        perror("Socket error");
        return 1;
    }

    unsigned char *buffer = (unsigned char *)malloc(65536);
    struct sockaddr saddr;
    socklen_t saddr_size = sizeof(saddr);
    int data_size;

    while (1) {
        data_size = recvfrom(sock_raw, buffer, 65536, 0, &saddr, &saddr_size);
        if (data_size < 0) {
            perror("Recvfrom error");
            break;
        }

        struct ethhdr *eth = (struct ethhdr *)buffer;
        if (ntohs(eth->h_proto) == ETH_P_IP) {
            struct iphdr *iph = (struct iphdr*)(buffer + sizeof(struct ethhdr));
            struct in_addr src, dst;
            src.s_addr = iph->saddr;
            dst.s_addr = iph->daddr;
            printf("IP Packet: %s -> %s\n", inet_ntoa(src), inet_ntoa(dst));
        }
    }

    close(sock_raw);
    return 0;
}


