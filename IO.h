#include <iostream>
#include <bitset>
using namespace std;

class IO
{
public:
	IO();
	~IO();
	void Print();
	void SetInputReg(std::bitset<32> );
	void SetOutputReg();
	bitset<32> GetOutputReg();
private:
	bitset<32> outputReg;
	bitset<32> inputReg;
};