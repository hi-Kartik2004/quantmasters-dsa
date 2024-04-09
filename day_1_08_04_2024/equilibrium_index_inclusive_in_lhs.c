#include <stdio.h>
#include <math.h>

int main(){
    int n;  scanf("%d", &n);

    int sum = n*(n+1)/2;

    // 1 2 3 4 5 6 7 8 -> ele = 6
    // 1 2 3 4 5 6 7 8 9 10 11 
    // 1 2 3 4 ...... n 
    // sum of total = n*(n+1)/2;
    // sum at equilibrium point is: n*(n+1)/2 - i*(i+1)/2  = (i *(i+1)/2);
    // (n*(n+1)/2) = 2*i*(i+1)/2;
    // n*(n+1)/2 = i * (i+1);
    // n*(n+1)/2 = i^2 + i -> solve this equation


    double possibleEquilibriumValue = (-1 + sqrt(1 + 4*(sum)))/(2);
    if(possibleEquilibriumValue - floor(possibleEquilibriumValue) != 0){
        printf("Not possible");
        return 0;
    }

    printf("The equilibrium index is %.0f\n", possibleEquilibriumValue);

    return 0;
}