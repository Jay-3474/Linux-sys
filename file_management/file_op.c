#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <strings.h>
#include <string.h>

int main()
{
	int fd;
	char buffer[100];
	const char *text = "Hello, Linux System Programming!";
	
	// 1. open and create a file
	fd = open("data", O_RDWR | O_CREAT, 0664);
	//fd = create("data", 0664);
	if(fd < 0)
	{
		perror("open");
		return 1;
	}
	printf("fd  = %d\n", fd);
	
	// 2. Write data to the file
    	if (write(fd, text, strlen(text)) == -1)
    	{
        	perror("write");
        	close(fd);
        	return 1;
    	}

    	// Move file pointer back to the beginning to read what we just wrote
    	lseek(fd, 0, SEEK_SET);

    	// 3. Read data from the file
    	ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    	if (bytesRead == -1)
    	{
        	perror("read");
        	close(fd);
        	return 1;
    	}

    	buffer[bytesRead] = '\0'; // Null-terminate the string
    	printf("Data read from file: %s\n", buffer);

    	// 4. Close the file descriptor
    	if (close(fd) == -1)
    	{
        	perror("close");
        	return 1;
    	}
	
	//bzero(s, sizeof(s));
	
	return 0;
}
