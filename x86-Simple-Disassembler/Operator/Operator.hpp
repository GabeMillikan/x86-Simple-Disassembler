#pragma once
#include "../Instruction/Instruction.hpp"

class Operator
{
public:
	Operator() {};
	Operator(Instruction * instruction);

	const char * GetString();

private:
	//Caller
	Instruction * instruction = nullptr;

	//Schema
	OperatorSchema schema = EmptyOperatorSchema;
};