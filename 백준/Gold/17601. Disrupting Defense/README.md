# [Gold I] Disrupting Defense - 17601 

[문제 링크](https://www.acmicpc.net/problem/17601) 

### 성능 요약

메모리: 2220 KB, 시간: 0 ms

### 분류

그리디 알고리즘

### 제출 일자

2025년 7월 22일 15:50:45

### 문제 설명

<p>You are playing a tactical game and facing a brutal combat. Your rival’s commander uses a circular formation to protect their headquarter, and you have to disrupt their defense to win the battle. The enemy’s circular formation consists of n soldiers numbered from 1 to n. In the beginning, soldier i and soldier j are adjacent if |i − j| ∈ {1, n − 1}.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/e6e8ddce-696e-478d-91f4-5af3fd8e884d/-/crop/393x385/64,15/-/preview/" style="width: 194px; height: 190px;"></p>

<p>You only have a small crew of warriors. Your force is too weak to fight more than two soldiers or any two soldiers who are not adjacent. Moreover, if you try to attack a single soldier, both of their adjacent soldiers will come to the rescue. In such situation, it is equivalent to fighting three soldiers. Thus, you may only launch attacks to aim at the gap between two adjacent soldiers. By doing so, you have a chance to take down these two soldiers. Your enemy will fill the gap after your attack. For example, soldiers 3 and n will become adjacent if you take down soldiers 1 and 2. You can repeatedly take down the soldiers until no one can defend their headquarter.</p>

<p>Unfortunately, you are still unable to defeat them in some situations. Each of the soldiers has their own value, and there are at most k different kinds of values in total. You should have heard “United we stand, divided we fall” before. The soldiers with the same value can unite, and the soldiers with different values cannot. When you attack two soldiers with different values, you always take them down. But when you attack two soldiers with the same value, they will not fall.</p>

<p>Please write a program to find out an attacking strategy to win the battle by disrupting the enemy’s defense. That is, take down all n soldiers of the circular formation.</p>

### 입력 

 <p>The first line contains two integers n and k. n is the number of enemy soldiers. k is the number of kinds of different values. Their values are numbered from 1 to k. The second line contains n integers v<sub>1</sub>, . . . , v<sub>n</sub> where soldier i’s value is v<sub>i</sub> for i ∈ {1, . . . , n}.</p>

### 출력 

 <p>If there is no way to disrupt the enemy’s defense, output −1. Otherwise, output n/2 lines. The i-th line describes your i-th attack with two integers p<sub>i</sub> and q<sub>i</sub> separated by a blank. Your i-th attack is to take down soldiers p<sub>i</sub> and q<sub>i</sub>. At that time, they must be adjacent and have different values.</p>

