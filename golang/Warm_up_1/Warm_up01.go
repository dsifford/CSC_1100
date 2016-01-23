// Print standard output to console
package main

import "fmt"

func main() {

	hello()

	a := 3
	b := 11

	fmt.Printf("a is %v\n", a)
	fmt.Printf("b is %v\n", b)
}

func hello() {
	fmt.Println("Hello World")
}
