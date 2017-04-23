#include <iostream>
#include <bitset>
#include "CPU.h"
using namespace std;

int main(){
	CPU cpu;
	std::bitset<16> pc; //Program counter
	std::bitset<32> cir; //Current Instruction Register
	std::bitset<32> data; //Input Data
	pc = 24; //Set the program counter to 24
	cir = 3456676618; //set the Current instruction register to 
	//3456676818 because it uses all the bytes and is a recognised instruction (INC) 
	data = 4567; //Set the data to 4567
	cpu.SetPC(pc); //Set the program counter to its value
	cout << cpu.GetPC() <<endl; //This should print 24 in binary
	cpu.IncrementPC(); //Increment the program counter by adding 3 to it
	cout << cpu.GetPC() << endl; // This should print 27 in binary
	cpu.SetCIR(cir); //Set the CIR to its value
	cout << cir << endl; //Print the CIR
	cpu.Decode(); //Split the CIR into the instruction and address
	cout << cpu.GetAddressReg() << endl; //This should print the address
	cout << cpu.GetInstructionReg() << endl; //This should print the instruction
	cpu.SetDataReg(data); //Set the data reg to its value
	cpu.Execute(); //Execute the instruction (INC)
	cout << cpu.GetStoreFlag() << endl;//Print the store flag, this should be 1
	cout << cpu.GetAccumulator() << endl; //Print the accumulator, this should be 4568 in binary
	cout << cpu.GetStoreFlag() << endl;//Print the store flag, this should be 0
}