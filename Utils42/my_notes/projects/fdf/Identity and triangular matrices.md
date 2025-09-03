A square diagonal matrix with entries of 1 on the main diagonal and 0 for all other entries is called an `identity matrix`, denoted by `I` . A sqaure matrix `L` with all entries above the main diagonal equal to zero is called a `lower triangular matrix`. If instead all entries below the main diagonal of a matrix `U`are equal to 0, the matrix is an `upper triangular matrix`, for instance:

## Identity Matrix (I)
### Definition Recap 
A square matrix with 1s on the diagonal  and `0s everywhere else` :

$$
Identity ={\begin{bmatrix}
1 & 0 & 0 \\
0 & 1 & 0 \\
0 & 0 & 1
\end{bmatrix}}
$$
> [!NOTE]
  I as the `1` in matrix multiplication. 
  > if we multiply any matrix `A` by `I` we get A back:
  > `AI = IA = A`

> [!EXAMPLE]
    > Imagine a transformation in 2D (like rotating or scaling). If we multiply a vector by the identity matrix, nothing changes:
    > $$
    > \begin{bmatrix}
    > 1 & 0 \\
    > 0 & 1
    > \end{bmatrix}
    > \begin{bmatrix}
    > 3 \\
    > 4
    > \end{bmatrix}
    > =
    > > \begin{bmatrix}
    > 3 \\
    > 4
    > \end{bmatrix}
    > $$
    > So, `I` is like **doing nothing** in terms of transformation
---

## Lower triangular Matrix (L)
Definition Recap:
all entries `above the main diagonal are zero:`
  
$$
lowerTrianleMatrix = \begin{bmatrix}
2 & 0 & 0 \\
1 & -2 & 0 \\
-5 & 0 & -1 \\

\end{bmatrix}
$$



---
## Upper triangular Matrix (U)

$$
upperTrianleMatrix = \begin{bmatrix}
1 & 5 & 4 \\
0 & 2 & 1 \\
0 & 0 & 3 \\

\end{bmatrix}
$$