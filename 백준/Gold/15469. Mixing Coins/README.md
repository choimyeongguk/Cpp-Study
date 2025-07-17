# [Gold IV] Mixing Coins - 15469 

[문제 링크](https://www.acmicpc.net/problem/15469) 

### 성능 요약

메모리: 33216 KB, 시간: 464 ms

### 분류

자료 구조, 구현, 큐, 스택

### 제출 일자

2025년 7월 17일 11:30:34

### 문제 설명

<p>Misaka likes to shoot coins as a powerful railgun.</p>

<p>She prepares a line of coins to fight crime. To produce a stronger coin, she mixes coins together. However, coins with different materials are not compatible to each other, so she only mixes coins with same material together.</p>

<p>Here’s the steps Misaka makes coins:</p>

<ol>
	<li>Find first three consecutive coins with same material from the beginning of the line</li>
	<li>Take them out from the line</li>
	<li>Mix together and produce a new coin with same material</li>
	<li>Put the new coin at the end of line</li>
</ol>

<p>She repeatedly do these steps until she can’t produce new coins anymore.</p>

<p>Misaka wants to know how many coins she will have. Please help her count coins rapidly!</p>

### 입력 

 <p>On the first line there is a single integer T indicating the number of test cases.</p>

<p>The first line of each test case contains an integer N indicating the number of groups of consecutive coins Misaka has. All coins are in a single line.</p>

<p>Then N lines follow, each line containing a character c<sub>i</sub> and an integer n<sub>i</sub>, denoting that there are n<sub>i</sub> consecutive coins with material c<sub>i</sub> for i-th group of consecutive coins, behind (i − 1)-th.</p>

<p>You may assume:</p>

<ul>
	<li>T ≤ 10</li>
	<li>1 ≤ N ≤ 10<sup>5</sup></li>
	<li>1 ≤ n<sub>i</sub> ≤ 10<sup>9</sup></li>
	<li>c<sub>i</sub> is an uppercase alphabet, c<sub>i</sub> ≠ c<sub>i+1</sub> for 1 ≤ i < N</li>
</ul>

### 출력 

 <p>For each test case, output an integer in one line, indicating the number of coins after Misaka doing the steps of making coins as many as possible.</p>

