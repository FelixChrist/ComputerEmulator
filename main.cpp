#include <iostream>
#include <bitset>

int main(){
	Initialise(); //initialise the computer
	while(1){
		FetchExecuteCycle(); //Run the fetch execute cycle
	}
}
void FetchExecuteCycle(){
	memory.SetMAR(cpu.GetPC()); //Set MAR to Location of instruction
	cpu.IncrementPC(); //Set PC to location of next instruction
	memory.SetMDR(); //Set MDR with instruction
	cpu.SetCIR(memory.GetMDRInstruction()); //Set CIR with the current instruction
	cpu.Decode(); //Decode the instruction
	memory.SetMAR(cpu.GetAddressReg) //Set MAR to location of data
	memory.SetMDR(); //Set MDR with data
	cpu.SetDataReg(memory.GetMDR()); //Set data register in CPU
	cpu.Execute(); //Execute Instruction
	if(cpu.GetJumpFlag()){
		cpu.Jump();
	}
	else{
		
	}
}