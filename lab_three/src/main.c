//
// Created by dmytro on 07.10.2026.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils/safe_io.h>

#include "../include/tasks.h"

static void menu(void) {
    int choice;

    while (true) {
        puts("Select a task:");
        puts("1. Task 7");
        puts("2. Task 18");
        puts("3. Task 21");
        puts("4. Task 25");
        puts("5. Task 29");
        puts("6. Task 44");
        puts("7. Task 68");
        puts("8. Task 77");
        puts("9. Task 81");
        puts("10. Task 113");
        puts("11. Exit");
        printf("Enter choice: ");

        if (read_int(&choice) != 0) {
            printf("Invalid input. Please enter a numeric choice.\n");
            continue;
        }

        system("clear");

        switch (choice) {
            case 1: task7(); break;
            case 2: task18(); break;
            case 3: task21(); break;
            case 4: task25(); break;
            case 5: task29(); break;
            case 6: task44(); break;
            case 7: task68(); break;
            case 8: task77(); break;
            case 9: task81(); break;
            case 10: task113(); break;
            case 11: return;
            default: printf("Invalid choice, please try again.\n");
        }

        puts("Press Enter to continue...");
        getchar();
        system("clear");
    }
}

int main(void) {
    system("clear");
    puts("Laboratory work #3\n");

    menu();

    return 0;
}
