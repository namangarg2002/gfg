<h2><a href="https://www.geeksforgeeks.org/problems/valid-pair-sum--141631/1">Pairs with Positive Sum</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given an integer array <strong>arr[]</strong> ,<span style="font-size: 14pt;">&nbsp;</span></span><span style="font-size: 14pt;">find the number of distinct pairs<strong> </strong>(i , j) such that (i &lt; j)&nbsp;and arr[i] + arr[j] &gt; 0.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [3, -2, 1]</span>
<span style="font-size: 18px;"><strong>Output:</strong> 2</span>
<span style="font-size: 18px;"><strong>Explanation:</strong> [3, -2], [3, 1] are two possible pairs.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [1, 3, 4, -2]</span>
<span style="font-size: 18px;"><strong>Output:</strong> 5
<strong>Explanation:</strong> [-2, 3], [-2, 4], [1, 3], [1, 4], and [3, 4] are five possible pairs.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [-1, -1, -1, 0]</span>
<span style="font-size: 18px;"><strong>Output:</strong> 0
<strong>Explanation:</strong> There are no possible pairs.</span></pre></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Searching</code>&nbsp;<code>Greedy</code>&nbsp;<code>Sorting</code>&nbsp;