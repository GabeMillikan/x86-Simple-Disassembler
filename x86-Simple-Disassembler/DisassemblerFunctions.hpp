#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./DisassemblerTypes.hpp"

template<typename T>
//Returns a value of type byte, word, or dword from a byte array at 'index' advancing 'index' depending on the size of the value read.
inline T Select(byte * source, int * index)
{
	int i = *index;

	*index += sizeof(T);

	return *(T *)&source[i];
}

//'back' must have been allocated using malloc()
inline void Append(char ** front, char * back)
{
	int frontLength = (*front == nullptr) ? 0 : strlen(*front);
	int backLength = (back == nullptr) ? 0 : strlen(back);

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != nullptr)	memcpy(output, *front, frontLength);

	if (back != nullptr)
		memcpy(&output[frontLength], back, backLength + 1);
	else
		output[frontLength] = '\0';

	free(back);
	free(*front);

	*front = output;
}
//Same as above except 'back' is not allocated using malloc()
inline void Append(char ** front, const char * back)
{
	int frontLength = (*front == nullptr) ? 0 : strlen(*front);
	int backLength = (back == nullptr) ? 0 : strlen(back);

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != nullptr) memcpy(output, *front, frontLength);

	if (back != nullptr)
		memcpy(&output[frontLength], back, backLength + 1);
	else
		output[frontLength] = '\0';

	free(*front);

	*front = output;
}
inline void Append(char ** front, const char * format, dword back)
{
	int frontLength = (*front == nullptr) ? 0 : strlen(*front);
	int backLength = snprintf(nullptr, 0, format, back);

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != nullptr)	memcpy(output, *front, frontLength);

	sprintf(&output[frontLength], format, back);

	free(*front);

	*front = output;
}
//'back' must have been allocated using malloc()
inline void Append(char ** front, const char * format, char * back)
{
	int frontLength = (*front == nullptr) ? 0 : strlen(*front);
	int backLength = snprintf(nullptr, 0, format, back);

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != nullptr)	memcpy(output, *front, frontLength);

	sprintf(&output[frontLength], format, back);

	free(back);
	free(*front);

	*front = output;
}
//Same as above except 'back' is not allocated using malloc()
inline void Append(char ** front, const char * format, const char * back)
{
	int frontLength;
	if (*front != nullptr)
		frontLength = strlen(*front);
	else
		frontLength = 0;
	int backLength = snprintf(nullptr, 0, format, back);

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != nullptr)	memcpy(output, *front, frontLength);

	sprintf(&output[frontLength], format, back);

	free(*front);

	*front = output;
}

//Output must be freed by calling free()
inline void RemoveLast(char ** string, int count)
{
	if (*string != nullptr)
	{
		int length = strlen(*string);

		char * output = (char *)malloc(length - count + 1);

		memcpy(output, *string, length - count);

		output[length - count] = '\0';

		free(*string);

		*string = output;
	}
}
