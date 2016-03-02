package main

import (
	"fmt"
)

func main() {

	var current, oneYear, twoYear float64

	inputFunc(&current, &oneYear, &twoYear)
	result1 := calculate(current, oneYear)
	result2 := calculate(oneYear, twoYear)
	output(result1, result2)

}

func inputFunc(current, oneYear, twoYear *float64) {
	fmt.Println("Enter the current price")
	fmt.Scanln(current)

	fmt.Println("Enter last year's price")
	fmt.Scanln(oneYear)

	fmt.Println("Enter the price two years ago")
	fmt.Scanln(twoYear)
}

func calculate(current, past float64) float64 {
	return (current - past) / past
}

func output(result1, result2 float64) {
	if result1 > result2 {
		fmt.Println("Inflation is increasing")
		return
	}

	fmt.Println("Inflation is decreasing")
}
