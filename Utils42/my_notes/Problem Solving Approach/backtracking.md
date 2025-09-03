The most brute force way to solve a problem is through **exhaustive search**. Generate all possibilitis and then check each of them for a solution.

Imagine we have the letters  `a-z` and were asked to generate strings of length `n` using the letters. There are 26^n possibilities, as each of the `n` letters could be `a-z`. We can imagine all possibilites as a tree. the root is the empty string `""`  , and then all ndes have `26` children, with the path from the root representing the string being built. So if we started at the root and went to the `g` node, then from that note went to the `p` node, that would represent the string `gp` .the depth of the tree is `n`, and the leaf node represent the string `gp`. The depth of the tree is  `n` and the leaf nodes represent answers.

![[level of depth and complexity recursive]]

Now, lets say we added a constraint so that instead of all solutions of length `n`, we only want ones that meet the constrains. An exhaustive search would still generat `all` strings of length ` n` as `candidates`, ad then check each one for the constraint. This would have a time complexity of `O(k·25^n)` 
where `k` is the work it costs to check if a string meets the constraint. This time complexity is ridiculously slow. 

`backtraking` is a way to efficiently runt through all possibilities in a problem. It typicalle uses an optimization that involves abandoning a `path` once it is determined that the path cannot lead to a solution. The idea is similar to [[binary search tree]] if we're  looking for a value `x` , and the root node has a value greater than `x`, then we know we can ignore the entire right subtree. because the number of nods in each subtree is exponential relative to the depth, backtracking can save huge amounts of computation. Imagive if the constraint was that the string could only have vowels - an exhaustive search would still generate 26^n strngs. and then check eadch one for it only had vowels. With backtracking we discard all subtrees that have non-vowels, improving from O(26^n) candidates to (O^5) 

> abandoning a path is also called sometimes [[pruning]]
> to summarize the difference between `exhautive search` and `backtracking` : In an exhaustive search, we generate all possibilities and then  check them for solutions.
> In backtracking, we prune paths that cannot lead to a solution, generating far fewer possibilities


Backtracking is great tool whenever a problems wants us to find `all` of something, or there isn't a clear way to find a solution  without checking all logical possibilities. 

> a strong hing that we should use backtracking is `if the input constraint are very small` as backtracking algorithm usually have exponential time complexities.


## Why backtracking is recursive ?
Backtracking is almost always implemented with recursion - it really  doesn't make sens to do it iteratively, either directly `(like modifying an array)` or `indirectly (using variables to represent some state)` 

### General backtraking rule 
```c
function backtrack(curr)
{
	if (base__case)
	{
		//increment or add to answer
		return ;
	}
	for (iterate_over_input)
	{
		modify_curr;
		backtrack(curr);
		//undo wahtever modification we've done to curr;
	}
}
```


## Annalogyy
Each call ot the function `backtrack`represents a node in the tree. Each iteration in the for loop represents a child of the current code, and calling `backtrack` in that loop represents moving to a child. 
The line where you undo the modifications is the `backtracking` step and is equivalent to moving back up the tree from a child to its parent.
At any given node, the path from the root to the node represents a candidate that is beign built. 
- The leaf nodes are complete solutions and represent the scope that the original `backtrack` call is being made from. 

## Generation
One common type of problem that can be solved with backtracking are problems that ask us to generate `all of something`