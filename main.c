#include <stdio.h>
#include <gtk/gtk.h>
#include <time.h>
#include <string.h>
void writting_diary() {
    char text[1000];
    int feeling;

    time_t t = time(NULL);
    struct tm *now = localtime(&t);

    printf("\n===== New Day =====\n");

    printf("Date: %d-%02d-%02d\n",
           now->tm_year + 1900,
           now->tm_mon + 1,
           now->tm_mday);

    printf("\nHow are you feeling?\n");
    printf("1 - Happy\n");
    printf("2 - Sad\n");
    printf("3 - Angry\n");
    printf("4 - Excited\n");
    printf("5 - Neutral\n");
    printf("Choice: ");

    scanf("%d", &feeling);

    const char *feeling_name;

    switch (feeling) {
        case 1:
            feeling_name = "Happy";
            break;
        case 2:
            feeling_name = "Sad";
            break;
        case 3:
            feeling_name = "Angry";
            break;
        case 4:
            feeling_name = "Excited";
            break;
        case 5:
            feeling_name = "Neutral";
            break;
        default:
            printf("Invalid feeling choice.\n");
            return;
    }

    getchar();

    printf("\nWrite your diary:\n");
    printf("> ");
    fgets(text, sizeof(text), stdin);

    FILE *fp = fopen("diary.txt", "a");

    if (fp == NULL) {
        printf("Error opening diary.txt\n");
        return;
    }

    fprintf(fp, "[%d-%02d-%02d]\n",
            now->tm_year + 1900,
            now->tm_mon + 1,
            now->tm_mday);

    fprintf(fp, "Feeling: %s\n", feeling_name);
    fprintf(fp, "%s", text);
    fprintf(fp, "-------------------------\n");

    fclose(fp);

    printf("\nDiary saved successfully!\n");
}
void history() {

}
void search() {

}
void categories() {
    int choice;
    const char *selected_feeling;

    while (1) {
        printf("\n===== Categories =====\n");
        printf("1 - Happy\n");
        printf("2 - Sad\n");
        printf("3 - Angry\n");
        printf("4 - Excited\n");
        printf("5 - Neutral\n");
        printf("6 - Back\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number from 1 to 6.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 6) {
            return;
        }

        switch (choice) {
            case 1:
                selected_feeling = "Happy";
                break;
            case 2:
                selected_feeling = "Sad";
                break;
            case 3:
                selected_feeling = "Angry";
                break;
            case 4:
                selected_feeling = "Excited";
                break;
            case 5:
                selected_feeling = "Neutral";
                break;
            default:
                printf("Wrong Choice. Please choose one of the options above.\n");
                continue;
        }

        FILE *fp = fopen("diary.txt", "r");

        if (fp == NULL) {
            printf("No diary entries found.\n");
            continue;
        }

        char line[1000];
        char current_diary[5000] = "";
        int matching = 0;
        int found = 0;

        while (fgets(line, sizeof(line), fp) != NULL) {
            if (strncmp(line, "[", 1) == 0) {
                current_diary[0] = '\0';
                matching = 0;
            }

            if (strstr(line, "Feeling: ") != NULL) {
                if (strstr(line, selected_feeling) != NULL) {
                    matching = 1;
                    found = 1;
                }
            }

            if (matching) {
                strcat(current_diary, line);
            }

            if (strncmp(line, "-------------------------", 25) == 0 && matching) {
                printf("\n%s", current_diary);
                current_diary[0] = '\0';
                matching = 0;
            }
        }

        fclose(fp);

        if (!found) {
            printf("\nNo diaries found in the %s category.\n", selected_feeling);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Marco Polo's Diary =====\n");
        printf("1 - New Day\n");
        printf("2 - History\n");
        printf("3 - Search\n");
        printf("4 - Categories\n");
        printf("5 - Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 1) {
            writting_diary();
        }
        else if (choice == 2) {
            history();
        }
        else if (choice == 3) {
            search();
        }
        else if (choice == 4) {
            categories();
        }
        else if (choice == 5) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Wrong Choice. Please choose one of the options above.\n");
        }
    }

    return 0;
}