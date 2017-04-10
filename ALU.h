#include <bitset>
class ALU
{
public:
	ALU();
	~ALU();
	void Execute(std::bitset<8>);
	void SetInputReg(std::bitset<32> );
	std::bitset<32> GetAccumulator();
private:
	std::bitset<32> accumulator;
	std::bitset<32> inputReg;
};