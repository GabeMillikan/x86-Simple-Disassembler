#pragma once
#include "./SIBEnums.hpp"

struct SIBSchema
{
	Scale scale;
	Index index;
	Base  base;
};

extern const SIBSchema EmptySIBSchema;

extern const SIBSchema SIBSchemas[0x100 /* 00 000 000 - 11 111 111 */];