# [Bronze II] Glass Reflection - 33225 

[문제 링크](https://www.acmicpc.net/problem/33225) 

### 성능 요약

메모리: 7796 KB, 시간: 40 ms

### 분류

구현, 문자열

### 제출 일자

2025년 3월 17일 20:49:36

### 문제 설명

<p>Late in the evening, you are sitting at the Funky Punk Café and feeling a bit bored because you have not done any programming all day. You stare out of the window and see that the text on the neon signs gets reflected in a funny way: the letters are partially overlapping, because the window is made of double-paned glass. Would it be possible to automatically read the text of the sign, just by looking at this mangled reflection? With a burst of sudden inspiration, you grab your laptop and OCR<sup>1</sup> camera from your bag, and start programming.</p>

<p>Your OCR camera appears to correctly recognize the letters in the reflection when it accounts for the mirroring, except that all the letters are duplicated. Moreover, if the text on the sign contains double (or more) letters, their reflection partially overlaps, resulting in only one more letter than there would be in the original word. For example, the word "<code>beer</code>" is reflected as "<code>bbeeerr</code>", and the word "<code>ooo</code>" is reflected as "<code>oooo</code>". All that is left for you to do, is to write a program that converts these reflected words back to their original form.</p>

<hr>
<p><sup>1</sup>OCR = Optical Character Recognition</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line containing a string of up to $10^6$ English lowercase letters (<code>a-z</code>), the reflected word read by your OCR camera.</li>
</ul>

### 출력 

 <p>Output the word in its original form.</p>

