#include "ALU.h"
#include <iostream>

using namespace std;
int main(){
	std::bitset<32> input = 54; //Set the input to 54
	std::bitset<8> instruction=3; //Set the instruction to 3 (ADD)
	ALU alu; //Instantiate an ALU
	alu.SetInputReg(input); //Set the input
	cout << alu.GetAccumulator() << endl; //Print the accumulator,
	//this should be 0
	alu.Execute(instruction); //Execute the add instruction
	cout << alu.GetAccumulator() << endl; //Print the accumulator,
	//this should have added 54 to 0 so should give 54
	input = 22; //Set input to 22
	alu.SetInputReg(input); //Set input
	instruction=4; //Set instruction to 4 (SUB)
	alu.Execute(instruction); //Execute the sub instruction
	cout << alu.GetAccumulator() << endl; //Print the accumulator,
	//This should be 32
	instruction = 5; //Set instruction to 5 (LSF)
	alu.Execute(instruction);//Execute the left shift
	cout << alu.GetAccumulator() << endl; //Print the accumulator,
	//This should have shifted 32 right 22 times
	instruction = 6; //Set the instruction 6 (RSF)
	alu.Execute(instruction);//Execute the right shift
	cout << alu.GetAccumulator() << endl; //Print the accumulator,
	//This should be back to 32
	instruction = 10; //Set instruction to 10 (INC)
	alu.Execute(instruction); //Execute the increment
	cout << alu.GetAccumulator() << endl; //Print the accumulator,
	//This should be 23
	instruction = 11; //Set instruction to 11 (DEC)
	alu.Execute(instruction); //Execute the decrement 
	cout << alu.GetAccumulator() << endl; //Print the accumulator,
	//This should be 21
	cout << alu.GetZeroFlag() << endl; //Print the zero flag, 
	//this should be zero because the accumulator is not zero
	instruction = 1; //Set instruction to 1 (LDA)
	input = 0; //Set data to 0
	alu.SetInputReg(input); //Set the input
	alu.Execute(instruction); //Execute the load instruction
	cout << alu.GetZeroFlag() << endl; //Print the zero flag
	//This should be 1 as the accumulator is 0
}