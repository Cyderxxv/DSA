#include"SortingAlgorithms.h"

// a.exe -a radix-sort input.txt -both
void Command_line1(int argc, char* argv[])
{
	cout << "Algorithm: ";
	int SortMode = CharSortToNum(argv[2]);
	PrintSortingMode(SortMode); cout << endl;
	int n = 0;
	n = ReadFileandReturnModeA(argv);
	cout << "Input file: " << argv[3] << endl;
	cout << "Input size: " << n << endl;

	int outputParam = 0;
	if (strcmp(argv[4], "-both") == 0) {
		outputParam = 2;
	}
	else {
		if (strcmp(argv[4], "-time") == 0) {
			outputParam = 1;
		}
		else {
			outputParam = 0;
		}
	}

	unsigned long long count_compare = 0;

	int* a = new int[n];
	int* b = new int[n];
	float running_time = 0;
	ReadFile_ModeA(argv, a, n);
	b = Copy_arr(a, n);
	clock_t tstart, tend;
	tstart = clock();
	Sorting_Algorithm_runtime( a, n, SortMode );
    tend = clock();
    running_time= (((float)tend - tstart) / CLOCKS_PER_SEC) * 1000;
	Sorting_Algorithm(b, n, SortMode, count_compare);
	Write_FileOutput(a, n);
	PrintCMD(outputParam, running_time, count_compare);
	delete[] a;
	delete[] b;
}

void Command_line2(int argc, char* argv[])
{
	cout << "Algorithm: ";
	int SortMode = CharSortToNum(argv[2]);
	PrintSortingMode(SortMode); cout << endl;
	int n = 0;
	n = atoi(argv[3]);
	cout << "Input size: " << atoi(argv[3]) << endl;

	int Output_Param = 0;
	int data = 0;
	cout << "Input order: ";
	if (strcmp(argv[4], "-rand") == 0) {
		data = 0;
		cout << "Randomized data" << endl;
	}
	else {
		if (strcmp(argv[4], "-nsorted") == 0) {
			data = 1;
			cout << "Nearly sorted data" << endl;
		}
		else if (strcmp(argv[4], "-sorted") == 0) {
			data = 2;
			cout << "Sorted data" << endl;
		}
		else {
			data = 3;
			cout << "Reverse sorted data" << endl;
		} 

	}
	if (strcmp(argv[5], "-both") == 0) {
		Output_Param = 2;
	}
	else {
		if (strcmp(argv[5], "-time") == 0) {
			Output_Param = 1;
		}
		else {
			Output_Param = 0;
		}
	}

	unsigned long long count_compare = 0;

	int* a = new int[n];
	int* b = new int[n];
	GenerateData(a, n, data);
	b = Copy_arr(a, n);
	float running_time = 0;
	
	clock_t tstart, tend;
	Sorting_Algorithm(a, n, SortMode, count_compare);
	tstart = clock();
	Sorting_Algorithm_runtime( b, n, SortMode );
    tend = clock();
    running_time= (((float)tend - tstart) / CLOCKS_PER_SEC) * 1000;
	Write_FileOutput(a, n);
	PrintCMD(Output_Param, running_time, count_compare);
	delete[] a;
	delete[] b;
}



void Command_line3(int argc, char* argv[])
{
	cout << "Algorithm: ";
	int SortMode = CharSortToNum(argv[2]);
	PrintSortingMode(SortMode); cout << endl;
	int n = 0;
	n = atoi(argv[3]);
	cout << "Input size: " << atoi(argv[3]) << endl;

	int Output_Param = 0;
	if (strcmp(argv[4], "-time") == 0) {
		Output_Param = 1;
	}
	else if (strcmp(argv[4], "-comp") == 0) {
		Output_Param = 0;
	}
	else if (strcmp(argv[4], "-both") == 0){
		Output_Param = 2;
	}
    else{
        cout << "Argument error" << endl;
    }

	
	unsigned long long count_compare = 0;
	
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
	    int* a = new int[n];
		 int* b = new int[n];
		GenerateData(a, n, i);
		b = Copy_arr(a, n);
		switch (i)
		{
		case 0:
		{
			cout << "Input order: Randomized data" << endl;
			Write_File(a, n, "input_1.txt");
			break;
		}
		case 1:
		{
			cout << "Input order: Nearly sorted data" << endl;
			Write_File(a, n, "input_2.txt");
			break;
		}
		case 2:
		{
			cout << "Input order: Sorted data" << endl;
			Write_File(a, n, "input_3.txt");
			break;
		}
		case 3:
		{
			cout << "Input order: Reverse sorted data" << endl;
			Write_File(a, n, "input_4.txt");
			break;
		}
		}
		float running_time = 0;
		clock_t tstart, tend;
		tstart = clock();
		Sorting_Algorithm_runtime( a, n, SortMode );
      tend = clock();
      running_time= (((float)tend - tstart) / CLOCKS_PER_SEC) * 1000;
		Sorting_Algorithm(b, n, SortMode, count_compare);
        PrintCMD(Output_Param, running_time, count_compare);
		cout << endl;
		count_compare = 0;
        running_time = 0;
		delete[] a;
		delete[] b;
	}
}


void Command_line4(int argc, char* argv[])
{
	cout << "Algorithm: ";

	int SortMode_1 = CharSortToNum(argv[2]);
	int SortMode_2 = CharSortToNum(argv[3]);
	PrintSortingMode(SortMode_1); cout << " | "; 
	PrintSortingMode(SortMode_2); cout << endl;

	int n = 0;
	n = ReadFileandReturnModeC(argv);
	cout << "Input file: " << argv[4] << endl;
	cout << "Input size: " << n << endl;
	unsigned long long count_compare_1 = 0, count_compare_2 = 0;

	int* a = new int[n];
	int* b = new int[n];
	int* A = new int[n];
	int* B = new int[n];
	ReadFile_ModeC(argv, a, n);
	b = Copy_arr(a, n);
	A = Copy_arr(a, n);
	B = Copy_arr(a, n);

	float running_time_1, running_time_2;
	count_compare_1 = 0; 
	count_compare_2 = 0;

	clock_t tstart, tend;
	tstart = clock();
	Sorting_Algorithm_runtime( a, n, SortMode_1);
    tend = clock();
    running_time_1= (((float)tend - tstart) / CLOCKS_PER_SEC) * 1000;
	Sorting_Algorithm(A, n, SortMode_1, count_compare_1);

	tstart = clock();
	Sorting_Algorithm_runtime( b, n, SortMode_2);
	tend = clock();
    running_time_2= (((float)tend - tstart) / CLOCKS_PER_SEC) * 1000;
	Sorting_Algorithm(B, n, SortMode_2, count_compare_2);
	Print_CommandLine4(running_time_1, running_time_2, count_compare_1, count_compare_2);
	delete[] a;
	delete[] b;
	delete[] A;
	delete[] B;
}

void Command_line5(int argc, char* argv[])
{
	cout << "Algorithm: ";

	int SortMode_1 = CharSortToNum(argv[2]);
	int SortMode_2 = CharSortToNum(argv[3]);
	PrintSortingMode(SortMode_1); cout << " | "; 
	PrintSortingMode(SortMode_2); cout << endl;	

	int n = 0;
	n = atoi(argv[4]);
	cout << "Input size: " << atoi(argv[4]) << endl;
	int data = 0;
	cout << "Input order: ";
	if (strcmp(argv[5], "-rand") == 0) {
		data = 0;
		cout << "Randomized data" << endl;
	}
	else {
		if (strcmp(argv[5], "-nsorted") == 0) {
			data = 1;
			cout << "Nearly sorted data" << endl;
		}
		else if (strcmp(argv[5], "-sorted") == 0) {
			data = 2;
			cout << "Sorted data" << endl;
		}
		else {
			data = 3;
			cout << "Reverse sorted data" << endl;
		}
	}
	unsigned long long count_compare_1 = 0, count_compare_2 = 0;

	int* a = new int[n];
	int* b = new int[n];
	int* A = new int[n];
	int* B = new int[n];
	GenerateData(a, n, data);
	b = Copy_arr(a, n);
	A = Copy_arr(a, n);
	B = Copy_arr(a, n);


	float running_time_1, running_time_2;

	clock_t tstart, tend;
	tstart = clock();
	Sorting_Algorithm_runtime( a, n, SortMode_1);
   tend = clock();
   running_time_1= (((float)tend - tstart) / CLOCKS_PER_SEC) * 1000;
	Sorting_Algorithm(A, n, SortMode_1, count_compare_1);

	tstart = clock();
	Sorting_Algorithm_runtime(b, n, SortMode_2);
	tend = clock();
    running_time_2= (((float)tend - tstart) / CLOCKS_PER_SEC) * 1000;
	Sorting_Algorithm(B, n, SortMode_2, count_compare_2);
	Print_CommandLine4(running_time_1, running_time_2, count_compare_1, count_compare_2);
	delete[] a;
	delete[] b;
	delete[] A;
	delete[] B;
}