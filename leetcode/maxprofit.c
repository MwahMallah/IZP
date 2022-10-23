#include <stdio.h>

int main(void)
{
    int prices[] = {7,1,5,3,6,4};
    int pricesSize = 6;

    int max_profit = 0;
    int counter = 0;
    
    int* l_price = &prices[0];
    int* r_price = &prices[1];
    
    while (*r_price != 4)
    {
        int profit = *r_price - *l_price;
        
        printf("%i - l_price, %i - r_price: %i - profit\n", *l_price, *r_price, profit);
        printf("\n");
        if (profit > max_profit)
        {
            printf("%i - profit\n", profit);
            max_profit = profit;
        }
        
        if (profit > 0)
        {
            r_price = &r_price[1];
        }
        else 
        {
            r_price = &r_price[1];
            l_price = &l_price[1];
        }
    }

    printf("%i and %i\n is equal to %i", *l_price, *r_price, max_profit);
}