#include"SortingAlgorithms.h"


void PrintSortingMode(int SortMode)
{
	switch (SortMode) {
	case 1: {
		cout << "Selection Sort";
		break;
	}
	case 2: {
		cout << "Insertion Sort";
		break;
	}
	case 3: {
		cout << "Bubble Sort";
		break;
	}
	case 4: {
		cout << "Shaker Sort";
		break;
	}
	case 5: {
		cout << "Shell Sort";
		break;
	}
	case 6:
	{
		cout << "Heap Sort";
		break;
	}
	case 7:
	{
		cout << "Merge Sort";
		break;
	}
	case 8:
	{
		cout << "Quick Sort";
		break;
	}
	case 9:
	{
		cout << "Counting Sort";
		break;
	}
	case 10:
	{
		cout << "Radix Sort";
		break;
	}
	case 11:
	{
		cout << "Flash Sort";
		break;
	}
	}

}


int ReadFileandReturnModeA(char* file_input[3]) {
	ifstream ifs(file_input[3]);
	if (ifs.fail()) return -1;
	int n;
	ifs >> n;
	ifs.close();
	return n;
}

int ReadFileandReturnModeC(char* file_input[4]) {
	ifstream ifs(file_input[4]);
	if (ifs.fail()) return -1;
	int n;
	ifs >> n;
	ifs.close();
	return n;
}

void ReadFile_ModeA(char* file_input[3], int* a, int n) {
	ifstream ifs(file_input[3]);
	ifs >> n;
	int i = 0;
	while (!ifs.eof()) {
		ifs >> a[i];
		i++;
	}
	ifs.close();
}

void ReadFile_ModeC(char* file_input[4], int* a, int n) {
	ifstream ifs(file_input[4]);
	ifs >> n;
	int i = 0;
	while (!ifs.eof()) {
		ifs >> a[i];
		i++;
	}
	ifs.close();
}

void Write_FileOutput(int* a, int n) {
	ofstream ofs("output.txt");
	ofs << n << endl;
	for (int i = 0; i < n; i++)
		ofs << a[i] << " ";
	ofs.close();
}

void Write_File(int* a, int n, string fileName) {
	ofstream ofs(fileName);
	ofs << n << endl;
	for (int i = 0; i < n; i++)
		ofs << a[i] << " ";
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int* Copy_arr(int* a, int n)
{
	int* b = new int[n];
	for (int i = 0; i < n; i++) b[i] = a[i];
	return b;
}

void PrintCMD(int Output_Param, float running_time, unsigned long long count_compare) {
	switch (Output_Param) {
	case 2: {
		cout << "----------------------" << endl;
		cout << "Running time: " << running_time << " ms" << endl;
		cout << "Comparisons: " << count_compare << endl;
		break;
	}
	case 1: {
		cout << "----------------------" << endl;
		cout << "Running time: " << running_time << " ms" << endl;
		break;
	}
	case 0: {
		cout << "----------------------" << endl;
		cout << "Comparisons: " << count_compare << endl;
		break;
	}
	}
}

void Print_CommandLine4(float running_time_1, float running_time_2, unsigned long long& count_compare_1, unsigned long long& count_compare_2)
{
	cout << "-----------------------------" << endl;
	cout << "Running time: " << running_time_1 << " ms" << " | " << running_time_2 << " ms" << endl;
	cout << "Comparisons: " << count_compare_1 << " | " << count_compare_2 << endl;
}