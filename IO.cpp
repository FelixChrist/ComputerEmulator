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
	std::bitset<32> GetOutputReg();
private:
	std::bitset<32> outputReg;
	std::bitset<32> inputReg;
};
IO::IO(){
	outputReg = 0; //Initialise registers to 0
	inputReg = 0;
}
IO::~IO(){
}
void IO::Print(){
	//Outputs to screen
	cout << inputReg << endl;
}
void IO::SetInputReg(std::bitset<32> input){
	inputReg = input;
}
void IO::SetOutputReg(){
	//Get user input
	int temp;
	cin >> temp;
	outputReg = temp;
}
std::bitset<32> IO::GetOutputReg(){
	return outputReg;
}
