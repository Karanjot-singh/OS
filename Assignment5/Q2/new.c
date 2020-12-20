    #include <stdio.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <unistd.h>
    
    int main(int argc, char *argv[])
    {
    	                 /* l_type   l_whence  l_start  l_len  l_pid   */
    	struct flock fl = { F_WRLCK, SEEK_SET, 0,       0,     0 };
    	int fd;
    
        fl.l_pid = getpid();
		fl.l_type = F_RDLCK;
    
    	printf("Press <RETURN> to try to get lock: ");
    	getchar();
    	printf("Trying to get lock...");
    
    	if (fcntl(fd, F_SETLKW, &fl) == -1) {
    		perror("fcntl");
    		exit(1);
    	}
    
    	printf("got lock\n");
    	printf("Press <RETURN> to release lock: ");
    	getchar();
    
    	fl.l_type = F_UNLCK;  /* set to unlock same region */
    
    	if (fcntl(fd, F_SETLK, &fl) == -1) {
    		perror("fcntl");
    		exit(1);
    	}
    
    	printf("Unlocked.\n");
    
    	close(fd);
    }
	