#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    char path1[500], path2[500];
    printf("Enter first file path: ");
    if (scanf("%s", path1) != 1) return 1;

    printf("Enter second file path: ");
    if (scanf("%s", path2) != 1) return 1;

    int fd1 = open(path1, O_RDONLY);
    if (fd1 < 0) {
        perror("open file 1");
        return 1;
    }

    int fd2 = open(path2, O_RDONLY);
    if (fd2 < 0) {
        perror("open file 2");
        close(fd1);
        return 1;
    }

    char c1, c2;
    off_t byte_idx = 0;

    while (1) {
        ssize_t n1 = read(fd1, &c1, 1);
        ssize_t n2 = read(fd2, &c2, 1);

        if (n1 < 0 || n2 < 0) {
            perror("error");
            close(fd1);
            close(fd2);
            return 1;
        }

        if (n1 == 0 && n2 == 0) {
            printf("Files are identical\n");
            close(fd1);
            close(fd2);
            return 0;
        }

        if (n1 != n2) {
            printf("Files differ at byte %ld\n", (long)byte_idx);
            close(fd1);
            close(fd2);
            return 1;
        }

        if (c1 != c2) {
            printf("Files differ at byte %ld\n", (long)byte_idx);
            close(fd1);
            close(fd2);
            return 1;
        }

        byte_idx++;
    }
}
