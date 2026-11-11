#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
    int fd = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    const char *text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    write(fd, text, strlen(text));
    close(fd);

    fd = open("data.txt", O_RDWR);
    if (fd < 0) {
        perror("open RDWR");
        return 1;
    }

    off_t size = lseek(fd, 0, SEEK_END);
    printf("Initial size: %ld\n", (long)size);

    if (ftruncate(fd, 10) < 0) {
        perror("ftruncate");
        close(fd);
        return 1;
    }

    size = lseek(fd, 0, SEEK_END);
    printf("Truncated size: %ld\n", (long)size);

    lseek(fd, 0, SEEK_SET);

    char buf[64];
    ssize_t n = read(fd, buf, sizeof(buf) - 1);
    if (n >= 0) {
        printf("Content: %s\n", buf);
    }

    close(fd);
    return 0;
}
