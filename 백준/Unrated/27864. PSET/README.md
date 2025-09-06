# [Unrated] PSET - 27864 

[문제 링크](https://www.acmicpc.net/problem/27864) 

### 성능 요약

메모리: 2092 KB, 시간: 0 ms

### 분류

분류 없음

### 제출 일자

2025년 9월 6일 11:19:59

### 문제 설명

<p>PSET is a derivative of the game SET. The game SET has 81 cards, each of which has one, two or three of the same shapes. The shapes are (for this problem):</p>

<p style="text-align: center;">Arrow: <img alt="" src="https://upload.acmicpc.net/c50e5305-2371-4742-a6d2-323c3b6b036f/-/crop/172x82/3,0/-/preview/" style="width: 86px; height: 41px;"> Diamond: <img alt="" src="https://upload.acmicpc.net/c50e5305-2371-4742-a6d2-323c3b6b036f/-/crop/133x82/333,0/-/preview/" style="width: 67px; height: 41px;"> and Oval: <img alt="" src="https://upload.acmicpc.net/c50e5305-2371-4742-a6d2-323c3b6b036f/-/crop/171x82/627,0/-/preview/" style="width: 86px; height: 41px;">.</p>

<p>Each group of shapes will have a color Red, Green or Blue (labeled R, G or B in case this page is black and white) and a fill type:</p>

<p style="text-align: center;">Empty: <img alt="" src="https://upload.acmicpc.net/0b556d10-5ce9-4d26-afc5-348acc95451d/-/crop/133x82/0,0/-/preview/" style="width: 67px; height: 41px;"> Striped: <img alt="" src="https://upload.acmicpc.net/0b556d10-5ce9-4d26-afc5-348acc95451d/-/crop/133x82/261,0/-/preview/" style="width: 67px; height: 41px;"> or Filled: <img alt="" src="https://upload.acmicpc.net/0b556d10-5ce9-4d26-afc5-348acc95451d/-/crop/133x82/550,0/-/preview/" style="width: 67px; height: 41px;">.</p>

<p>This gives 81 possible combinations. Three cards are a SET, if, for each property (count, color, fill and shape), the property is the same on all three cards or different on all three cards. For example, for the following cards, 1, 2 and 3 form a SET (different counts, same color, different fill, different shape) but 1, 2 and 4 do not form a SET (for several reasons, one of which is 1 and 4 have the same count, 2 has a different count):</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a16416e1-a782-471c-9df5-3a80c06f5614/-/preview/" style="width: 469px; height: 176px;"></p>

<p>Note that given two cards, there is exactly one other card which forms a set with the first two.</p>

<p>We will use the code <code>{count}{color}{fill}{shape}</code> to specify a SET card. For example, the cards above are: <code>2GSD</code>, <code>3GFA</code>, <code>1GEO</code>, <code>2BSA</code>. <code>{fill}</code> is one of <code>E</code>, <code>S</code> or <code>F</code> for Empty, Striped or Filled respectively. <code>{shape}</code> is one of <code>A</code>, <code>D</code> or <code>O</code> for Arrow, Diamond or Oval respectively.</p>

<p>Each PSET card consists of two set cards different from <code>2GSD</code> which form a SET with <code>2GSD</code>. From the example above <code>3GFA</code> and <code>1GEO</code>. The SET cards on the PSET card are above one another and rotated 90 degrees. See the example below.</p>

<p>Three PSET cards form a PSET if the (possibly after flipping a card) the top SET cards form a SET and the bottom SET cards form a SET.</p>

<p>In the example below, there are four PSETs. { 1, (flip) 2,3 }, { 1, 2, 4}, { (flip) 1, 3, 4} and { 2, 3 , (flip)4.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/750b8b8f-2833-440f-89da-bd872ffb902d/-/preview/" style="width: 469px; height: 176px;"></p>

<p>Write a program which takes as input a collection of distinct PSET cards and outputs the number of (three card) PSETs.</p>

### 입력 

 <p>Input consists of multiple lines of input. The first line contains the number N of PSET cards to follow (4 ≤ N ≤ 20). This is followed by N lines of input, one per card. Each card line consists of a four character code (as described above) for the top of the card followed by a space and a four character code for the bottom of the card.</p>

### 출력 

 <p>The output consists of a single line that contains the integer number of PSETs in the input collection.</p>

