# [Platinum III] Balancing Art - 32807 

[문제 링크](https://www.acmicpc.net/problem/32807) 

### 성능 요약

메모리: 2484 KB, 시간: 8 ms

### 분류

최대 유량, 매개 변수 탐색, 그래프 이론

### 제출 일자

2025년 10월 5일 14:15:45

### 문제 설명

<p>Pete Tencious is a world-renowned artist who specializes in mobiles. The San Francisco Museum of Art is currently displaying a collection of his artwork entitled Balance I, Balance II, Balance III, ..., you get the idea. Each of these works contains two or more spheres with wires strung between them. At the ends of each wire are a number of disks that are attached to the two spheres that the wire connects. When you sum up the number of disks at each sphere you get the same number (hence the word "Balance") --- Pete calls this the <em>balance number</em> for each mobile. On some of these wires there are also extra disks suspended between spheres. The artist says this work represents the balance of nature (the disks attached to the spheres) corrupted by the influence of humankind (the extra disks between the spheres). Clearly Pete has a much better impression of nature than people.</p>

<p>The funny thing is that Mother Nature decided to step in and throw Pete a curve. A minor earthquake in the Bay area has dislodged the disks, and they are now all hanging loose between spheres. Pete is currently working on Balance CCXLI and can't be reached, so the museum curators have to fix the mobiles themselves. They can't remember exactly what the balance number should be for each mobile, but they decide it should be as large as possible, leaving as few extra disks in between the spheres as possible (they apparently have a little better view of humankind than you-know-who). However, determining the minimum number of disks left between the spheres is a bit difficult, so they have come to you for help.</p>

<p>Figure C.1 shows the state of one mobile after the earthquake, corresponding to the first sample input. Figure C.2 shows one way the disks could be moved by the curators so that each sphere has the same number of disks, while leaving the minimum number of disks between the spheres.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 203px; height: 226px;"></p>

<p style="text-align: center;">Figure C.1: After the earthquake</p>

<p style="text-align: center;"><img alt="" src="" style="width: 203px; height: 226px;"></p>

<p style="text-align: center;">Figure C.2: Disks moved to maximize balance number</p>

### 입력 

 <p>The first line of input contains two positive integers $n$ $m$, where $n$ $(2 \leq n \leq 200)$ is the number of spheres in a mobile (numbered 1 to $n$) and $m$ $(1 \leq m \leq 500)$ is the number of wires connecting the spheres. This is followed by $m$ lines of the form $s_1$ $s_2$ $d$, where $s_1$ and $s_2$ $(1 \leq s_1, s_2 \leq n, s_1 \neq s_2)$ are two spheres connected by a wire and $d$ $(0 \leq d \leq 10\,000)$ is the number of disks hanging on the wire after the earthquake. There is at most one wire between any two spheres.</p>

### 출력 

 <p>Output the minimum number of disks left hanging on the wires between spheres after the maximum balance number has been reached.</p>

