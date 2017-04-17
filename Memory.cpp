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
Memory::Memory(){
	for(int i = 0;i<RAM_SIZE;i++){
		RAM.push_back(0); //Fills RAM up to the defined size
	}
	// RAM[0]=2;
	// RAM[1]=17;
	// RAM[3]=3;
	// RAM[4]=24;
	// RAM[6]=1;
	// RAM[7]=100;
	// RAM[9]=2;
	// RAM[10]=100;
	
	// RAM[17]=22;
	// RAM[24]=2;
}
Memory::~Memory(){
	RAM.clear(); //Clears the RAM
}
void Memory::SetProgram(int address, int opcode, int operand){
	RAM[address] = opcode;
	std::bitset<16> temp = operand;
	for(int i = 0;i < 2;i++){
		for(int j =0;j < 8;j++){
			RAM[address+1+i][j] = temp[j+(i*8)];
		}
	}
}
void Memory::SetProgram(int address, int data){
	std::bitset<32> temp = data;
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 8;j++){
			RAM[address+i][j] = temp[j+(i*8)];
		}
	}
}
std::bitset<32> Memory::GetMDR(){
	return MDR; //Returns data value at address
}
void Memory::SetMDRInstruction(){
	for(int j = 0;j < 3; j++){
		for(int i = 0;i < 8; i++){
			MDR[i+(j*8)] = RAM[(int)MAR.to_ulong()+j][i];//Sets value of specified address in RAM
		}
	}
}
void Memory::SetMDRData(){
	for(int j = 0;j < 4; j++){
		for(int i = 0;i < 8; i++){
			MDR[i+(j*8)] = RAM[(int)MAR.to_ulong()+j][i];//Sets value of specified address in RAM
		}
	}
}
void Memory::SetAddress(){
	for(int j = 0;j < 4; j++){
		for(int i = 0;i < 8; i++){
			RAM[(int)MAR.to_ulong()+j][i]=MDR[i+(j*8)];//Sets value of specified address in RAM
		}
	}
}

void Memory::SetMAR(std::bitset<16> address){
	MAR=address;
}
void Memory::SetMDR(std::bitset<32> data){
	MDR = data;
}