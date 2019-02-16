#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define SIZE_BUF 256
#define SIZE_LOGTYPE 50
#define REPORT_FILE "report.txt"

void analizeLog(char *logFile, char *report);

int main(int argc, char **argv) {

    if (argc < 2) {
	printf("Usage:./dmesg-analizer.o logfile.txt\n");
	return 1;
    }

    analizeLog(argv[1], REPORT_FILE);

    return 0;
}

void analizeLog(char *logFile, char *report) {
    printf("Generating Report from: [%s] log file\n", logFile);

   	int file;
	file = open(logFile, O_RDONLY);	
	char buf[SIZE_BUF]; 	// A character array where the read content will be stored.
	char logTypes[SIZE_LOGTYPE];
	
	if(file < 0){
		write(2, "Error: Couldn't read file.\n'", SIZE_BUF);
	}
	
	while(read(file, buf, (SIZE_BUF -1)) != 0){
		for(int i = 0; i < SIZE_BUF; i++){
			if(buf[i] != '\n') {	//Else is end of line
					logTypes[i] 	= buf[i];
					if(buf[i]==':' && buf[i+1] ==' ' || buf[i+1] =='\n'){
						printf("%s\n", logTypes);
						break;
					}
			}
			else{
				lseek(file, SIZE_BUF ,SEEK_CUR);
				memset(logTypes, '\0', SIZE_LOGTYPE);  //End of line
				break;
			}
		}
	}
			


	close(file);

    printf("Report is generated at: [%s]\n", report);
}
