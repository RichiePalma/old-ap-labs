## Problem

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 


Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.


Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

## How the software works

### Input

At this version of the software the input string has to be changed directly in the code at line 5 where variable 'input' is declared.

### Output

The software will return the length of the longest substring found in the input string.

### Compilation & Execution

The current version runs as a simple Java file. So, it can either be compiled and executed by javac and java commands or by the use of a compiler that is compatible with Java. 

### How it works

The software consists in a double loop where it will compare the characters of the input string and the current substring in such way that it will look if the current character of input string looped is found or not in the current substring.

If current character is not in the substring, it will be concatenaded. Else, the substring will be restarted as only the currect char looped.

In this way each loop starts in the character that broke the sequence, so it doesn't loop through the whole input string from the start.


