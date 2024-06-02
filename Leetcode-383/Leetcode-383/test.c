#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int ransomNoteSize = strlen(ransomNote);
    int n = 0;
    while (n < ransomNoteSize)
    {
        char* ptr = strchr(magazine, ransomNote[n]);
        if (ptr == NULL)
        {
            return false;
        }
        else
        {
            n++;
            *ptr += 32;
        }
    }
    return true;
}

int main()
{
    char* a1 = "aa";
    char* a2 = "ab";
    bool x = canConstruct(a1, a2);
 	return 0;
}