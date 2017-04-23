#include <iostream>
#include <bitset>
#include "IO.h"
using namespace std;

int main(){
	IO io; //Instantiate an IO module
	std::bitset<32> reg = 127; //Set register to 127
	io.SetInputReg(reg); //Set the input register
	io.Print(); //Print the input register, this should be 127
	io.SetOutputReg(); //Set the output register to a user input
	cout << io.GetOutputReg() << endl; //Print the output register,
	//this should be what the user set it to
}