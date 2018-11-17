#include <iostream>
#include <string>
using namespace std;
int main(){
    string ip;
    printf("Input ip addr: ");
    getline(cin, ip);
    printf("Your input %s", ip.c_str());
    // char x[6] = "12345";
    // char u[5];
    // std::memset(u, 0, 5);
    // std::strcpy(u, x);
    // std::printf("str: %s; copied one: %s; its lenth:%d\n",x,u,(int)strlen(x));
}