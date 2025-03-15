#include"SortingAlgorithms.h"


int ConvertToNum(int i, char* argv[]) {
	if (i >= 5 && i <= 6) {
		if (strcmp(argv[1], "-a") == 0) {
			if (i == 5) {
				if (CharSortToNum(argv[2]) != 0) {
					if (argv[3][strlen(argv[3]) - 1] == 't') {
						if (ReadFileandReturnModeA(argv) != -1) {
							if (strcmp(argv[4], "-both") == 0 || strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-comp") == 0)
								return 1;
						}
					}
				else {
					if (strcmp(argv[4], "-both") == 0 || strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-comp") == 0)
						return 3;
					}
				}
			}
			else {
				if (CharSortToNum(argv[2]) != 0) {
					if (argv[3][strlen(argv[3]) - 1] != 't') {
						if (strcmp(argv[4], "-rand") == 0 || strcmp(argv[4], "-nsorted") == 0 || strcmp(argv[4], "-sorted") == 0 || strcmp(argv[4], "-rev") == 0) {
							if (strcmp(argv[5], "-both") == 0 || strcmp(argv[5], "-time") == 0 || strcmp(argv[5], "-comp") == 0)
								return 2;
						}
					}
				}
			}
			return -1;
		}
		else if (strcmp(argv[1], "-c") == 0) {
			if (i == 5) { 
				if (CharSortToNum(argv[2]) != 0 && CharSortToNum(argv[3]) != 0) {
					if (argv[3][strlen(argv[3]) - 1] == 't')
						if (ReadFileandReturnModeC(argv) != -1) {
							return 4;
						}
				}
			}
			else {
				if (CharSortToNum(argv[2]) != 0 && CharSortToNum(argv[3]) != 0) {
					if (argv[4][strlen(argv[4]) - 1] != 't') {
						if (strcmp(argv[5], "-rand") == 0 || strcmp(argv[5], "-nsorted") == 0 || strcmp(argv[5], "-sorted") == 0 || strcmp(argv[5], "-rev") == 0)
							return 5;
					}
				}
			}
			return -1;
		}
	}
	return -1;
}

int CharSortToNum(const char* ss)
{
	int SortMode = 0;
	if (strcmp(ss, "selection-sort") == 0) {
		SortMode = 1;
	}
	else if (strcmp(ss, "insertion-sort") == 0) {
		SortMode = 2;
	}
	else if (strcmp(ss, "bubble-sort") == 0) {
		SortMode = 3;
	}
	else if (strcmp(ss, "shaker-sort") == 0) {
		SortMode = 4;
	}
	else if (strcmp(ss, "shell-sort") == 0) {
		SortMode = 5;
	}
	else if (strcmp(ss, "heap-sort") == 0) {
		SortMode = 6;
	}
	else if (strcmp(ss, "merge-sort") == 0) {
		SortMode = 7;
	}
	else if (strcmp(ss, "quick-sort") == 0) {
		SortMode = 8;
	}
	else if (strcmp(ss, "counting-sort") == 0) {
		SortMode = 9;
	}
	else if (strcmp(ss, "radix-sort") == 0) {
		SortMode = 10;
	}
	else if (strcmp(ss, "flash-sort") == 0) {
		SortMode = 11;
	}
	return SortMode;
}

void Sorting_Algorithm_runtime(int* a, int n, int SortMode)
{
	switch (SortMode) {
	case 1: {
		SelectionSort(a, n);
		break;
	}
	case 2: {
		InsertionSort(a, n);
		break;
	}
	case 3: {
        BubbleSort(a, n);
		break;
	}
	case 4: {
		ShakerSort(a, n);
		break;
	}
	case 5: {
		ShellSort(a, n);
		break;
	}
	case 6:
	{
        HeapSort(a, n);
		break;
	}
	case 7:
	{
		MergeSort_Original(a, n);
		break;
	}
	case 8:
	{
		QuickSort(a, n);
		break;
	}
	case 9:
	{
		CountingSort(a, n);
		break;
	}
	case 10:
	{
		RadixSort(a, n);
		break;
	}
	case 11:
	{
        FlashSort(a, n);
		break;
	}
	}

}

void Sorting_Algorithm(int* a, int n, int SortMode, unsigned long long& count_compare)
{
	switch (SortMode) {
	case 1: {
		SelectionSort_CC(a, n, count_compare);
		break;
	}
	case 2: {
		InsertionSort_CC(a, n, count_compare);
		break;
	}
	case 3: {
		BubbleSort_CC(a, n, count_compare);
		break;
	}
	case 4: {
		ShakerSort_CC(a, n, count_compare);
		break;
	}
	case 5: {
		ShellSort_CC(a, n, count_compare);
		break;
	}
	case 6:
	{
        HeapSort_CC(a, n, count_compare);
		break;
	}
	case 7:
	{
		MergeSort_CC(a, n, count_compare);
		break;
	}
	case 8:
	{
		QuickSort_CC(a, n, count_compare);
		break;
	}
	case 9:
	{
		CountingSort_CC(a, n, count_compare);
		break;
	}
	case 10:
	{
		RadixSort_CC(a, n, count_compare);
		break;
	}
	case 11:
	{
		FlashSort_CC(a, n, count_compare);
		break;
	}
	}

}