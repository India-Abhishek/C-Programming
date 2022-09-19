#include <stdio.h>

// resersive binary search

int recursiveBinarySearch(int array[], int start_index, int end_index, int element){
   if (end_index >= start_index){
      int middle = start_index + (end_index - start_index )/2;
      if (array[middle] == element)
         return middle;
      if (array[middle] > element)
         return recursiveBinarySearch(array, start_index, middle-1, element);
      return recursiveBinarySearch(array, middle+1, end_index, element);
   }
   return -1;
}

int main(void){
//initilizing variables 
    int n;       // size of the array
    int element;// enement to search
    int temp; // to store and sort array  
// input size of the array
    printf("Enter the Number of elements\n");
    scanf("%d",&n);
//initilize array with size 
    int a[n];
// input array
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
//sorting array
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
//Printing sorted array
    printf("The sorted arry is\n");
    for(int i=0;i<n;i++)
    {
        printf( "%d",a[i]);
        printf(" ");
    }
    
    printf("\nEnter item to be searched\n");
    scanf("%d",&element);
    
// searching elemenby calling the function and storing in "found_index" variable
    int found_index = recursiveBinarySearch(a, 0, n-1, element);
    if(found_index == -1 ) {
        printf("Element not found in the array ");
    }
    else{
        printf("\nElement found at index : %d",found_index);
    }
    return 0;
}