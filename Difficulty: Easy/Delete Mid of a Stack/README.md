<h2><a href="https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1">Delete Mid of a Stack</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a stack <strong>s</strong>, delete the <strong>middle element </strong>of the stack without using any additional data structure. The middle element is defined as the floor(size of stack + 1) / 2)-th element from the bottom of the stack (using 1-based indexing).</span></p>
<p><strong><span style="font-size: 18px;">Note</span></strong><span style="font-size: 18px;"><strong>:</strong> The output shown by the compiler is the stack from top to bottom.</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> s = [10, 20, 30, 40, 50]
<strong>Output:</strong> [50, 40, 20, 10]
<strong>Explanation:</strong> The bottom-most element will be 10 and the top-most element will be 50. Middle element will be element at index 3 from bottom, which is 30. Deleting 30, stack will look like [10, 20, 40, 50].</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> s = [10, 20, 30, 40]
<strong>Output:</strong> [40, 30, 10]
<strong>Explanation:</strong> T</span><span style="font-size: 14pt;">he bottom-most element will be 10 and the top-most element will be 40. Middle element will be element at index 2 from bottom, which is 20. Deleting 20, stack will look like [10, 30, 40].</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>2 ≤ element of stack ≤ 10<sup>5<br></sup>2 ≤ s.size() ≤ 10<sup>4</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Recursion</code>&nbsp;<code>Stack</code>&nbsp;<code>STL</code>&nbsp;