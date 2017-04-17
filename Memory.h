#include <vector>
#include <bitset>
#define RAM_SIZE 65536
using namespace std;

class Memory
{
public:
	Memory();
	~Memory();
	std::bitset<32> GetMDR();
	void SetAddress();
	void SetMDRInstruction();
	void SetMDRData();
	void SetProgram(int , int,  int );
	void SetProgram(int , int );
	void SetMAR(std::bitset<16> );
	void SetMDR(std::bitset<32> );
private:
	std::vector< std::bitset<8> > RAM; //Vector of 8 bit numbers to act as RAM
	std::bitset<16> MAR;
	std::bitset<32> MDR;	
	
};