#include <stdio.h>
#include <math.h>

#define MAX_SIZE 1e8+10

int isEquilibriumIndex(int n){
    // Intuition...
    
    // 1 2 3 4 5 6 7 8 -> ele = 6
    // 1 2 3 4 5 6 7 8 9 10 11 
    // 1 2 3 4 ...... n 
    // sum of total = n*(n+1)/2;
    // sum at equilibrium point is: n*(n+1)/2 - i*(i+1)/2  = (i *(i+1)/2) - i;
    // (n*(n+1)/2) = 2*i*(i+1)/2 - i;
    // n*(n+1)/2 = i * (i+1) - i;
    // n*(n+1)/2 = i^2 -> solve this equation

    int sum = n*(n+1)/2;
    // printf("Sum is %d\n", sum);
    // printf("sqrt(sum) is %f\n", sqrt(sum));
    if(sqrt(sum) - floor(sqrt(sum)) != 0){
        // printf("Not possible");
        return 0;
    }

    // printf("The equilibrium value is %.0f\n", sqrt(sum));
    // printf("The equilibrium index is %.0f\n", sqrt(sum)-1);
    return 1;
}

int main(){
    // int n;  scanf("%d", &n);
    int count = 0;
    for(int i = 2; i < MAX_SIZE; i++){
        if(isEquilibriumIndex(i)){
            printf("%d - %.0f\n", i, sqrt(i*(i+1)/2));
            count++;
        }

        if(count == 10){
            break;
        }
    }
    
    return 0;
}