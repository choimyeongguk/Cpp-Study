# [Platinum IV] LED - 16361 

[문제 링크](https://www.acmicpc.net/problem/16361) 

### 성능 요약

메모리: 9120 KB, 시간: 92 ms

### 분류

이분 탐색, 매개 변수 탐색

### 제출 일자

2025년 11월 13일 13:14:33

### 문제 설명

<p>A Light-Emitting Diode (LED) is a semiconductor light source, which emits light when an electric current of voltage higher than a threshhold is applied to its leads. ACM R&D recently reported that they have succesfully developed a new LED, namely, ACMOLED. An ACMOLED has a special behavior that the intensity of light emitted from it changes in two steps as the voltage of the electric current increases, as depicted in the graph below.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/90a93b1d-f721-458a-a7a6-bcfa9815e17b/-/preview/" style="width: 321px; height: 193px;"></p>

<p>As shown, an ACMOLED is not activated in the voltage range from 0 to <em>V</em><sub>1</sub>, while it emits light with intensity <em>L</em><sub>1</sub> ≥ 0 when the voltage reaches the first threshold <em>V</em><sub>1</sub> and light with intensity <em>L</em><sub>2</sub> ≥ <em>L</em><sub>1</sub> when the voltage reaches the x threshold <em>V</em><sub>2</sub>. More specifically, if <em>F</em>(<em>v</em>) is the function that maps voltage <em>v</em> to the intensity of light emitted from an ACMOLED, then for four real numbers <em>L</em><sub>1</sub>, <em>L</em><sub>2</sub>, <em>V</em><sub>1</sub>, and <em>V</em><sub>2</sub> with 0 ≤ <em>L</em><sub>1</sub> ≤ <em>L</em><sub>2</sub> and 0 < <em>V</em><sub>1</sub> < <em>V</em><sub>2</sub>, we have</p>

<p style="text-align: center;"><em>F</em>(<em>v</em>) = 0 (if 0 ≤ <em>v</em> < <em>V</em><sub>1</sub>), <em>L</em><sub>1</sub> (if <em>V</em><sub>1</sub> ≤ <em>v</em> < <em>V</em><sub>2</sub>), <em>L</em><sub>2</sub> (if <em>v</em> ≥ <em>V</em><sub>2</sub>)</p>

<p>The very issue now is that ACM R&D still does not know the exact values of two threshold voltage values <em>V</em><sub>1</sub> and <em>V</em><sub>2</sub> and the two intensity values <em>L</em><sub>1</sub> and <em>L</em><sub>2</sub> as well. Researchers in ACM R&D plan to estimate these four values for ACMOLEDs by repeated experiments.</p>

<p>Experiments are performed by applying current of a specific voltage and observing the intensity of light emitted from an ACMOLED. After <em>n</em> repeated experiments with different voltage values, obtained are the data of <em>n</em> tuples (<em>v</em><sub>1</sub>, <em>l</em><sub>1</sub>), (<em>v</em><sub>2</sub>, <em>l</em><sub>2</sub>), ..., (<em>v<sub>n</sub></em>, <em>l<sub>n</sub></em>), where <em>l<sub>i</sub></em> is the observed intensity for voltage <em>v<sub>i</sub></em>. Due to the impreciseness of the observing device and other reasons, the experimental data are not accurate and may contain some error. Nonetheless, they want to find a best estimated intensity function <em>F</em>(<em>v</em>) that minimizes the following error function:</p>

<p style="text-align: center;">error(<em>F</em>) = max<sub>1≤<em>i</em>≤<em>n</em></sub> |<em>l<sub>i</sub></em> - <em>F</em>(<em>v<sub>i</sub></em>)|</p>

<p>where |<em>x</em>| denotes the absolute value of a real number <em>x</em>.</p>

<p>For a given data of <em>n</em> tuples, write a program that finds an estimated intensity function <em>F</em> that minimizes the above error function and outputs the value of error(<em>F</em>).</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer <em>n</em> (1 ≤ <em>n</em> ≤ 300,000), where <em>n</em> is the number of tuples (<em>v<sub>i</sub></em>, <em>l<sub>i</sub></em>) in the experimental data. In the following <em>n</em> lines, each line contains two integers, which range inclusively from 0 to 10<sup>9</sup>, representing <em>v<sub>i</sub></em> and <em>l<sub>i</sub></em> in each tuple (<em>v<sub>i</sub></em>, <em>l<sub>i</sub></em>) of the experimental data. Note that you may assume that there are no two tuples (<em>v<sub>i</sub></em>, <em>l<sub>i</sub></em>) and (<em>v<sub>j</sub></em>, <em>l<sub>j</sub></em>) in the input such that 1 ≤ <em>i</em> < <em>j</em> ≤ <em>n</em> and <em>v<sub>i</sub></em> = <em>v<sub>j</sub></em>.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line consisting of one real number, rounded to the first decimal place, which represents the minimum value of error(<em>F</em>).</p>

