# [Unrated] Movie Night - 27390 

[문제 링크](https://www.acmicpc.net/problem/27390) 

### 성능 요약

메모리: 20708 KB, 시간: 56 ms

### 분류

분류 없음

### 제출 일자

2025년 8월 3일 15:58:32

### 문제 설명

<p>You're trying to organize an outing to a movie with a group of friends. This is made complicated by the fact that your friends will decide whether to come based on who else is coming. If you give one of your friends a call, you know you're going to have a conversation like this:</p>

<ul>
	<li><strong>You</strong>: "Hi Fred, want to come with us to the 7:30 showing of Coding Horror from the Accidentally Quadratic Lagoon?"</li>
	<li><strong>Fred</strong>: "Well, I dunno... is Francine coming?"</li>
</ul>

<p>In fact, for each one of your friends <em>X</em>, there is exactly one other friend <em>Y</em> such that <em>X</em> will come only if <em>Y</em> also comes. Of course, you must invite a subset of your friends such that everyone invited knows who else is invited and will be willing to come, and no one uninvited will need to come.</p>

<p>The question is, how many such subsets of your friends are there? You don't want to go to the movies alone, so every set must have at least one friend.</p>

### 입력 

 <p>The first line of input contains an integer $n$ ($2 \le n \le 10^5$). This is the number of friends you might invite to the movie. You identify your friends by a number from 1 to $n$.</p>

<p>Each of the next $n$ lines contains a single integer $y$ ($1 \le y \le n$). This indicates that friend $x$ will only go to the movie if friend $y$ also goes to the movie, where $x$ is $1$ for the first $y$ value, $2$ for the second $y$ value, and so on. No one will be their own friend! (i.e., $x \ne y$)</p>

### 출력 

 <p>Output a single integer, which is the number of distinct nonempty subsets of your friends you could invite such that everyone you invite will be willing to come. Since this number may be quite large, output it modulo $10^9 + 7$.</p>

