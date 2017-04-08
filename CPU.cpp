#include <bitset>
#include "ControlUnit.h"
#include "ALU.h"

class CPU
{
public:
	CPU();
	~CPU();
private:
	ControlUnit controlUnit;
	ALU alu;
};