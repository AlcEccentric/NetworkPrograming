#include "ip_maths.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <cctype>

// #define debug 1
bool decIpIsValid(const char* ip){
    for(int i = 0; i < strlen(ip); i++){
        bool isDot = ip[i] == '.';
        if (!isdigit(ip[i]) && !isDot){
            return false;
        }
    }
    char ipCopy[20];
    std::memset(ipCopy, 0, 20);
    std::strcpy(ipCopy, ip);
    char * charNum = strtok(ipCopy, ".");
    int count = 0;
    while(charNum != NULL){
         
        int num = std::atoi(charNum);
        count ++;
        if(num>255||num<0){
            return false;
        }
        charNum = strtok(NULL, ".");
       
    }
    if(count != 4){
        return false;
    }
    return true;
}
void convertDecIpNumToString(int ipNum, char * numBuffer){
    if(ipNum > 255 || ipNum < 0){
        std::printf("IpNum is too big\n");
        return;
    }
    char num[4];
    std::memset(num, 0, 4);
    int index = 0;
    if(ipNum > 99){
        index = 2;
    }else if(ipNum <= 99 && ipNum > 9){
        index = 1;
    }else{
        index = 0;
    }
    if(ipNum == 0){
        num[0] = '0';
        std::strcpy(numBuffer, num);
        return;
    }
    while(ipNum != 0 && index > -1){
        num[index] = ipNum % 10 + '0';
        ipNum /= 10;
        index --;
    }
    
    #ifdef debug
    std::printf("DecIpNum corresponding string:%s\n", num);
    #endif
    std::strcpy(numBuffer, num);
}
int eightBitStringToInt(char * snippet){
    int number = 0;
    for(int i = 0; i < 8; i++ ){
        number += std::pow(2, 7-i) * (snippet[i]-'0');
    }
    if (number > 255) {
        std::printf("In eightBitStringToInt: The number is too big.\n");
        return -1;
    }
    #ifdef debug
    std::printf("In eightBitStringToInt: The eight bit number of %s is %d \n ", snippet, number);
    #endif
    return number;
}
void intTo8BitBinString(int number, char* bitBuffer){
    char ip_snippet[9];
    if (number < 0 || number > 255) {
        std::printf("The incoming number is invalid: %d\n", number);
        return;
    }
    int count = 7;
    while (number != 0){
        ip_snippet[count] = number%2 + '0';
        number /= 2;
        count --;
    }
    while (count != -1){
        ip_snippet[count] = '0';
        count --;
    }

    #ifdef debug
    std::printf("incoming number: %d \n", number);
    std::printf("converted snippet: %s \n",ip_snippet);
    
    #endif

    std::strcpy(bitBuffer, ip_snippet);
}

void binIpToDecIp(char* binIp, char* decBuffer){
    char res[17];
    char eightBit[9];
    std::memset(eightBit, 0, 9);
    std::memset(res, 0, 17);
    int strLen = 0;
    int dotNum = 0;
    for(int i = 0; i < 32; i += 8){
        std::strncpy(eightBit, binIp+i, 8);
        int decSnippetNum = eightBitStringToInt(eightBit);
        #ifdef debug
            std::printf("In binIpToDecIp, decSnippetNum:%d \n", decSnippetNum);
        #endif
        char decSnippetStr[4];
        std::memset(decSnippetStr, 0, 4);
        convertDecIpNumToString(decSnippetNum, decSnippetStr);
        #ifdef debug
            std::printf("In binIpToDecIp, decSnippetStr:%s \n", decSnippetStr);
        #endif
        std::strcpy(res+strLen, decSnippetStr);
        strLen += std::strlen(decSnippetStr);
        if (strLen!=16 && dotNum != 3) {
            res[strLen] = '.';
            strLen++;
            dotNum++;
        }
    }

    #ifdef debug
        std::printf("In binIpToDecIp, res:%s\n", res);
    #endif

    std::strcpy(decBuffer, res);
}
void decIpToBinIP(char * decIp, char* bitBuffer){
    char * charNum = strtok(decIp, ".");
    char binIp [33];
    std::memset(binIp, 0, 33);
    int i = 0;
    while(charNum != NULL){
        int number = std::atoi(charNum);
        char bitStr[9];
        std::memset(bitStr, 0, 9);
        #ifdef debug
        std::printf("%d ",number);
        std::printf("\n");
        #endif
        if(i > 24){
            std::printf("Number is too big.\n");
            return;
        }
        intTo8BitBinString(number, bitStr);
        std::strncpy(binIp+i, bitStr, 8);
        charNum = std::strtok(NULL,".");
        i+=8;
    }

    std::strcpy(bitBuffer, binIp);
}


void get_broadcast_address(const char *ip_addr, char mask, char* output_buffer){
    char ipBinBroadcast[33];
    std::memset(ipBinBroadcast, 0, 33); 
    char ipDec[17];
    std::memset(ipBinBroadcast, 0, 17);
    std::strcpy(ipDec, ip_addr);
    decIpToBinIP(ipDec, ipBinBroadcast);

    for (int i = mask; i < 32; i++){
        ipBinBroadcast[i] = '1';
    }
    #ifdef debug
    std::cout<<"broadIP bin format: "<< ipBinBroadcast << std::endl;
    #endif
    binIpToDecIp(ipBinBroadcast, output_buffer);
}

int get_ip_integeral_equivalent(const char* ip_addr){
    char ip[17];
    std::memset(ip, 0, 17);
    std::strcpy(ip, ip_addr);
    char * charNum = strtok(ip, ".");
    int expo = 24;
    int sum = 0;
    while(charNum != NULL && expo > -1){
        int number = std::atoi(charNum);
        #ifdef debug
        std::cout<< number <<" ";
        #endif
        sum += number * std::pow(2, expo);
        charNum = strtok(NULL, ".");
        expo-=8;
    }
    #ifdef debug
    std::cout<<std::endl;
    #endif
    return sum;
}

void get_abcd_ip_format(unsigned int ip_address, char* output_buffer){
    std::memset(output_buffer, 0, 20);
    int len = 0;
    int dotCount = 0;
    int ABCD[4] = {0,0,0,0};
    int abcd = 3;
    while(ip_address != 0){
        int snippet = ip_address % 256;
        if(abcd < 0) {
            std::printf("Input integer error");
            return;
        }
        ABCD[abcd] = snippet;
        ip_address /= 256;
        abcd --;
    }

    for(abcd = 0; abcd < 4; abcd ++){
        char numBuf[4];
        std::memset(numBuf, 0, 4);
        convertDecIpNumToString(ABCD[abcd], numBuf);
        #ifdef debug
            std::cout<< "Lenth of snippet: "<<len<<" NumSnippet: "<< numBuf <<std::endl;
        #endif
        std::strcpy(output_buffer+len, numBuf);
        len += std::strlen(numBuf);
        if(dotCount < 3){
            output_buffer[len] = '.';
            dotCount ++;
            len ++;
        }
    }
        
}

void get_network_id(const char* ip_addr, char mask, char* output_buffer){
    char ipBinNetId[33];
    std::memset(ipBinNetId, 0, 33); 
    char ipDec[17];
    std::memset(ipBinNetId, 0, 17);
    std::strcpy(ipDec, ip_addr);
    decIpToBinIP(ipDec, ipBinNetId);

    for (int i = mask; i < 32; i++){
        ipBinNetId[i] = '0';
    }
    #ifdef debug
    std::cout<<"broadIP bin format: "<< ipBinNetId << std::endl;
    #endif
    binIpToDecIp(ipBinNetId, output_buffer);
}

    