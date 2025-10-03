# [Gold I] Up and Down - 32683 

[문제 링크](https://www.acmicpc.net/problem/32683) 

### 성능 요약

메모리: 14740 KB, 시간: 236 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 가장 긴 증가하는 부분 수열 문제, 세그먼트 트리

### 제출 일자

2025년 10월 3일 15:52:11

### 문제 설명

<p>Given a sequence of integers with length $N$, find the maximum length of a subsequence that strictly increases and then strictly decreases; the last position of strictly increasing must coincide with the first position of strictly decreasing. A subsequence can be obtained from a sequence by removing some or no elements from the sequence without changing the order of the remaining elements.</p>

<p>For this problem, the length of the strictly increasing subsequence and the length of the strictly decreasing subsequence should be at least 2.  In particular, an empty subsequence or a subsequence of length 1 <strong>DOES NOT</strong> strictly increase nor does it strictly decrease.  See the examples below for further illustration.</p>

<p>Some examples:</p>

<ul>
	<li>7 neither strictly increases nor strictly decreases;</li>
	<li>1 1 1 neither strictly increases nor strictly decreases;</li>
	<li>1 1 2 neither strictly increases nor strictly decreases;</li>
	<li>1 2 7 strictly increases; it does not strictly decrease;</li>
	<li>3 2 1 strictly decreases; it does not strictly increase;</li>
	<li>8 9 3 strictly increases and then strictly decreases; this is the type of subsequence your solution needs to find.</li>
</ul>

### 입력 

 <p>A positive integer $T$ $(1 \le T \le 5 \cdot 10^4)$, denoting a number of test cases, is written in the first line.</p>

<p>Each test case consists of two lines. The first line contains a positive integer $N$ $(3 \le N \le 2 \cdot 10^5)$, denoting a number of integers in the list. The second line contains $N$ integers $a_i$, each in the range of a signed 32-bit integer $(-2^{31} \le a_i \le 2^{31}-1)$.</p>

<p>For each input file, the total number of integers in the lists across all test cases will not exceed $5 \cdot 10^5$.</p>

### 출력 

 <p>For each test case, output a single non-negative integer: the maximum length among all subsequences that strictly increase and, then, strictly decrease. For example, in Sample Input 3, the subsequence <code>1 2 4 5 2 1</code> is the maximal length "up-and-down" subsequence for that input, so the output should be $6$.</p>

