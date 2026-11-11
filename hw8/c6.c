#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
    int fd = open("numbers.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    for (int i = 1; i <= 10; i++) {
        char buf[16];
        snprintf(buf, sizeof(buf), "%d\n", i);
        write(fd, buf, strlen(buf));
    }
    close(fd);

    fd = open("numbers.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    int line_count = 1;
    off_t line4_pos = 0;
    off_t line5_pos = 0;
    off_t curr = 0;
    char ch;

    while (read(fd, &ch, 1) == 1) {
        curr++;
        if (ch == '\n') {
            line_count++;
            if (line_count == 4) {
                line4_pos = curr;
            } else if (line_count == 5) {
                line5_pos = curr;
                break;
            }
        }
    }

    off_t file_end = lseek(fd, 0, SEEK_END);
    int remainder_len = file_end - line5_pos;
    char remainder[24];

    lseek(fd, line5_pos, SEEK_SET);
    read(fd, remainder, remainder_len);

    lseek(fd, line4_pos, SEEK_SET);
    write(fd, "100\n", 4);
    write(fd, remainder, remainder_len);

    lseek(fd, 0, SEEK_SET);
    char out[24];
    ssize_t n;
    while ((n = read(fd, out, sizeof(out))) > 0) {
        write(1, out, n);
    }

    close(fd);
    return 0;
}
