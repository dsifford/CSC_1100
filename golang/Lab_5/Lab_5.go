package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"strconv"
	"strings"
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

// Problem 2 utils

type ticket struct {
	Price, Sold float64
}

func (t ticket) sales() float64 {
	return t.Sold * t.Price
}

func totalSold(t ...ticket) (sold float64) {
	for _, val := range t {
		sold += val.Sold
	}
	return
}

func totalSales(t ...ticket) (sales float64) {
	for _, val := range t {
		sales += val.sales()
	}
	return
}

func parseTicketData(s *bufio.Scanner) (price, sold float64, err error) {
	s.Split(bufio.ScanLines)
	if scannable := s.Scan(); scannable == false {
		err = errors.New("EOL Reached; Nothing else scannable")
		return
	}
	values := strings.Split(s.Text(), " ")
	price, _ = strconv.ParseFloat(values[0], 64)
	sold, _ = strconv.ParseFloat(values[1], 64)

	return

}

func problem2() {

	var box, sideline, premium, general ticket

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

	box.Price, box.Sold, err = parseTicketData(scanner)
	if err != nil {
		panic(err)
	}
	sideline.Price, sideline.Sold, err = parseTicketData(scanner)
	if err != nil {
		panic(err)
	}
	premium.Price, premium.Sold, err = parseTicketData(scanner)
	if err != nil {
		panic(err)
	}
	general.Price, general.Sold, err = parseTicketData(scanner)
	if err != nil {
		panic(err)
	}

	writer := bufio.NewWriter(outFile)
	fmt.Fprintf(writer, "Number of tickets sold: %.2f\nTotal Revenue in sales: $%.2f",
		totalSold(box, sideline, premium, general), totalSales(box, sideline, premium, general))
	writer.Flush()

}

// Problem 3 utils

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
