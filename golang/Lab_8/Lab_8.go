package main

import (
	"fmt"
)

func main() {

	var yrs int
	var popA, popB, growthA, growthB float64

	fmt.Print("Enter the population of town A: ")
	fmt.Scanln(&popA)

	fmt.Print("Enter the growth rate of town A: ")
	fmt.Scanln(&growthA)

	fmt.Print("Enter the population of town B: ")
	fmt.Scanln(&popB)

	fmt.Print("Enter the growth rate of town B: ")
	fmt.Scanln(&growthB)

	if growthA > 1 {
		growthA = growthA / 100
	}

	if growthB > 1 {
		growthB = growthB / 100
	}

	for popB >= popA {
		popB = (popB * growthB) + popB
		popA = (popA * growthA) + popA
		yrs++
	}

	fmt.Printf("The population of town A will be greater than town B after %v years.\n"+
		"The population of town A is: %v\nThe population of town B is: %v\n\n", yrs, int(popA), int(popB))

}
