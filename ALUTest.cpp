#include "ALU.h"
#include <iostream>

using namespace std;
int main(){
	std::bitset<32> input = 54;
	std::bitset<8> instruction=0;
	ALU alu;
	alu.SetInputReg(input);
	cout << alu.GetAccumulator() << endl;
	alu.Execute(instruction);
	cout << alu.GetAccumulator() << endl;
	input = 22;
	alu.SetInputReg(input);
	instruction=3;
	alu.Execute(instruction);
	cout << alu.GetAccumulator() << endl;
}