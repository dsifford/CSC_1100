package main

import (
	"fmt"
	"os"
	"sort"
)

func main() {
	fmt.Printf("----------Begin Problem 1----------\n")
	problem1()
	fmt.Printf("----------Begin Problem 2----------\n")
	problem2()
	fmt.Printf("----------Begin Problem 3----------\n")
	problem3()
}

func problem1() {

	nums := make([]float64, 3, 3)

	fmt.Println("Enter three numbers")
	for i := range nums {
		fmt.Scanln(&nums[i])
	}

	sort.Float64s(nums)
	fmt.Printf("%v %v %v\n", nums[2], nums[1], nums[0])

}

func problem2() {

	var num1, num2 int
	var op string

	fmt.Println("Enter two integers")
	fmt.Scanln(&num1)
	fmt.Scanln(&num2)

	fmt.Print("Enter the operation to be performed (+, -, *, /): ")
	fmt.Scanln(&op)

	switch {
	case op == "+":
		fmt.Printf("%v + %v = %v\n", num1, num2, num1+num2)
	case op == "-":
		fmt.Printf("%v - %v = %v\n", num1, num2, num1-num2)
	case op == "*":
		fmt.Printf("%v * %v = %v\n", num1, num2, num1*num2)
	case op == "/":
		fmt.Printf("%v / %v = %v\n", num1, num2, num1/num2)
	default:
		fmt.Println("Invalid operator. Please try again.")
	}

}

func problem3() {

	var grade int
	var letter string

	fmt.Print("Enter your percentage: ")
	fmt.Scanln(&grade)

	switch {
	case grade > 89 && grade < 101:
		letter = "A"
	case grade > 79 && grade < 90:
		letter = "B"
	case grade > 69 && grade < 80:
		letter = "C"
	case grade > 59 && grade < 70:
		letter = "D"
	case grade > 0 && grade < 60:
		letter = "F"
	default:
		fmt.Println("Input not within range. Please try again")
		os.Exit(0)
	}

	fmt.Println(letter)

}
