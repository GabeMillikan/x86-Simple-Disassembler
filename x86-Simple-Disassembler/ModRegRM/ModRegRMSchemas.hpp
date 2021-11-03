#pragma once
#include "./ModRegRMEnums.hpp"

struct ModRegRMSchema
{
	struct
	{
		Mod mod;
		Size modSize;
	};
	struct
	{
		Reg reg;
		Size regSize;
	};
	struct
	{
		RM rm;
		Size rmSize;
		RM rm16; //Used to accomodate inconsistencies between 16-bit and 32-bit addressing methods
	};
};

extern const ModRegRMSchema EmptyModRegRMSchema;

extern const ModRegRMSchema ModRegRMSchemas[0x100 /* 00 000 000 - 11 111 111 */];