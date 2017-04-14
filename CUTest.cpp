#include <bitset>
#include <iostream>
#include "CU.h"
using namespace std;


int main(){
	CU cu;
	std::bitset<32> input;
	input = 345667; 
	cout << input << endl;
	cu.SetInputReg(input); //Set the input register
	cu.Decode(); //Decode the input
	cout << cu.GetInstructionReg() << endl; //Print the instruction
	cout << cu.GetAddressReg() << endl; //Print the address

}