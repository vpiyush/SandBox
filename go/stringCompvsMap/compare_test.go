package main

import (
	"testing"
)

var tests = []struct {
	first, second string
}{
	{
		first:  "lifeCycle1",
		second: "stateA",
	},
	{
		first:  "lifeCycle2",
		second: "stateB",
	},
	{
		first:  "lifeCycle3",
		second: "stateC",
	},
	{
		first:  "lifeCycle4",
		second: "stateD",
	},
	{
		first:  "lifeCycle5",
		second: "stateE",
	},
	{
		first:  "lifeCycle6",
		second: "stateF",
	},
	{
		first:  "lifeCycle1",
		second: "stateNone",
	},
	{
		first:  "ifeCycle5",
		second: "tateA",
	},
	{
		first:  "feCycle6",
		second: "stateA",
	},
}

/*
func BenchmarkStringCompare(b *testing.B) {
	for _, tt := range tests {
		for i := 0; i < b.N; i++ {
			StringCompare(tt.first)
		}
	}
}

func BenchmarkStringMapCompare(b *testing.B) {
	for _, tt := range tests {
		for i := 0; i < b.N; i++ {
			StringMapCompare(tt.first)
		}
	}
}*/

func BenchmarkStringCompare2(b *testing.B) {
	for _, tt := range tests {
		for i := 0; i < b.N; i++ {
			StringCompare2(tt.first, tt.second)
		}
	}
}

func BenchmarkStringMapComparer2(b *testing.B) {
	for _, tt := range tests {
		for i := 0; i < b.N; i++ {
			StringMapCompare2(tt.first, tt.second)
		}
	}
}
