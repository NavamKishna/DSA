#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int heap_arr[], int n, int root)
{
   // build heapify
    int largest = root;  // Initialize largest as root
    int left = 2 * root + 1;  // left child
    int right = 2 * root + 2;  // right child

    // If left child is larger than root
    if (left < n && heap_arr[left] > heap_arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && heap_arr[right] > heap_arr[largest])
        largest = right;

    // If largest is not root
    if (largest != root) {
        swap(heap_arr[root], heap_arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(heap_arr, n, largest);
    }
}
  
// implementing heap sort
void heapSort(int heap_arr[], int n)
{
    // build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap_arr, n, i);

    // extracting elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(heap_arr[0], heap_arr[i]);

        // call max heapify on the reduced heap
        heapify(heap_arr, i, 0);
    }
}
  
/* print contents of array */
void displayArray(int heap_arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << heap_arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    int n, choice;
    cout << "Enter the number of elements: ";
    cin >> n;

    int heap_arr[n];

    cout << "Enter 1 to input your own values or 2 to generate random values: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the elements:\n";

        for (int i = 0; i < n; i++)
            cin >> heap_arr[i];
    }
    else if (choice == 2) {
        // use current time as seed for random generator
        srand(time(0));

        // generate random numbers between 1 and 100
        for (int i = 1; i < n+1; i++)
            heap_arr[i-1] = rand() % 100 + 1;
    }
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}