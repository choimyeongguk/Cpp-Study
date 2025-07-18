# [Gold III] Jelly Raid - 11489 

[문제 링크](https://www.acmicpc.net/problem/11489) 

### 성능 요약

메모리: 3424 KB, 시간: 8 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 6월 29일 01:16:10

### 문제 설명

<p>The full-board residents of the famous but misnamed Adephagia School For Boys feel hard done by. Recent savings have seen dinnertime puddings cut back to a single biscuit while the masters finish their meals with fine raspberry jelly every night. Although the choice of custard cream or bourbon is not a bad one, the children hunger for the raspberry-filled delight and have planned a midnight raid.</p>

<p>A child must make it from their dorm, across the school to the kitchen without being seen by the patrolling masters. In any turn a child can stand still, or move to a horizontally or vertically neighbouring cell. Each turn the patrolling masters will move a step along their route. When they reach the end of their route, they will turn and continue to retrace their steps indefinitely. A child will be caught if the child and a master are on the same row or column with no blocked area between them.</p>

<p>If the child can make it to the fridge in the kitchen unseen, we recognise they can either make it back to their bed unseen or get caught fully of jelly and not care. See the first example, where the child can reach the fridge after 26 turns, even though it gets spotted at that same time.</p>

### 입력 

 <ul>
	<li>One line consisting of two positive integers r c (1 < r, c ≤ 60), the size of the school in rows and columns.</li>
	<li>One line consisting of two pairs of bracketed positive integers, the row and column coordinates of the starting bed in the dormitory and the fridge in the kitchen respectively.</li>
	<li>Another r lines, each containing a string of c characters with the following meaning:
	<ul>
		<li>’.’: Walkable area</li>
		<li>’#’: Blocked area</li>
	</ul>
	</li>
	<li>One line consisting of a single integer p (1 ≤ p ≤ 200) representing the number of patrolling masters.</li>
	<li>Another p lines, each a size-prefixed list of between 1 and 7 space-separated bracketed (r, c) coordinates representing a contiguous path for the master to patrol.</li>
</ul>

<p>All ‘special’ coordinates (locations of the bed, fridge, and masters) will be marked as walkable on the map.</p>

### 출력 

 <p>On a single line print the minimum number of turns for the child to reach the jelly. If the child cannot reach the jelly, output IMPOSSIBLE.</p>

