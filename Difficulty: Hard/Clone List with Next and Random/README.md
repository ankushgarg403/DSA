<h2><a href="https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1">Clone List with Next and Random</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given a special linked list with <strong>n</strong>&nbsp;nodes where each node has two pointers a&nbsp;next pointer&nbsp;that points to the next node of the singly linked list, and a&nbsp;random pointer&nbsp;that points to the random node of the linked list.<br></span></p>
<ul>
<li><span style="font-size: 14pt;">Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node. </span></li>
<li><span style="font-size: 14pt;">Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list structure. </span></li>
<li><span style="font-size: 14pt;">None of the pointers in the new list should point to nodes in the original list and o</span><span style="font-size: 14pt;">riginal linked list should remain unchanged.</span></li>
</ul>
<p><span style="font-size: 14pt;">Return the&nbsp;head&nbsp;of the copied linked list.<br></span><span style="font-size: 14pt;"><br>Each node of the linked list is represented as a pair of [val, random_index] where:</span></p>
<ul>
<li><span style="font-size: 14pt;">val represents node.data.</span></li>
<li><span style="font-size: 14pt;">random_index<strong> </strong>(1-based index) represents the index of the node that the random pointer of the current node points to, or NULL<strong> </strong>if it does not point to any node.</span></li>
</ul>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>head = [[1, 3], [3, 3], [5, NULL], [9, 3]] <br> &nbsp; <img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700186/Web/Other/blobid0_1756531264.jpg" width="433" height="147"><br><strong>Output: </strong>[[1, 3], [3, 3], [5, NULL], [9, 3]]<strong>
Explanation: </strong>
Node 1 points to Node 3 as its NEXT and Node 5 as its RANDOM.
Node 3 points to Node 5 as its NEXT and Node 5 as its RANDOM.
Node 5<strong> </strong>points to Node 9 as its NEXT and NULL as its RANDOM.
Node 9 points to NULL as its NEXT and Node 5 as its RANDOM.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>head = [[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]<br> &nbsp;<img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700186/Web/Other/blobid1_1756531275.jpg" width="456" height="133"><br><strong>Output: </strong>[[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]<strong>
Explanation: </strong>
Node 1 points to Node 2 as its NEXT and Node 3 as its RANDOM.
Node 2 points to Node 3 as its NEXT and Node 1 as its RANDOM.
Node 3 points to Node 4 as its NEXT and Node 5 as its RANDOM.
Node 4 points to Node 5 as its NEXT and Node 3 as its RANDOM.
Node 5 points to NULL as its NEXT and Node 2 as its RANDOM.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>head = [[7, NULL], [7, NULL]]<br><strong>Output: </strong>head<strong> </strong>=<strong> </strong>[[7, NULL], [7, NULL]]<strong>
Explanation: </strong>
Node 7<strong> </strong>points to Node 7 as its NEXT and NULL as its RANDOM.
Node 7 points to NULL as its NEXT and NULL as its RANDOM.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints</strong>:<br>1 ≤ n ≤ 100<br>0 ≤ node-&gt;data ≤ 1000</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Morgan Stanley</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>OYO Rooms</code>&nbsp;<code>Snapdeal</code>&nbsp;<code>D-E-Shaw</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Ola Cabs</code>&nbsp;<code>Walmart</code>&nbsp;<code>Adobe</code>&nbsp;<code>BankBazaar</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Linked List</code>&nbsp;