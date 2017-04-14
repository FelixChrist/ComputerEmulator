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
	void SetMAR(std::bitset<16> );
	void SetMDR(std::bitset<32> );
private:
	std::vector< std::bitset<8> > RAM; //Vector of 8 bit numbers to act as RAM
	std::bitset<16> MAR;
	std::bitset<32> MDR;	
	
};
Memory::Memory(){
	for(int i = 0;i<RAM_SIZE;i++){
		RAM.push_back(0); //Fills RAM up to the defined size
	}
	RAM[0]=2;
	RAM[2]=14;
	RAM[3]=3;
	RAM[5]=24;
	RAM[14]=22;
	RAM[24]=2;
}
Memory::~Memory(){
	RAM.clear(); //Clears the RAM
}
std::bitset<32> Memory::GetMDR(){
	return MDR; //Returns data value at address
}
void Memory::SetMDRInstruction(){
	for(int j = 0;j < 3; j++){
		for(int i = 0;i < 8; i++){
			MDR[i*(j+1)] = RAM[(int)MAR.to_ulong()+j][i];//Sets value of specified address in RAM
		}
	}
}
void Memory::SetMDRData(){
	for(int j = 0;j < 4; j++){
		for(int i = 0;i < 8; i++){
			MDR[i*(j+1)] = RAM[(int)MAR.to_ulong()+j][i];//Sets value of specified address in RAM
		}
	}
}
void Memory::SetAddress(){
	for(int j = 0;j < 4; j++){
		for(int i = 0;i < 8; i++){
			RAM[(int)MAR.to_ulong()+j][i]=MDR[i*(j+1)];//Sets value of specified address in RAM
		}
	}
}

void Memory::SetMAR(std::bitset<16> address){
	MAR=address;
}
void Memory::SetMDR(std::bitset<32> data){
	MDR = data;
}