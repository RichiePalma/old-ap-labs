#include <stdio.h>

int main() {
	
  char prevChar;
  char currentChar;
  char nextChar;
  
	while ((currentChar = getchar()) != EOF) {	//Read from console
	  
		if (currentChar == '"') {
		
		putchar(prevChar = currentChar); 
      
		while ((currentChar = getchar()) != '"') {
			putchar(prevChar = currentChar);
		}
		putchar(prevChar = currentChar);
		} 
    
		else if (currentChar == '/') {		//Detects first slash
			nextChar = getchar();
			if (nextChar == '/') {		// Second slash, hence all the line is ignored 
					putchar('\n');		
			} 
			else if (nextChar == '*') {  //Start of comment block 
				prevChar = getchar();
				while ((currentChar = getchar()) != '/' || prevChar != '*') { //End of comment block if false
					prevChar = currentChar;
				}
			}
			else {
				putchar(currentChar);
				putchar(prevChar = nextChar);
			}
		} 
    
		else {
			putchar(prevChar = currentChar);
		}
	}
}
