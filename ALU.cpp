#include <bitset>
#include <iostream>
using namespace std;
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
	void ResetStoreFlag();
	bool GetStoreFlag();
	bool GetHalt();
private:
	std::bitset<32> accumulator;
	std::bitset<32> inputReg;
	bool jumpFlag;
	bool storeFlag;
	bool halt;
};
ALU::ALU(){
	accumulator = 0; //initialises the registers to 0
	inputReg = 0;
	jumpFlag = 0;
	storeFlag = 0;
	halt = 0;
}
ALU::~ALU(){
}
void ALU::Execute(std::bitset<8> instruction){
	// cout << "Data: " << inputReg << endl;
	//cout << "Instruction: " << instruction.to_ulong() << endl;
	switch((int)instruction.to_ulong()){
		case 0:
			halt = 1;
			cout << "Halting." << endl;
		case 1: //LDA
			accumulator = inputReg;
			break;
		case 2: //STA
			storeFlag = 1;
			//cout << "Setting Store Flag to " << storeFlag << endl;
			break;
		case 3: //ADD
			accumulator = (int)accumulator.to_ulong() + (int)inputReg.to_ulong();
			break;
		case 4: //SUB
			accumulator = accumulator.to_ulong() - inputReg.to_ulong();
			break;
		case 5: //LSF
			accumulator = accumulator.to_ulong() << inputReg.to_ulong();
			break;
		case 6: //RSF
			accumulator = accumulator.to_ulong() >> inputReg.to_ulong();
			break;
		case 7: //BRA
			jumpFlag = 1;
			break;
		case 8: //BRZ
			if(accumulator == 0){
				jumpFlag = 1;
			}
			break;
		case 9: //INC
			accumulator = accumulator.to_ulong() + 1;
			break;
		case 10: //DEC
			accumulator = accumulator.to_ulong() - 1;
			break;

	}
	//cout << "Store Flag: " << storeFlag << endl;
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
void ALU::ResetStoreFlag(){
	storeFlag = 0;
}
bool ALU::GetStoreFlag(){
	return storeFlag;
}
bool ALU::GetHalt(){
	return halt;
}