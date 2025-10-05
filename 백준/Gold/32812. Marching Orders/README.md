# [Gold III] Marching Orders - 32812 

[문제 링크](https://www.acmicpc.net/problem/32812) 

### 성능 요약

메모리: 2092 KB, 시간: 0 ms

### 분류

수학, 정수론, 중국인의 나머지 정리

### 제출 일자

2025년 10월 5일 14:43:55

### 문제 설명

<p>Dean Bob Roberts is in charge of the order in which the professors of his college march in the graduation ceremonies. Because of complaints among certain professors from the newly created DEI Studies Department, it has been decided that the order in which they march should not be based on seniority but should be random. Bob thinks this is fine, and to be totally transparent he has communicated the following method he will use to create the marching list: He starts with an alphabetically ordered list of $n$ professors numbered $0, 1, \ldots, n-1$ and a non-negative integer $m < 10^{9}$. Then the first person in the marching list is the one in position $m$ mod $n$ in the alphabetic list. This shortens the alphabetic list by one, shifting down all those in positions greater than $m$ mod $n$.  The second person in the marching list is the one in position $m$ mod $(n-1)$, and so on.</p>

<p>For example, assume we have $6$ professors A, B, C, D, E and F. If $m = 11679$, then the marching list is created as follows:</p>

<table class="table table-bordered td-center th-center table-center-50">
	<thead>
		<tr>
			<th>$n$</th>
			<th>$m$ mod $n$</th>
			<th>alphabetic list</th>
			<th>marching list</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>6</td>
			<td>3</td>
			<td>A B C D E F</td>
			<td>D</td>
		</tr>
		<tr>
			<td>5</td>
			<td>4</td>
			<td>A B C E F</td>
			<td>D F</td>
		</tr>
		<tr>
			<td>4</td>
			<td>3</td>
			<td>A B C E</td>
			<td>D F E</td>
		</tr>
		<tr>
			<td>3</td>
			<td>0</td>
			<td>A B C</td>
			<td>D F E A</td>
		</tr>
		<tr>
			<td>2</td>
			<td>1</td>
			<td>B C</td>
			<td>D F E A C</td>
		</tr>
		<tr>
			<td>1</td>
			<td>0</td>
			<td>B</td>
			<td>D F E A C B</td>
		</tr>
	</tbody>
</table>

<p>This sounds fair, but is not as transparent as some professors would like as Dean Roberts does not make public the value of $m$ that he uses. This makes it difficult to determine if he is actually following the method he has stated or has just selected the marching order based on his personal whims and biases. What the faculty would like to know is, for a given marching order, is there a value of $m$ which would produce that order?</p>

### 입력 

 <p>The first line of input contains a single decimal integer $n$ $(5 \leq n \leq 20)$, the number of professors who will be marching. The second line consists of a string containing a permutation of the first $n$ uppercase letters of the alphabet, giving the proposed marching order.</p>

### 출력 

 <p>If the given marching order could not have come from the algorithm, output a single line containing the word <code>NO</code>. Otherwise, output two lines, the first containing the word <code>YES</code> and the second containing the smallest non-negative value of $m$ which could produce the given marching order.</p>

