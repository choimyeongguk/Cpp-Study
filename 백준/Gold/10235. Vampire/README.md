# [Gold III] Vampire - 10235 

[문제 링크](https://www.acmicpc.net/problem/10235) 

### 성능 요약

메모리: 2236 KB, 시간: 0 ms

### 분류

기하학, 구현

### 제출 일자

2025년 7월 26일 10:50:38

### 문제 설명

<p>Mr. C is a vampire. If he is exposed to the sunlight directly, he turns into ash. Nevertheless, last night, he attended to the meeting of Immortal and Corpse Programmers Circle, and he has to go home in the near dawn. Fortunately, there are many tall buildings around Mr. C's home, and while the sunlight is blocked by the buildings, he can move around safely. The top end of the sun has just reached the horizon now. In how many seconds does Mr. C have to go into his safe coffin?</p>

<p>To simplify the problem, we represent the eastern dawn sky as a 2-dimensional <i>x</i>-<i>y</i> plane, where the <i>x</i> axis is horizontal and the <i>y</i> axis is vertical, and approximate building silhouettes by rectangles and the sun by a circle on this plane.</p>

<p>The <i>x</i> axis represents the horizon. We denote the time by <i>t</i>, and the current time is <i>t</i>=0. The radius of the sun is <i>r</i> and its center is at (0, -<i>r</i>) when the time <i>t</i>=0. The sun moves on the <i>x</i>-<i>y</i> plane in a uniform linear motion at a constant velocity of (0, 1) per second.</p>

<p>The sunlight is blocked if and only if the entire region of the sun (including its edge) is included in the union of the silhouettes (including their edges) and the region below the horizon (y ≤ 0).</p>

<p>Write a program that computes the time of the last moment when the sunlight is blocked.</p>

<p>The following figure shows the layout of silhouettes and the position of the sun at the last moment when the sunlight is blocked, that corresponds to the first dataset of Sample Input below. As this figure indicates, there are possibilities that the last moment when the sunlight is blocked can be the time <i>t</i>=0.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/cd6abdc7-bb76-4eeb-b633-194e8f9ed9d9/-/preview/"></p>

<p>The sunlight is blocked even when two silhouettes share parts of their edges. The following figure shows the layout of silhouettes and the position of the sun at the last moment when the sunlight is blocked, corresponding to the second dataset of Sample Input. In this dataset the radius of the sun is 2 and there are two silhouettes: the one with height 4 is in -2 ≤ <i>x</i> ≤ 0, and the other with height 3 is in 0 ≤ <i>x</i> ≤ 2.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/601b7067-456b-4f46-97ea-ac8d601fbe39/-/preview/"></p>

### 입력 

 <p>The input consists of multiple datasets. The first line of a dataset contains two integers <i>r</i> and <i>n</i> separated by a space. <i>r</i> is the radius of the sun and <i>n</i> is the number of silhouettes of the buildings. (1 ≤ <i>r</i> ≤ 20, 0 ≤ <i>n</i> ≤ 20)</p>

<p>Each of following <i>n</i> lines contains three integers <i>x<sub>li</sub></i>, <i>x<sub>ri</sub></i>, <i>h<sub>i</sub></i> (1 ≤ <i>i</i> ≤ <i>n</i>) separated by a space.</p>

<p>These three integers represent a silhouette rectangle of a building. The silhouette rectangle is parallel to the horizon, and its left and right edges are at <i>x</i> = <i>x<sub>li</sub></i> and <i>x</i> = <i>x<sub>ri</sub></i>, its top edge is at <i>y</i> = <i>h<sub>i</sub></i>, and its bottom edge is on the horizon. (-20 ≤ <i>x<sub>li</sub></i> < <i>x<sub>ri</sub></i> ≤ 20, 0 < <i>h<sub>i</sub></i> ≤ 20)</p>

<p>The end of the input is indicated by a line containing two zeros separated by a space.</p>

<p>Note that these silhouettes may overlap one another.</p>

### 출력 

 <p>For each dataset, output a line containing the number indicating the time <i>t</i> of the last moment when the sunlight is blocked. The value should not have an error greater than 0.001. No extra characters should appear in the output.</p>

