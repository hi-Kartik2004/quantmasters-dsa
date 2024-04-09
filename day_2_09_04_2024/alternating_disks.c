#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(){
    // input number of disks
    int n;  scanf("%d", &n);

    // 1 0 1 0 1 0 1 0 -> 1 = dark, 0 = light
    // 0 1 1 0 1 0 1 0
    // 0 1 0 1 0 1 0 1 = 4 swaps 
    // 0 0 1 0 1 0 1 1 = 3 swaps
    // 0 0 0 1 0 1 1 1 = 2 swaps
    // 0 0 0 0 1 1 1 1 = 1 swap

    // so total number of swaps = (n/2)*((n/2)+1)/2

    // allowed to change the position of 2 neighbouring disks only

    // creating an alternating array for better clarity

    // 0 1 0 1 0 1 0 1
    // 0 0 1 0 1 0 1 1 = 3 swaps
    // 0 0 0 1 0 1 1 1 = 2 swaps
    // 0 0 0 0 1 1 1 1 = 1 swaps

    int arr[n];
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            arr[i] = 1;
        }else{
            arr[i] = 0;
        }
    }

    // handling the swaps
    int no_of_swaps = 0; // to check the formula given above :)
    for(int j = 0; j < n/2; j++){
        for(int i = j; i < n-1-j; i+=2){
            no_of_swaps++;
            swap(arr, i, i+1);
        }
    }

    // printing the output array after the operation
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("The number of swaps is %d\n", no_of_swaps);

    return 0;
}