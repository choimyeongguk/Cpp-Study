# [Silver III] Pascal Multiple - 32675 

[문제 링크](https://www.acmicpc.net/problem/32675) 

### 성능 요약

메모리: 9940 KB, 시간: 12 ms

### 분류

수학, 다이나믹 프로그래밍

### 제출 일자

2025년 10월 3일 13:44:28

### 문제 설명

<p>The $(i,j)$th binomial coefficient, denoted $C(i,j)$, is the (zero-indexed) $j$th entry of the (zero-indexed) $i$th row in Pascal's triangle:</p>

<pre>1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
...
</pre>

<p>where $C(0,0) = 1$ and the $(i+1)$st row can be computed from the $i$th row using the recursion $$C(i+1, j) = C(i,j) + C(i, j-1),$$ treating as $0$ any out-of-bounds entries of the triangle on the right-hand side.</p>

<p>Given $N$ and $K$, compute how many entries in the first $N+1$ rows of Pascal's triangle are multiples of $K$. To be precise: for how many pairs of indices $(i,j)$ with $0\leq i\leq N$ and $0 \leq j \leq i$, is $C(i,j)$ divisible by $K$?</p>

### 입력 

 <p>The single line of input contains two positive integers $N$ $(1 \leq N \leq 10^3)$ and $K$ $(1 \leq K \leq N)$, with meaning as described above.</p>

### 출력 

 <p>Print the number of entries in the first $N+1$ rows of Pascal's triangle that are divisible by $K$.</p>

