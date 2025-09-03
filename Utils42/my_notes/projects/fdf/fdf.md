---
sticker: emoji//1f92a
---
## [[slope]] in 2D -> Why it matters for FDF ?

- The [[slope]] formula:
$$
m = \frac{y_{2} - y_{1}}{x_{2} - x_{1}}
$$

tell us how `steep`a line is.
- In fdf each line segment betweeen two points on a grid has a slope. This is important for drawing the line `pixel by pixel`

We're walking from point to point `p1` to `p2` on a 2D grid. Slope tell us **how many steps in y** we move for every  `setp in x` . This is litterally what the [[brensenham line]] algorithm does
in fdf we're basically taking a 2D grid of numbers (height) and turning it into a 3D wireframe map. right now we've probably done **isometric projection** or maybe a simple rotation using `sin/cos` around `X,Y,Z` axes.

That's all good, but it has some limits:
- rotation step-by-step can accumulate floating point errors.
- Chaining rotations with matrices sometimes feels clunky.
- we don't always get smooth, intuitive arcball feel clunky.

This is where [[quaternions]]