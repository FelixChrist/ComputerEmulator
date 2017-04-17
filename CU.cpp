#include <bitset>
#include <iostream>
using namespace std;
class CU
{
public:
	CU();
	~CU();
	void SetInputReg(std::bitset<32>);
	void Decode();
	void Execute(bool );
	std::bitset<8> GetInstructionReg();
	std::bitset<16> GetAddressReg();
	void ResetJumpFlag();
	bool GetJumpFlag();
	void ResetStoreFlag();
	bool GetStoreFlag();
	bool GetHalt();
private:
	std::bitset<32> inputReg;
	std::bitset<8> instructionReg;
	std::bitset<16> addressReg;
	bool jumpFlag;
	bool storeFlag;
	bool halt;
};
CU::CU(){
	inputReg = 0; // Sets all registers to 0 on initialisation 
	instructionReg = 0;
	addressReg = 0;
	jumpFlag = 0;
	storeFlag = 0;
	halt = 0;
}
CU::~CU(){
}
void CU::SetInputReg(std::bitset<32> input){
	inputReg = input;
}
void CU::Decode(){
	//cout <<  "Decode input: " << inputReg << endl;
	for(int i = 0;i < 8;i++){
		instructionReg[i] = inputReg[i];
	}
	//cout << instructionReg << endl;
	for(int i = 8;i < 24; i++){
		addressReg[i-8]=inputReg[i];
	}
	//cout << addressReg << endl;
}
void CU::Execute(bool zeroFlag){
	switch(instructionReg.to_ulong()){
		case 0: //Halting
			halt = 1;
			cout << "Halting." << endl;
		case 1: //LDA
			break;
		case 2: //STA
			storeFlag = 1;
			//cout << "Setting Store Flag to " << storeFlag << endl;
			break;
		case 3: //ADD
			break;
		case 4: //SUB
			break;
		case 5: //LSF
			break;
		case 6: //RSF
			break;
		case 7: //BRA
			jumpFlag = 1;
			break;
		case 8: //BRZ
			if(zeroFlag){
				jumpFlag = 1;
			}
			break;
		case 9: //BRP
			if(not zeroFlag){
				jumpFlag = 1;
			}
			break;
		case 10: //INC
			break;
		case 11: //DEC
			break;
	}
}
std::bitset<8> CU::GetInstructionReg(){
	return instructionReg;
}
std::bitset<16> CU::GetAddressReg(){
	return addressReg;
}
void CU::ResetJumpFlag(){
	jumpFlag = 0;
}
bool CU::GetJumpFlag(){
	return jumpFlag;
}
void CU::ResetStoreFlag(){
	storeFlag = 0;
}
bool CU::GetStoreFlag(){
	return storeFlag;
}
bool CU::GetHalt(){
	return halt;
}