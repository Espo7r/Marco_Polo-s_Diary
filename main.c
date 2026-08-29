#include <stdio.h>
#include <gtk/gtk.h>
#include <time.h>
void writting_diary(const char *text) {
FILE *fp = fopen("diary.txt", "a");
    if (fp == NULL) {
        printf("Error opening diary.txt\n");
        exit(1);
    }
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d\n",now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
    fprintf(fp,"%s\n\n",text);

}
void history() {

}
void search() {

}
void categories() {

}

int main() {
    int choice;
    const char *text = NULL;

        printf("1-New Day\n");
        printf("2-History\n");
        printf("3-Search\n");
        printf("4-Categories\n");
        printf("5-Exit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        if (choice == 1) {
            writting_diary(&text);
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
            exit(0);
        }
        else {
            printf("Wrong Choice\n");
        }

        return 0;
}