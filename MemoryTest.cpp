#include <iostream>
#include <bitset>
#include "Memory.h"
using namespace std;

int main(){
	Memory memory; //Create a memory object
	std::bitset<16> address; //Create an address
	std::bitset<32> data; //Create some data
	address = 0; //Set the address to 0
	memory.SetMAR(address); //Set the MAR to 0
	memory.SetMDRInstruction(); //Set the MDR
	cout << memory.GetMDR() << endl;//The memory is
	// preloaded to 2 so it should print 2 in binary
	//as well 17 in the next byte
	address = 9; //Set the MAR to 14 
	memory.SetMAR(address); //Set MAR to 14
	memory.SetMDRData(); //Set the MDR
	cout << memory.GetMDR() << endl; //The memory is
	//preloaded to 2 followed by 100 so these should be 
	//printed in binary
	address = 300;//Set the address to 300
	memory.SetMAR(address);//Set the MAR
	data = 592445; //Set the data to 592445
	memory.SetMDR(data);//Set the MDR with the data
	memory.SetAddress(); //Set the specified address to the data
	address = 24; //Set the address to 24
	memory.SetMAR(address); //Set the MAR
	memory.SetMDRData(); //Set the MDR with data
	cout << memory.GetMDR() << endl; //This should print 2 in binary
	address = 300; //Set the address to 300
	memory.SetMAR(address); //Set the MAR to the address
	memory.SetMDRData(); //Set the MDR to the specified value
	cout << memory.GetMDR().to_ulong() << endl; //This should 
	//print 592445 as it was the value stored in memory
}