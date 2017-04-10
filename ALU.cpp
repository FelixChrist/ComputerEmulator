#include <bitset>

class ALU
{
public:
	ALU();
	~ALU();
	void Execute(std::bitset<8>);
	void SetInputReg(std::bitset<32> );
	std::bitset<32> GetAccumulator();
	void ResetJumpFlag();
	bool GetJumpFlag();
private:
	std::bitset<32> accumulator;
	std::bitset<32> inputReg;
	bool jumpFlag;
};
ALU::ALU(){
	accumulator = 0; //initialises the registers to 0
	inputReg = 0;
	jumpFlag = 0;
}
ALU::~ALU(){
}
void ALU::Execute(std::bitset<8> instruction){
	switch((int)instruction.to_ulong()){
			break;
		case 0: //ADD
			accumulator = (int)accumulator.to_ulong() + (int)inputReg.to_ulong();
			break;
		case 1: //SUB
			accumulator = accumulator.to_ulong() - inputReg.to_ulong();
			break;
		case 2: //LSHIFT
			accumulator = accumulator.to_ulong() << inputReg.to_ulong();
			break;
		case 3: //RSHIFT
			accumulator = accumulator.to_ulong() >> inputReg.to_ulong();
			break;
		case 4: //BRZ
			if(accumulator == 0){
				jumpFlag = 1;
			}

	}
}
void ALU::SetInputReg(std::bitset<32> input){
	inputReg=input;
}
std::bitset<32> ALU::GetAccumulator(){
	return accumulator;
}
void ALU::ResetJumpFlag(){
	jumpFlag = 0;
}
bool ALU::GetJumpFlag(){
	return jumpFlag;
}