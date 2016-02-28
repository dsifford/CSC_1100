package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"regexp"
	"strconv"
	"strings"
)

func main() {

	var input, x1, x2, x3, x4, x5 int
	fmt.Println("Enter an integer")
	fmt.Scanln(&input)
	fmt.Printf("Integer reversed:%d\n\n\n", reverseDigit(input))

	fmt.Println("Enter five numbers")
	fmt.Scanln(&x1)
	fmt.Scanln(&x2)
	fmt.Scanln(&x3)
	fmt.Scanln(&x4)
	fmt.Scanln(&x5)
	fmt.Printf("The mean of your numbers is: %v\nThe SD of your numbers is: %v\n\n\n",
		mean(x1, x2, x3, x4, x5), sd(x1, x2, x3, x4, x5))

	fmt.Println("Enter any string")
	reader := bufio.NewReader(os.Stdin)
	inputStr, _ := reader.ReadString('\n')
	fmt.Printf("The number of lowercase vowels in your input is: %v\n\n", getLowerVowels(inputStr))

}

// Problem 1
func reverseDigit(n int) int {
	var payload string
	isNeg := false
	if n < 0 {
		isNeg = true
		n *= -1
	}
	x := strings.Split(strconv.Itoa(n), "")
	for i := range x {
		payload = x[i] + payload
	}
	output, err := strconv.Atoi(payload)
	if err != nil {
		panic(err)
	}
	if isNeg {
		return output * -1
	}

	return output
}

// Problem 2
func mean(nums ...int) (x float64) {
	for i := range nums {
		x += float64(nums[i])
	}
	x = x / float64(len(nums))
	return
}

func sd(nums ...int) (x float64) {
	m := mean(nums...)
	var ssq float64
	for i := range nums {
		ssq += math.Pow((float64(nums[i]) - m), 2)
	}
	return math.Sqrt(ssq / float64(len(nums)))
}

// Problem 3
func getLowerVowels(input string) int {
	fmt.Println(input)
	r := regexp.MustCompile("(a|e|i|o|u|y)")
	x := r.FindAllString(input, -1)
	return len(x)
}
