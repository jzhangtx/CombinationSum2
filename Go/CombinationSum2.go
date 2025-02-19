package main

import "fmt"

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func Count(v []int, n int) int {
	count := 0
	for _, i := range v {
		if i == n {
			count++
		}
	}

	return count
}

func Equal(v1, v2 []int) bool {
	for _, n := range v1 {
		if Count(v1, n) != Count(v2, n) {
			return false
		}
	}

	return true
}

func Exists(vv [][]int, v []int) bool {
	for _, vec := range vv {
		if Equal(vec, v) {
			return true
		}
	}

	return false
}

func GetCombination(A []int, val, index int, r []int, result *[][]int) {
	if val == 0 {
		if !Exists(*result, r) {
			c := make([]int, len(r))
			copy(c, r)
			*result = append(*result, c)
		}
		return
	}

	if index == len(A) || val < 0 {
		return
	}

	for i := index; i < len(A); i++ {
		r = append(r, A[i])
		GetCombination(A, val-A[i], i+1, r, result)
		r = r[:len(r)-1]
	}
}

func CombinationSum(A []int, val int) [][]int {
	var result [][]int
	var r []int

	GetCombination(A, val, 0, r, &result)

	return result
}

func main() {
	for {
		fmt.Print("Number of elements: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := GetArrayFromInput(count, "Please enter the array: ")

		fmt.Print("Please enter the sum: ")
		var val int
		fmt.Scan(&val)

		result := CombinationSum(vec, val)

		fmt.Println("The combinations that have a sum of ", val, ": ", result)
	}
}
