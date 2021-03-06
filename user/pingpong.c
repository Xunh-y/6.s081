#include "kernel/types.h"
#include "user/user.h"

int main (int argc, char *argv[]) {
    int par_fd[2], child_fd[2];
    char buf[64];
    pipe(par_fd);
    pipe(child_fd);
    if (fork() == 0) {
        read(par_fd[0], buf, 4);
        printf("%d: received %s\n", getpid(), buf);
        write(child_fd[1], "pong", 4);
    } else {
    	write(par_fd[1], "ping", 4);
    	read(child_fd[0], buf, 4);
    	printf("%d: received %s\n", getpid(), buf);
    }
    exit(0);
}
