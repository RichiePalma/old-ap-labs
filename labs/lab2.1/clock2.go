// Clock2 is a concurrent TCP server that periodically writes the time.	
package main

import (
	"io"
	"log"
	"net"
	"time"
	"os"
)

func handleConn(c net.Conn) {
	defer c.Close()
	for {
		 //io.WriteString(c, "Mexico: ")
		_, err := io.WriteString(c, time.Now().Format("15:04:05\n"))
		if err != nil {
			return // e.g., client disconnected
		}
		time.Sleep(5 * time.Second)
	}
}

func main() {
	args := os.Args
	args[2] = "localhost:" + args[2]
	listener, err :=  net.Listen("tcp", args[2]) //test localhost:9090
	if err != nil {
		log.Fatal(err)
	}

	for {
		conn, err :=  listener.Accept()
		if err != nil {
			log.Print(err) // e.g., connection aborted
			continue
		}

		go handleConn(conn) // handle connections concurrently
	}
}
