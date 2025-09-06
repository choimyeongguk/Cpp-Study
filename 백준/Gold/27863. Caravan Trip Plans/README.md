# [Gold V] Caravan Trip Plans - 27863 

[문제 링크](https://www.acmicpc.net/problem/27863) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

수학, 조합론

### 제출 일자

2025년 9월 6일 11:27:05

### 문제 설명

<p>A caravan route is a sequence of camping locations a bit less than a day’s travel apart. The camping locations can be either dry camps with little water or oases with plentiful water and perhaps fodder to animals. A caravan trip always starts and ends at an oasis and never goes back to a previous camp. A caravan trip is a destination oasis and a number of days to get there. For example, if the oases are at camps 2, 3, 5, 7, 11, etc. and the caravan wants to meet another caravan at camp 7 in 10 days, the caravan can wait 3 days and then go directly to camp 7, or leave now and wait 3 days at camp 7, or wait 1 day at each of camps 2, 3 and 5. A caravan trip plan is the choice of which camps to be at each night. For example, waiting 1 day at each of 2, 3, 5 gives a trip plan 1, 2, 2, 3, 3, 4, 5, 5, 6, 7.</p>

<p>Write a program which takes as input the locations of the oases on a caravan route and a caravan trip destination and number of days and outputs the number of distinct trip plans.</p>

<p>For example: with oases at camps 2, 3, 5, 7, 11, a 7 day trip to camp 5 has 10 trip plans as shown below (0 means rest at start).</p>

<pre>0012345, 0122345, 0123345, 0123455, 1222345, 1223345, 1223455, 1233345, 1233455, 1234555</pre>

### 입력 

 <p>Input consists of multiple lines of input. The first line of input contains two space separated decimal integers N and M, where N is the number of oasis locations to be specified and M is the number of caravan trips for which the number of trip plans are to be found (5 ≤ N ≤ 20, 1 ≤ M ≤ 10).</p>

<p>The second line of input contains N space separated decimal integers giving the number of days, O<sub>n</sub>, to each oasis in increasing (O<sub>n-1</sub> < O<sub>n</sub>) order (1 ≤ O<sub>n</sub> ≤ 60).</p>

<p>The remaining M input lines each contain two space separated decimal integers D<sub>m</sub> and T<sub>m</sub>, where D<sub>m</sub> is the index of the destination oasis in the list and T<sub>m</sub> is the number of days to get there: (1 ≤ D<sub>m</sub> ≤ N, O[D<sub>m</sub>] ≤ T<sub>m</sub> ≤ 60)</p>

### 출력 

 <p>There are M lines of output. The k-th output line contains a single decimal integer giving the number of distinct trip plans for a caravan over the route of camps in the second input line with the trip as specified in input line k+2.</p>

