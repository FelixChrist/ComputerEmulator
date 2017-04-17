#include <iostream>
#include <bitset>
#include "Memory.h"
#include "CPU.h"
using namespace std;
CPU cpu;
Memory memory;
void FetchExecuteCycle(){


	memory.SetMAR(cpu.GetPC()); //Set MAR to Location of instruction

	cpu.IncrementPC(); //Set PC to location of next instruction
	memory.SetMDRInstruction(); //Set MDR with instruction
	if(memory.GetMDR()==0){
		while(1){}
	}
	cpu.SetCIR(memory.GetMDR()); //Set CIR with the current instruction
	cpu.Decode(); //Decode the instruction
	memory.SetMAR(cpu.GetAddressReg()); //Set MAR to location of data
	memory.SetMDRData(); //Set MDR with data
	cpu.SetDataReg(memory.GetMDR()); //Set data register in CPU
	cpu.Execute(); //Execute Instruction
	cout << "Accumulator: " << cpu.GetAccumulator().to_ulong() << endl;
	if(cpu.GetJumpFlag()){
		cpu.Jump();
	}
	if(cpu.GetStoreFlag()){
		memory.SetMDR(cpu.GetAccumulator());
		memory.SetMAR(cpu.GetAddressReg());
		memory.SetAddress();
	}

}

int main(){
	while(1){
		FetchExecuteCycle(); //Run the fetch execute cycle
	}
}
