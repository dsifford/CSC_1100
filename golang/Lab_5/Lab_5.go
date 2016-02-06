package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	problem1()
	problem2()
	problem3()
}

func problem1() {
	var mass, density, volume float64
	var payload []string

	inFile, err := os.Open("inFile1")
	if err != nil {
		panic(err)
	}
	defer inFile.Close()

	outFile, err := os.Create("outFile1.txt")
	if err != nil {
		panic(err)
	}
	defer outFile.Close()

	scanner := bufio.NewScanner(inFile)
	scanner.Split(bufio.ScanWords)

	for scanner.Scan() {
		payload = append(payload, scanner.Text())
	}

	mass, _ = strconv.ParseFloat(payload[0], 64)
	density, _ = strconv.ParseFloat(payload[1], 64)

	volume = mass / density

	writer := bufio.NewWriter(outFile)
	fmt.Fprintf(writer, "Volume: %.2f", volume)
	writer.Flush()

}

func problem2() {

	var boxSales, sidelineSales, premiumSales, generalSales,
		totalSold, totalSales float64

	data := make(map[string]float64)
	data["boxPrice"] = 0
	data["boxSold"] = 0
	data["sidelinePrice"] = 0
	data["sidelineSold"] = 0
	data["premiumPrice"] = 0
	data["premiumSold"] = 0
	data["generalPrice"] = 0
	data["generalSold"] = 0

	inFile, err := os.Open("inFile2")
	if err != nil {
		panic(err)
	}
	defer inFile.Close()

	outFile, err := os.Create("outFile2.txt")
	if err != nil {
		panic(err)
	}
	defer outFile.Close()

	scanner := bufio.NewScanner(inFile)
	scanner.Split(bufio.ScanWords)

	for key := range data {
		if scannable := scanner.Scan(); scannable == false {
			break
		}
		val, _ := strconv.ParseFloat(scanner.Text(), 64)
		data[key] = val
	}

	boxSales = data["boxSold"] * data["boxPrice"]
	sidelineSales = data["sidelineSold"] * data["sidelinePrice"]
	premiumSales = data["premiumSold"] * data["premiumPrice"]
	generalSales = data["generalSold"] * data["generalPrice"]

	totalSold = data["boxSold"] + data["sidelineSold"] + data["premiumSold"] +
		data["generalSold"]

	totalSales = boxSales + sidelineSales + premiumSales + generalSales

	writer := bufio.NewWriter(outFile)
	fmt.Fprintf(writer, "Number of tickets sold: %.2f\nTotal Revenue in sales: $%.2f",
		totalSold, totalSales)
	writer.Flush()

}

type person struct {
	Fname, Lname                   string
	CurrentSalary, NewSalary, Rate float64
}

func scanNext(s *bufio.Scanner) {
	scannable := s.Scan()
	if scannable == false {
		panic("Error")
	}
}

func problem3() {

	var person1, person2, person3 person
	people := []person{person1, person2, person3}

	inFile, err := os.Open("inFile3")
	if err != nil {
		panic(err)
	}
	defer inFile.Close()

	outFile, err := os.Create("outFile3.txt")
	if err != nil {
		panic(err)
	}
	defer outFile.Close()

	scanner := bufio.NewScanner(inFile)
	scanner.Split(bufio.ScanWords)

	writer := bufio.NewWriter(outFile)

	for p := range people {
		if scannable := scanner.Scan(); scannable == false {
			break
		}

		people[p].Lname = scanner.Text()
		scanNext(scanner)

		people[p].Fname = scanner.Text()
		scanNext(scanner)

		f, err := strconv.ParseFloat(scanner.Text(), 64)
		if err != nil {
			panic(err)
		}
		people[p].CurrentSalary = f
		scanNext(scanner)

		f, err = strconv.ParseFloat(scanner.Text(), 64)
		if err != nil {
			panic(err)
		}
		people[p].Rate = f

		people[p].NewSalary = (people[p].CurrentSalary * (people[p].Rate / 100)) +
			people[p].CurrentSalary

		fmt.Fprintf(writer, "%s %s %.2f\n",
			people[p].Fname, people[p].Lname, people[p].NewSalary)
	}
	writer.Flush()

}
