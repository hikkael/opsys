#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    int fd = open("sparse.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    char *start = "START";
    write(fd, "START", 5);
    lseek(fd, 1024 * 1024, SEEK_CUR);
    write(fd, "END", 3);
    close(fd);

    fd = open("sparse.bin", O_RDONLY);
    if (fd < 0) {
        perror("open read-only");
        return 1;
    }

    off_t size = lseek(fd, 0, SEEK_END);
    printf("Apparent size: %ld bytes\n", (long)size);
    close(fd);

    /*
     * du (disk usage) shows allocated physical disk blocks, while lseek shows the logical size.
     * The file system creates a file hole of unwritten space between "START" and "END",
     * allocating physical disk blocks only for the written bytes.
     */
    return 0;
}
