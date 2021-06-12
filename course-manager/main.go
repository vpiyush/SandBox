package main

import (
	_ "encoding/json"
	"fmt"
	"log"
	"net/http"
)

func main() {
	// Hello world, the web server
	var mgr Manager
	mgr.Initialize()
	mgr.Start(":8000")
	log.Println("Listing for requests at http://localhost:8000/hello")
}
