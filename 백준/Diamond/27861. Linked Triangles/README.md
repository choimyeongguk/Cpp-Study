# [Diamond IV] Linked Triangles - 27861 

[문제 링크](https://www.acmicpc.net/problem/27861) 

### 성능 요약

메모리: 2096 KB, 시간: 0 ms

### 분류

수학, 브루트포스 알고리즘, 기하학, 3차원 기하학

### 제출 일자

2025년 9월 6일 14:31:02

### 문제 설명

<p>A triangle △ABC is linked by a triangle △DEF if</p>

<ol>
	<li>Exactly one edge of △DEF passes through the interior of △ABC(in the plane of △ABC(see figure below) OR</li>
	<li>One vertex of △DEF lies in the interior of △ABC (in the plane of △ABC) and the adjacent edges lie on opposite sides of the plane of △ABC</li>
</ol>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/08bb2d08-2f64-4cea-90e0-60fc09fc1202/-/preview/" style="width: 337px; height: 242px;"></p>

<p>It turns out that △ABC is linked by △DEF if and only if △DEF is linked by △ABC. In this case we say that △ABC and △DEF are linked.</p>

<p>A set of points in 3-dimensional space is in general position, if no four points lie in the same plane (which means no three points lie on the same line).</p>

<p>It is known that given any six points in 3-dimensional space in general position, there is at least one way to split the six points into two sets of three so that the triangles determined by the two subsets are linked. Note that if the points are in general position, case 2 above can not occur because it would have four points in the plane of △ABC.</p>

<p>Write a program which takes as input six points in 3-dimensions and outputs the number of ways of splitting the points into two sets of three which give linked triangles as well as the points in the subsets.</p>

### 입력 

 <p>Input consists of six lines containing three space separated double precision floating point values x, y and z giving the coordinates of a point, for six points in total. (-10 ≤ x,y,z ≤ 10)</p>

### 출력 

 <p>The first line of output contains a single decimal integer N, which is the number of linked triangles found.</p>

<p>The first line is followed by N additional lines each containing two space decimal integers, m and n, for which choosing points 1, m and n as one triangle and the remaining points as the other triangle give a linked pair. On each of these lines, m < n, and the lines should be in lexicographical order. That is (now pay attention), if m1 n1 is above m2 n2, then either m1 < m2 or (m1 = m2 and n1 < n2).</p>

