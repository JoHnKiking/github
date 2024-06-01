#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<assert.h>


//╫╩╩╩
void Swap(int* p1, int* p2);


//д╛хоиЩпР
//╡ЕхКеепР
void InsertSort(int* a, int n);

//оё╤ШеепР
void ShellSort(int* a, int n);

//я║тЯеепР
void SelectSort(int* a, int n);

//╤яеепР
void HeapSort(int* a, int n);

//©ЛкыеепР
void QuickSort(int* a, int left, int right);

//ц╟ещеепР
void BubbleSort(int* a, int n);