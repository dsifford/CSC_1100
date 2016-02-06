package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// PI is an abbreviated representation of math.PI
const PI float64 = 3.1416

type geometry interface {
	area() float64
	perim() float64
}

type rectangle struct {
	Length, Width float64
}

type circle struct {
	Radius float64
}

func (r rectangle) area() float64 {
	return r.Length * r.Width
}

func (r rectangle) perim() float64 {
	return (r.Length * 2) + (r.Width * 2)
}

func (c circle) area() float64 {
	return PI * c.Radius * c.Radius
}

func (c circle) perim() float64 {
	return 2 * PI * c.Radius
}

type person struct {
	Fname, Lname string
	Age          int64
}

type account struct {
	Balance, Rate float64
}

func (a account) interest() float64 {
	rate := a.Rate / 100
	return a.Balance * (1 + rate*0.083333)
}

func main() {

	inFile, err := os.Open("inFile")
	if err != nil {
		panic(err)
	}
	defer inFile.Close()

	outFile, err := os.Create("outFile.txt")
	if err != nil {
		panic(err)
	}
	writer := bufio.NewWriter(outFile)

	var rect rectangle
	var cir circle
	var p person
	var a account

	scanner := bufio.NewScanner(inFile)
	scanner.Split(bufio.ScanLines)

	line := parseLine(scanner)
	rect.Length, _ = strconv.ParseFloat(line[0], 64)
	rect.Width, _ = strconv.ParseFloat(line[1], 64)

	line = parseLine(scanner)
	cir.Radius, _ = strconv.ParseFloat(line[0], 64)

	line = parseLine(scanner)
	p.Fname = line[0]
	p.Lname = line[1]
	p.Age, _ = strconv.ParseInt(line[2], 10, 0)

	line = parseLine(scanner)
	a.Balance, _ = strconv.ParseFloat(line[0], 64)
	a.Rate, _ = strconv.ParseFloat(line[1], 64)

	fmt.Fprintf(writer,
		"Rectangle:\n"+
			"Length = %v, Width = %v, Area = %.2f, Perimeter = %.2f\n\n"+
			"Circle:\n"+
			"Radius = %v, Area = %.2f, Circumference = %.2f\n\n"+
			"Name: %s %s, Age: %v\n"+
			"Beginning balance = $%v, Interest rate = %v\n"+
			"Balance at the end of the month = $%.2f",
		rect.Length, rect.Width, rect.area(), rect.perim(), cir.Radius,
		cir.area(), cir.perim(), p.Fname, p.Lname, p.Age, a.Balance, a.Rate,
		a.interest())

	writer.Flush()

}

func parseLine(s *bufio.Scanner) []string {
	if scannable := s.Scan(); scannable == false {
		panic("Error: Not scannable")
	}
	return strings.Split(s.Text(), " ")
}
