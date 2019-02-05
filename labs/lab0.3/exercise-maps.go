package main

import (
	"golang.org/x/tour/wc"
	"strings"
	//"fmt"
)
var m map[string]int
var word string

func WordCount(s string) map[string]int {
	m = make(map[string]int)
	
	for _, word := range strings.Fields(s){
		m[word] += 1
		//fmt.Println(word, m[word])
	}
	return m
	//return map[string]int{word: m[word]}
}

func main() {
	//WordCount("Test numero uno")
	wc.Test(WordCount)
}
