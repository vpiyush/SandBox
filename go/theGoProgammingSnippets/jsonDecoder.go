package main

import (
	"encoding/json"
	"fmt"
)

type Movie struct {
	Title  string
	Year   int  `json:"released"`
	Color  bool `json:"color,omitempty"`
	Actors []string
}

var movies = []Movie{
	{Title: "Casablanca", Year: 1942, Color: false,
		Actors: []string{"Humphrey Bogart", "Ingrid Bergman"}},
	{Title: "Cool Hand Luke", Year: 1967, Color: true,
		Actors: []string{"Paul Newman"}},
	{Title: "Bullitt", Year: 1968, Color: true,
		Actors: []string{"Steve McQueen", "Jacqueline Bisset"}},
	// ...
}

func main() {
	data, err := json.Marshal(movies)
	if err != nil {
		panic("json marshalling failed")
	}
	data, err = json.MarshalIndent(movies, "", "	")
	if err != nil {
		panic("json marshalling failed")
	}
	fmt.Printf("data %s\n", data)
	//fmt.Println("data ", data)

	var title []struct{ Title string }
	err = json.Unmarshal(data, &title)
	if err != nil {
		fmt.Printf("Unmarshaling failed", err)
	}
	fmt.Printf("data %s\n", title)

}
