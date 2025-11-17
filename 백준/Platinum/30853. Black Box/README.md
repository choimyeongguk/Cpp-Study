# [Platinum III] Black Box - 30853 

[문제 링크](https://www.acmicpc.net/problem/30853) 

### 성능 요약

메모리: 11428 KB, 시간: 216 ms

### 분류

자료 구조, 세그먼트 트리, 이분 탐색

### 제출 일자

2025년 11월 17일 22:25:44

### 문제 설명

<p>The following <strong><code>Python</code></strong>-like pseudo code for function <strong><code>BlackBox()</code></strong> takes a list of positive integers and shuffles the integers in the list in a specific way, and returns the result as a list.</p>

<p>Three list methods are used below; For a list <code>L</code>, <code>len(L)</code> returns the number of items in <code>L</code>. <code>L.append(x)</code> adds the item <code>x</code> to the end of <code>L</code>. <code>L.pop(idx)</code> removes the item at the specified index <code>idx</code> from the list <code>L</code> and returns the removed item.</p>

<p>Given a list <strong><code>Z</code></strong> of positive integers, write a program to reconstruct a list <strong><code>I</code></strong> such that <strong><code>Z = BlackBox(I)</code></strong>.</p>

<pre><strong>function</strong> BlackBox( Banana ):
    <strong>if</strong> len( Banana ) ≤ 4 :
        exit("Too small Banana")
    Apple = [] # [] is an empty list
    Mango = 0
    Papaya = len( Banana )

    <strong>while</strong>( Papaya >= 2 ) :
        Kiwi = Banana[ Mango ]
        Apple.append( Kiwi )
        Banana.pop( Mango )
        Papaya = Papaya - 1
        Mango = ( Kiwi + Mango - 1 ) % Papaya
    # end of while

    Apple.append( Banana[ 0 ] )
    Pear = len( Apple ) - 1
    Orange = Apple[ Pear ]
    Lime = Apple[ 0 ]
    Coconut = Orange % Pear
    Melon = Apple[ Coconut ]
    Apple[ 0 ] = Melon
    Apple[ Coconut ] = Lime

    <strong>return</strong> ( Apple )
# end of function BlackBox
</pre>

<p> </p>

### 입력 

 <p>Your program is to read from standard input. The first line contains a positive integer $n$ representing the number of positive integers of a list <strong><code>Z</code></strong>, where $5 ≤ n ≤ 200\,000$. The following $n$ lines contain $n$ positive integers of the list <strong><code>Z</code></strong> returned from <strong><code>BlackBox(I)</code></strong>; the $i$-th line contains the $i$-th integer of the list <strong><code>Z</code></strong> between $1$ and $100\,000$, both inclusive.</p>

### 출력 

 <p>Your program is to write to standard output. Print $n$ integers of the list <strong><code>I</code></strong> where <strong><code>Z = BlackBox(I)</code></strong>, one per line; the $i$-th line should contain the $i$-th integer of <strong><code>I</code></strong>.</p>

