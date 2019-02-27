#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>


#define SIZE_BUF 64

// Ricardo Palma A01226922
/* Sources:
 *			http://codewiki.wikidot.com/c:system-calls:open 
 * 		http://codewiki.wikidot.com/c:system-calls:read
 * 		http://codewiki.wikidot.com/c:system-calls:write
 * 		http://codewiki.wikidot.com/c:system-calls:close
 */


int main(int argc, char *argv[]){
	int file;
	file = open(argv[1], O_RDONLY);	
	char *buffer;
	buffer = calloc(SIZE_BUF, sizeof(char)); 
	int  lines = 0;
	

	if(file < 0){
		write(2, "Error: Couldn't read file.\n'", SIZE_BUF);
	}
	while(read(file, buffer, SIZE_BUF -1) != 0){
			write(1, buffer, SIZE_BUF);
			int i = 0;
			for(i = 0; i < SIZE_BUF; i++){
				if(buffer[i] == '\n'){
					lines++;
					break;
				}
			}
			// lseek formula ferpart
			//~ int jump = (i*sizeof(char)-strlen(buffer)*sizeof(char))+1;
			//~ lseek(file, jump , SEEK_CUR);
		//	buffer[0] = '\0';
			memset(buffer, '\0', SIZE_BUF*sizeof(char));
	}
	//memset(buf, '\0', SIZE_BUF);
	buffer[SIZE_BUF] = '\0';
	printf("Number of lines %i \n",lines);

	close(file);
}

// -------------------------------- withot syscalls -----------------------------------------------------------

//~ int main(int argc, char *argv[]){
	//~ FILE *fp;
	//~ char *buffer; 
	//~ buffer = calloc(SIZE_BUF, sizeof(char));
	//~ int lines = 0;
	//~ int ch = 0;
	
	//~ if(argc != 2){
		//~ printf("Only one argument is accepted. Example:  ./cross-ref file.txt \n");
	//~ }
	//~ else{
		//~ fp = fopen(argv[1], "r");
		//~ if(fp == NULL){
			//~ write(2, "Error: Couldn't read file.\n", SIZE_BUF);
		//~ }
		//~ //while(!feof(fp)){
		//~ while(!feof(fp)){
			//~ ch = fgetc(fp);
			//~ printf("%c", ch);
			//~ if(ch == '\n'){
				//~ lines++;
			//~ }
		//~ }
		//~ printf("%i\n", lines);
		//~ fwrite(buffer, SIZE_BUF, 1, fp);
		//~ fseek(fp, 0, SEEK_SET);
		//~ fread(buffer, strlen(buffer)+1, 1, fp);
	//~ }
		
		//~ fclose(fp);
//~ }
