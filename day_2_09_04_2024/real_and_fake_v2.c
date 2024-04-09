#include <stdio.h>
#include <stdio.h>

int main(){ 
    // coins count
    int n;  scanf("%d", &n);
    int coins[n];
    int total_weight_of_the_bag = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &coins[i]);
        total_weight_of_the_bag += coins[i];
    }

    int a1 = coins[0];
    int a2 = coins[1];
    int a3 = coins[2];

    int real_coin_weight;
    if(a1 == a2 && a2 == a3){
        real_coin_weight = a1;
    }else if(a1 == a2 && a2 != a3){
        // the fake coin is among the first 3 memebers of the array (lucky case)
        // fake coin is a3
        if(a1 > a3){
            printf("Fake coin is lighter\n");
        }else if(a1 < a3){
            printf("Fake coint is heavier\n");
        }else{
            printf("cannot determine\n");
        }
        return 0;
    }else if(a1 != a2 && a2 == a3){
        // fake is a1
        if(a1 > a3){
            printf("Fake coin is heavier\n");
        }else if(a1 < a3){
            printf("Fake coin is lighter\n");
        }else{
            printf("Cannot determine\n");
        }
        return 0;
    }

    int sum_with_all_real_coins = n*real_coin_weight;

    if(total_weight_of_the_bag > sum_with_all_real_coins){
        printf("Fake coin is heavier\n");
    }else if(total_weight_of_the_bag < sum_with_all_real_coins){
        printf("Fake coin is lighter");
    }else{
        printf("Cannot determine\n");
    }

    return 0;
}