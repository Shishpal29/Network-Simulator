#include "Hub.h"
#include<iostream>

using namespace std;

Hub::Hub()
{
    data = "0";
    mac_add = 0;
}

void Hub::store(int dest_mac,string dest_data,string src)
{
	mac_add=dest_mac;
	data=dest_data;
	hubtodevice(mac_add, data, src);
}


