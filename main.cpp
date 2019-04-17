#include<bits/stdc++.h>

#include "Device.h"
#include "Hub.h"

using namespace std;

Device d1,d2,d3,d4,d5;
Hub h;

void Hub::hubtodevice(int dest_mac_add,string data,string source)
{
	if(d1.macaddress==dest_mac_add && d1.info==data && source!="d1")
		cout<<"\nd1 Accepted the Data and the Received data is: "<<data;
	else
		if(source!="d1")
			cout<<"\nData doesn't belong to  d1";

	if(d2.macaddress==dest_mac_add && d2.info==data && source!="d2")
		cout<<"\nd2 Accepted the Data and the Received data is: "<<data;
	else
		if(source!="d2")
			cout<<"\nData doesn't belong to d2";

	if(d3.macaddress==dest_mac_add && d3.info==data && source!="d3")
		cout<<"\nd3 Accepted the Data and the Received data is: "<<data;
	else
		if(source!="d3")
			cout<<"\nData doesn't belong to d3";

	if(d4.macaddress==dest_mac_add && d4.info==data && source!="d4")
		cout<<"\nd4 Accepted the Data and the Received data is: "<<data;
	else
		if(source!="d4")
			cout<<"\nData doesn't belong to d4";

	if(d5.macaddress==dest_mac_add && d5.info==data && source!="d5")
		cout<<"\nd5 Accepted the Data and the Received data is: "<<data;
	else
		if(source!="d5")
			cout<<"\nData doesn't belong to d5";
	cout<<"\n";
}

void src_transfer(string source){
	if(source=="d1")
	{
        	d1.setdata("0");
	}
	if(source=="d2")
	{
        	d2.setdata("0");
	}
	if(source=="d3")
	{
        	d3.setdata("0");
	}
	if(source=="d4")
	{
        	d4.setdata("0");
	}
	if(source=="d5")
	{
        	d5.setdata("0");
	}
}

void dedicated(string source, string dest, string data){
	if(dest=="d1"||dest=="d2"||dest=="d3"||dest=="d4"||dest=="d5")
    	{
		src_transfer(source);
        	if(dest=="d1")
        	{
        		d1.setdata(data);
        	}
        	if(dest=="d2")
        	{
        		d2.setdata(data);
        	}
        	if(dest=="d3")
        	{
        		d3.setdata(data);
        	}
        	if(dest=="d4")
        	{
        		d4.setdata(data);
        	}
        	if(dest=="d5")
        	{
        		d5.setdata(data);
        	}
       		cout<<"\nAfter Data Transfer: \n";
        	cout<<"d1 info after communication:    "<<d1.info<<"\n";
		cout<<"d2 info after communication:    "<<d2.info<<"\n";
		cout<<"d3 info after communication:    "<<d3.info<<"\n";
		cout<<"d4 info after communication:    "<<d4.info<<"\n";
		cout<<"d5 info after communication:    "<<d5.info<<"\n";      	
        }
}

void star(string dest, string source, string src_data){  //star
    	if(dest=="d1")
    	{
    		d1.setdata(src_data);
    		h.store(d1.macaddress, src_data, source);
    	}
    	if(dest=="d2")
    	{
    		d2.setdata(src_data);
    		h.store(d2.macaddress, src_data, source);
    	}
	if(dest=="d3")
    	{
		d3.setdata(src_data);
    		h.store(d3.macaddress, src_data, source);
    	}
    	if(dest=="d4")
    	{
    		d4.setdata(src_data);
    		h.store(d4.macaddress, src_data, source);
    	}
    	if(dest=="d5")
    	{
    		d5.setdata(src_data);
    		h.store(d5.macaddress, src_data, source);
    	}
}

void initialize_devices(){   //initialize
	d1.set_mac_address(19802);
	d1.setdata("0");
   	d2.set_mac_address(19803);
	d2.setdata("0");
  	d3.set_mac_address(19804);
	d3.setdata("0");
   	d4.set_mac_address(19805);
	d4.setdata("0");
   	d5.set_mac_address(19806);
	d5.setdata("0");	
}

void info_set(string data,int source,int dest,Device d[],int end_devices){  //datalink
      
	clock_t start;
        double time_taken;
        start = clock();

	for(int j=0; j<end_devices; j++){
		if (j==source-1){
			 continue;
		}
		
		for(int i=0;i<data.length();i++){
			d[dest-1].info+=data[i];
			if(j==dest-1){
				cout<<"\nReceived frame number: "<<(i+1)<<" at The Destination "<<j+1<<"\n";
				cout<<"Received frame number: "<<(i+1)<<"\n";
				cout<<"The source "<<source<<" received the ack \n\n";
			}
			else{
				break;
			}
		}
	}
	time_taken = ( clock() - start) / (double) CLOCKS_PER_SEC;
        cout<<"Total Time Taken for Transmission: "<< time_taken <<'\n';
	cout<<"Broadcast domain = 1 and Collision domain = "<<end_devices;
}

void infotransfer(int source,int dest,string data,int bridge_count,int total_devices){ //datalink
	//source and dest are from 1,2 & 3    	
	Device d[total_devices];
	//first time forwards ARP request to all ports to get mac of all
	if(bridge_count==1){
		for(int i=0;i<total_devices;i++){
			d[i].set_mac_address(i+500);
    		}
		info_set(data, source, dest,d, total_devices);	
	}
	else{  //now source know which port connected to which so direct transmission
		//look up in table and forward frame to destination
		clock_t start; 
        	double time_taken;
        	start = clock();
		for(int j=0; j<total_devices; j++){
			if(dest==j+1){
				for(int i=0;i<data.length();i++){
					d[dest-1].info+=data[i];
					if(j==dest-1){
						cout<<"Received frame number: "<<(i+1)<<" at The Destination "<<j+1<<"\n";
						cout<<"The source "<<source<<" received the ack \n\n";
					}
					else{
						break;
					}
				}
			}
		}
		time_taken = (clock() - start ) / (double) CLOCKS_PER_SEC;
            	cout<<"Total Time Taken for Transmission: "<< time_taken <<'\n';
		cout<<"Broadcast domain = 1 and Collision domain = "<<total_devices;
	}	
}

int main() {

   int ch_2,ch_1, src_len=0, flag=1, bridge_count=0, total_devices;
   string src_data;
   string source, dest;
   cout<<"\nNote: Data Link Layer is under construction \n";
   cout<<"\nChoice? 1:Physical Link layer  2: data Link Layer ";
   cin>>ch_1;
   switch(ch_1) {
   	case 1:   //physical layer implementation

		initialize_devices();
		
		//source device input
		cout<<"Available Devices: d1, d2, d3, d4, d5.\n";
   		cout<<"Enter the source device: ";
   		cin>>source; 
		
		//check if source device exist or not
		if(source!="d1" && source!="d2" && source!="d3" && source!="d4" && source!="d5"){
			cout<<"Source Device doesn't exist. \n";
			break;
		}
		
		//destination device input
   		cout<<"Enter the destination device: ";
   		cin>>dest; 
		//check if destination device exist or not
		if(dest!="d1" && dest!="d2" && dest!="d3" && dest!="d4" && dest!="d5"){
			cout<<"Destination Device doesn't exist. \n";
			break;
		}
		
		// source data input
   		cout<<"Enter the Source Data for transmission: ";
   		cin>>src_data; 
		
		//check if src_data is valid or not
		src_len = src_data.size();
		for(int i=0; i<src_len; i++){
			if(src_data[i]!='1' && src_data[i]!='0'){
				flag=0;
				break;
			}
		}
		if(flag == 0){
			cout<<"Invalid Data for Transmission.\n";
			break;
		}

		//assigning data to source
        	if(source=="d1")
        	{
        		d1.setdata(src_data);
        	}
        	if(source=="d2")
        	{
        		d2.setdata(src_data);
        	}
        	if(source=="d3")
        	{
        		d3.setdata(src_data);
        	}

        	if(source=="d4")
        	{
        		d4.setdata(src_data);
        	}
        	if(source=="d5")
        	{
        		d5.setdata(src_data);
        	}
		
		//initial device info
		cout<<"\nBefore Data Transfer: \n";
        	cout<<"d1 info before Transmission:    "<<d1.info<<"\n";
		cout<<"d2 info before Transmission:    "<<d2.info<<"\n";
		cout<<"d3 info before Transmission:    "<<d3.info<<"\n";
		cout<<"d4 info before Transmission:    "<<d4.info<<"\n";
		cout<<"d5 info before Transmission:    "<<d5.info<<"\n";  
		
		//choice for dedicated or star
   		cout<<"Choice? 1: Dedicated Network 2: Star Topology ";
   		cin>>ch_2;
   		switch(ch_2)
  		{
   			case 1:  //dedicated
				dedicated(source, dest, src_data);
        			break;
   			case 2:  //star
				star(dest,source,src_data);
    				break;
   			default:
   				cout<<"\nInvalid Choice.";
  		}
		break;
   	case 2:  //data link layer implementation
   		
		int our_choice=0;
		cout<<"\nHub - Switch - Hub Configuration is under Construction";
   		cout<<"\nChoice? 1: Switch - Device Configuration 2 Hub - Switch - Hub Configuration\n";
   		cin>>our_choice;
   		if(our_choice==1){   //switch - End Configuration
   			int source,dest;
   			string data; 
			int y;
			
   			cout<<"\nSwitch is created. Enter the number of total end devices\n";
   			cin>>total_devices;  //end devices
   			
			while(flag){
   				cout<<"\nChoose Source from 1,2,3: ";
   				cin>>source;
   				cout<<"Choose Destination from 1,2,3 (shouldn't be same as Source): ";
   				cin>>dest;
   				cout<<"Enter Data to do transmission: ";
   				cin>>data;
   				bridge_count++;
				
				//infotransfer function call
   				infotransfer(source, dest,data,bridge_count,total_devices);
			
   				cout<<"\nEnter any key greater then 0 if want to do more transmission: ";
   				cin>>y;
   				if(y<=0){
					 flag=0;
				} 
			}		
   		} //our_choice==1 completed	
		break;
   }
   return 0;
}

