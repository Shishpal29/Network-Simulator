#ifndef HUB_H
#define HUB_H
#include<string>

using namespace std;

class Hub
{
    public:
        Hub();
        string data;
	int mac_add;
	void store(int m,string x,string s);
	void hubtodevice(int mac_add,string d,string s);

};

#endif // DEVICE_H

