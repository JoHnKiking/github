#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<assert.h>


//����
void Swap(int* p1, int* p2);


//Ĭ������
//��������
void InsertSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

//������
void HeapSort(int* a, int n);

//��������
void QuickSort(int* a, int left, int right);

//ð������
void BubbleSort(int* a, int n);