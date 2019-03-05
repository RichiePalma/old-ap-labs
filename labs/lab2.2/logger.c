/*
 *  Reference: https://www.linuxjournal.com/article/8603
 */

#include <stdarg.h>
#include <stdio.h>

#define RESET				0
#define BRIGHT 			1
#define DIM					2
#define UNDERLINE 	3
#define BLINK				4
#define REVERSE		7
#define HIDDEN			8

#define BLACK 				0
#define RED					1
#define GREEN				2
#define YELLOW			3
#define BLUE				4
#define MAGENTA		5
#define CYAN				6
#define	WHITE			7

void textcolor(int attr, int fg, int bg);

void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}

int infof(const char *format, ...){
	textcolor(BRIGHT, WHITE, HIDDEN);
	printf("INFO: ");
	textcolor(RESET, WHITE, BLACK);
	printf("%s\n", format);
}

int warnf(const char *format, ...){
	textcolor(BRIGHT, MAGENTA, HIDDEN);
	printf("WARNING: ");
	textcolor(RESET, WHITE, BLACK);
	printf("%s\n", format);
}

int errorf(const char *format, ...){
	textcolor(BRIGHT, RED, HIDDEN);
	printf("ERROR: ");
	textcolor(RESET, WHITE, BLACK);
	printf("%s\n", format);
}

int panicf(const char *format, ...){
	textcolor(BRIGHT, YELLOW, HIDDEN);
	printf("PANIC: ");
	textcolor(RESET, WHITE, BLACK);
	printf("%s\n", format);
}
