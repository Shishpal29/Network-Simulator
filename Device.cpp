#include "Device.h"
#include<iostream>

using namespace std;

Device::Device()
{
    //Constructor
}

void Device::set_mac_address(int mac)
{
   macaddress=mac;
}

void Device::setdata(string inf)
{
    info=inf;
}

