#include <iostream>
#include <bitset>
#include "IO.h"
using namespace std;

int main(){
	std::bitset<32> reg;
	IO io;
	reg = 114;
	io.SetInputReg(reg);
	io.Print();
	io.SetOutputReg();
	cout << io.GetOutputReg() << endl;
}