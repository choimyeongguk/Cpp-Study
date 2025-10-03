# [Gold IV] Big And - 32663 

[문제 링크](https://www.acmicpc.net/problem/32663) 

### 성능 요약

메모리: 8352 KB, 시간: 136 ms

### 분류

자료 구조, 그리디 알고리즘, 우선순위 큐

### 제출 일자

2025년 10월 3일 14:10:19

### 문제 설명

<p>You are building a boolean circuit and need to compute the logical <code>AND</code> of a collection of <em>source signals</em>. The problem is that you only have access to a collection of identical <code>AND</code> gates that take two boolean inputs (i.e. <code>True</code> or <code>False</code>) and outputs a single boolean value that is <code>True</code> if and only if both inputs were <code>True</code>.</p>

<p>Recalling your digital design course, you remember you can connect some of these <code>AND</code> gates together (by connecting the outputs of some to the inputs of others) to build a circuit that has one input for each source signal you need to consider and a single output that is <code>True</code> if and only if every source signal is <code>True</code>. More precisely, you should build a circuit satisfying the following properties.</p>

<ul>
	<li>There are precisely $N-1$ <code>AND</code> gates in the circuit where $N$ is the number of source signals.</li>
	<li>Every source signal will be connected to the input of precisely one <code>AND</code> gate.</li>
	<li>Every input to an <code>AND</code> gate in the circuit is connected to precisely one signal, which will either be one of the source signals or will be the output signal of another <code>AND</code> gate.</li>
	<li>There will be no "cycle" of signals: the signal output from one <code>AND</code> gate will never reach one of its own input wires.</li>
</ul>

<p>Finally, the output of your circuit will be connected to an LED which will be used to indicate if this signal is <code>True</code> or <code>False</code>. So the LED will illuminate if and only if all source signals are <code>True</code>.</p>

<p>You want to do this in a way that minimizes the worst-case delay for the output signal to change if the source of one of the input signals changes. You know the following:</p>

<ul>
	<li>If the source signal $i$ changes its value then it takes exactly $n_i$ nanoseconds for this change to reach your circuit.</li>
	<li>For any <code>AND</code> gate, after an input signal changes it takes exactly $D$ nanoseconds for the output signal to change (if the new inputs would cause the output to change).</li>
	<li>It takes exactly $L$ nanoseconds for the LED to change when the signal it receives changes.</li>
	<li>Since the components of your circuit will be placed so close together, the time it takes for a signal to propagate from the output of one of your <code>AND</code> gates to another component of the circuit is negligible and will be regarded as $0$ nanoseconds.</li>
</ul>

<p>Help design a circuit to minimize the maximum time between when one of the sources signal changes to when the LED changes (if indeed the new input would cause the LED to change).</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d94f444f-bc58-4e30-8077-6d5d345d3dd7/-/preview/" style="width: 557px; height: 100px;"></p>

<p style="text-align: center;">Figure 1: Illustration of an optimal circuit for each of the sample inputs. The numbers on the left indicate the index of the source signal.</p>

### 입력 

 <p>The first line of input contains three integers $N$ ($2 \leq N \leq 4 \cdot 10^5$), $D$ and $L$ ($1 \leq D,L \leq 10^9$) where $N$ is the number of source signals and $D,L$ are as in the problem description. The second line contains $N$ integers $n_1, n_2, \ldots n_N$ ($1 \leq n_i \leq 10^9$) where $n_i$ indicates the number of nanoseconds it takes for a change source $i$'s signal to reach your circuit.</p>

### 출력 

 <p>Output the smallest time $T$ such that it is possible to build a circuit ensuring it takes at most $T$ nanoseconds for the LED to change if one of the source's signal changes in a way that would cause the LED to change.</p>

