#include "ip_maths.h"
#include <string>
#include <iostream>
using namespace std;

const int PREFIX_LEN = 17;

void test(char *ip, char mask){
    char ip_broad_buffer[PREFIX_LEN];
    memset(ip_broad_buffer, 0, PREFIX_LEN);
    get_broadcast_address(ip, mask, ip_broad_buffer);
    long integerIP = get_ip_integeral_equivalent(ip);
    cout<< "Broadcast ip: " << ip_broad_buffer << "\n";
    cout<< "Integer ip: " << integerIP << "\n";

}

int main(){
    string ip;
    int mask;
    char ipChar[20];
    memset(ipChar, 0, 20);
    while(1){
        printf("Input ip addr: ");
        getline(cin, ip);
        
        if(decIpIsValid(ip.c_str()) == false){
            printf("Input content is invalid!\n");
        }else{
            break;
        }
    }
    while(1){
        printf("Input mask: ");
        scanf("%d", &mask);
        if(mask > 31 || mask < 1){
            printf("Input content is invalid!\n");
        }else{
            break;
        }
    }
    strcpy(ipChar, ip.c_str());
    test(ipChar, mask);
    return 0;
}