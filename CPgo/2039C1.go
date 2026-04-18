package main

import (
	"fmt"
	_ "math"
)

var ans int = 0
var m1 int64
var x1 int64

func rec(i int64, sum int64, arr []int64) {
	if i == int64(len(arr)) {
		if sum != x1 && sum <= m1 && sum != 0 && x1 != 0 && (x1%(sum^x1) == 0 || sum%(sum^x1) == 0) {
			ans++
		}
		return
	}
	rec(i+1, sum+arr[i], arr)
	rec(i+1, sum, arr)
}
func solve() {
	var x, m int64
	fmt.Scanln(&x, &m)
	x1, m1 = x, m
	var t int64 = min(x, m)
	cnt := 0
	var arr []int64
	for ; t != 0; t = t >> 1 {
		arr = append(arr, 1<<cnt)
		cnt++
	}

	rec(0, 0, arr)

	fmt.Println(ans)
	ans = 0

}
func main() {
	var tc int
	fmt.Scanf("%d\n", &tc)

	for ; tc != 0; tc-- {
		solve()
	}

}
