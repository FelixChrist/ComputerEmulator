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