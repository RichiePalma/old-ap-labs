## Challenge 2 First Term Exam
### Problem 1: DMESG Analyzer. (Retrieved from Professor Obed N Muñoz [Github Repository](https://github.com/CodersSquad/ap-labs/blob/master/challenges/chal2/dmesg-analyzer.md))
---
Implement a system log analyzer and classifier for GNU/Linux. In this particular case, a sample log output file is provided. It's highly recommended to implement this challenge in a Linux-based operating system. This challenge involves a proper struct design choice for the logs classification and storing.

### Requirements
- The program must be implemented in C programming language.
- You program will classify log entries by the ```<log_type>:``` prefix
- Those log entries that don't follow the ```<log_type>:``` convention will go to the General classification.
- Repeated log classes are not allowed.
- Use the ```dmesg-analyzer.c``` template
- The solution must use at least 3 of the following system calls:
  - ```open()```
  - ```read()```
  - ```write()```
  - ```lseek()```
  - ```close()```
- You need to follow the output format guidelines.
- Coding best practices that we learned in class will be reviewed.
- Before submitting you code, make sure it's compiling and running correctly.

### Sample Execution

```./dmesg-analizer.o dmesg.txt```

### Sample Expected output file ```dmesg_report.txt```

```
General:
  [    0.000000] Linux version 4.15.0-45-generic (buildd@lgw01-amd64-031) (gcc version 7.3.0 (Ubuntu 7.3.0-16ubuntu3)) #48-Ubuntu SMP Tue Jan 29 16:28:13 UTC 2$
Command line:
  [    0.000000] BOOT_IMAGE=/boot/vmlinuz-4.15.0-45-generic root=UUID=d67ab183-f0e2-4bb6-8270-ad35088cef7a ro splash quiet
KERNEL supported cpus:
  [    0.000000]   Intel GenuineIntel
  [    0.000000]   AMD AuthenticAMD
  [    0.000000]   Centaur CentaurHauls
x86/fpu:
  [    0.000000] Supporting XSAVE feature 0x001: 'x87 floating point registers'
  [    0.000000] Supporting XSAVE feature 0x002: 'SSE registers'
  [    0.000000] Supporting XSAVE feature 0x004: 'AVX registers'
  [    0.000000] xstate_offset[2]:  576, xstate_sizes[2]:  256
  [    0.000000] Enabled xstate features 0x7, context size is 832 bytes, using 'standard' format.
pci_bus 0000:00:
  [    0.032806] root bus resource [io  0x0000-0x0cf7 window]
  [    0.032808] root bus resource [io  0x0d00-0xffff window]
  [    0.032809] root bus resource [mem 0x000a0000-0x000bffff window]
  [    0.032810] root bus resource [mem 0x80000000-0xfdffffff window]
  [    0.032812] root bus resource [bus 00-ff]
Zone ranges:
  [    0.000000]   DMA      [mem 0x0000000000001000-0x0000000000ffffff]
  [    0.000000]   DMA32    [mem 0x0000000001000000-0x000000007ffeffff]
  [    0.000000]   Normal   empty
  [    0.000000]   Device   empty
```

### Test Cases
The program will be tested with the following cases:

1. [dmesg.txt](https://github.com/RichiePalma/ap-labs/blob/master/challenges/chal2/dmesg.txt)

``` ./dmesg-analyzer.o dmesg.txt ```

### How to run it

Compile the program by executing

``` gcc dmesg-analyzer.c -o dmesg-analyzer.o ```

And run it, simply by executing

``` ./dmesg-analyzer.o dmesg.txt ``` 

Where the parameter ```dmesg.txt``` is the text file to test.

### Problem 2: Directory Scanner (Retrieved from Professor Obed N Muñoz [Github Repository](https://github.com/CodersSquad/ap-labs/blob/master/challenges/chal2/directory-scanner.md))
---

Implement a directory scanner tool for any given path. It's highly recommended to implement it for a UNIX-based machine.

### Requirements
- The program must be implemented in Golang programming language.
- Given one path, the program must count the following file's types:
  - Directories
  - Symbolic Links
  - Others
- Use the provided template dir-scan.go
- Repeated log classes are not allowed.
- You need to follow the output format guidelines.
- Coding best practices that we learned in class will be reviewed.
- Before submitting you code, make sure it's compiling and running correctly.
### Sample Execution
``` ./directory-scanner /tmp ```

### Sample Expected output

```
Directory Scanner Tool
+-------------------------+------+
| Path                    | /tmp |
+-------------------------+------+
| Directories             | 10   |
| Symbolic Links          | 5    |
| Other files             | 50   |
+-------------------------+------+
```

### Test Cases

The program will be tested with the following cases:

1. ```/tmp``` directory

```./directory-scanner /tmp```

2. ```/etc``` directory

```./directory-scanner /etc```

3. ```/usr/lib```  directory

```./directory-scanner /usr/lib```

### Useful links
- https://golang.org/pkg/os/#Lstat
- https://golang.org/pkg/path/filepath/#Walk

### How to run it

One can test the program by executing the following command:

``` go run dir-scan.go /tmp ```

Where the parameter ```/tmp``` is the path to test. 
