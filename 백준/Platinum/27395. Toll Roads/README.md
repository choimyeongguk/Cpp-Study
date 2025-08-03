# [Platinum III] Toll Roads - 27395 

[문제 링크](https://www.acmicpc.net/problem/27395) 

### 성능 요약

메모리: 113104 KB, 시간: 680 ms

### 분류

그래프 이론, 자료 구조, 트리, 이분 탐색, 분리 집합, 오프라인 쿼리, 최소 스패닝 트리, 최소 공통 조상

### 제출 일자

2025년 8월 3일 17:14:27

### 문제 설명

<p>Your state has a number of cities, and the cities are connected by roads. Unfortunately, all of the roads are toll roads!</p>

<p>You now run the local chapter of AAA (American Automobile Association), and people are constantly asking you about the tolls. In particular, they've been asking about individual tolls on any single road on a path between two cities. Odd, but that's what they've been asking!</p>

<p>Given a description of the cities in your state and the roads that connect them, and a series of queries consisting of two separate cities, for each query determine two things:</p>

<ul>
	<li>First, the smallest value such that there is a route between the two cities where no road has a toll greater than that value.</li>
	<li>Second, the number of cities reachable from your starting city using no road with a toll greater than that first value.</li>
</ul>

### 입력 

 <p>The first line of input contains three integers $n$ ($2 \le n \le 2 \times 10^5$), $m$ ($1 \le m \le 2 \times 10^5$) and $q$ ($1 \le q \le 2 \times 10^5$), where $n$ is the number of cities, $m$ is the number of roads, and $q$ is the number of queries. The cities are each identified by a number $1$ through $n$.</p>

<p>Each of the next $m$ lines contains three integers $u$, $v$ ($1 \le u,v \le n, u \ne v$) and $t$ ($0 \le t \le 2 \times 10^5$), which represents a road between cities $u$ and $v$ with toll $t$. The roads are two-way, and the toll is the same in either direction. It is guaranteed that there is a path between any two cities, and that there is at most one road between any two cities.</p>

<p>Each of the next $q$ lines contains two integers $a$ and $b$ ( $1 \le a,b \le n, a \ne b$). This represents a query about a path from $a$ to $b$.</p>

### 출력 

 <p>Output $q$ lines. Each line is an answer to a query, in the order that they appear. Output two space-separated integers, $w$ and $k$, on each line, where $w$ is the smallest amount such that there is a route from $a$ to $b$ with no toll greater that $w$, and $k$ is the number of cities reachable from $a$ using no road with a toll greater than $w$.</p>

