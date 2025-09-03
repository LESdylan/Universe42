for any [[polyhedra]] that doesn't intersect itself, the
- number of faces
- plus the number of vertices (corner points)
- minus the number of edges

always equals 2

This is usually written:
$$
F + V - E = 2
$$

a cube has:
- 6 faces
- 8 [[vertices]]
- 12 edges
- F + V -E = 6 + 8 - 12 = 2


| Name         | Faces                                                                             | Vertices | Edges | F+V-E |       |
| ------------ | --------------------------------------------------------------------------------- | -------- | ----- | ----- | ----- |
| Tetrahedron  | ![Tetrahedron](https://www.mathsisfun.com/geometry/images/poly-tetrahedron.svg)   | 4        | 4     | 6     | **2** |
| Cube         | ![Cube](https://www.mathsisfun.com/geometry/images/poly-cube.svg)                 | 6        | 8     | 12    | **2** |
| Octahedron   | ![Octahedron](https://www.mathsisfun.com/geometry/images/poly-octahedron.svg)     | 8        | 6     | 12    | **2** |
| Dodecahedron | ![Dodecahedron](https://www.mathsisfun.com/geometry/images/poly-dodecahedron.svg) | 12       | 20    | 30    | **2** |
| Icosahedron  | ![Icosahedron](https://www.mathsisfun.com/geometry/images/poly-icosahedron.svg)   | 20       | 12    | 30    | **2** |

|                                                                                        |                                                                                                                                                                                             |
| -------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ![cube extra face](https://www.mathsisfun.com/geometry/images/cube-extra-face.svg)     | **Why always 2?**  <br>Imagine taking the cube and adding an edge (from corner to corner of one face).  <br>  <br>We get an extra edge, plus an extra face:<br><br>**7** + 8 − **13** _=_ 2 |
|                                                                                        |                                                                                                                                                                                             |
| ![cube extra vertex](https://www.mathsisfun.com/geometry/images/cube-extra-vertex.svg) | Or try to include another [[vertex]], and we get an extra edge:<br><br>6 + **9** − **13** _=_ 2.                                                                                            |

> [!NOTE]
    > No matter what we do, we always end up with 2
    > (but only for this type of polyhedron)
    

It may be easier to see when we "flatten out" the shapes into what is called a **graph** (a diagram of connected points, not the data plotting kind of graph).

A tetrahedron can be drawn like this:

  ![tetrahedron](https://www.mathsisfun.com/sets/images/graph-tetrahedron.svg)

Note that one of the "faces" is the outside region, like this:

  ![tetrahedron](https://www.mathsisfun.com/sets/images/graph-tetrahedron-count.svg)

So there are 4 regions (faces), 4 vertices and 6 lines (edges):

F + V − E _=_ 4 + 4 − 6 _=_ **2**

Let's try this with a cube. Here is one way to show it:

  ![graph of cube](https://www.mathsisfun.com/sets/images/graph-cube.svg)

There are 6 regions (counting the outside), 8 vertices and 12 edges:

F + V − E _=_ 6 + 8 − 12 _=_ **2**

We can discover what is going on when we build up graphs from just one vertex:

 ![graph 1 dot](https://www.mathsisfun.com/sets/images/graph-1dot.svg)With one vertex we have one region (the whole area), the one vertex and no edges: **1 + 1 − 0 _=_ 2** ![graph 2 dots](https://www.mathsisfun.com/sets/images/graph-2dot.svg) Add another vertex. We still have one region, but now have two vertices and one edge: **1 + 2 − 1 _=_ 2** ![graph 3 dots](https://www.mathsisfun.com/sets/images/graph-3dot.svg) Adding another vertex we can have two regions (inside and outside), three vertices and three edges: **2 + 3 − 3 _=_ 2** ![graph 3 dots](https://www.mathsisfun.com/sets/images/graph-3adot.svg) **Or** we could have one region, three vertices and two edges (this is allowed 
 because it is a graph, not a solid shape): **1 + 3 − 2 _=_ 2**  
 
 ![graph 4 dots](https://www.mathsisfun.com/sets/images/graph-4dot.svg)Adding another vertex we can have several different graphs ...  
 ![graph tetrahedron](https://www.mathsisfun.com/sets/images/graph-tetrahedron.svg)
 ... one of those graphs is a tetrahedron: **4 + 4 − 6 _=_ 2**

There is always a **balance** between faces, vertices and edges.

**Your turn!** Turn the tetrahedron graph into a cube graph. See if you can make an octahedron graph, too.

(Isn't it amazing how we can show 3d shapes as a series of connected points!)

## The Sphere

![sphere like icosahedron](https://www.mathsisfun.com/geometry/images/sphere-icosa.svg)

All Platonic Solids (and many other solids) are like a [Sphere](https://www.mathsisfun.com/geometry/sphere.html) ... we can reshape them so that they become a Sphere (move their corner points, then curve their faces a bit).

For this reason we know that **F + V − E _=_ 2 for a sphere**

> [!WARNING]
> be careful, we cannot simply say a sphere has 1 face, and 0 vertices and edges, for `F + V - E = 1`

So, the result is 2 again.