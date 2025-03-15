#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid;

    // 创建一个子进程
    pid = fork();

    if(pid < 0){
        // 创建进程失败
        fprintf(stderr, "Fork failed\n");
        return 1;
    }else if(pid == 0){
        printf("Child process: PID = %d\n", getpid());
        sleep(2);
        printf("Child process: Exiting\n");
    }else{
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        wait(NULL); // 等待子进程结束
        printf("Parent process: Child process has finished\n");
    }

    return 0;
}