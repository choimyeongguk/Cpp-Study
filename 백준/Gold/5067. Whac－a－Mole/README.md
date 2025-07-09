# [Gold II] Whac-a-Mole - 5067 

[문제 링크](https://www.acmicpc.net/problem/5067) 

### 성능 요약

메모리: 2228 KB, 시간: 220 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 7월 9일 22:58:43

### 문제 설명

<p>While visiting a traveling fun fair you suddenly have an urge to break the high score in the Whac-a-Mole game. The goal of the Whac-a-Mole game is to... well... whack moles. With a hammer. To make the job easier you have first consulted the fortune teller and now you know the exact appearance patterns of the moles.</p>

<p>The moles appear out of holes occupying the n<sup>2</sup> integer points (x, y) satisfying 0 ≤ x, y < n in a two-dimensional coordinate system. At each time step, some moles will appear and then disappear again before the next time step. After the moles appear but before they disappear, you are able to move your hammer in a straight line to any position (x2, y2) that is at distance at most d from your current position (x1, y1). For simplicity, we assume that you can only move your hammer to a point having integer coordinates. A mole is whacked if the center of the hole it appears out of is located on the line between (x1, y1) and (x2, y2) (including the two endpoints). Every mole whacked earns you a point. When the game starts, before the first time step, you are able to place your hammer anywhere you see fit.</p>

### 입력 

 <p>The input consists of several test cases. Each test case starts with a line containing three integers n, d and m, where n and d are as described above, and m is the total number of moles that will appear (1 ≤ n ≤ 20, 1 ≤ d ≤ 5, and 1 ≤ m ≤ 1000). Then follow m lines, each containing three integers x, y and t giving the position and time of the appearance of a mole (0 ≤ x, y < n and 1 ≤ t ≤ 10). No two moles will appear at the same place at the same time.</p>

<p>The input is ended with a test case where n = d = m = 0. This case should not be processed.</p>

### 출력 

 <p>For each test case output a single line containing a single integer, the maximum possible score achievable.</p>

