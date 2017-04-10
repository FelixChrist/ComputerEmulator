#include <bitset>

class ALU
{
public:
	ALU();
	~ALU();
	void Execute(std::bitset<8>);
	void SetInputReg(std::bitset<32> );
	std::bitset<32> GetAccumulator();
private:
	std::bitset<32> accumulator;
	std::bitset<32> inputReg;
};
ALU::ALU(){
	accumulator=0; //initialises the registers to 0
	inputReg=0;
}
ALU::~ALU(){
}
void ALU::Execute(std::bitset<8> instruction){
	switch((int)instruction.to_ulong()){
		case 0: //LOAD
			accumulator = inputReg;
			break;
		case 1: //STORE
			accumulator = accumulator;
			break;
		case 2: //ADD
			accumulator = (int)accumulator.to_ulong() + (int)inputReg.to_ulong();
			break;
		case 3: //SUB
			accumulator = accumulator.to_ulong() - inputReg.to_ulong();
			break;
		case 4: //LSHIFT
			accumulator = accumulator.to_ulong() << inputReg.to_ulong();
			break;
		case 5: //RSHIFT
			accumulator = accumulator.to_ulong() >> inputReg.to_ulong();
			break;
	}
}
void ALU::SetInputReg(std::bitset<32> input){
	inputReg=input;
}
std::bitset<32> ALU::GetAccumulator(){
	return accumulator;
}
