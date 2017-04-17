#include <bitset>
#include "CU.h"
#include "ALU.h"

class CPU
{
public:
	CPU();
	~CPU();
	void SetCIR(std::bitset<32> );
	void IncrementPC();
	void SetPC(std::bitset<16> );
	void SetDataReg(std::bitset<32> );
	void Decode();
	bool GetJumpFlag();
	void Jump();
	bool GetStoreFlag();
	void Execute();
	bool GetHalt();
	std::bitset<16> GetAddressReg();
	std::bitset<8> GetInstructionReg();
	std::bitset<32> GetAccumulator();
	std::bitset<16> GetPC();
private:
	CU cu;
	ALU alu;
	std::bitset<32> cir;
	std::bitset<16> pc;
};
CPU::CPU(){
	cir = 0;
	pc = 0;
}
CPU::~CPU(){
}
std::bitset<8> CPU::GetInstructionReg(){
	return cu.GetInstructionReg();
}
void CPU::SetCIR(std::bitset<32> instruction){
	cir = instruction;
}
void CPU::Execute(){
	alu.Execute(cu.GetInstructionReg());
	cu.Execute(alu.GetZeroFlag());
}
void CPU::IncrementPC(){
	pc =(int)pc.to_ulong() + 3;
}
void CPU::SetPC(std::bitset<16> address){
	pc = address;
}
void CPU::SetDataReg(std::bitset<32> data){
	alu.SetInputReg(data);
}
void CPU::Decode(){
	cu.SetInputReg(cir);
	cu.Decode();
}
std::bitset<16> CPU::GetPC(){
	return pc;
}
bool CPU::GetJumpFlag(){
	return cu.GetJumpFlag();
}
bool CPU::GetStoreFlag(){
	return cu.GetStoreFlag();
}
void CPU::Jump(){
	pc = cu.GetAddressReg();
	cu.ResetJumpFlag();
}
std::bitset<32> CPU::GetAccumulator(){
	cu.ResetStoreFlag();
	return alu.GetAccumulator();
}
std::bitset<16> CPU::GetAddressReg(){
	return cu.GetAddressReg();
}
bool CPU::GetHalt(){
	return cu.GetHalt();
}