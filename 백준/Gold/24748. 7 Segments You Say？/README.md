# [Gold III] 7 Segments You Say? - 24748 

[문제 링크](https://www.acmicpc.net/problem/24748) 

### 성능 요약

메모리: 2116 KB, 시간: 0 ms

### 분류

구현, 런타임 전의 전처리, 문자열

### 제출 일자

2025년 7월 27일 18:02:30

### 문제 설명

<p>A seven segment LCD display provides a mechanism to display a hexadecimal digit by turning on some combination of segments to form the digits as shown below by the <span style="color:#da3832;">RED</span> segments.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 722px; height: 324px;"></p>

<p>The image above represents the entire hexadecimal character set [0-9, AbCdEF] for this particular seven segment display. Note that the digits ‘b’ and ‘d’ appear as lower-case letters to avoid the ambiguity with the digit 8 and 0 respectively. A special character where no segments are on can be used as a space.</p>

<p>Each segment is numbered 0 through 6 as shown above by the small numbers in each segment. So, for example, the digit 3 has segments 0, 2, 3, 5 and 6 turned on. Each segment can be represented by 1 bit (0 if the segment is not on and 1 if the segment is on). Each digit is represented by 7 bits. The low order bit corresponds to segment 0 and the high order bit corresponds to segment 6. For the digit 3, the bit string is “1101101”. For this problem, you will read a string of bits and display the seven segment output representation scaled in size by some factor.</p>

### 입력 

 <p>Input consists of a single line containing the scaling factor S, (1 ≤ S ≤ 8), followed by a single space, followed by a bit string consisting of 1 to 1000 zeroes and ones (0’s and 1’s). If the bit string length is not a multiple of 7, you must pad it on the left with 0’s (zeroes). Every 7 bits represents a single digit to display. Invalid digits should be displayed using the special character.</p>

### 출력 

 <p>Output consists of multiple lines depending on the number of digits to be displayed and the scaling factor. Each digit to be displayed will consist of a display cell that is S*7 rows and S*3 columns. Each horizontal segment that is on shall be composed of S lines of S*3 “X” characters and each horizontal segment that is not on shall be composed of S lines of S*3 space characters. Each vertical segment that is on shall be composed of S*2 lines of S “X” characters vertically. Each vertical segment that is not on shall be composed of S*2 lines of S space characters vertically. Vertical segments on the same row should have S space character(s) between them. Multiple digit cells will be placed next to each other leaving S*2 spaces between cells. The maximum output line length is 80 columns. Any digit cell that will not completely fit on the output row should be moved to the next line of cells, leaving S blank lines between cells and no extra space at the beginning or ends of any rows. Spaces that are part of the seven segment display should always be displayed, even at the end (or beginning) of a line.</p>

<p>Part of this problem is formatting. As such, the output will be strictly checked and must follow the format rules precisely as stated above.</p>

<p> </p>

