# [Platinum IV] Forest for the Trees - 30530 

[문제 링크](https://www.acmicpc.net/problem/30530) 

### 성능 요약

메모리: 2552 KB, 시간: 312 ms

### 분류

그래프 이론, 자료 구조, 브루트포스 알고리즘, 정렬, 기하학, 집합과 맵, 해시를 사용한 집합과 맵, 두 포인터

### 제출 일자

2025년 9월 28일 19:11:50

### 문제 설명

<p>You have sent a robot out into the forest, and it has gotten lost.  It has a sensor that will detect all the trees around itself regardless of any occlusions, but unfortunately in this forest, all trees look alike.  You do have a map of all trees in the forest, represented as $(x,y)$ points.  Conveniently, since this used to be a tree farm, all trees are at integer coordinates, though not all coordinates are occupied.  The robot's sensor tells you the $x$ and $y$ distance to each tree within range, relative to the front of the robot.  However, the robot is heading in an unknown direction relative to the map, so each sensor reading is given as a tuple of (distance to the right of the robot, distance forward of the robot) and either value can be negative since the robot can sense in all directions.  Helpfully, the robot will always place itself at integer coordinates and aligned to the positive or negative $x$ or $y$ axis, and will never be at the same location as a tree.  Can you find out where the robot is?</p>

### 입력 

 <p>The first line of input contains three integers: $n_t$, the number of trees in the forest, $n_s$, the number of trees sensed by the robot, and $r_{max}$, the maximum Manhattan distance (sum of $x$ and $y$ distances) of any sensor reading.  The next $n_t$ lines each contain two integers representing the $(x,y)$ locations of all the trees relative to a global coordinate system.  The final $n_s$ lines each contain two integers.  The first integer in the $i^{th}$ sensor reading, $s_{i,x}$, represents the distance to the tree along the axis perpendicular to the robot's heading and the second integer $s_{i,y}$ represents the distance along the axis parallel to the robot's heading.  You can assume that $|s_{i,x}|+|s_{i,y}| \leq r_{max}$ for all $i$.  You may also assume $0 < n_t \leq 5000$, $0 < n_s \leq 1000$, $0 < r_{max} \leq 1000$, and all tree locations have $x$ and $y$ coordinates $-100,000 \leq x,y \leq 100,000$.</p>

### 출력 

 <p>Print one of the following: the $x,y$ location of the robot, printed as two integers separated by a space; "Impossible" if there is no location in the map that could produce the given sensor values, or "Ambiguous" if two or more distinct locations and/or orientations could produce the given sensor values.</p>

