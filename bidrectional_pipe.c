#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
    int fd1[2],fd2[2]; //fd1 parent fd2 child
    pipe(fd1);
    pipe(fd2);
    char message1[] = "Hello from child";
    char message2[] = "Hello from parent";

    pid_t pid = fork();

    if(pid>0) { //parent can read and write 
        close(fd1[0]);
        close(fd2[1]);
        //can write
        printf("Parent added string to pipe1\n");
        write(fd1[1],message2,sizeof(message2));
        close(fd1[1]);
        //can read
        char buffer[100];
        read(fd2[0],buffer,sizeof(buffer));
        printf("Parent read string ->  %s  in pip2\n",buffer);
        close(fd2[0]);
    }

    else if(pid == 0) { //child also can read and write
        close(fd1[1]);
        close(fd2[0]);
        printf("child wrote string into buffer\n");
        write(fd2[1],message1,sizeof(message1));
        close(fd2[1]);
        char str[100];
        read(fd1[0],str,sizeof(str));
        printf("child read %s  from buffer too\n",str);
        close(fd1[0]);
    }

    return 0;
}