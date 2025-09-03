A matrix is an array of numbers:
$$
\begin{bmatrix}
6 & 4 & 24 \\
1 & -9 & 8
\end{bmatrix}
$$
This one has 2 Row and 3 columns

## Adding
to add two matrices: add the numbers int he matching positions:

![[Pasted image 20250829204205.png]]
These are teh calculations:
```c
int matrix[2][2] = {{3,8},{4,6}};
int matrix2[2][2] = {{4,0},{1,-9}};

matrix[0][0] + matrix2[0][0] = 7
matrix[0][1] + matrix2[0][1] = 8
matrix[1][0] + matrix2[1][0] = 5
matrix[1][1] + matrix2[1][1] = -3

```

The two matrices must be the same size, i,e. the rows must match in size, and the columns must match in size.

> [!EXAMPLE]
    > a matrix with 3 rows and 5 columns can be added to another matrix of 3 rows and 5 columns
    > but it could not be added to a  matrix with 3 rows and 4 columns (the columns don't match in size)
    
## Negative
The negative of a matrix is also simple
![[Pasted image 20250829204854.png]]

## Substracting
To susbtract two matrices: substract the numbers in the matching positions:

![[Pasted image 20250829204936.png]]
## Multiply by  a constant
We can multiply a matrix by constant ( the value 2 in this case)
![[Pasted image 20250829205150.png]]
we call the constant a scalar, so officially this is called [[scalar multiplication]]

## Multiplying by another matrix
To multiply a matrix by single number, multiply it by every element of the matrix (look intot the scheme above)
WE call the number (`2` int is case) a `scalar` , a single number used to scal teh values in matrix. And this is called `scalar multiplication`

but to multiply a matrix by another matrix we need to do the `dot product` of rows and columns ... what does that mean ? 
To work out the answer for the `1st row` and `1st column`:

![[Pasted image 20250829210039.png]]
![[Pasted image 20250829210047.png]]
$$
\begin{bmatrix}
1 & 2 & 3  \\
4 & 5 & 6
\end{bmatrix}
*
\begin{bmatrix}
7 & 8 \\
9 & 10 \\
11 & 12
\end{bmatrix}
=
\begin{bmatrix}
58 & 64 \\
139 & 154
\end{bmatrix}
$$
> [!SUCCESS]
> DONE!

## Why do is this way ?
This may seem an odd and complicated way of multiplying, but is necessary. 

> [!EXAMPLE]
    > The local shop sells 3 types of pies
    > - Apple ppies cost $3 each
    > - Cherry pies cost $4 each
    > - Blueberry pies cost $2 each
    > - And this is how many they sold in 4 days

|           | Mon | Tue | Wed | Thu |
| --------- | --- | --- | --- | --- |
| Apple     | 13  | 9   | 7   | 15  |
| Cherry    | 8   | 7   | 4   | 6   |
| Blueberry | 6   | 4   | 0   | 3   |
```c
#include <stdio.h>

void revenue(int prices[], int qty[3][4], int result[4]) {
    for (int day = 0; day < 4; day++) {
        result[day] = 0;
        for (int item = 0; item < 3; item++) {
            result[day] += prices[item] * qty[item][day];
        }
    }
}

int main() {
    int prices[3] = {3, 4, 2};
    int qty_sold[3][4] = {
        {13, 9, 7, 15},   // Apples
        { 8, 7, 4,  6},   // Cherries
        { 6, 4, 0,  3}    // Blueberries
    };

    int result[4];
    revenue(prices, qty_sold, result);

    printf("Revenue per day:\n");
    for (int day = 0; day < 4; day++) {
        printf("Day %d: $%d\n", day+1, result[day]);
    }

    return 0;
}

/*
Day 1: $83
Day 2: $63
Day 3: $37
Day 4: $75
*/


```
## Division matrices
we don't divide instead we multiply by the inverse of B
$$
\frac{A}{B} = A * (1 / B) = A * B^{-1}
$$

## Transposing
To transpose a matrix, swap the rows and columns
We put a `T` in the top right-hand corner to mean transpose:
$$
\begin{bmatrix}
6 & 4 & 24 \\
1 & -9 & 8

\end{bmatrix}^T \\
 =
 \begin{bmatrix}
6 & 1 \\
4 & -9 \\
24 & 8
\end{bmatrix}

$$

A matrix is usually shown by a `capital letter` (such as `A`, or `B`)
Each entry (or "element") is shown by a lower case letter with `subscript` of `row, column`

## Notation
## 