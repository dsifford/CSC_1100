package main

import (
	"fmt"
)

// Problem1 - Write two functions:
//     1) printArray: Prints an int array
//     2) smallestIndex: takes as parameters an int array and its size and
//        returns the index of the first occurrence of the smallest element
//        in the array.
func Problem1() {
	fmt.Printf("Problem 1:\n")
	mySlice := []int{0, 1, 2, 3, 4, -10}
	printArray(mySlice)
	smallest := smallestIndex(mySlice)
	fmt.Printf("Smallest index = %v\n", smallest)
}

func printArray(s []int) {
	fmt.Printf("%+v\n", s)
}

func smallestIndex(s []int) (smallest int) {
	for _, i := range s {
		if i < smallest {
			smallest = i
		}
	}
	return
}
