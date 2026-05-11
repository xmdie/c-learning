#include <stdio.h>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

void print_header() {
    printf(CYAN BOLD);
    printf("[==========================]\n");
    printf("|      CALCULATOR v1.0     |\n");
    printf("|         by xmdie         |\n");
    printf("[==========================]\n");
    printf(RESET);
}

void print_divider() {
    printf(CYAN "---------------------------\n" RESET);
}

int main() {
    double a, b;
    char op;
    char again;

    print_header();

    do {
        print_divider();
        printf(YELLOW "  ENTER CALC OPERATION: " RESET);
        scanf("%lf %c %lf", &a, &op, &b);

        double result = 0;
        int error = 0;

        if (op == '+') result = a + b;
        else if (op == '-') result = a - b;
        else if (op == '*') result = a * b;
        else if (op == '/' && b != 0) result = a / b;
        else { error = 1; }

        if (error) {
            printf(RED "  ERROR! NOT CORRECT OPERATOR OR DIVIDE 0.\n" RESET);
        } else {
            printf(GREEN "  Resulst is: %.2f\n" RESET, result);
        }

        print_divider();
        printf(YELLOW "  AGAIN? (y/n): " RESET);
        scanf(" %c", &again);

    } while (again == 'y');

    printf(CYAN BOLD "\n  BYE!<3!\n" RESET);
    return 0;
}
