//
// Created by dmytro on 05.11.2026.
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
        puts("1. Task 18");
        puts("2. Task 25");
        puts("3. Task 44");
        puts("4. Task 80");
        puts("5. Task 81");
        puts("6. Task 142");
        puts("7. Task 177");
        puts("8. Task 186");
        puts("9. Task 233");
        puts("10. Task 249");
        puts("11. Exit");
        printf("Enter choice: ");

        if (read_int(&choice) != 0) {
            printf("Invalid input. Please enter a numeric choice.\n");
            continue;
        }

        system("clear");

        switch (choice) {
            case 1: task18(); break;
            case 2: task25(); break;
            case 3: task44(); break;
            case 4: task80(); break;
            case 5: task81(); break;
            case 6: task142(); break;
            case 7: task177(); break;
            case 8: task186(); break;
            case 9: task233(); break;
            case 10: task249(); break;
            case 11: return;
            default: printf("Invalid choice, please try again.\n");
        }

        puts("Press Enter to continue...");
        getchar();
        system("clear");
    }
}

int main(void) {
    menu();

    return 0;
}
