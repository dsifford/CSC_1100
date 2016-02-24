package main

import (
	"fmt"
)

func main() {
	exercise1()
	exercise2()
	exercise3()
}

func exercise1() {
	var age int
	var delim []byte
	var name string

	fmt.Println("Enter your age")
	fmt.Scanln(&age)

	fmt.Println("Enter a delimiter")
	fmt.Scan(&delim)

	fmt.Println("Enter your name")
	fmt.Scanln(&name)

	fmt.Printf("Name: %v\nDelim: %c\nAge: %v\n\n", name, delim[0], age)
}

func exercise2() {
	var kg, lbs float64

	fmt.Println("Enter your weight in kilograms")
	fmt.Scanln(&kg)

	lbs = kg * 2.2

	fmt.Printf("Pounds: %.2flbs\nKilograms: %.2fkg\n\n", lbs, kg)
}

func exercise3() {
	var seconds, mins, hours int

	fmt.Println("Enter elapsed time in seconds")
	fmt.Scanln(&seconds)

	mins = seconds / 60
	hours = mins / 60

	fmt.Printf("Time in Hours, Mins, Seconds:\nHours: %v Mins: %v Seconds: %v\n", hours, mins%60, seconds%60)

}
