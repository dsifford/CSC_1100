package main

// NOTE: It's also possible to "namespace" an entire package, similar
// to C++ "using namespace" (see below), but it's not recommended. Instead
// importing with an alias is recommended (if there are package name conflicts)
//
// import . "fmt" === using namespace fmt    // BAD
// import myAlias "fmt"   // GOOD
// Package can now be used using myAlias.functionName()

import "fmt"

func main() {
	problem1()
	problem2()
	problem3()
}

func problem1() {
	var name string
	var studyHours float64

	fmt.Println("Write your name")
	if _, err := fmt.Scanln(&name); err != nil {
		fmt.Println("Error:", err)
	}

	fmt.Println("How many hours do you need to study?")
	if _, err := fmt.Scanln(&studyHours); err != nil {
		fmt.Println("Error:", err)
	}

	fmt.Printf("Hello, %s! on Saturday, you need "+
		"to study %g hours for the exam.\n\n", name, studyHours)

}

func problem2() {
	var capacity, mpg, totalMiles float64

	fmt.Println("What is the capacity of your fuel tank?")
	if _, err := fmt.Scanln(&capacity); err != nil {
		fmt.Println("Error:", err)
	}

	fmt.Println("How many miles does your vehicle get per gallon?")
	if _, err := fmt.Scanln(&mpg); err != nil {
		fmt.Println("Error:", err)
	}

	totalMiles = capacity * mpg

	fmt.Printf("Your vehicle can travel a total of %g miles without refueling.\n\n", totalMiles)

}

func problem3() {
	var hours, mins, seconds, totalSeconds int

	fmt.Println("Please enter the elapsed time in hours, minutes, and seconds.")

	fmt.Println("Enter hours")
	if _, err := fmt.Scanln(&hours); err != nil {
		fmt.Println("Error:", err)
	}

	fmt.Println("Enter minutes")
	if _, err := fmt.Scanln(&mins); err != nil {
		fmt.Println("Error:", err)
	}

	fmt.Println("Enter seconds")
	if _, err := fmt.Scanln(&seconds); err != nil {
		fmt.Println("Error:", err)
	}

	totalSeconds = (hours * 60 * 60) + (mins * 60) + seconds

	fmt.Println("The total time in seconds is", totalSeconds)

}
