#include <stdio.h>
#include <emscripten.h>
//nodefs.cc
void setup_nodefs() {
    EM_ASM(
        FS.mkdir('/data');
        FS.mount(NODEFS, {root:'.'}, '/data');
    );
}

int main() {
    setup_nodefs();

    FILE* fp = fopen("/data/nodefs_data.txt", "r+t");
    if (fp == NULL) fp = fopen("/data/nodefs_data.txt", "w+t");
    int count = 0;
    if (fp) {
        fscanf(fp, "%d", &count);
        count++;
        fseek(fp, 0, SEEK_SET);
        fprintf(fp, "%d", count);
        fclose(fp);
        printf("count:%d\n", count);
    }
    else {
        printf("fopen failed.\n");
    }

    return 0;
}
