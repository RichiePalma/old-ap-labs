## Lab 0.2 - Strings Manipulation Library

### The Problem (Retrieved from [Linking Process in C by Obed N Munoz](https://softfire-143705.appspot.com/hello-c-world/03-linking.slide#6))

Implement a library for string manipulation *strlib.c* with the following functions:
```
int strlen(char *str)
*char stradd(char *origin, char *addition)
int strfind(char *origin, char *substr)
```

Call all functions from *strlib.c* library in a new str-main.c file
Use the following commands for compilation and linking

```
gcc -c str-main.c -o str-main.o
gcc -c strlib.c -o strlib.o
gcc str-main.o strlib.o -o str-final.o
```
Your program needs to support the following arguments. Check the expected output:

```
./str-final.o originalVeryLongString Addition Add
Initial Lenght      : 22
New String          : originalVeryLongStringAddition
SubString was found : yes
```
