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
int get_ip_integeral_equivalent(const char* ip_addr);
void get_abcd_ip_format(unsigned int ip_address, char* output_buffer);
void get_network_id(const char* ip_Addr, char mask, char* output_buffer);
unsigned int get_subnet_cardinality(char mask);

#endif