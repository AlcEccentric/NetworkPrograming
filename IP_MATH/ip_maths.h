#ifndef IP_MATHS_H
#define IP_MATHS_H
/* Necessary Utils for IP math*/
bool decIpIsValid(const char* ip);
void convertDecIpNumToString(int ipNum, char * numBuffer);
int eightBitStringToInt(char * snippet);
void intTo8BitBinString(int number, char* bitBuffer);
void binIpToDecIp(char* binIp);
void decIpToBinIP(char * decIp);

/* assignment funcs */
void get_broadcast_address(const char *ip_addr, char mask, char* output_buffer);
long get_ip_integeral_equivalent(const char* ip_addr);

#endif