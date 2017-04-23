#include <iostream>
#include <bitset>
#include <vector>
#include "Memory.h"
#include "CPU.h"
#include "IO.h"
#include <fstream>
#include <string>
#include <sstream>
#define PROGRAM "PowerOfTwo"
#define DEBUG
using namespace std;
CPU cpu;
Memory memory;
IO io;
void SetProgram(){
	string line;
	int address;
	int opcode;
	int operand;
	int data;
	std::vector<string> lines;
	std::vector<std::vector<string> > code;
	string current;
	ifstream myfile (PROGRAM);
	// This reads Assembly from the program
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			//cout << line << '\n';
			lines.push_back(line);
		}
		myfile.close();
		for(int i = 0;i < lines.size();i++){
			std::vector<string> temp;
			code.push_back(temp);
			for(int j = 0;j < lines[i].size();j++){
				//cout << "Here!" << endl;
				if(lines[i][j]==' '){
					if(current.compare(":")){
						code[i].push_back(current);
						
					}
					current.clear();
				}
				else{
					current.push_back(lines[i][j]);
					
				}
				

				
			}
			
			code[i].push_back(current);
			for(int j = 0;j<code[i].size();j++){
				cout << code[i][j] << endl;
			}
			cout << endl;
			current.clear();
		}
		//This converts to machine code
		for(int i = 0;i < code.size();i++){
			if(code[i].size()==3){
				istringstream(code[i][0]) >> address;
				if(not code[i][1].compare("HLT")){
					opcode = 0;
				}
				else if(not code[i][1].compare("LDA")){
					opcode = 1;
				}
				else if(not code[i][1].compare("STA")){
					opcode = 2;
				}
				else if(not code[i][1].compare("ADD")){
					opcode = 3;
				}
				else if(not code[i][1].compare("SUB")){
					opcode = 4;
				}
				else if(not code[i][1].compare("LSF")){
					opcode = 5;
				}
				else if(not code[i][1].compare("RSF")){
					opcode = 6;
				}
				else if(not code[i][1].compare("BRA")){
					opcode = 7;
				}
				else if(not code[i][1].compare("BRZ")){
					opcode = 8;
				}
				else if(not code[i][1].compare("BRP")){
					opcode = 9;
				}
				else if(not code[i][1].compare("INC")){
					opcode = 10;
				}
				else if(not code[i][1].compare("DEC")){
					opcode = 11;
				}
				else if(not code[i][1].compare("INP")){
					opcode = 12;
				}
				else if(not code[i][1].compare("OUT")){
					opcode = 13;
				}
				istringstream(code[i][2]) >> operand;
				memory.SetProgram(address,opcode,operand);
			}
			else if(code[i].size() == 2){
				istringstream(code[i][0]) >> address;
				istringstream(code[i][1]) >> data;
				memory.SetProgram(address,data);
			}
			else{
				cout << "Error Loading Program." << endl;
			}
		}
	}

	else cout << "Unable to open file"; 
}
bool FetchExecuteCycle(){


	memory.SetMAR(cpu.GetPC()); //Set MAR to Location of instruction
	#ifdef DEBUG
	cout << "Instruction address: " << cpu.GetPC().to_ulong() << endl;
	#endif
	cpu.IncrementPC(); //Set PC to location of next instruction
	memory.SetMDRInstruction(); //Set MDR with instruction
	cpu.SetCIR(memory.GetMDR()); //Set CIR with the current instruction
	cpu.Decode(); //Decode the instruction
	memory.SetMAR(cpu.GetAddressReg()); //Set MAR to location of data
	memory.SetMDRData(); //Set MDR with data
	//cout << "Memory stuff: " << memory.GetMDR().to_ulong() << endl;
	cpu.SetDataReg(memory.GetMDR()); //Set data register in CPU


	cpu.Execute(); //Execute Instruction
	#ifdef DEBUG
	cout << "Jump: " << cpu.GetJumpFlag() << endl;
	cout << "Store: " << cpu.GetStoreFlag() << endl;
	cout << "In: " << cpu.GetInFlag() << endl;
	cout << "Out: " << cpu.GetOutFlag() << endl;
	#endif
	if(cpu.GetJumpFlag()){
		cpu.Jump(); //Branch the PC
	}
	if(cpu.GetStoreFlag()){ //Stores a value
		memory.SetMDR(cpu.GetAccumulator());
		memory.SetMAR(cpu.GetAddressReg());
		memory.SetAddress();
	}

	if (cpu.GetInFlag()){//Gets user input

		io.SetOutputReg();
		memory.SetMDR(io.GetOutputReg());
		memory.SetMAR(cpu.GetAddressReg());
		memory.SetAddress();
		cpu.ResetInFlag();	
	}

	if(cpu.GetOutFlag()){//Prints stuff to screen
		io.SetInputReg(cpu.GetAccumulator());
		io.Print();
		cpu.ResetOutFlag();
	}

	if(not cpu.GetHalt()){
		#ifdef DEBUG
		cout << "Accumulator: " << cpu.GetAccumulator().to_ulong() << endl;
		#endif
	}

	return cpu.GetHalt();


}

int main(){
	SetProgram();
	cout << "Starting Program..." << endl;
	while(1){
		if(FetchExecuteCycle()){//Run the fetch execute cycle
			break; //Breaks if halted
		} 
	}
	return 1;
}
