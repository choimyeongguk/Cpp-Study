# [Gold II] Brownian Bears - 32808 

[문제 링크](https://www.acmicpc.net/problem/32808) 

### 성능 요약

메모리: 2756 KB, 시간: 108 ms

### 분류

수학, 다이나믹 프로그래밍, 확률론

### 제출 일자

2025년 10월 5일 15:13:07

### 문제 설명

<p>Dr. Ursula Major is an internationally renowned expert in the study of bears, specifically brown bears, which are known in many parts of North America as grizzly bears. She is most famous for her discovery of an extremely rare brown bear subspecies --- the <em>Brownian bear</em>, whose feeding behavior seems to be guided by an intriguing mixture of regularity and randomness.</p>

<p>At present, Dr. Major is studying a pair of Brownian bears living on a narrow strip of land that is oriented east-west. This territory has $n$ evenly spaced locations where the bears can forage for berries, and Dr. Major has labelled these locations $1, 2, \ldots, n$ from west to east. Every morning, each Brownian bear wakes up in one of the $n$ locations and randomly chooses to move either east or west to the neighboring location. What is remarkable is that the probability of moving in either direction is exactly $50\%!$ (Dr. Major's working theory is that this is rooted in some kind of quantum mechanical phenomenon in the bears' brains.) If a bear happens to start the day in one of the end locations ($1$ or $n$), then it will randomly choose between moving to the sole neighboring location or staying where it is. After making its choice, the bear spends the day foraging for berries in the chosen location, and then also sleeps there that night. The next morning, the process begins all over again.</p>

<p>Dr. Major is particularly interested in days when the two bears forage together, i.e., in the same location, so she plans to observe them over a period of time, possibly as long as a month (or until her funding runs out). At the beginning of the first observation day, the two bears wake up in different locations. Can you help Dr. Major determine the probability that the two bears will forage together for at least one day during the course of her experiment?</p>

<p>Note that the two bears can move past each other without foraging together. For example, if the bears start a particular day in locations $4$ and $5$, and if the bear in location $4$ moves east and the bear in location $5$ moves west, then the bears simply pass each other that morning without foraging together.</p>

### 입력 

 <p>The input consists of a single line containing four integers, $n$ $x$ $y$ $d$, where $n$ $(2 \leq n \leq 100)$ is the number of locations, $x$ and $y$ $(1 \leq x, y \leq n, x \neq y)$ are the locations where the two bears wake up at the beginning of the first observation day, and $d$ $(1 \leq d \leq 31)$ is the number of observation days.</p>

### 출력 

 <p>Output a line containing the probability that the two bears forage together for at least one day during the $d$ observation days. Express this probability as a fraction $a/b$ in lowest terms, where $a$ is a non-negative integer and $b$ is a positive integer. See the sample outputs for examples.</p>

