#include <iostream>
#include <bitset>
#include "CPU.h"
using namespace std;

int main(){
	CPU cpu;
	std::bitset<16> pc;
	std::bitset<32> cir;
	std::bitset<32> data;
	pc = 24;
	cir = 345667000-182;
	data = 4567;
	cpu.SetPC(pc);
	cout << cpu.GetPC() <<endl;
	cpu.IncrementPC();
	cout << cpu.GetPC() << endl;
	cpu.SetCIR(cir);
	cout << cir << endl;
	cpu.Decode();
	cout << cpu.GetAddressReg() << endl;
	cout << cpu.GetInstructionReg() << endl;
	cpu.SetDataReg(data);
	cpu.Execute();
	cout << cpu.GetStoreFlag() << endl;
}