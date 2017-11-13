#include "StringFunctions.h"

namespace StringF
{
	int strlen(char *string)
	{
		int i = 0;
		while (string[i] != '\0')
		{
			i++;
		}
		return i;
	}
	int strfind(char *string, char *sub)
	{
		int loc = -1;
		int j = 0;
		bool found = false;
		int i = 0;
		for (i = 0; i < strlen(string); i++)
		{
			if (string[i] == sub[0])
			{
				for (j = 0; j < strlen(sub); j++)
				{			
					if (string[j + i ] == sub[j])
					{
						found = true;
						continue;
					}
					else
					{
						found = false;
						break;
					}
					
			
				}
				if (found == true)
				{
					break;
				}
				else continue;
			}
		}
		if (found == true)
		{
			loc = i;
		}
		else
		{
			loc = -1;
		}
		return loc;
	}
	char *strtok(char *string, int *idx,int *length,char delimiter)
	{
		if (*idx < strlen(string))
		{
			int i = 0;
			int j = 0;
			bool init = false;
			char *returnS = "";
			for (i = *idx; i < strlen(string); i++)
			{
				if (i == strlen(string) - 1)
				{
					returnS = new char[i - *idx + 1];
					init = true;
					for (j = *idx; j < i; j++)
					{
						returnS[j - *idx] = string[j];
					}
					returnS[i - *idx] = '\0';
					*length = i - *idx;
					*idx = i + 1;
					break;
				}
				else if (string[i] == delimiter)
				{
					returnS = new char[i - *idx];
					init = true;
					for (j = *idx; j < i; j++)
					{
						returnS[j - *idx] = string[j];
					}
					returnS[i - *idx] = '\0';
					*length = i - *idx;
					*idx = i + 1;
					break;
				}
				
			}
			
			return returnS;

		}
		return "";
	}
}