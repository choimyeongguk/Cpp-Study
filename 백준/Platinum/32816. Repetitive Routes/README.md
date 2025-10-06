# [Platinum II] Repetitive Routes - 32816 

[문제 링크](https://www.acmicpc.net/problem/32816) 

### 성능 요약

메모리: 59912 KB, 시간: 260 ms

### 분류

오프라인 쿼리, mo's

### 제출 일자

2025년 10월 7일 01:42:39

### 문제 설명

<p>Tory operates a dial-in mobility service where customers can book a vehicle to come and pick them up from one location and drive them to another location to be dropped off. The vehicles used can seat many passengers, so sometimes additional stops are made along the way to pick up and drop off other passengers. Users of the service are generally tolerant of some inefficient routes, but they are less tolerant of revisiting a location that they have visited at least once on their journey already. Tory has come up with a sequence of pickups and drop offs to serve all of the passengers but he wants to know how many complaints he is likely to receive. From past experience, Tory knows that he can expect one complaint for each time a customer returns to a location that they have already been to on their journey. Note that this means that the same customer may lodge multiple complaints, and possibly for visiting the same location more than two times! Given a sequence of pickups and drop offs and their locations, determine how many complaints Tory can expect to receive.</p>

<p>The customer's pickup location and drop off location both count towards locations that they may return to and complain about. Consecutive pickups or drop offs at the same location also count as repeated visits to the same location for anyone in the vehicle at the time. The customer's drop off location may be the same as their pickup location. As per above, the customer will complain about this!</p>

### 입력 

 <p>The first line of input is the number of customers, $n$ ($1\leq n \leq 200\,000$). This is followed by $2n$ lines, each consisting of two integers. The first is a customer number from $1$ to $n$ and the second represents a location and is in the range $1$ to $2n$. Distinct location numbers correspond to distinct locations. Each customer number will appear exactly twice. The first occurrence of customer number $C$ corresponds to the pickup of customer $C$ and the second occurrence of customer number $C$ corresponds to the drop off. All lines in between correspond to locations visited and pickups and drop offs completed while customer $C$ is in the vehicle. Customer $1$ will be the first customer to be picked up. Customer $C$ will be picked up before customer $C+1$ is picked up. Similarly, location $1$ will be the pickup location of customer $1$ and a location $L+1$ will only be visited if location $L$ has been visited. There is no limit on the number of passengers that can be in the vehicle at the same time.</p>

### 출력 

 <p>Output a single integer, the number of complaints Tory can expect to receive for the sequence of pickups and drop offs.</p>

