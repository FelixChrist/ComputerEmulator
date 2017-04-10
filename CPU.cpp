#include <bitset>
#include "CU.h"
#include "ALU.h"

class CPU
{
public:
	CPU();
	~CPU();
	void SetCIR();
	void IncrementPC();
	void SetPC(std::bitset<16> );
	void SetInput();
	void SetDataReg(std::bitset<32> );
	void Decode();
	bool GetJumpFlag();
	void ResetJumpFlag();
	void Jump();
	std::bitset<16> GetPC();
private:
	CU cu;
	ALU alu;
	std::bitset<32> cir;
	std::bitset<16> pc;
	std::bitset<32> dataReg;
};
CPU::CPU(){
	cir = 0;
	pc = 0;
}
CPU::~CPU(){
}
void CPU::IncrementPC(){
	pc += 3;
}
void CPU::SetPC(std::bitset<16> address){
	pc = address;
}
void CPU::SetDataReg(std::bitset<32> data){
	dataReg = data;
}
void CPU::Decode(){
	cu.Decode(cir);
}
std::bitset<16> CPU::GetPC(){
	return pc;
}
bool CPU::GetJumpFlag(){
	return alu.GetJumpFlag();
}
void CPU::ResetJumpFlag(){
	alu.ResetJumpFlag();
}
void CPU::Jump(){
	pc = cu.GetAddressReg();
}