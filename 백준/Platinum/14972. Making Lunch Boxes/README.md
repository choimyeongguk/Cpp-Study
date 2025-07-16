# [Platinum V] Making Lunch Boxes - 14972 

[문제 링크](https://www.acmicpc.net/problem/14972) 

### 성능 요약

메모리: 222424 KB, 시간: 5188 ms

### 분류

비트마스킹, 브루트포스 알고리즘, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2025년 7월 16일 11:31:06

### 문제 설명

<p>Taro has been hooked on making lunch boxes recently. Taro has obtained a new lunch box recipe book today, and wants to try as many of the recipes listed in the book as possible.</p>

<p>Enough of the ingredients for all the recipes are at hand, but they all are in vacuum packs of two. If only one of them is used leaving the other, the leftover will be rotten easily, but making two of the same recipe is not interesting. Thus he decided to make a set of lunch boxes, each with different recipe, that wouldn't leave any unused ingredients.</p>

<p>Note that the book may include recipes for different lunch boxes made of the same set of ingredients.</p>

<p>How many lunch box recipes can Taro try today at most following his dogma?</p>

### 입력 

 <p>The input consists of at most 50 datasets, each in the following format.</p>

<pre><em>n</em> <em>m</em>
<em>b</em><sub>1,1</sub>...<em>b</em><sub>1,<em>m</em></sub> 
... 
<em>b</em><sub><em>n,</em>1</sub>...<em>b</em><sub><em>n,m</em></sub> 
</pre>

<p>The first line contains <em>n</em>, which is the number of recipes listed in the book, and <em>m</em>, which is the number of ingredients. Both <em>n</em> and <em>m</em> are positive integers and satisfy 1 ≤ <em>n</em> ≤ 500, 1 ≤ <em>m</em> ≤ 500 and <strong>1 ≤ <em>n</em> × <em>m</em> ≤ 500</strong>. The following <em>n</em> lines contain the information for each recipe with the string of length <em>m</em> consisting of 0 or 1. <em>b<sub>i,j</sub></em> implies whether the <em>i</em>-th recipe needs the <em>j</em>-th ingredient. 1 means the ingredient is needed for the recipe and 0 means not. Each line contains at least one 1.</p>

<p>The end of the input is indicated by a line containing two zeros.</p>

### 출력 

 <p>For each dataset, output the maximum number of recipes Taro can try.</p>

