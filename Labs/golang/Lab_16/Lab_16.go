package main

import (
	"fmt"
	"strings"
)

func main() {

	var input string
	fmt.Println("Enter a string")
	fmt.Scanln(&input)

	fmt.Printf("Your input in uppercase is %v\n", strings.ToUpper(input))

}
