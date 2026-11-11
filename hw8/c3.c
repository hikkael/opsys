#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    char path[256];
    printf("Enter file path: ");
    scanf("%s", path);

    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    off_t size = lseek(fd, 0, SEEK_END);
    if (size < 0) {
        perror("lseek");
        close(fd);
        return 1;
    }

    for (off_t pos = size - 1; pos >= 0; pos--) {
        lseek(fd, pos, SEEK_SET);
        char ch;
        
        if (read(fd, &ch, 1) == 1) {
            write(STDOUT_FILENO, &ch, 1);
        }
    }

    write(STDOUT_FILENO, "\n", 1);
    close(fd);
    return 0;
}
