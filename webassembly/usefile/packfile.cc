#include <stdio.h>
int main() {
    FILE* fp = fopen("hello.txt", "rt");
    if (fp) {
        while (!feof(fp)) {
            char c = fgetc(fp);
            if (c != EOF) {
                putchar(c);
            }
        }
        fclose(fp);
    }
    return 0;
}
