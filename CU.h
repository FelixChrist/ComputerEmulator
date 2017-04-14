#include <bitset>
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
