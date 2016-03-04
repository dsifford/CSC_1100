package main

import (
	"fmt"
)

// Problem2 steps:
// - Initialize two one-dimension arrays as global variables
// - In the main function print out the two original arrays.
// - Write and test a program that consists of the following functions:
//      - arrayAdd( ): do the addition for two one-dimension arrays and output the result.
//      - arrayMulti( ): do the multiplication for one one-dimension array and one integer and output the result.
func Problem2() {
	fmt.Printf("\nProblem 2:\n")
	fmt.Printf("Slice 1:%+v\nSlice 2:%+v\n", slice1, slice2)
	arrayAdd(slice1, slice2)
	arrayMulti(slice1, 5)
}

var slice1 = []int{0, 1, 2, 3, 4}
var slice2 = []int{4, 3, 2, 1, 0}

func arrayAdd(s1 []int, s2 []int) {
	s3 := make([]int, 5)
	for i := range s1 {
		s3[i] = s1[i] + s2[i]
	}
	fmt.Printf("Slice1 + Slice2 = %+v\n", s3)
}

func arrayMulti(s []int, m int) {
	for i := range s {
		s[i] *= m
	}
	fmt.Printf("Slice1 * %v = %+v\n", m, s)
}
