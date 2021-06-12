package main

import (
	"io"
	"log"
	"net"
	"time"
)

func main() {
	listener, err := net.Listen("tcp", "localhost:8080")
	if err != nil {
		log.Fatal("listen failed", err)
	}
	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Print("accept failed", err)
			continue
		}
		handleConn(conn)
	}
}
func handleConn(c net.Conn) {
	defer c.Close()
	for {
		_, err := io.WriteString(c, time.Now().Format("15:04:09\n"))
		if err != nil {
			log.Fatal("io write failed", err)
		}
		time.Sleep(1 * time.Second)
	}
}
