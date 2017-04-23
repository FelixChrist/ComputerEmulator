#include <bitset>
#include "CU.h"
#include "ALU.h"

class CPU
{
public:
	CPU();
	~CPU();
	void SetCIR(std::bitset<32> );
	void IncrementPC();
	void SetPC(std::bitset<16> );
	void SetDataReg(std::bitset<32> );
	void Decode();
	bool GetJumpFlag();
	void Jump();
	bool GetStoreFlag();
	bool GetInFlag();
	bool GetOutFlag();
	void Execute();
	bool GetHalt();
	void ResetInFlag();
	void ResetOutFlag();
	std::bitset<16> GetAddressReg();
	std::bitset<8> GetInstructionReg();
	std::bitset<32> GetAccumulator();
	std::bitset<16> GetPC();
private:
	CU cu;
	ALU alu;
	std::bitset<32> cir;
	std::bitset<16> pc;
};