#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    char src_path[256];
    char dst_path[256];

    printf("Enter source file path: ");
    scanf("%s", src_path);

    printf("Enter destination file path: ");
    scanf("%s", dst_path);
    
    int src_fd = open(src_path, O_RDONLY);
    if (src_fd < 0) {
        perror("open source");
        return 1;
    }

    int dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd < 0) {
        perror("open destination");
        close(src_fd);
        return 1;
    }

    char buffer[1024];
    int total_bytes = 0;

    ssize_t bytes_read;

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        ssize_t bytes_written = write(dst_fd, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("write error");
            close(src_fd);
            close(dst_fd);
            return 1;
        }
        total_bytes += bytes_written;
    }

    if (bytes_read < 0) {
        perror("read failed");
        close(src_fd);
        close(dst_fd);
        return 1;
    }

    close(src_fd);
    close(dst_fd);

    printf("Total bytes copied: %d\n", total_bytes);
    return 0;
}
