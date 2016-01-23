package main

import "fmt"

func main() {
	practice1()
	practice2()
}

func practice1() {
	var num int

	fmt.Println("Enter a number")
	if _, err := fmt.Scanln(&num); err != nil {
		fmt.Println("Error:", err)
	}

	var average int

	num1 := 125
	num2 := 28
	num3 := -25

	average = (num1 + num2 + num3) / 3
	fmt.Println("Average =", average)

}

func practice2() {
	var num1, num2, num3, num4, num5, average int

	fmt.Println("Enter 5 numbers")
	fmt.Scanln(&num1)
	fmt.Scanln(&num2)
	fmt.Scanln(&num3)
	fmt.Scanln(&num4)
	fmt.Scanln(&num5)

	average = (num1 + num2 + num3 + num4 + num5) / 5

	fmt.Println("Average =", average)

}
