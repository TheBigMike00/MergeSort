#include <iostream>

using namespace std;

void printArray(int* ar, int begin, int end)

{

    for(int i = begin; i <= end; i++)

    {

        cout << ar[i] << " ";

    }

    cout << "\n";

}

void sortArray(int *arr)
{

}

void merge(int *arr, int l, int m, int r)
{
    //write a function that takes in the OG array allong with the
//left, right, and center
//this function will merge two temp arrays 
// one from the L to the M 
//another from M+1 to the R // we will need to get the sizes of the arrays 
int sz1 = m - l + 1;
int sz2 = r - m; //now we will need to make temp arrays 
int NL[sz1];
int NR[sz2];//now we will need to copy data into temp arrays 
  
for (int i = 0; i < sz1; i++) 
    NL[i] = arr[l + i]; 
for (int j = 0; j < sz2; j++) 
    NR[j] = arr[m + 1 + j]; 
 
    int i = 0; // Initial index of first subarray 
    int j = 0; // Initial index of second subarray 
    int k = l; // Initial index of merged subarray 
    while (i < sz1 && j < sz2) 
    { 
        if (NL[i] <= NR[j]) 
        { 
            arr[k] = NL[i]; 
            i++;
            //if left is smallest put that first 
            //copy that over the original array and 
            //increment by 1 to the next 
            //bucket 
        } 
        else
        { 
            arr[k] = NR[j]; 
            j++; 
            //if right is smallest put that first 
            //copy that over the original array and 
            //increment by 1 to the next 
            //bucket 
        } 
        k++;
        //increment k by one regardless as the bucket for 
        //original array has to move no matter what 
    // Copy the remaining elements of L[], if there 
    //are any 

    }
    while (i < sz1) 
    { 
        arr[k] = NL[i]; 
        i++; 
        k++; 
    }     //Copy the remaining elements of R[], if there 
    //are any 
    while (j < sz2) 
    { 
        arr[k] = NR[j]; 
        j++; 
        k++; 
    }      
    
}

//which portion of the array am I mergeSorting....

void mergeSort(int* ar, int begin, int end)

{

    cout << "Merge Sorting: ";

    printArray(ar, begin, end);

    //if it is not a 1 list (not trivially sorted)

    if(begin != end)

    {

        //divide in half and call mergeSort on each half

        int begin1 = begin;

        int end1 = (end + begin) / 2;

        int begin2 = end1 + 1;

        int end2 = end;

        //call mergesort on the first half

        mergeSort(ar, begin1, end1);

        //call mergesort on the second half

        //this will not fire until the entire 

        //first half is dealt with

        mergeSort(ar, begin2, end2);

        //now perform the merge step

        //cout << "Now we have to merge!!!!\n Start to cry Clancy!!!\n";
        merge(ar, begin, end1, end);
    }


    else

    {

        cout << "One List! Do nothing\n";

    }

    

}

int main()

{

    int ar[7] = {7,10,1,4,3,9,2};

    mergeSort(ar, 0, 6);

    printArray(ar, 0, 6);

    return 0;

}

