/*
 * File: WriteArguments.c
 * Author: Kiki Su
 * Created: 2026-01-28 10:37
 * Description: Loop and write each of its arguments.
 */

#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s file1 file2...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "w");
        if (!fp) {
            perror("fopen");
            return 1;
        }

        char buffer[1024];
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            fclose(fp);
            return 1;
        }

        fprintf(fp, "%s", buffer);
        fclose(fp);
    }

    return 0;
}
