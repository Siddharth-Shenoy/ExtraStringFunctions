#pragma once

namespace StringF
{
	int strlen(char *string);
	char* strtok(char *string, int *idx,int *length,char delimiter = ' ');
	int strfind(char *string, char *sub);
}