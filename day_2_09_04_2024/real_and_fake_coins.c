#include <stdio.h>
#include <stdlib.h>

int main(){
    // number of coins
    printf("Number of coins: ");
    int n;  scanf("%d", &n);

    // weight of real coins?
    printf("Real coin weight: ");
    int real_coin_weight;   scanf("%d", &real_coin_weight);

    // fake coin weight?
    printf("Fake coin weight: ");
    int fake_coin_weight; scanf("%d", &fake_coin_weight);

    // if all real
    int sum_will_all_real = n * real_coin_weight;

    // with one fake coin
    int sum_with_fake = fake_coin_weight + (n-1)*real_coin_weight;

    if(sum_with_fake > sum_will_all_real){
        printf("Fake coin is heavier\n");
    }else if(sum_with_fake < sum_will_all_real){
        printf("Fake coin is lighter\n");
    }else{
        printf("Cannot differentiate between fake and real coin on the basis of weights\n");
    }

    return 0;
}