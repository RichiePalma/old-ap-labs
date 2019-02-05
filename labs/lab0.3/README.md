
## [exercise-slices.go](exercise-slices.go)
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
 
 Within the same for we now iterate through the arrays of dx size in order to apply the function x*y. 
 
 ```go 
for j := range matrix[i]{ 
	matrix[i][j] = uint8(i * j)
}
```

### How to test it

You can either run it from any shell with ```go run exercise-slices.go``` or use [The Go Playground](https://play.golang.org/).
