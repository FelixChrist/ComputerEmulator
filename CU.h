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