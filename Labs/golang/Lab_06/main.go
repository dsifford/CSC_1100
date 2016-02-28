package main

import (
	"fmt"
)

func main() {

	var baseSalary, noOfServiceYears, totalSales, bonus, additionalBonus,
		paycheck float64

	fmt.Print("Enter base salary: ")
	fmt.Scanln(&baseSalary)

	fmt.Print("Enter number of years worked: ")
	fmt.Scanln(&noOfServiceYears)

	fmt.Print("Enter total sales: ")
	fmt.Scanln(&totalSales)

	switch {
	case noOfServiceYears <= 5:
		bonus = 10 * noOfServiceYears
	default:
		bonus = 20 * noOfServiceYears
	}

	switch {
	case totalSales < 5000:
		additionalBonus = 0
	case totalSales > 10000:
		additionalBonus = totalSales * 0.06
	default:
		additionalBonus = totalSales * 0.03
	}

	paycheck = baseSalary + bonus + additionalBonus

	fmt.Printf("The paycheck value for this month is: $%v\n", paycheck)

}
