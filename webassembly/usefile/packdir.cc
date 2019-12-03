#include <stdio.h>

void read_fs(const char* fname) {
    FILE* fp = fopen(fname, "rt");
    if (fp) {
        while (!feof(fp)) {
            char c = fgetc(fp);
            if (c != EOF) {
                putchar(c);
            }
        }
        fclose(fp);
    }
}

void write_fs() {
    FILE* fp = fopen("t3.txt", "wt");
    if (fp) {
        fprintf(fp, "This is t3.txt.wo ca...\n");
        fclose(fp);
    }
}

int main() {
    read_fs("dat_dir/t1.txt");
    read_fs("dat_dir/t2.txt");
    read_fs("dat_dir/sub_dir/t3.txt");

    write_fs();
    read_fs("t3.txt");
    return 0;
}
