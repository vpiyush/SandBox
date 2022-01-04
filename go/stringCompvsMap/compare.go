package main

import "fmt"

var stringMap = map[string]string{
	"lifeCycle1::stateA": "1",
	"lifeCycle2::stateB": "1",
	"lifeCycle3::stateC": "1",
	"lifeCycle4::stateD": "1",
	"lifeCycle5::stateE": "1",
	"lifeCycle6::stateF": "1",
}

func StringCompare(s string) bool {
	if s == "lifeCycle1" {
		return true
	} else if s == "lifeCycle2" {
		return true
	} else if s == "lifeCycle3" {
		return true
	} else if s == "lifeCycle4" {
		return true
	} else if s == "lifeCycle5" {
		return true
	} else if s == "lifeCycle6" {
		return true
	}

	return false
}

func checkS2(s2 string) bool {
	if s2 == "stateA" {
		return true
	} else if s2 == "stateB" {
		return true
	} else if s2 == "stateC" {
		return true
	} else if s2 == "stateD" {
		return true
	} else if s2 == "stateE" {
		return true
	} else if s2 == "stateF" {
		return true
	}
	return false
}

func StringCompare2(s1 string, s2 string) bool {
	if s1 == "lifeCycle1" {
		return checkS2(s2)
	} else if s1 == "lifeCycle2" {
		return checkS2(s2)
	} else if s1 == "lifeCycle3" {
		return checkS2(s2)
	} else if s1 == "lifeCycle4" {
		return checkS2(s2)
	} else if s1 == "lifeCycle5" {
		return checkS2(s2)
	} else if s1 == "lifeCycle6" {
		return checkS2(s2)
	}

	return false
}

func StringMapCompare2(s1 string, s2 string) bool {
	s := s1 + "::" + s2
	if _, ok := stringMap[s]; ok {
		return true
	}
	return false
}

func StringMapCompare(s string) bool {
	if _, ok := stringMap[s]; ok {
		return true
	}
	return false
}

func main() {
	fmt.Println("vim-go")

}
