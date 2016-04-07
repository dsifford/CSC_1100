package main

import (
	"fmt"
)

func main() {

	arr := [15]int{23, 3, 21, 5, 78, 52, 46, 73, 46, 73, 62, 77, 43, 48, 25}
	fmt.Println(arr)

	smallest := arr[0]
	var secondSmallest int

	for _, i := range arr {
		if i < smallest {
			smallest = i
		}
	}

	if smallest == arr[0] {
		secondSmallest = arr[1]
	} else {
		secondSmallest = arr[0]
	}

	for _, i := range arr {
		if i == smallest {
			continue
		}

		if i < secondSmallest {
			secondSmallest = i
		}
	}

	fmt.Println("The second smallest is ", secondSmallest)

}
