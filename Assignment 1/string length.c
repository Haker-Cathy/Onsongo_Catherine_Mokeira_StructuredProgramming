#include <stdio.h>
#include <string.h>

int main(){
    char s[256];
    printf("Enter a string (max 255 chars): ");

    // use fgets to allow spaces
    if (!fgets(s, sizeof(s), stdin)) {
        printf("Error reading input\n");
        return 1;
    }
    //remove trailing newline if present
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n'){
        s[len-1] = '\0';
        len--;
    }
    printf("You entered: %s\n", s);
    printf("Length: %zu\n", len);
    return 0;
}



