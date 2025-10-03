# [Gold III] Rectangle Tiling - 32677 

[문제 링크](https://www.acmicpc.net/problem/32677) 

### 성능 요약

메모리: 2220 KB, 시간: 0 ms

### 분류

수학, 그리디 알고리즘

### 제출 일자

2025년 10월 3일 16:38:18

### 문제 설명

<p>Consider a rectangle with integer side lengths. A square tiling of the rectangle is a covering of the entire region using non-overlapping squares whose sides are parallel with those of the rectangle. In a square tiling, no square may overhang (extend beyond the rectangle's boundary).</p>

<p>You have a collection of squares with side lengths being powers of $2$. Find a square tiling of the rectangle using the fewest squares possible, or, indicate that it cannot be done.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/e3cdb27e-2d4d-43b6-bb93-43be3918ea3a/-/preview/" style="width: 768px; height: 456px;"></p>

<p style="text-align: center;">Figure 1: Optimal square tilings for the first three sample inputs. The small unlabelled tiles are $1 \times 1$ tiles.</p>

### 입력 

 <p>The first line of input contains three integers $W, H$ and $N$ ($1 \leq W,H \leq 2^{50}$ and $1 \leq N \leq 51$). Here, $W$ and $H$ indicate the dimensions of the rectangle. The next line contains $N$ integers $a_0, a_1, \ldots, a_{N-1}$ where $a_i$ ($0 \leq a_i \leq 2^{51}$) is the number of $2^i \times 2^i$ squares you own.</p>

### 출력 

 <p>If there is a square tiling of a $W \times H$ rectangle using the squares you own, output the minimum number of squares needed in such a square tiling. Otherwise, output $-1$ if there is no square tiling of the rectangle using the squares you own.</p>

