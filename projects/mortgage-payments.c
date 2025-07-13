#include <stdio.h>
#include <math.h>

void calculateMortgage(double principal, double annualInterestRate, int years) {
    // Convert annual interest rate to monthly
    double monthlyRate = annualInterestRate / 12.0 / 100.0;
    int months = years * 12;

    // Calculate monthly payment using the formula for fixed monthly payments
    double monthlyPayment = principal * (monthlyRate * pow(1 + monthlyRate, months)) / 
                            (pow(1 + monthlyRate, months) - 1);

    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Payment Schedule:\n");
    printf("Month\tBalance\t\tPayment\t\tInterest\tPrincipal\n");

    double balance = principal;
    for (int month = 1; month <= months; month++) {
        double interest = balance * monthlyRate;
        double principalPaid = monthlyPayment - interest;
        
        // Update balance
        balance -= principalPaid;
        
        // Print payment details for this month
        if (balance < 1000) {
            printf("%d\t$%.2f\t$%.2f\t\t$%.2f\t\t$%.2f\n", 
                month, balance, monthlyPayment, interest, principalPaid);
        }
        else {
            
        }
        

        // If the balance goes negative due to rounding, set it to zero
        if (balance < 0) {
            balance = 0;
        }
    }
}

int main() {
    double principal, annualInterestRate;
    int years;

    // Input from user
    printf("Enter loan amount: $");
    scanf("%lf", &principal);
    printf("Enter annual interest rate (e.g., 5 for 5%%): ");
    scanf("%lf", &annualInterestRate);
    printf("Enter loan term in years: ");
    scanf("%d", &years);

    calculateMortgage(principal, annualInterestRate, years);

    return 0;
}

// gcc -o mortgage-payments.exe mortgage-payments.c -lm
