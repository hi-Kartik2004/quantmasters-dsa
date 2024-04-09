#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(int n){
    int smallestPrimeNumber = n;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            smallestPrimeNumber = i;
            break;
        }
    }

    return smallestPrimeNumber;
}


void solve(){
    int n,k;   scanf("%d", &n); scanf("%d", &k);
    
    // if the number is even avoid running the function with sqrt(N) time.
    if(n % 2 == 0){
        printf("The resultant number is %d\n", n + 2*(k));
        return;
    }

    int smallestPrimeNumber = sieve(n);

    printf("The resultant number is %d\n", n + smallestPrimeNumber + 2*(k-1));
}

int main(){
    // testcases
    int t;  scanf("%d", &t);

    while(t--){
        solve();
    }

    return 0;
}