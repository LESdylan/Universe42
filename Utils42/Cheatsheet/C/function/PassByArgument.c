#include <stdio.h>

void passByArgument(char **str, char **str2) {
    char *temp;
    temp = *str;     // Store the value of str
    *str = *str2;    // Set str to point to the value of str2
    *str2 = temp;    // Set str2 to point to the original value of str
}

void passByValue(char *str, char *str2) {
    char *temp; 
    temp = str;      // Store the value of str
    str = str2;      // Swap the local pointer variables (does not affect original str in main)
    str2 = temp;     // Swap the local pointer variables (does not affect original str2 in main)
    // Nothing is returned, so the changes are local to the function
}

int main(void) {
    char *str = "Hi !", *str2 = "By3 !";

    // passByValue does not affect the original pointers
    passByValue(str, str2);
    printf("%s %s\n", str, str2);  // Output will be: "Hi ! By3 !"

    // passByArgument swaps the actual pointers
    passByArgument(&str, &str2);
    printf("%s %s\n", str, str2);  // Output will be: "By3 ! Hi !"

    return 0;
}