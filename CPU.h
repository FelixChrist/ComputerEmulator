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
	void Jump();
	bool GetStoreFlag();
	void Execute();
	std::bitset<16> GetAddressReg();
	std::bitset<32> GetAccumulator();
	std::bitset<16> GetPC();
private:
	CU cu;
	ALU alu;
	std::bitset<32> cir;
	std::bitset<16> pc;
	std::bitset<32> dataReg;
};