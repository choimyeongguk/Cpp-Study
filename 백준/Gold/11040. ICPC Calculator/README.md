# [Gold III] ICPC Calculator - 11040 

[문제 링크](https://www.acmicpc.net/problem/11040) 

### 성능 요약

메모리: 2092 KB, 시간: 0 ms

### 분류

구현, 자료 구조, 스택

### 제출 일자

2025년 6월 27일 12:07:50

### 문제 설명

<p>In mathematics, we usually specify the order of operations by using parentheses. For example, 7 × (3 + 2) always means multiplying 7 by the result of 3 + 2 and never means adding 2 to the result of 7 × 3. However, there are people who do not like parentheses. International Counter of Parentheses Council (ICPC) is attempting to make a notation without parentheses the world standard. They are always making studies of such no-parentheses notations.</p>

<p>Dr. Tsukuba, a member of ICPC, invented a new parenthesis-free notation. In his notation, a single expression is represented by multiple lines, each of which contains an addition operator (+), a multiplication operator (*) or an integer. An expression is either a single integer or an operator application to operands. Integers are denoted in decimal notation in one line. An operator application is denoted by a line of its operator immediately followed by lines denoting its two or more operands, each of which is an expression, recursively. Note that when an operand is an operator application, it comprises multiple lines.</p>

<p>As expressions may be arbitrarily nested, we have to make it clear which operator is applied to which operands. For that purpose, each of the expressions is given its nesting level. The top level expression has the nesting level of 0. When an expression of level n is an operator application, its operands are expressions of level n + 1. The first line of an expression starts with a sequence of periods (.), the number of which indicates the level of the expression.</p>

<p>For example, 2 + 3 in the regular mathematics is denoted as in Figure 1. An operator can be applied to two or more operands. Operators + and * represent operations of summation of all operands and multiplication of all operands, respectively. For example, Figure 2 shows an expression multiplying 2, 3, and 4. For a more complicated example, an expression (2 + 3 + 4) × 5 in the regular mathematics can be expressed as in Figure 3 while (2 + 3) × 4 × 5 can be expressed as in Figure 4.</p>

<pre>+
.2
.3</pre>

<p>Figure 1: 2 + 3</p>

<pre>*
.2
.3
.4</pre>

<p>Figure 2: An expression multiplying 2, 3, and 4</p>

<pre>*
.+
..2
..3
..4
.5</pre>

<p>Figure 3: (2 + 3 + 4) × 5</p>

<pre>*
.+
..2
..3
.4
.5</pre>

<p>Figure 4: (2 + 3) × 4 × 5</p>

<p>Your job is to write a program that computes the value of expressions written in Dr. Tsukuba's notation to help him.</p>

### 입력 

 <p>The input consists of multiple datasets. Each dataset starts with a line containing a positive integer n, followed by n lines denoting a single expression in Dr. Tsukuba's notation.</p>

<p>You may assume that, in the expressions given in the input, every integer comprises a single digit and that every expression has no more than nine integers. You may also assume that all the input expressions are valid in the Dr. Tsukuba's notation. The input contains no extra characters, such as spaces or empty lines.</p>

<p>The last dataset is immediately followed by a line with a single zero.</p>

### 출력 

 <p>For each dataset, output a single line containing an integer which is the value of the given expression.</p>

