#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#endif

/**
 * 复制文件
 * @param src 源文件路径
 * @param dst 目标文件路径
 * @return 0表示复制成功，-1表示复制失败
 */
int copy_file(const char* src, const char* dst){
#ifdef _WIN32
    // 使用Windows API函数CopyFileA()复制文件
    if(!CopyFileA(src, dst, FALSE)){
        fprintf(stderr, "复制失败, 错误码: %lu\n", GetLastError());
        return -1;
    }
#else
    // 使用POSIX API函数open()、read()和write()复制文件
    int in_fd = open(src, O_RDONLY);
    if(in_fd < 0){
        perror("无法打开源文件");
        return -1;
    }

    int out_fd = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(out_fd < 0) {
        perror("无法创建目标文件");
        close(in_fd);
        return -1;
    }

    char buffer[4096];
    ssize_t n;
    while((n = read(in_fd, buffer, sizeof(buffer))) > 0) {
        if(write(out_fd, buffer, n) != n) {
            perror("写入错误");
            close(in_fd);
            close(out_fd);
            return -1;
        }
    }

    close(in_fd);
    close(out_fd);
#endif
    return 0;
}

int main(){
    char src[256], dst[256];
    printf("请输入源文件路径: ");
    scanf("%255s", src);
    printf("请输入目标文件路径: ");
    scanf("%255s", dst);

    if(copy_file(src, dst) == 0) {
        printf("文件复制成功！\n");
    } else {
        printf("文件复制失败。\n");
    }
    return 0;
}