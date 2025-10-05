# [Bronze II] A Stack of Gold - 32805 

[문제 링크](https://www.acmicpc.net/problem/32805) 

### 성능 요약

메모리: 2084 KB, 시간: 0 ms

### 분류

수학, 사칙연산

### 제출 일자

2025년 10월 5일 13:24:35

### 문제 설명

<p>Lt. Columbo, arguably the best detective in the world, was faced with a problem. He was asked: if he was placed in a room with some number of stacks of gold-colored coins, where all but one stack consisted solely of tungsten coins, and the remaining stack consisted solely of pure gold coins, how could he determine which stack had the pure gold coins? Oh, excuse me, there's just one more thing... he was also told he is given a modern penny scale and one penny. A modern version of the penny scale operates as follows: when you deposit a penny and put an object (or objects) on the scale, the machine displays the weight on a digital display. The scale is extremely accurate, down to milligrams. Every coin is the same size and color, but the tungsten coins weigh $29\,260$ mg each and the gold coins weigh $29\,370$ mg each.</p>

<p>Being the genius that he is, Columbo came up with the solution to figure out which stack contained the gold coins using a single weighing (since he has only one penny for the penny scale). As an example, suppose there are four stacks of coins labeled $1$ through $4$. If he took one coin from stack $1$, two coins from stack $2$, three coins from stack $3$ and four coins from stack $4$, and weighed those $10$ coins together on the penny scale, he could determine which stack had the gold coins. "How?" you might ask. Suppose all four stacks were tungsten. The total weight of the $10$ coins would be $292\,600$ mg. If, say, stack $1$ was gold (one gold coin in the pile that was weighed), the total weight would be $292\,710$ mg. If stack $2$ was gold (two gold coins in the pile that was weighed), the total weight would be $292\,820$ mg. So, if you know the number of coins being weighed and the total weight of those coins, you can determine which stack has the gold coins. Just as a reminder, given a number of stacks, $s$, the number of coins, $c$, being weighed will be:</p>

<p>\[c = \frac{s(s+1)}{2}\]</p>

### 입력 

 <p>Input consists of a single line containing two integers $w$ $s$, where $w$ ($87\,890 \leq w \leq 147\,774\,000$) is the weight in milligrams reported by the scale and $s$ ($2 \leq s \leq 100$) is the number of coin stacks. The stacks are labeled $1$ to $s$ with $i$ coins from stack $i$ moved to the scale for $1 \leq i \leq s$. For given values of $w$ and $s$, it will always be possible to determine which stack is composed solely of gold coins.</p>

### 출력 

 <p>Output consists of a single positive integer indicating which stack contains the gold coins.</p>

