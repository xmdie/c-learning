#include <stdio.h>
#include <string.h>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

struct Contact {
    char name[50];
    char phone[20];
};

struct Contact book[100];
int count = 0;

void header() {
    printf(CYAN BOLD);
    printf("[================]\n");
    printf("|   PHONEBOOK    |\n");
    printf("|   by xmdie     |\n");
    printf("[================]\n");
    printf(RESET);
}

void divider() {
    printf(CYAN "──────────────────\n" RESET);
}

void add_contact() {
    printf(YELLOW "Name: " RESET);
    scanf("%s", book[count].name);
    printf(YELLOW "Phone: " RESET);
    scanf("%s", book[count].phone);
    count++;
    printf(GREEN "Contact added!\n" RESET);
}

void show_contacts() {
    if (count == 0) {
        printf(RED "Book is empty!\n" RESET);
        return;
    }
    for (int i = 0; i < count; i++) {
        printf(CYAN "%d. " RESET, i + 1);
        printf("%s — %s\n", book[i].name, book[i].phone);
    }
}

int main() {
    int choice;

    header();

    do {
        divider();
        printf(BOLD " MAIN MENU\n" RESET);
        printf(YELLOW " 1 - add contact\n" RESET);
        printf(YELLOW " 2 - show all contacts\n" RESET);
        printf(YELLOW " 0 - quit\n" RESET);
        printf(CYAN " Press : " RESET);
        scanf("%d", &choice);
        divider();

        if (choice == 1)      add_contact();
        else if (choice == 2) show_contacts();
        else if (choice != 0) printf(RED "No!\n" RESET);

    } while (choice != 0);

    printf(GREEN "Bye <3!\n" RESET);
    return 0;
}
