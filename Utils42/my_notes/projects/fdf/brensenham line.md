For a series of points `(x0, y0), (x1, y1), ..., (xn,yn)` we want to draw `lines connecting each consecutive point.`

The key idea : 
$$
slope m = \frac{y_{2} - y_{1}}{x_{2} -x_{1}}
$$
- `m < 1` -> change in x dominates, move horizontally pixel by pixel and compute y.
- `m > 1` -> change in y dominates, move vertically pixel by pixel and compute x.

this ensure we fill the line correctly on the grid, even though the screen is discrete.

---
## Math example
Suppose we have points `p1 = (1,2)` and `p2 = (5,6)`:
$$
m = \frac{y_{2} - y_{1}}{x_{2} - x_{1}} = \frac{6 - 2}{5 - 1} = \frac{4}{4} = 1
$$

- slope = 1 -> move 1  pixel in X, 1 pixel in y each step.
- Sequence of points to draw:
$$
(1,2)(2,3),(3,4),(4,5),(5,6)
$$
## Horizontal line
Points 
- `P1 = (2,3)`
- `P2 = (6,3)`
$$
\frac{y_{2} - y_{1}}{x_{2} - x_{1}} =\frac{3 - 3}{6 - 2} = 0 / 4 = 0
$$
- slope = 0 ->horizontal line
- Move in `x` only, y stays the same
- point to draw:
$$
(2,3)(3,3)(4,3)(5,3)(6,3)
$$
## Vertical line
- points
	- `P1 = (4,2)`
	- `P2 = (4,6)`
$$
\frac{y_{2} - y_{1}}{x_{2} - x_{1}} =\frac{6 - 2}{4 - 4} = 4 / 0
$$
$$
(4,2),(4,3),(4,4),(4,5),(4,6)
$$
## Steep line
- points
	- `P1 = (1,1)`
	- `P2 = (3,7)`

$$
\frac{y_{2} - y_{1}}{x_{2} - x_{1}} =\frac{7 - 1}{3 - 1} = \frac{6}{2} = 3
$$
$$
(1,1),(1,2),(1,3),(2,4),(2,5),(2,6),(3,7)
$$
## Negative slope
- points
	- `P1 = (2,6)`
	- `P2 = (6,2)`

$$
\frac{y_{2} - y_{1}}{x_{2} - x_{1}} =\frac{}{}
$$

$$
(2,6),(3,5),(4,4),(5,3),(6,2)
$$

> [!NOTE]
    > Notice how the [[slope]] dictates whether we step more in `x` or `y`, and whether `y` increases or decreases. This is exactly teh logic a line drawing   algorithm uses in `FDF` or graphic projects

![[slope_bresenahm algorithm]]![[Pasted image 20250827204148.png]]