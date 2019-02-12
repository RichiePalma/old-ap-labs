## Lab 1.1 - mycat

### Problem (Retrieved from Professor Obed N Munoz [Github Repository](https://github.com/CodersSquad/ap-labs/tree/master/labs/lab1.1))

- Rewrite the cat.c program by using ```read```, ```write```, ```open``` and ```close``` instead of their library equivalents.
- Generate a report with performance metrics between the existing ```cat.c``` and your ```mycat.c```.

### How it works

This simple software implements the use of system calls. As simple as opening a file that was submited as parameter in console. 

```C
  file = open(argv[1], O_RDONLY);	
```

The ```open``` syscall will return a number depending if the software was able to find the file. If it is negative or equal to 0 it should 
return an standar error with code 2; otherwise, the ```read``` syscall will start buffering until there is no more characters left.
```C
  while(read(file, buf, SIZE_BUF -1) != 0){
			// Rest of the code
  }
```

Inside the loop, the ```write``` syscall will return the text back an standar output with code 1. It is important to add the symbol *\0* 
to the buffer, so the system call indicates the end of the file.
```C
  write(1, buf, SIZE_BUF); 
  memset(buf, '\0', SIZE_BUF);
```

### How tu run it

One can easily compile the file by running

```
gcc my cat.c
```

As the problem indicates, a benchmarking is needed to be done to compare ```mycat.c``` and ```cat.c```. 
In this case, the command ```time``` can be used.

```
time ./a.exe mycat.c
```
