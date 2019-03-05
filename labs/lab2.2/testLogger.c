int infof(const char *format, ...);
int warnf(const char *format, ...);
int errorf(const char *format, ...);
int panicf(const char *format, ...);

int main()
{	
	infof("logger.c: In function ‘infof’:\n");
	warnf("implicit declaration of function ‘printf'\n");
	errorf("%s expected ‘;’ before ‘printf’\n", "Line 36 test.c");
	panicf("you need to restart your computer\n");
	return 0;
}
