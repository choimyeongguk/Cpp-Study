# [Unrated] Make Your Own Morse Code Palindrome - 30539 

[문제 링크](https://www.acmicpc.net/problem/30539) 

### 성능 요약

메모리: 2116 KB, 시간: 0 ms

### 분류

분류 없음

### 제출 일자

2025년 9월 28일 18:26:11

### 문제 설명

<p>A <em>palindrome</em> is a word, number, phrase, or other sequence of characters which reads the same backward as forward, such as <em>madam</em> or <em>racecar</em> or <em>1881</em>. <em>Phrase palindromes</em> ignore capitalization, punctuation, and word boundaries. For example:</p>

<p style="text-align: center;"><strong>Madam I'm Adam.</strong></p>

<p><em>Morse code</em> is a method used in telecommunication to encode text characters as standardized sequences of two different signal durations, called dots and dashes, or dits and dahs. Morse code is named after Samuel Morse, one of the inventors of the telegraph. The International Morse code for letters and digits (the code does not distinguish between upper and lower case) is:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a17efcd3-9cce-4496-a93f-419cd5e20cf5/-/preview/" style="width: 630px; height: 453px;"></p>

<p>A word, number or phrase is a <em>Morse Code Palindrome</em> if the morse code for the letters and digits in the word, number or phrase reads the same backwards or forwards (ignoring spaces between character codes.</p>

<p>For example:</p>

<p>159</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a212872b-2847-4c21-8db0-8aff8ad8482f/-/preview/" style="width: 370px; height: 12px;"></p>

<p>Footstool</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/95df86eb-2236-40b5-bbfd-ffa88f4c8581/-/preview/" style="width: 534px; height: 12px;"></p>

<p>Write a program which takes as input a string and determines the <em>smallest</em> number of characters to append to the end of the word to make it a Morse Code Palindrome.</p>

### 입력 

 <p>Input consists of a single line containing a string of up to 30 capital letters and/or digits possibly including spaces and punctuation.</p>

### 출력 

 <p>The output consists of a single line.</p>

<p>If the input string is already a Morse Code Palindrome, output the digit 0. Otherwise output the number of characters to append, followed by a single space followed by a string containing capital letters and/or digits to append to make the input a Morse Code Palindrome.</p>

<p>Since there may be more than one valid answer (see samples 2 and 3 below), a result will be judged correct if the number of appended characters is less than or equal to the judges’ answer and the input followed by your output is a Morse Code Palindrome.</p>

