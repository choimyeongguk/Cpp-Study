# [Gold I] Jesting Jabberwocky - 26020 

[문제 링크](https://www.acmicpc.net/problem/26020) 

### 성능 요약

메모리: 5172 KB, 시간: 108 ms

### 분류

브루트포스 알고리즘, 다이나믹 프로그래밍

### 제출 일자

2025년 8월 2일 11:48:27

### 문제 설명

<p style="text-align: center;"><img alt="" src="" style="width: 200px; height: 179px;"></p>

<p style="text-align: center;">Figure J.1: In Sample 1, Alice has to move at least two cards to sort her hand.</p>

<p>The famous card game manufacturer <em>Greatest Cards Production Company</em> (GCPC) has just created the brand new card game <em>Jabberwocky</em>. In this game, everyone gets the same amount of cards -- which might be quite a lot -- and each card belongs to one of four different suits: hearts, diamonds, clubs, or spades.</p>

<p>As huge card game nerds, Alice and her friends are very hyped about meeting up and trying out the card game everybody seems to talk about these days. Due to a traffic jam, Alice is a bit late to the party and her friends are impatiently waiting for her. They have already distributed all cards and everybody is ready to go, except for Alice. She has just picked up her cards and insists on sorting them by suit first. For that, she repeatedly picks one card from her hand and inserts it somewhere else until her cards are grouped by suit. Her friends are getting increasingly annoyed with Alice and she wants to sort her cards as quickly as possible. How many cards does Alice need to move before they can start playing?</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with a string $s$ ($1\leq|s|\leq 10^5$), representing the suits of Alice's cards as they are initially ordered. The string consists of the characters <code>h</code>, <code>d</code>, <code>c</code>, and <code>s</code> (hearts, diamonds, clubs and spades).</li>
</ul>

### 출력 

 <p>Output a single integer, the minimum number of cards Alice has to move in order to sort the cards by suit.</p>

