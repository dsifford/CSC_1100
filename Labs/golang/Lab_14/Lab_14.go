package main

import (
	"fmt"
)

type currency struct {
	hundreds, fifties, twenties, tens, fives, ones int
}

func (c *currency) change(v int) {

	if v > 100 {
		c.hundreds = v / 100
		v = v % 100
	}
	if v > 50 {
		c.fifties = v / 50
		v = v % 50
	}
	if v > 20 {
		c.twenties = v / 20
		v = v % 20
	}
	if v > 10 {
		c.tens = v / 10
		v = v % 10
	}
	if v > 5 {
		c.fives = v / 5
		v = v % 5
	}
	if v > 1 {
		c.ones = v / 1
		v = v % 1
	}

}

func main() {

	var input int
	c := currency{}

	fmt.Println("Enter any integer")
	fmt.Scanln(&input)

	c.change(input)
	fmt.Printf(
		"Your change is:\n"+
			"%v hundreds\n"+
			"%v fifties\n"+
			"%v twenties\n"+
			"%v tens\n"+
			"%v fives\n"+
			"%v ones\n",
		c.hundreds, c.fifties, c.twenties, c.tens, c.fives, c.ones)

}
