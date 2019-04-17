#ifndef DEVICE_H
#define DEVICE_H
#include<string>

using namespace std;

class Device
{
    public:
        Device();
        int macaddress;
        string info;
        void set_mac_address(int);
        void setdata(string);
};

#endif // DEVICE_H

