#include <stdio.h>
#include <math.h>

double calculate_mortgage_payment(double principal, double annual_interest_rate, int num_payments) {
    // Calculate monthly interest rate
    double monthly_interest_rate = annual_interest_rate / 12 / 100;

    // Calculate monthly payment using the mortgage formula
    double payment = principal * (monthly_interest_rate * pow(1 + monthly_interest_rate, num_payments)) /
                         (pow(1 + monthly_interest_rate, num_payments) - 1);

    return payment;
}

int main() {
    double principal, annual_interest_rate;
    int num_payments;

    // Get input from the user
    printf("Enter the loan principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the annual interest rate (as a percentage): ");
    scanf("%lf", &annual_interest_rate);

    printf("Enter the total number of payments: ");
    scanf("%d", &num_payments);

    // Calculate monthly payment
    double monthly_payment = calculate_mortgage_payment(principal, annual_interest_rate / 100, num_payments);

    // Print the calculated payment
    printf("\nMonthly Mortgage Payment: $%.2f\n", monthly_payment);

    return 0;
}

// gcc -o mortgage.exe mortgage.c -lm