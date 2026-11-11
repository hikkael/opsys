#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
    int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char input[500];
    ssize_t n = read(0, input, sizeof(input) - 1);
    if (n <= 0) {
        close(fd);
        return 0;
    }
    
    input[n] = '\0';

    char buffer[1000];
    snprintf(buffer, sizeof(buffer), "PID=%d: %s", getpid(), input);

    int len = strlen(buffer);

    write(fd, buffer, len);

   /*
     * O_APPEND makes it that write calls always append to end of the file.
     * The file table entry still maintains current offset position that advances
     * after each write operation, so SEEK_CUR returns the new updated offset byte position.
     */
    off_t pos = lseek(fd, 0, SEEK_CUR);

    printf("Final offset: %ld\n", (long)pos);

    close(fd);
    return 0;
}
