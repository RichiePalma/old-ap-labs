int infof(const char *format, ...);
int warnf(const char *format, ...);
int errorf(const char *format, ...);
int panicf(const char *format, ...);

int main()
{	
	infof("logger.c: In function ‘infof’:");
	warnf("implicit declaration of function ‘printf’");
	errorf("expected ‘;’ before ‘printf’");
	panicf("you need to restart your computer");
	return 0;
}
