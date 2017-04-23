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
	bool GetZeroFlag();
private:
	std::bitset<32> accumulator;
	std::bitset<32> inputReg;
	bool zeroFlag;
};
ALU::ALU(){
	accumulator = 0; //initialises the registers to 0
	inputReg = 0;
	zeroFlag = 0;

}
ALU::~ALU(){
}
void ALU::Execute(std::bitset<8> instruction){
	// cout << "Data: " << inputReg << endl;
	//cout << "Instruction: " << instruction.to_ulong() << endl;
	switch((int)instruction.to_ulong()){
		case 0: //Halting
		case 1: //LDA
			accumulator = inputReg;
			break;
		case 2: //STA
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
			break;
		case 8: //BRZ
			break;
		case 9: //BRP
			break;
		case 10: //INC
			accumulator = inputReg.to_ulong() + 1;
			break;
		case 11: //DEC
			accumulator = inputReg.to_ulong() - 1;
			break;
		case 12: //INP
			break;
		case 13: //OUT
			accumulator = inputReg;
			break;

	}
	if(accumulator == 0){
		zeroFlag = 1;
	}
	else{
		zeroFlag = 0;
	}
	//cout << "Store Flag: " << storeFlag << endl;
}
void ALU::SetInputReg(std::bitset<32> input){
	inputReg=input;
}
std::bitset<32> ALU::GetAccumulator(){
	return accumulator;
}
bool ALU::GetZeroFlag(){
	return zeroFlag;
}
