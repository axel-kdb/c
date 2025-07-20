#include <stdio.h>
#include <string.h>

int checkfile(FILE *pfile) {
    if (pfile == NULL) {
        printf("Error opening file!\n");
    return 1;
    }
}

int main() {
    
    FILE *pfile = fopen("test.txt", "a+");

    checkfile(pfile);

    printf("Enter a string: ");
    char content[100] = {0};
    fgets(content, sizeof(content), stdin);
    content[strcspn(content, "\n")] = 0;
    fprintf(pfile, "%s\n", content);

    printf("Do you want to display the file content? (Y) or (N): ");
    char choice = 0;
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        rewind(pfile);
        char line[100];
        while (fgets(line, sizeof(line), pfile)) {
            printf("%s", line);
        }
    }
    else if (choice == 'N' || choice == 'n') {
        printf("You chose not to display the file content.\n");
    }
    else {
        printf("Invalid choice.\n");
    }

    fclose(pfile);

    return 0;

}
