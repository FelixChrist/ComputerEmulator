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
	void ResetInFlag();
	bool GetInFlag();
	void ResetOutFlag();
	bool GetOutFlag();
private:
	std::bitset<32> inputReg;
	std::bitset<8> instructionReg;
	std::bitset<16> addressReg;
	bool jumpFlag;
	bool storeFlag;
	bool halt;
	bool inFlag;
	bool outFlag;
};
CU::CU(){
	inputReg = 0; // Sets all registers to 0 on initialisation 
	instructionReg = 0;
	addressReg = 0;
	jumpFlag = 0;
	storeFlag = 0;
	halt = 0;
	inFlag = 0;
	outFlag = 0;
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
	//cout << instructionReg.to_ulong() << endl;
	for(int i = 8;i < 24; i++){
		addressReg[i-8]=inputReg[i];
	}
	//cout << addressReg.to_ulong() << endl;
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
			storeFlag = 1;
			break;
		case 11: //DEC
			storeFlag = 1;
			break;
		case 12: //INP
			inFlag = 1;
		case 13: //OUT
			outFlag = 1;

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
void CU::ResetInFlag(){
	inFlag = 0;
}
bool CU::GetInFlag(){
	return inFlag;
}
void CU::ResetOutFlag(){
	outFlag = 0;
}
bool CU::GetOutFlag(){
	return outFlag;
}