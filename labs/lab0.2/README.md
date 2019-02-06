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
### How it works

``` int strlen(char *str)``` will have the simple task to count the number of characters in a string. So, this method will take care of looping throught the string while keeping a counter until it finds a symbol which indicates the end of the string.

```go
int strlen(char *str){ 

  int i = 0;
  int count = 0;
  while(str[i] != '\0'){
    count++;
    i++;
  }
  return count;
}
```
``` char* stradd(char *origin, char *addition) ```has the task to concatenate two strings. Since the concatenation of string origin and string addition is the size total from the sum of A & B sizes, one can allocate memory of such size. 

```go
  int totalLength = strlen(origin) + strlen(addition);
  char *newString = (char *)malloc(totalLength+1);
```

Then the software iterates through each of the strings, adding each character to the right index in the new string. With both loops, origin & addition are successfuly concatenated. It is important to add the escape symbol into the new character, so a buffer can tell the end of the string.

```go
  int i = 0;
  int j = 0;
  while(origin[i] != '\0'){
    newString[j] = origin[i];
    i++;
    j++;
  }

  i = 0;

  while(addition[i] != '\0'){
    newString[j] = addition[i];
    i++;
    j++;
  }

  newString[j] = '\0';
```

Finally, ```int strfind(char *origin, char *substr)``` takes care of telling if string substr is a substring of string origin. The software will loop through *origin* as it finds the first character of *substr*

```go
  int i = 0;
  while(origin[i] != '\0'){
    int j = 0;
    if(origin[i] == substr[j]){
      // Rest of the code
    }
    i++;
  }
  return 0;
```

If such character is found. It will enter another loop where it will compare the rest of consecutive characters from *origin* to look if they match the rest of characters in *substr* until it matches completely; otherwise, it will break the current loop and continue to search the first character from *substr* again. It is important for the software to tell if *origin* no longer has any characters, arrived to the end of the string, while searching for the rest of *substr*'s characters, so an IndexOutOfBounds does not prompt. 

```go
while(substr[j] != '\0' && origin[i+j] != '\0'){
  if(origin[i+j] == substr[j]){
    if(j == strlen(substr) -1){
      return 1;
    }
    j++;
  }
  else{
    break;
  }
}

```
This method will return 0 if *substr* is not a substring of *origin* or 1 if it is. 

### How to run it

As mentioned in the instructions mentioned in the Problem section, *strlib.c* and *str-main.c* need to be linked in order to be executed. This can be done by writting the following:

```
gcc -c str-main.c -o str-main.o
gcc -c strlib.c -o strlib.o
gcc str-main.o strlib.o -o str-final.o
```
When executing, it is important to provide 3 arguments that will be the strings the software will be working with. This arguments follow the next format.

```
./str-final.o stringToCountCharacters stringToConcatenateIntoFirstArgument stringToMatchAsSubstring

```
