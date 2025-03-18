#include"SortingAlgorithms.h"

template<class T>
void Swap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}
  
//HEAP_SORT
void HeapBuild(int* arr, int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
		{ 
			Swap(arr[i], arr[largest]); 
			HeapBuild(arr, n, largest); 
		} 
} 

void HeapSort(int* arr, int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        HeapBuild(arr, n, i); 
  
    for (int i=n-1; i>0; i--) 
		{ 
			Swap(arr[0], arr[i]);  
			HeapBuild(arr, i, 0); 
		} 
} 

void HeapBuild_CC(int* a, int n, int i, unsigned long long& count_compare) {
	int largest = i; 
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 

	if ((++count_compare && left < n) && (++count_compare && a[left] > a[largest])) {
		largest = left;
	}
	if ((++count_compare && right < n) && (++count_compare && a[right] > a[largest])) {
		largest = right;
	}

	if (++count_compare && largest != i) {
		Swap(a[i], a[largest]);
		HeapBuild_CC(a, n, largest, count_compare);
	}
}

void HeapSort_CC(int* a, int n, unsigned long long& count_compare) {

	for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
		HeapBuild_CC(a, n, i, count_compare);
	//heap sort
	for (int i = n - 1; ++count_compare && i >= 0; i--) {
		Swap(a[0], a[i]);
		HeapBuild_CC(a, i, 0, count_compare);
	}
}


//BUBBLE SORT

void BubbleSort(int* a, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		bool swapped = false;
		for (int j = 0; j < i; j++)
			if (a[j] > a[j + 1])
			{
				swapped = true;
				Swap(a[j], a[j + 1]);
			}
		if (!swapped)
			return;
	}
}

void BubbleSort_CC(int* a, int n, unsigned long long& count_compare)
{
	for (int i = n - 1; ++count_compare && i >= 0; i--)
	{
		bool swapped = false;
		for (int j = 0; ++count_compare && j < i; j++){

			if ( ++count_compare && a[j] > a[j + 1])
			{
				swapped = true;
				Swap(a[j], a[j + 1]);
			}
		}
		if (!swapped)
			return;
	}
}



//FLASH SORT
void FlashSort(int* a, int n)
{
	int minVal = a[0]; 
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[n];

	int i1 = 0;
	while (i1 < m)
	{
		l[i1] = 0; 
		i1++;
	}

	int i2 = 1;
	while (i2 < n)
	{
		if (a[i2] < minVal)
			minVal = a[i2];
		if (a[i2] > a[max])
			max = i2;
		i2++;
	}

	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);

	int i3 = 0;
	while (i3 < n)
	{
		int k = int(c1 * (a[i3] - minVal));
		++l[k];
		i3++;
	}

	int i4 = 1;
	while (i4 < m)
	{
		l[i4] += l[i4 - 1];
		i4++;
	}


	Swap(a[max], a[0]);
	int n_move = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;

	while (n_move < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++n_move;
		}
	}
	delete[] l;
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int t = a[i];
		while (t < a[j] && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t;
	}
}

void FlashSort_CC(int* a, int n, unsigned long long& count_compare)
{
	int minVal = a[0]; 
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[n];

	int i1 = 0;
	while (++count_compare && i1 < m)
	{
		l[i1] = 0; 
		i1++;
	}

	int i2 = 1;
	while (++count_compare && i2 < n)
	{
		if (++count_compare && a[i2] < minVal)
			minVal = a[i2];
		if (++count_compare && a[i2] > a[max])
			max = i2;
		i2++;
	}

	if (++count_compare && a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);

	int i3 = 0;
	while (++count_compare && i3 < n)
	{
		int k = int(c1 * (a[i3] - minVal));
		++l[k];
		i3++;
	}

	int i4 = 1;
	while (++count_compare && i4 < m)
	{
		l[i4] += l[i4 - 1];
		i4++;
	}


	Swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;

	while (++count_compare && nmove < n - 1)
	{
		while (++count_compare && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (++count_compare && k < 0) break;
		while (++count_compare && j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	for (int i = 1; ++count_compare && i < n; i++)
	{
		int j = i - 1;
		int t = a[i];
		while (++count_compare && t < a[j] && ++count_compare && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t;
	}

    //cout <<"so phep so sanh la: " << count_compare << endl;
}


//SELECTION SORT
void SelectionSort(int* a, int n) {

	for (int i = 0; i < n-1; i++) {
		int flag = i;
		for (int j = i+1; j < n; j++)
			if (a[j] < a[flag]) {
				flag = j;
			}
		Swap(a[i], a[flag]); 
	}
}

void SelectionSort_CC (int* a, int n, unsigned long long& countCompare){
    	for (int i = 0; ++countCompare && i < n-1; i++) {
		int min = i;
		for (int j = i+1; ++countCompare && j < n; j++)
			if (++countCompare && a[j] < a[min]) {
				min = j;
			}
		Swap(a[i], a[min]);
	}
}


//MERGE SORT
void Merge(int* a, int left, int mid, int right, unsigned long long& count_compare) {
	int n1 = mid - left + 1; 
	int n2 = right - mid; 
	int* a1 = new int[n1];
	int* a2 = new int[n2];

	for (int i = 0;++count_compare && i < n1; i++) {
		a1[i] = a[left + i];
	}
	for (int i = 0; ++count_compare && i < n2; i++) {
		a2[i] = a[mid + 1 + i];
	}
	int i = 0; 
	int j = 0; 
	int k = left; 

	while ((++count_compare && i < n1) && (++count_compare && j < n2)) {
		if (++count_compare && a1[i] <= a2[j]) {
			a[k] = a1[i]; 
			i++; 
		}
		else {
			a[k] = a2[j]; 
			j++; 
		} 
		k++; 
	}
	
	while (++count_compare && i < n1) {
		a[k] = a1[i]; 
		i++; 
		k++; 
	}

	while (++count_compare && j < n2) {
		a[k] = a2[j]; 
		j++; 
		k++; 
	}
	delete[] a1;
	delete[] a2;
}

void MergeSort_F(int* a, int left, int right, unsigned long long& count_compare) {
	if (++count_compare && left < right) {
		int mid = (right + left) / 2;
		MergeSort_F(a, left, mid, count_compare);
		MergeSort_F(a, mid + 1, right, count_compare);
		Merge(a, left, mid, right, count_compare);
	}
}

void MergeSort_CC(int* a, int n, unsigned long long& count_compare) {
	MergeSort_F(a, 0, n-1, count_compare);
}

void Merge_Original(int* a, int left, int mid, int right) {
	int n1 = mid - left + 1; 
	int n2 = right - mid; 
	int* a1 = new int[n1];
	int* a2 = new int[n2];

	for (int i = 0; i < n1; i++) {
		a1[i] = a[left + i];
	}
	for (int i = 0; i < n2; i++) {
		a2[i] = a[mid + 1 + i];
	}
	int i = 0; 
	int j = 0; 
	int k = left; 

	while (i < n1 && j < n2) {
		if (a1[i] <= a2[j]) {
			a[k] = a1[i]; 
			i++; 
		}
		else {
			a[k] = a2[j]; 
			j++; 
		} 
		k++; 
	}
	
	while (i < n1) {
		a[k] = a1[i]; 
		i++; 
		k++; 
	}

	while (j < n2) {
		a[k] = a2[j]; 
		j++; 
		k++; 
	}

	delete[] a1;
	delete[] a2;
}

void MergeSort_F_Original(int* a, int left, int right) {
	if (left < right) {
		int mid = (right + left) / 2;
		MergeSort_F_Original(a, left, mid);
		MergeSort_F_Original(a, mid + 1, right);
		Merge_Original(a, left, mid, right);
	}
}

void MergeSort_Original(int* a, int n) {
	MergeSort_F_Original(a, 0, n-1);
}


//SHAKER SORT
void ShakerSort_CC(int* a, int n, unsigned long long& count_compare) {
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (++count_compare && Left < Right)
	{
		for (int i = Left; ++count_compare && i < Right; i++)
		{
			if (++count_compare && a[i] > a[i + 1])
			{
				Swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; ++count_compare && i > Left; i--)
		{
			if (++count_compare && a[i] < a[i - 1])
			{
				Swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}

void ShakerSort(int* a, int n) {
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (a[i] < a[i - 1])
			{
				Swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}


//SHELL SORT
void ShellSort(int* a, int n)
{
	int inter, i, j, temp;
	for (inter = n / 2; inter > 0; inter /= 2)
	{
		for (i = inter; i < n; i++)
		{
			temp = a[i];
			for (j = i; j >= inter && a[j - inter] > temp; j -= inter)
			{
				a[j] = a[j - inter];
			}
			a[j] = temp;
		}
	}

}
 
void ShellSort_CC(int* a, int n, unsigned long long& count_compare)
{
	int inter, i, j, temp;
	count_compare = 0;
	for (inter = n / 2; ++count_compare && inter > 0; inter /= 2)
	{
		for (i = inter; ++count_compare && i < n; i++)
		{
			temp = a[i];
			for (j = i; ++count_compare && j >= inter && ++count_compare && a[j - inter] > temp; j -= inter)
			{
				a[j] = a[j - inter];
			}
			a[j] = temp;
		}
	}
}


//INSERTION SORT
void InsertionSort(int a[], int n){
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int t = a[i];
		while (t < a[j] && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t;
	}
}

void InsertionSort_CC (int a[], int n, unsigned long long& count_compare){
	for (int i = 1; ++count_compare && i < n; i++)
	{
		int j = i - 1;
		int t = a[i];
		while (++count_compare && t < a[j] && ++count_compare && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t;
	}
}


//RADIX SORT
int getMax(int* arr, int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void CountSort(int* arr, int n, int exp)
{
	int output[n];
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
    {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void RadixSort(int* arr, int n)
{
	int m = getMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		CountSort(arr, n, exp);
}

int getMax(int* arr, int n, unsigned long long& count_compare)
{
	int mx = arr[0];
	for (int i = 1; ++count_compare && i < n; i++)
		if (++count_compare && arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSorts(int* arr, int n, int exp, unsigned long long& count_compare)
{
	int output[n];
	int i, count[10] = { 0 };
	for (i = 0;++count_compare && i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; ++count_compare && i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; ++count_compare && i >= 0; i--)
    {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; ++count_compare && i < n; i++)
		arr[i] = output[i];
}

void RadixSort_CC(int* arr, int n, unsigned long long& count_compare)
{
	int m = getMax(arr, n, count_compare);
	for (int exp = 1; ++count_compare && m / exp > 0; exp *= 10)
		countSorts(arr, n, exp, count_compare);
}


//QUICK SORT
void QuickSortFunc_CC(int* a, int low, int high,unsigned long long& count_compare)
{
	int i = low;
	int j = high;
	int pivot = a[(i + j) / 2];
	int temp;

	while (++count_compare && i <= j)
	{
		while (++count_compare && a[i] < pivot) i++;
		while (++count_compare && a[j] > pivot) j--;
		if (++count_compare && i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (++count_compare && j > low)
		QuickSortFunc_CC(a, low, j, count_compare);
	if (++count_compare && i < high)
		QuickSortFunc_CC(a, i, high, count_compare);
}

void QuickSort_CC(int* a, int n, unsigned long long& count_compare) {
	QuickSortFunc_CC(a, 0, n-1, count_compare);
    
}

void QuickSortFunc_Original(int* a, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = a[(i + j) / 2];
	int temp;

	while (i <= j)
	{
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (j > low)
		QuickSortFunc_Original(a, low, j);
	if (i < high)
		QuickSortFunc_Original(a, i, high);
}

void QuickSort(int* a, int n) {
	QuickSortFunc_Original(a, 0, n-1);
}


//COUNTING SORT
void CountingSort(int* arr, int n)
{
    int* output= new int[n]; 
    int max = arr[0];
    int min = arr[0];
     
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
        else if(arr[i] < min)
            min = arr[i];
    }
 
    int k = max - min + 1;
 
    int* count_array = new int[k];
	for (int i = 0; i < k; i++)
	{
		count_array[i] = 0;
	}
 
    for(int i = 0; i < n; i++)
        count_array[arr[i] - min]++;
 
    for(int i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];
 
    for(int i = 0; i < n; i++)
    {
        output[count_array[arr[i] - min] - 1] = arr[i];
        count_array[arr[i] - min]--;
    }
 
 
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
 
	delete[] output;
	delete[] count_array;
}

void CountingSort_CC(int* input, int n, unsigned long long& count_compare)
{
 	
    int* output= new int[n];
    int max = input[0];
    int min = input[0];
 
    for(int i = 1; ++count_compare && i < n; i++)
    {
        if(++count_compare && input[i] > max)
            max = input[i];
        else if(++count_compare && input[i] < min)
            min = input[i];
    }
    int k = max - min + 1;
 
    int* count_array = new int[k]; 
	for (int i = 0; ++count_compare && i < k; i++)
	{
		count_array[i] = 0;
	}
 
   for(int i = 0; ++count_compare && i < n; i++)
        count_array[input[i] - min]++;
 
   for(int i = 1; ++count_compare && i < k; i++)
        count_array[i] += count_array[i - 1];
 
   for(int i = 0; ++count_compare && i < n; i++)
    {
        output[count_array[input[i] - min] - 1] = input[i];
        count_array[input[i] - min]--;
    }

 
   for(int i = 0; ++count_compare && i < n; i++)
        input[i] = output[i];
 	
	delete[] output;
	delete[] count_array;
}

