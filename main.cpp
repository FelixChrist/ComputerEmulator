#include <iostream>
#include <bitset>

int main(){
	Initialise(); //initialise the computer
	while(1){
		FetchExecuteCycle(); //Run the fetch execute cycle
	}
}
void FetchExecuteCycle(){
	cpu.SetPC();
	memory.SetMAR(cpu.GetPC());
	cpu.IncrementPC();
	memory.SetMDR();
	cpu.SetCIR(memory.GetMAR());
	instruction=Decode(cpu.GetCIR());
	jump=IsJump(instruction);
	if(Jump){
		PC = Instruction;
	}
	else{
		Execute(Instruction);
	}
}