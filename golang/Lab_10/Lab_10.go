package main

import (
	"fmt"
)

func main() {

	var group1, group2 int
	var n []byte
	fmt.Scanln(&n)

	for i, num := range n {
		num -= 48

		if i%2 == 0 {
			group1 += int(num)
		} else {
			group2 += int(num)
		}
	}

	if check := group1 + group2; check%2 == 0 {
		group1 *= -1
	} else {
		group2 *= -1
	}

	if sum := group1 + group2; sum%11 == 0 {
		fmt.Println("The number is divisible by 11")
	} else {
		fmt.Println("The number is not divisible by 11")
	}

}
