```c
  

float color_interp_t(const t_bresenham_state *bs, int step)
{
    float den;
    float t;

    if (!bs)
        return (0.0f);

    // denominator is the bigger delta (dx or dy)
    den = (float)bs->delta[0];
    if ((float)bs->delta[1] > den)
        den = (float)bs->delta[1];

    // normalize step count to [0, 1]
    if (den <= 0.0f)
        t = 0.0f;
    else
        t = (float)step / den;

    // clamp to [0, 1]
    if (t < 0.0f)
        t = 0.0f;
    if (t > 1.0f)
        t = 1.0f;

    return (t);
}

```

This function computes a parameter $$t\in [0,1]$$
that represents how far along the line we are, relative to the total number of steps needed to draw it.
- `bs->delta[0] = delta(x);
- `bs->delta[1] = delta[y];`
- `den` = the long of `dx`, `dy` -> i.e., the total number fo steps bresenham will take
- `step` = the current step index (0 -> start pixel, `den`->end pixel)
- `t = step / den` -> a normalized progress ration between 0.0 and 1.0
This `t` can then be used for `interpolation`- For example:
- blending colors from the start to the end of the line (color gradient)
- interpolating depth values (z-buffer in 3D rendering)
- animating something smoothly along the line.

--- 
## Concept to learn
### 1. Parameterization we're learning here
- Any point along a line from A to B can expressed as : 
$$
P(t) = (1 - t)A + tB, t \in [0,1]
$$
- This is called  [[linear interpolation]] (LERP)
2 . Normalization
- Taking an arbitrary value (step) and mapping it into a normalized [0,1] range by diviging by the maximum
- Useful in computer graphics, signal processing, ML, basically everywhere
3 . [[Clamping]]
- Making sure values don't go outside of a valide range. (if `t > 1 -> clamp to 1)`
