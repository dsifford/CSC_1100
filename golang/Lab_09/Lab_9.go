package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	fmt.Printf("Begin Problem 1:\n\n")
	problem1()
	fmt.Printf("\n\nBegin Problem 2:\n\n")
	problem2()
	fmt.Printf("\n\nBegin Problem 3:\n\n")
	problem3()
}

// Problem recap:
// Need to make a program that accepts N number of integers from stdin,
// and then prints the sum of all even and odd integers separately
func problem1() {
	var nums int
	var sumOfEven, sumOfOdd int

	fmt.Println("Enter a series of integers")
	for {
		if _, err := fmt.Scanln(&nums); err != nil {
			break
		}

		if nums%2 == 0 {
			sumOfEven = sumOfEven + nums
		} else {
			sumOfOdd = sumOfOdd + nums
		}

	}

	fmt.Printf("Sum of even numbers = %v\nSum of odd numbers = %v\n",
		sumOfEven, sumOfOdd)

}

// Problem recap:
// Write function that takes an integer and returns the number of
// digits of that integer
func problem2() {

	var num int

	fmt.Println("Enter an integer")
	if _, err := fmt.Scanln(&num); err != nil {
		return
	}

	numstring := strconv.Itoa(num)

	fmt.Printf("The integer is %v digits long\n", len(numstring))

}

// Problem 3 Recap:
// Write a function that takes any positive integer and returns
// whether or not the integer is a prime number
func problem3() {
	var num int

	fmt.Println("Enter a positive integer")
	if _, err := fmt.Scanln(&num); err != nil || num < 0 {
		return
	}

	if num%2 == 0 {
		if num == 2 {
			fmt.Println("Number is prime")
			return
		}
		fmt.Println("Number is not prime")
	} else {
		num2 := math.Sqrt(float64(num))
		counter := 3

		for {
			if float64(counter) > num2 {
				break
			}

			if num%counter == 0 {
				fmt.Println("Number is not prime")
				return
			}
			counter = counter + 2
		}

		fmt.Println("Number is prime")
	}

}
