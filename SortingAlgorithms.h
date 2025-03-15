#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include<stdlib.h>
#include<string.h>
using namespace std; 

void GenerateData(int a[], int n, int dataType);
int ConvertToNum(int i, char* argv[]);
int CharSortToNum(const char* ss);
void Sorting_Algorithm(int* a, int n, int SortMode, unsigned long long& count_compare);
void Sorting_Algorithm_runtime(int* a, int n, int SortMode);

//HEAP SORT
void HeapBuild(int* arr, int n, int i);
void HeapSort(int* arr, int n);
void HeapBuild_CC(int* a, int n, int i, unsigned long long& count_compare);
void HeapSort_CC(int* a, int n, unsigned long long& count_compare);

//BUBBLE SORT
void BubbleSort(int* a, int n);
void BubbleSort_CC(int* a, int n, unsigned long long& count_compare);

//FLASH SORT
void FlashSort(int* a, int n);
void FlashSort_CC(int* a, int n, unsigned long long& count_compare);

//SELECTION SORT
void SelectionSort(int* a, int n);
void SelectionSort_CC(int* a, int n, unsigned long long& countCompare);

//MERGE SORT
void MergeSort_Original(int* a, int n);
void MergeSort_F_Original(int* a, int left, int right);
void Merge_Original(int* a, int left, int mid, int right);
void MergeSort_CC(int* a, int n, unsigned long long& count_compare);
void MergeSort_F(int* a, int left, int right, unsigned long long& count_compare);
void Merge(int* a, int left, int mid, int right, unsigned long long& count_compare);

//SHAKER SORT
void ShakerSort_CC(int* a, int n, unsigned long long& count_compare);
void ShakerSort(int* a, int n);

//SHELL SORT
void ShellSort(int* arr, int n);
void ShellSort_CC(int* a, int n, unsigned long long& count_compare);

//INSERTION SORT
void InsertionSort(int a[], int n);
void InsertionSort_CC(int a[], int n, unsigned long long& count_compare);

//RADIX SORT
int getMax_Original(int* arr, int n);
void CountSort(int* arr, int n, int exp);
void RadixSort(int* arr, int n);
int getMax(int* arr, int n, unsigned long long& count_compare);
void countSorts(int* arr, int n, int exp, unsigned long long& count_compare);
void RadixSort_CC(int* arr, int n, unsigned long long& count_compare);

//QUICK SORT
void QuickSortFunc_Original(int* a, int low, int high);
void QuickSort(int* a, int n);
void QuickSortFunc_CC(int* a, int low, int high,unsigned long long& count_compare);
void QuickSort_CC(int* a, int n, unsigned long long& count_compare);

//COUNTTING SORT
void CountingSort(int* arr, int n);
void CountingSort_CC(int* input, int n, unsigned long long& count_compare);

//PRINT AND WRITE
void printArray(int arr[], int n);
int* Copy_arr(int* a, int n);
void PrintSortingMode(int SortMode);
void ReadFile_ModeA(char* file_input[3], int* a, int n);
void Write_FileOutput(int* a, int n);
void Write_File(int* a, int n, string fileName);
void PrintCMD(int Output_Param, float running_time, unsigned long long count_compare);
void Print_CommandLine4(float running_time_1, float running_time_2, unsigned long long& count_compare_1, unsigned long long& count_compare_2);
int ReadFileandReturnModeA(char* file_input[3]);
int ReadFileandReturnModeC(char* file_input[4]);
void ReadFile_ModeC(char* file_input[4], int* a, int n);

//COMMAND LINE
void Command_line1(int argc, char* argv[]);
void Command_line3(int argc, char* argv[]);
void Command_line2(int argc, char* argv[]);
void Command_line4(int argc, char* argv[]);
void Command_line5(int argc, char* argv[]);
