//purpose: with a given monthly budget, to find number of coffees possible for purchase,
//number of free coffees redeemable, money left over, and number of coupons left over
//user input is not assumed as valid

#include <stdio.h>

int main()
{
    int redeem = 0; //number of coupons to redeem a free coffee
    double price = 0; //price of individual coffee
    double monthlyBudget = 0;
    
    printf("How much does a coffee cost?\n");
    scanf("%lf", &price);
    
    if(price < 0.01){
        printf("Invalid Input.\n");
        return(0);
    }
    
    printf("How many coupons does it take to get a free coffee?\n");
    scanf("%d", &redeem);
    
    if(redeem % 1 != 0 || redeem <= 1){ //redeem must be a positive integer
        printf("Invalid Input.\n");
        return(0);
    }
    
    printf("How much money do you have to spend on coffee this month?\n");
    scanf("%lf", &monthlyBudget);
    
    if(monthlyBudget < 0){
        printf("Invalid Input.\n");
        return(0);
    }
    
    int paidCoffees = monthlyBudget / price; //number of coffees possible to purchase
    int freeCoffees = paidCoffees / redeem; //number of free coffees possible
    int coupons = paidCoffees + freeCoffees -  freeCoffees*redeem; //number of left over coupons
    double moneyRemaining = monthlyBudget - (price*paidCoffees); 
    double priceAverage = paidCoffees * price / (freeCoffees + paidCoffees); //average price including purchased and free coffee
    
    if(freeCoffees == 0){
        printf("This month, you can purchase %d coffees at $%.2lf each.\n"
               "You will not be able to redeem any additional coffees from coupons this month.\n"
               "At the end of the month, you will have $%.2lf and %d coupon(s) remaining.\n"
               "On average, you spent $%.2lf on each cup of coffee this month.\n",
               paidCoffees, price, moneyRemaining, paidCoffees, priceAverage);
    }else{
        printf("This month, you can purchase %d coffees at $%.2lf each.\n"
           "You will be able to redeem an additional %d coffee(s) from coupons.\n"
           "At the end of the month, you will have $%.2lf and %d coupon(s) remaining.\n"
           "On average, you spent $%.2lf on each cup of coffee this month.\n", 
           paidCoffees, price, freeCoffees, moneyRemaining, coupons, priceAverage);
    }
    
    
    return(0);
}