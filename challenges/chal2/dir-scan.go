package main

import (
	"fmt"
	//"log"
	"os"
	"path/filepath"
)

// scanDir stands for the directory scanning implementation
func scanDir(dir string) error {
	 var files []string
	 
	 //dirs := 0
	 dirs, symlink, blocked,other := 0,0,0,0	// Directories, Symbolic Links, Acess Denied and others
	 //total := 0 //Testing counter of total files
	 
	 err := filepath.Walk(dir, func(path string, info os.FileInfo, err error) error{
		files = append(files, info.Name())
		if info.IsDir(){
			dirs++
		}else if info.Mode()&(1<<2) == 0{		//chmod 000 No one has acess to
			blocked++
		}else if info.Mode()&os.ModeSymlink != 0{
			symlink++
		}else{
			other++
		}
			//total++
			return nil
	 })
	 
	 if err != nil {
        panic(err)
    }
    
    //fmt.Println("Total files ",total)
	
	//~ for _, file := range files{
		//~ fmt.Println(file)
	//~ } 
		fmt.Println("Path \t\t", dir)
		fmt.Println("Directories \t", dirs )
		fmt.Println("Symbolic Links \t", symlink)
		fmt.Println("Access Denied \t", blocked)
		fmt.Println("Other files \t", other)
		return nil
	

}

func main() {

	if len(os.Args) < 2 {
		fmt.Println("Usage: ./dir-scan <directory>")
		os.Exit(1)
	}

	scanDir(os.Args[1])
}
