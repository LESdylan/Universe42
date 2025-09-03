The determinant is a **special number** that can be calculated from a `matrix` . This one has 2 rows and 2 columns

Let's calculate the determinant of the matrix:
$$
3*6 - 8*4 = 18 - 32 \\
-14
$$
The determinant of  a matrix `A` is  a number associated with **A**, denoted det(**A**) or `|A|` . It is often used in determining the solvability of systems of [[linear equations]]. 

For matrices up to a dimension **3 * 3** , determinants are calculates as follows:

$$
|A| = |u_{1}| = u_{1},
$$
$$
|A| = \begin{bmatrix}
u_{1} & u_{2} \\
v_{1} & v_{2}
\end{bmatrix} = u_{1}v_{2} - u_{2}v_{1}
$$
$$
|A| = \begin{bmatrix}
u_{1} & u_{2} & u_{3} \\
v_{1} & v_{2} & v_{3} \\
w_{1} & w_{2} & w_{3}
\end{bmatrix}
= u_{1}((v_{2}w_{3} -v_{3}w_{2})) + u_{2}(v_{3}w_{1} - v_{1}w_{3}) + u_{3}(v_{1}w_{2} -v_{2}w_{1}) \implies u · (v * w)
$$

> [!INFO]
    > The symbols · and `x` are the dot product and cross product, as described in Sections 3.3.3 and 3.3.5, respectively.) Determinate are geometrically related to (oriented) [[hypervolumes]]: a generalized concept of volumes in n-dimensional space for an `n x n` determinant, where length area, and volume are the **1D, 2D, 3D** volume measurement. For a 1 x 1 matrix, A = [u_1]. 

For a 2 x 2 matrix,
$$
A = \begin{bmatrix}
u_{1} & u_{2}  \\
v_{1} & v_{2}
\end{bmatrix}
$$

|A| corresponds  to the signed area of the parallelogram determined by the points.
If the parallelogram is swept counterclockwise from the first point to the second, the determinant is positive, else
negative. For a 3 x 3 matrix, A = [u v w] (where u v w are column vectors)

|A| Corresponds to the signed volumes of the parallepiped determined by the three vectors. In general for an n-dimensional matrix the determinant corresponds to the signed hypervolum of the n-dimensional hyperparallepiped determined by its column vectors.

> [!NOTE]
    > The determinant of  a matrix remains unchanged if the matrix is transposed
    > $$
    > |A| = |A|^T
    > $$


