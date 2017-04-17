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
	std::bitset<8> GetInstructionReg();
	std::bitset<16> GetAddressReg();
private:
	std::bitset<32> inputReg;
	std::bitset<8> instructionReg;
	std::bitset<16> addressReg;
};
CU::CU(){
	inputReg = 0; // Sets all registers to 0 on initialisation 
	instructionReg = 0;
	addressReg = 0;
}
CU::~CU(){
}
void CU::SetInputReg(std::bitset<32> input){
	inputReg = input;
}
void CU::Decode(){
	cout <<  "Decode input: " << inputReg << endl;
	for(int i = 0;i < 8;i++){
		instructionReg[i] = inputReg[i];
	}
	//cout << instructionReg << endl;
	for(int i = 8;i < 24; i++){
		addressReg[i-8]=inputReg[i];
	}
	//cout << addressReg << endl;
}
std::bitset<8> CU::GetInstructionReg(){
	return instructionReg;
}
std::bitset<16> CU::GetAddressReg(){
	return addressReg;
}