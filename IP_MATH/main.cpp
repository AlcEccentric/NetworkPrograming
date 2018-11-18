#include "ip_maths.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

const int PREFIX_LEN = 17;

unsigned int getIntIP(){
    unsigned int ip;
    while(1){
        printf("Input ip integer: ");
        scanf("%d", &ip);

        if(ip>(pow(2,32)-1) || ip < 0){
            printf("Input content is invalid!\n");
        }else{
            break;
        }

    }
    return ip;
}

void getDecIP(char* ipChar){
    string ip;
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

    strcpy(ipChar, ip.c_str());
}

void getDecNetId(char* idChar){
    string id;
    memset(idChar, 0, 20);
    while(1){
        printf("Input net id: ");
        getline(cin, id);
        
        if(decIpIsValid(id.c_str()) == false){
            printf("Input content is invalid!\n");
        }else{
            break;
        }
    }

    strcpy(idChar, id.c_str());
}

int getMask(){
    int mask;
    string s;
    while(1){
    printf("Input mask: ");
    getline(cin, s);
    mask = (int) atoi(s.c_str());

        if(mask > 31 || mask < 1){
            printf("Input content is invalid!\n");
        }else{
            break;
        }
    }
    return mask;
}

void testBroad(){
    int mask;
    char ipChar[20];
    getDecIP(ipChar);
    mask = getMask();

    char ip_broad_buffer[PREFIX_LEN];
    memset(ip_broad_buffer, 0, PREFIX_LEN);
    get_broadcast_address(ipChar, mask, ip_broad_buffer);
    
    cout<< "Broadcast ip: " << ip_broad_buffer << "\n";

}

void testNetID(){
    int mask;
    char ipChar[20];
    getDecIP(ipChar);
    mask = getMask();

    char net_id_buffer[PREFIX_LEN];
    memset(net_id_buffer, 0, PREFIX_LEN);
    get_network_id(ipChar, mask, net_id_buffer);
    
    cout<< "Net id: " << net_id_buffer << "\n";

}

void testCard(){
    char mask;
    mask = getMask();
    cout<< "Subnet cardinality: " << get_subnet_cardinality(mask) << "\n";
}

void testIPGenInteger(){
    char ipChar[20];
    getDecIP(ipChar);
    int integerIP = get_ip_integeral_equivalent(ipChar);
    cout<< "Integer ip: " << integerIP << "\n";
}

void testIntegerGenIP(){
    unsigned int intIP = getIntIP();
    char ipChar[20];
    get_abcd_ip_format(intIP, ipChar);
    cout << "ABCD format ip: " << ipChar << endl;
}

void testIPBelong(){
    int mask;
    mask = getMask();

    char ipChar[20];
    getDecIP(ipChar);
    
    char idChar[20];
    getDecNetId(idChar);

    check_ip_subnet_member(idChar, mask, ipChar);

}

int main(){
    
    // testBroad();
    // testIPGenInteger();
    // testIntegerGenIP();
    // testNetID();
    // testCard();
    testIPBelong();
    return 0;
}