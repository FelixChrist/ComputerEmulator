#include <iostream>
#include <bitset>
#include "Memory.h"
using namespace std;

int main(){
	Memory memory; //Create a memory object
	std::bitset<16> address;
	std::bitset<32> data;
	address = 0;
	memory.SetMAR(address); //Set the MAR to 0
	memory.SetMDRInstruction(); //Set the MDR
	cout << memory.GetMDR() << endl;
	address = 14;
	memory.SetMAR(address); //Set MAR to 14
	memory.SetMDRData(); //Set the MDR
	cout << memory.GetMDR() << endl;
	address = 300;
	memory.SetMAR(address);
	data = 5924;
	memory.SetMDR(data);
	memory.SetAddress();
	address = 24;
	memory.SetMAR(address);
	memory.SetMDRData();
	cout << memory.GetMDR() << endl;
	address = 300;
	memory.SetMAR(address);
	memory.SetMDRData();
	cout << memory.GetMDR() << endl;

}