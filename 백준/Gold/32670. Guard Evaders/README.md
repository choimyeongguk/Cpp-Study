# [Gold III] Guard Evaders - 32670 

[문제 링크](https://www.acmicpc.net/problem/32670) 

### 성능 요약

메모리: 2088 KB, 시간: 72 ms

### 분류

자료 구조, 그래프 이론, 그래프 탐색, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵, 집합과 맵

### 제출 일자

2025년 10월 3일 16:59:35

### 문제 설명

<p>Here is a new game to play. You and a team of your friends sequentially run through a row of guards (a bit like in the playground game "Rover, Red Rover.") The guards may be facing forward, left, or right. When facing forward, they can't see you coming until it's too late, because they have very limited peripheral vision. (Perhaps they wear blinders.) They can similarly not see you if they are facing sideways away from you as you come through. However, as soon as you pass between a pair of guards, they do hear you and turn to face where you came through, so that if you tried to pass through the same pair of guards again they would be positioned to stop you. Two guards stop a player trying to pass between them if at least one of them is facing the gap that the player attempts to run through.</p>

<p>More formally: Given a row of $g$ guards labeled $1$ through $g$ from left to right, each player chooses to run through the gap between guards $i$ and $i+1$ (for some $1 \leq i \leq g-1$). A player cannot run to the left of the first guard or to the right of the last. If either guard $i$ is facing right or guard $i+1$ is facing left (or both), the player is caught. Otherwise, guard $i$ turns to face right and guard $i+1$ turns to face left. No other guards change orientation.</p>

<p>Given how the guards are initially facing and the number of players $p$ on your team, can all $p$ players run through the guards without getting caught?</p>

### 입력 

 <p>The first line of input contains two positive integers: the number of guards $g$ $(2 \leq g \leq 10)$ and the number of players on your team $p$ $(1\leq p \leq 50)$. The second line contains a string of uppercase letters representing the directions each of the guards is initially facing. Each character in the string is either <code>L</code> (left), <code>F</code> (forward), or <code>R</code> (right). The first illustration shows four guards configured according to input string <code>RFRL</code>.</p>

### 출력 

 <p>If with optimal play all players can make it past the guards without getting caught, print <code>1</code>. Otherwise print <code>0</code>.</p>

