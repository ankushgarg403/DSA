<h2><a href="https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1">Postfix to Infix Conversion</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p dir="ltr"><span style="font-size: 18px;">Given a string <strong>s</strong> that represents the postfix form of a valid mathematical expression. Convert it to its infix form.</span></p>
<p dir="ltr"><span style="font-size: 18px;"><strong>Example:</strong></span></p>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">s = "ab*c+" 
</span><strong style="font-size: 18px;">Output: </strong><span style="font-size: 18px;">((a*b)+c)
</span><strong style="font-size: 18px;">Explanation: </strong><span style="font-size: 18px;">The postfix expression ab*c+ represents (a*b)+c. Therefore, its equivalent infix expression is ((a*b)+c).
</span></span></pre>
<pre><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">s = "</span><span style="font-size: 14pt;">abc/-"
</span><strong style="font-size: 18px;">Output: </strong><span style="font-size: 18px;">(a-(b/c))
</span><strong style="font-size: 18px;">Explanation: </strong><span style="font-size: 18px;">The postfix expression abc/- represents a-(b/c). Therefore, its equivalent infix expression is (a-(b/c)).</span></pre>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Stack</code>&nbsp;<code>Strings</code>&nbsp;