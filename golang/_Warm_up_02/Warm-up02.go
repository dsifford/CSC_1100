// Demo of stdin
package main

import "fmt"

func main() {
	var x float32
	var y int
	var ch1, ch2 string
	var name string

	fmt.Println("Enter a character")
	if _, err := fmt.Scanln(&ch1); err != nil {
		fmt.Println("Error:", err)
	}

	fmt.Println("Enter a number")
	if _, err := fmt.Scanln(&y); err != nil {
		fmt.Println("Error:", err)
	}

	fmt.Println("Enter another character")
	if _, err := fmt.Scanln(&ch2); err != nil {
		fmt.Println("Error:", err)
	}

	fmt.Println("Enter a name")
	if _, err := fmt.Scanf("%s", &name); err != nil {
		fmt.Println("Error:", err)
	}

	fmt.Println("Enter a floating point value")
	if _, err := fmt.Scanf("%g", &x); err != nil {
		fmt.Println("Error:", err)
	}

	// Display the values read
	fmt.Printf("ch1\t=\t%s\ny\t=\t%d\nch2\t=\t%s\nName\t=\t%s\nx\t=\t%g\n",
		ch1, y, ch2, name, x)
}
