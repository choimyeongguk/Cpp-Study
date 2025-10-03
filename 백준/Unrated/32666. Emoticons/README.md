# [Unrated] Emoticons - 32666 

[문제 링크](https://www.acmicpc.net/problem/32666) 

### 성능 요약

메모리: 2104 KB, 시간: 8 ms

### 분류

문자열, 브루트포스 알고리즘

### 제출 일자

2025년 10월 3일 16:11:46

### 문제 설명

<p>Emma is a college student who regularly posts messages on her favorite social media, which supports several emoticons--- a pictorial representation of a facial expression using characters.</p>

<p>One day, she noticed that some emoticons in her message were automatically converted to the corresponding emojis by the platform.</p>

<p>For example, if she sends a message "<code>Hello ;-)</code>" to the platform, the actual post will be "<code>Hello </code><img alt="" src="https://upload.acmicpc.net/715b0459-260f-4ca3-a4a6-0814f0d29832/-/preview/">".</p>

<p>If two or more emoticons overlap in a message, the system always converts the leftmost emoticon first.</p>

<p>Here is the complete list of the supported emoticons on that social media.</p>

<table class="table table-bordered">
	<tbody>
		<tr>
			<th>Type</th>
			<th>Emoticon</th>
			<th>Emoji</th>
			<th>Meaning</th>
		</tr>
		<tr>
			<td>Western</td>
			<td><code>:)</code></td>
			<td><img alt="" src="https://upload.acmicpc.net/603f380a-e8bf-49b6-b05f-dc9397122880/-/preview/"></td>
			<td>Smiley</td>
		</tr>
		<tr>
			<td>Western</td>
			<td><code>:-)</code></td>
			<td><img alt="" src="https://upload.acmicpc.net/603f380a-e8bf-49b6-b05f-dc9397122880/-/preview/"></td>
			<td>Smiley</td>
		</tr>
		<tr>
			<td>Western</td>
			<td><code>:-(</code></td>
			<td><img alt="" src="https://upload.acmicpc.net/2b9de8b6-9395-4fd6-b863-fdb9fe8f402a/-/preview/"></td>
			<td>Frown</td>
		</tr>
		<tr>
			<td>Western</td>
			<td><code>;-)</code></td>
			<td><img alt="" src="https://upload.acmicpc.net/715b0459-260f-4ca3-a4a6-0814f0d29832/-/preview/"></td>
			<td>Wink</td>
		</tr>
		<tr>
			<td>Western</td>
			<td><code>xD</code></td>
			<td><img alt="" src="https://upload.acmicpc.net/8e517ba7-00dd-4fe0-9084-a5215f43029b/-/preview/"></td>
			<td>Laughing</td>
		</tr>
		<tr>
			<td>Eastern</td>
			<td><code>^_^</code></td>
			<td><img alt="" src="https://upload.acmicpc.net/603f380a-e8bf-49b6-b05f-dc9397122880/-/preview/"></td>
			<td>Smiley</td>
		</tr>
		<tr>
			<td>Eastern</td>
			<td><code>-_-</code></td>
			<td><img alt="" src="https://upload.acmicpc.net/bf3e83bb-b588-467b-b4c6-64dd99a30bd9/-/preview/"></td>
			<td>Expressionless</td>
		</tr>
		<tr>
			<td>Eastern</td>
			<td><code>^o^</code></td>
			<td><img alt="" src=""></td>
			<td>Screwed</td>
		</tr>
		<tr>
			<td>Eastern</td>
			<td><code>^^;</code></td>
			<td><img alt="" src=""></td>
			<td>Sweating</td>
		</tr>
		<tr>
			<td>Eastern</td>
			<td><code>(..)</code></td>
			<td><img alt="" src=""></td>
			<td>Looking down</td>
		</tr>
	</tbody>
</table>

<p>She always uses the following "visible" characters and the space character "<code> </code>".</p>

<ul>
	<li>Digits: <code>0123456789</code></li>
	<li>Uppercase letters: <code>ABCDEFGHIJKLMNOPQRSTUVWXYZ</code></li>
	<li>Lowercase letters: <code>abcdefghijklmnopqrstuvwxyz</code></li>
	<li>Symbols: <code>!"#$%&'()*+,-./:;<=>?@[\]^_'{|}~</code></li>
</ul>

<p>Today, just before posting, she accidentally replaced all occurrences of one character in her message with another character.</p>

<p>Such characters include space, and she might have replaced a character with the same character, causing no effect.</p>

<p>Now, she wants to know the message length after the platform converts emoticons into emojis, where she counts each emoji as one character.</p>

<p>Can you help her find the minimum and maximum possible message lengths?</p>

### 입력 

 <p>The input contains Emma's original text (before she accidentally replaced characters) on one line. The text contains at most $100$ characters, consisting of the visible ASCII characters defined above and the space character.</p>

<p>Her text is not empty, and its first and last characters are visible characters.</p>

### 출력 

 <p>Output two integers, the minimum and the maximum possible message lengths after emoticons in her message are converted into emojis.</p>

