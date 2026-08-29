#include <stdio.h>
#include <gtk/gtk.h>

void writting_diary() {


}
void history() {

}
void search() {

}
void categories() {

}

int main() {
    int choice,return_value= 1;
    while (return_value != 0) {
        return_value = 0;
        printf("1-New Day\n");
        printf("2-History\n");
        printf("3-Search\n");
        printf("4-Categories\n");
        printf("5-Exit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        if (choice == 1) {
            writting_diary();
            return_value=0;
        }
        else if (choice == 2) {
            history();
            return_value=0;
        }
        else if (choice == 3) {
            search();
            return_value=0;
        }
        else if (choice == 4) {
            categories();
            return_value=0;
        }
        else if (choice == 5) {
            printf("Exiting...\n");
            return_value=0;
            exit(0);
        }
        else {
            return_value = 1;
            printf("Wrong Choice\n");
        }
    }
        return 0;
}