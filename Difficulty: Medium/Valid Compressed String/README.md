<h2><a href="https://www.geeksforgeeks.org/problems/valid-compressed-string--170647/1">Valid Compressed String</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given two strings <strong>s</strong> and <strong>t</strong>, where s is the original string and t is its compressed form, find if t is a valid compression of s or not.</span></p>
<ul>
<li><span style="font-size: 18px;">During compression, any sequence of consecutive characters may be replaced by the number of characters removed. </span></li>
<li><span style="font-size: 18px;">If t contains consecutive digits, treat them as a single number. For example, "B32" represents "B" + "32",&nbsp; not "B" + "3" + "2".</span></li>
</ul>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "GEEKSFORGEEKS", t = "G7G3S"
<strong>Output: </strong>true
<strong>Explanation: </strong>'G' + skip 7 characters ("EEKSFOR") + 'G' + skip 3 characters ("EEK") + 'S' matches s exactly.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "DFS", t = "D1D"
<strong>Output : </strong>false
<strong>Explanation: </strong>t is not a valid compressed string.
</span></pre>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Facebook</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Greedy</code>&nbsp;