#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

//INSERTION SORT
void insertionSort(float arr[], int n)
{
	int i, j;
    float key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
//INSERTION SORT

//SELECTION SORT
void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(float arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        if(min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
}
//SELECTION SORT
//QUICKSORT
int partition(float arr[], int start, int end)
{
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
 
void quickSort(float arr[], int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}
//QUICKSORT

//MERGESORT
void merge(float array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto *leftArray = new float[subArrayOne],
         *rightArray = new float[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
    auto indexOfSubArrayOne
        = 0,
        indexOfSubArrayTwo
        = 0;
    int indexOfMergedArray
        = left;
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(float array[], int const begin, int const end)
{
    if (begin >= end)
        return; 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
} 
//MERGESORT

void printArray(float arr[], int n)
{
	int i;
	for (i = 0; i < n; i++){
        cout << arr[i] << " ";   
    }
	cout << endl;
}

int main()
{
    srand ( time(NULL) );
    const int n=100000;
    float arr[n];
    for(int i=0;i<n;i++){
        float r = 0 + static_cast<float>(rand()) * static_cast<float>(1 - 0) / RAND_MAX;
        arr[i]=r;
    }
    //printArray(arr,n);
    auto start_time = chrono::high_resolution_clock::now();
	//insertionSort(arr,n);
    //selectionSort(arr,n);
    quickSort(arr,0,n-1);
    //mergeSort(arr,0,n-1);
    auto end = chrono::system_clock::now();
    auto end_time = chrono::high_resolution_clock::now();
    auto time = end_time - start_time;
    cout<<"Execution time: "<<time/std::chrono::milliseconds(1) << "ms.\n";
    cout<<"Para "<<n<<" elementos"<<endl;
	//printArray(arr,n);

	return 0;
}
