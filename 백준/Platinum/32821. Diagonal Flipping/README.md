# [Platinum IV] Diagonal Flipping - 32821 

[문제 링크](https://www.acmicpc.net/problem/32821) 

### 성능 요약

메모리: 34316 KB, 시간: 376 ms

### 분류

구현, 그래프 이론, 자료 구조, 그래프 탐색, 깊이 우선 탐색, 분리 집합, 이분 그래프

### 제출 일자

2025년 10월 10일 12:13:50

### 문제 설명

<p>We are given an $m \times n$ grid that consists of $0$s and $1$s. We have two types of diagonal operations like the following two figures. The type $A$ diagonal flipping operation to a grid position $(i,j)$ is to flip all the elements in the positions $(i + k,j - k)$ of the grid for any integer $k$. If we flip the element $0$, then it becomes $1$. If we flip the element $1$, then it becomes $0$. The type $B$ diagonal flipping operation to a grid position $(i,j)$ is to flip all the elements in the positions $(i + k,j + k)$ of the grid for any integer $k$. Note that a grid position $(p, q)$ is valid only when $0 ≤ p ≤ m - 1$, $0 ≤ q ≤ n - 1$.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/48ba3f1e-034e-4a09-8ae0-28f9d75ed989/-/preview/" style="width: 400px; height: 158px;"></p>

<p style="text-align: center;">Fig 1. Type $A$ diagonal operation to the grid position $(2, 0)$</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/08afc963-1a3c-42a7-8ab7-f178328c79ab/-/preview/" style="width: 400px; height: 156px;"></p>

<p style="text-align: center;">Fig 2. Type $B$ diagonal operation to the grid position $(2, 1)$</p>

<p>Fig 1 shows the type $A$ diagonal flipping operation to the grid position $(2, 0)$. Note that the type $A$ diagonal flipping operations to the grid positions $(1, 1)$ or $(0, 2)$ have the same effect. Fig 2 shows the type $B$ diagonal flipping operation to the grid position $(2, 1)$. The type $B$ diagonal flipping operations to the grid positions $(1, 0)$ or $(3, 2)$ have the same effect.</p>

<p>Given an information of an $m \times n$ grid, write a program to output the minimum number of the diagonal operations to make all the elements in the grid to zeros.</p>

### 입력 

 <p>Your program is to read from standard input. The first line of input contains two positive integers $m$ ($1 ≤ m≤1\,000$) and $n$ ($1 ≤ n ≤ 1\,000$) where $m$ and $n$ indicate the number of rows and columns of the grid, respectively. The rows of the grid are numbered from $0$ to $m - 1$ and the columns are numbered from $0$ to $n - 1$. In the following $m$ lines, the $i$-th line contains $n$ numbers, separated by spaces, which are zero or one that correspond to the row $i - 1$ of the grid.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the minimum number of the diagonal operations to make all the elements of the grid to zeros. If it is not possible to make all the elements of the grid zeros, the program should print the number <code>-1</code>.</p>

