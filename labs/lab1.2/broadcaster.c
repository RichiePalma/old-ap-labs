#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv){
	
	int sizeText = 0;
	
	for(int i = 1; i < argc ; i++){
		sizeText += strlen(argv[i]) + 1; 	// +1 due to blankspaces
	}
	
	char text [sizeText];
	text[0] = '\0';
	for(int i = 1; i < argc; i++){
		strcat(text,argv[i]);
		strcat(text," ");
	}
	text[sizeText - 1 ] = '\n';
	 
	struct dirent *broadCastDir;
	const char *path = "/dev/";
	const int pathlength = strlen(path);
	DIR *dir;
	dir = opendir(path);
	
	char *pathpts;
	size_t c, len;
	int flag = 0;
	int fd;
	int i = 0;
	while ((broadCastDir = readdir(dir)) != NULL) {
		len = strlen(broadCastDir->d_name);

		for (c = broadCastDir->d_name[i]; i < len; i++) {
			if (isdigit(c) != 0) {
				continue;
			} else {
				flag = -1;
				break;
			}
		}
		if (flag == -1) {
			flag = 0;
			continue;
		}

		for (c = broadCastDir->d_name[i]; i < len; i++) {
			if (isdigit(c) != 0) {
				continue;
			} else {
				flag = -1;
				break;
			}
		}
		if (flag == -1) {
			flag = 0;
			continue;
		}

		if ((pathpts =
		     calloc((strlen(broadCastDir->d_name) + pathlength) + 1,
			    sizeof(char))) == NULL) {
			perror("Error calloc: ");
		} else {
			pathpts[0] = '\0';
			strcat(pathpts, path);
			strcat(pathpts, broadCastDir->d_name);
		}

		fd = open(pathpts,  O_NOCTTY );
		if (fd == -1) {
			perror("Error file descriptor: ");
		}
		write(fd, text, sizeText);
		close(fd);
	}

	closedir(dir);
	return EXIT_SUCCESS;

}
