#include<stdio.h>
#include<stdlib.h>

void traverse(int *arr,int n){
    int i;

    for(i=0; i<n; i++){
        printf("%d\t",*(arr+i));
    }
}

void insert(int *arr, int n){
    int item2, i;
    int pos2;
    printf("Enter value: \n");
    scanf("%d",&item2);
    printf("Enter position: \n");
    scanf("%d",&pos2);
    // incresing size of array by 1 so that we can add another item in array
    n++; 

    // shift elements forward
    for(i=n-1; i>pos2; i--){
        arr[i]=arr[i-1];
    }

    // insert item at position
    arr[pos2-1]=item2;
    
    // print the updated array
    for(i=0; i<n; i++){
        printf("%d\t",arr[i]); //
    }

}

void delete(int *arr, int n){
    int item3,pos3,i;
    printf("Enter position of element to delete: ");
    scanf("%d",&pos3);

    // delete item from that position
    for(i=pos3-1;i<n; i++){
        arr[i]=arr[i+1];
    }

    // print the updated array
    for(i=0; i<n-1; i++){
        printf("%d\t",arr[i]);
    }

}

void search(int *arr,int n){
    int item4, pos4=-1, i;
    printf("enter iteam locate: ");
    scanf("%d",&item4);

    //search item at every index of array
    for(i=0; i<n; i++){
        if(arr[i]==item4){
            pos4=i;
            printf("%d is located at %d\n",item4,pos4);
        }
    }

    // if item is not there in array
    if(pos4=-1){
        printf("Element not found!!!\n");
    }
    
}

void sort(int *arr, int n){
    int pos5,i,j,temp;

    // sorting items one by one
    for(i=1; i<n-1; i++){
        for(j=0; j<n-1; j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }

    // print the updated array
    for(i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
}

void main(){
    int n,a,i,c;
    printf("Enter Size to create an array: ");
    scanf("%d",&n);
    int *arr;
    //create arr with size
    arr=(int*)malloc(n*sizeof(int));
    
    while(1){
        printf("Enter no of elements: ");
        scanf("%d",&n);

        //reallocating size of the array
        arr=realloc(arr,n*sizeof(int));

        //taking input in array
        printf("Enter elements: \n");
        for(i=0; i<n; i++){
            scanf("%d",&arr[i]);
        }

        printf("\n---------------MENU------------------\n");
        printf("Choose any one option: \n");
        printf("\t 1.Traverse\n");
        printf("\t 2.insert\n");
        printf("\t 3.Delete\n");
        printf("\t 4.Search\n");
        printf("\t 5.Sort\n");
        scanf("%d",&a);
        
        switch (a)
        {
        case 1:
        traverse(arr,n);
        break;

        case 2:
        insert(arr,n);
        break;

        case 3:
        delete(arr,n);
        break;

        case 4:
        search(arr,n);
        break;

        case 5:
        sort(arr,n);
        break;
        
        
        default:
        printf("Invalid Input");
        break;
        }
        printf("\n DO YOU WANT MENU AGAIN ?\n");
        printf("Type '1' for YES or '0' for NO\n");
        scanf("%d",&c);
        if(c==0){
            break;
        }
        
    }
    free(arr);
    getchar();

}
