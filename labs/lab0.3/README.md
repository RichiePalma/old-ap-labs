
## [exercise-slices.go](https://github.com/RichiePalma/ap-labs/blob/master/labs/lab0.3/exercise-slices.go)
### Problem (Retrieved from [Golang](https://tour.golang.org/moretypes/18))

Implement Pic. It should return a slice of length *dy*, each element of which is a slice of dx 8-bit unsigned integers. When you run the program, it will display your picture, interpreting the integers as grayscale (well, bluescale) values.

The choice of image is up to you. Interesting functions include (x+y)/2, x*y, and x^y.

(You need to use a loop to allocate each *[]uint8* inside the *[][]uint8*.)

(Use *uint8(intValue)* to convert between types.) 

### How it works

We start by creating an array of length dy then loop through it creating another array size dx within each index. 

```go
matrix := make([][]uint8, dy)
for i := range matrix{
  matrix[i] = make([]uint8, dx)
}
 ```
 
 Within the same for loop we now iterate through the arrays of dx size in order to apply the function x*y. 
 
 ```go 
for j := range matrix[i]{ 
	matrix[i][j] = uint8(i * j)
}
```

### How to test it

You can either run it from any shell with ```go run exercise-slices.go``` or use [The Go Playground](https://play.golang.org/).

<br>
<br>

## [exercise-maps.go](https://github.com/RichiePalma/ap-labs/blob/master/labs/lab0.3/exercise-maps.go)
### Problem (Retrieved from [Golang](https://tour.golang.org/moretypes/23))

Implement *WordCount*. It should return a map of the counts of each “word” in the string *s*. The *wc*.Test function runs a test suite against the provided function and prints success or failure.

You might find [strings.Fields](https://golang.org/pkg/strings/#Fields) helpful.

### How it works

Using the *Fields* method from strings, the software is able to split the text in words whenever it finds a blank space between characters. In this way one can loop through the string and save each *word* as a key within the *Map m* then give each Key a value of how many times was it found in the string. 

```go
for _, word := range strings.Fields(s){
	m[word] += 1
}
```
### How to test it

You can either run it from any shell with ```go run exercise-maps.go``` or use [The Go Playground](https://play.golang.org/).
