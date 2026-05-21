#include <stdio.h>
#include <string.h>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

struct Task {
    char title[100];
    int done;
};

struct Task tasks[100];
int count = 0;

void header() {
    printf(CYAN BOLD);
    printf("[================]\n");
    printf("|  Task Manager  |\n");
    printf("|   by xmdie     |\n");
    printf("[================]\n");
    printf(RESET);
}

void divider() {
    printf(CYAN "──────────────────\n" RESET);
}

void add_task() {
    printf(YELLOW "Task: " RESET);
    scanf(" %[^\n]", tasks[count].title);
    tasks[count].done = 0;
    count++;
    printf(GREEN "Task added!\n" RESET);
}

void show_tasks() {
    if (count == 0) {
        printf(RED "No tasks!\n" RESET);
        return;
    }
    for (int i = 0; i < count; i++) {
        if (tasks[i].done == 1)
            printf(GREEN "%d. [x] %s\n" RESET, i + 1, tasks[i].title);
        else
            printf(RED "%d. [ ] %s\n" RESET, i + 1, tasks[i].title);
    }
}

void complete_task() {
    show_tasks();
    if (count == 0) return;
    printf(YELLOW "Task number: " RESET);
    int num;
    scanf("%d", &num);
    if (num < 1 || num > count) {
        printf(RED "Wrong number!\n" RESET);
        return;
    }
    tasks[num - 1].done = 1;
    printf(GREEN "Done!\n" RESET);
}

int main() {
    int choice;

    header();

    do {
        divider();
        printf(BOLD " MAIN MENU\n" RESET);
        printf(YELLOW " 1 - add task\n" RESET);
        printf(YELLOW " 2 - show tasks\n" RESET);
        printf(YELLOW " 3 - complete task\n" RESET);
        printf(YELLOW " 0 - quit\n" RESET);
        printf(CYAN " Press: " RESET);
        scanf("%d", &choice);
        divider();

        if (choice == 1)      add_task();
        else if (choice == 2) show_tasks();
        else if (choice == 3) complete_task();
        else if (choice != 0) printf(RED "Wrong!\n" RESET);

    } while (choice != 0);

    printf(GREEN "Bye! <3\n" RESET);
    return 0;
}
