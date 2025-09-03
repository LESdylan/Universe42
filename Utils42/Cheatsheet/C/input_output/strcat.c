#include <stdio.h>
#include <string.h>

char *cat(char *str, const char *str2) {
    int size_str = strlen(str);
    int size_str2 = strlen(str2);
    int i = 0;

    // Append str2 to str
    while (i <= size_str2) {
        str[size_str + i] = str2[i];
        i++;
    }

    // Null-terminate the concatenated string
    str[size_str + i] = '\0';
    return str;
}

int main(void) {
    // Create a buffer large enough to hold the result of concatenation
    char str[100] = "hello"; // buffer for 'hello' and str2
    char *str2 = "worñd";

    // Call the cat function
    printf("%s\n", cat(str, str2));  // Output: "helloworñd"

    return 0;
}
