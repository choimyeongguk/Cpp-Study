# [Silver IV] ISBN Conversion - 30532 

[문제 링크](https://www.acmicpc.net/problem/30532) 

### 성능 요약

메모리: 2092 KB, 시간: 0 ms

### 분류

구현, 문자열

### 제출 일자

2025년 9월 28일 17:25:14

### 문제 설명

<p>An ISBN (International Standard Book Number) is a unique identifier assigned to a distinct edition/version of a published book (for example, hardcover and paperback versions of the same edition get different ISBNs). ISBNs assigned before 2007 were $10$ digits long (the ISBN-10 standard), and ISBNs assigned on or after January 1, 2007, are $13$ digits long (the ISBN-13 standard). Some books issued before 2007 that are still in print have both an original ISBN-10 and a matching ISBN-13, and some newer books are also given both an ISBN-10 and an ISBN-13, the former for backward-compatibility purposes.  That "double identity" situation is the basis for this problem, which requires you to convert valid ISBN-10s to their corresponding ISBN-13s.</p>

<p>The last digit of any ISBN is a <em>checksum digit</em> that can be used for simple error detection.  ISBN-10 and ISBN-13 use different rules for computing/verifying this last digit:</p>

<ol>
	<li>ISBN-10: If the $10$ digits from left to right are $d_1, d_2, \ldots, d_{10}$ (so $d_{10}$ is the checksum digit), and if \[ S = 10 \cdot d_1 + 9 \cdot d_2 + 8 \cdot d_3 + \ldots + 2 \cdot d_9 + 1 \cdot d_{10} \] (coefficients decrease from $10$ to $1$), then $S$ must be a multiple $\textrm{of }11$, i.e., $S \equiv 0$ $(\textrm{mod }11)$.</li>
	<li>ISBN-13: If the $13$ digits from left to right are $d_1, d_2, \ldots, d_{13}$ (so $d_{13}$ is the checksum digit), and if \[ S = 1 \cdot d_1 + 3 \cdot d_2 + 1 \cdot d_3 + 3 \cdot d_4 + \ldots + 3 \cdot d_{12} + 1 \cdot d_{13} \] (odd-indexed digits are multiplied by $1$, even-indexed digits are multiplied $\textrm{by }3$), then $S$ must be a multiple $\textrm{of }10$, i.e., $S \equiv 0$ $(\textrm{mod }10)$.</li>
</ol>

<p>It is not hard to see that each rule uniquely determines the checksum digit (given the other digits).</p>

<p><em>X Factor</em>: Note the following small but important detail for ISBN-10 that does not apply to ISBN-13: because the modulus $\textrm{is }11$, the value of the checksum digit lies in $\{0, 1, 2, \ldots, 9, 10\}$, and in the special case that the value of the checksum digit $\textrm{is }10$, it is written as X so that only one character is required.  So, for example, $039428013\textrm{X}$ is a valid ISBN-10.</p>

<p><em>Hyphens</em>: Technically an ISBN-10 consists of four parts, one of which is the checksum digit. (The exact rules defining the first three parts are complicated, so we will not deal with them here.) Two adjacent parts can optionally be separated by a hyphen, which means that an ISBN-10 may contain up to three hyphens, but it cannot begin or end with a hyphen, and it cannot contain consecutive hyphens.  If there are three hyphens, one must separate the checksum digit from the digit that precedes it (if there are fewer than three hyphens, there may or may not be a hyphen between the checksum digit and the digit that precedes it). So, for the purposes of this problem, the following are valid ISBN-10s:</p>

<p style="text-align: center;">$039428013\textrm{-X}$</p>

<p style="text-align: center;">$0\textrm{-}39\textrm{-}428013\textrm{X}$</p>

<p style="text-align: center;">$3\textrm{-}540\textrm{-}42580\textrm{-}2$</p>

<p style="text-align: center;">$3540425802$</p>

<p>And the following are <em>invalid</em> ISBN-10s (the first two because of a hyphen-placement error, the last because it fails the checksum test above):</p>

<p style="text-align: center;">$3\textrm{-}540\textrm{-}4258\textrm{-}02$</p>

<p style="text-align: center;">$3\textrm{-}540\textrm{-}425802\textrm{-}$</p>

<p style="text-align: center;">$0\textrm{-}14\textrm{-}028333\textrm{-}3$</p>

<p>How do you convert an ISBN-10 to an ISBN-13? Simply (i) prepend the three digits $978$, (ii) remove the old checksum digit, and (iii) append a new checksum digit as determined by the ISBN-13 rule.<sup>1</sup> To keep things simple, maintain the positions of any existing hyphens, and follow the prepended 978 with a hyphen.</p>

<hr>
<p><sup>1</sup>In general, an ISBN-13 can begin with three digits other than 978, but only 978 can be prepended to an ISBN-10 to form the matching ISBN-13.</p>

### 입력 

 <p>The first line of input contains an integer, $T$ $(1 \leq T \leq 25)$, the number of (possibly invalid) ISBN-10s to process.  This is followed by $T$ lines, each of which contains a nonempty string of length between $10$ and $13$, inclusive. Each character is either a $\textrm{base-}10$ digit ('<code>0</code>' to '<code>9</code>'), a hyphen ('<code>-</code>'), or '<code>X</code>' (capital X).</p>

### 출력 

 <p>For each test case, if the candidate ISBN-10 is not valid according to the details given above, output a line containing "<code>invalid</code>". Otherwise, output a line containing the corresponding ISBN-13.</p>

