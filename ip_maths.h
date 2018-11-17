#ifndef IP_MATHS_H
#define IP_MATHS_H

bool decIpIsValid(const char* ip);
void convertDecIpNumToString(int ipNum, char * numBuffer);
int eightBitStringToInt(char * snippet);
void intTo8BitBinString(int number, char* bitBuffer);
void binIpToDecIp(char* binIp);
void decIpToBinIP(char * decIp);
void get_broadcast_address(char *ip_addr, char mask, char* output_buffer);

#endif