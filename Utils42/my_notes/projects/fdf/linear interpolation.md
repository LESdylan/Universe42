LERP means that we move from a pointer A to a point B with a t value as factor of growth.

$$
LERP(Start,End,T) = (1 - t) * Start + T *End
$$
- when t = 0; result = `start`
- when t = 1: result = `end`
- when 0 < t < 1 : result is somehwere in between

## 2. Example: Interpolating numbers
Suppose we want to interpolate from `start = 10` to `end = 20`
- t = 0.0 -> 10
- t = 0.25 -> (1 - 0.25) · 10 + 0.25 · 20 = 7.5 + 5 = 12.5
- t = 0.5 -> 15
- t = 0.75 -> 17.5
- t = 1.0 -> 20

So lerp is just sliding smoothly from one value to another.

> [!EXAMPLE]
    > in FDF, every [[vertex]] in the wireframe has a color (say based on its height)
    > when we draw a line between two vertices with bresenham, we want the pixels to smoothly fade from the start color to the end color
    > colors in graphics are usually stored as RGB values.
    > Example 
    > Start color = red = `(255,0,0)`
    > End color = Blue = `0,0,255` 
    > at each step 
    > $$
    > Color(t) = (1 - t) * Start + t * End
    > $$
    > Break it down per channel
    > - Red: (1−t)⋅255+t⋅0(1-t)\cdot255 + t\cdot0(1−t)⋅255+t⋅
    > - Green: (1−t)⋅0+t⋅0=0(1-t)\cdot0 + t\cdot0 = 0(1−t)⋅0+t⋅0=0
    > - Blue: (1−t)⋅0+t⋅255(1-t)\cdot0 + t\cdot255(1−t)⋅0+t⋅255
    > - - t=0: (255, 0, 0) = red
    > - t=0.5t = 0.5t=0.5: (128, 0, 128) = purple
    > - t=1.0t = 1.0t=1.0: (0, 0, 255) = blue
    
    
## Examble in fdf
```css
start_value ----(t=0.25)---> ---X---(t=0.5)---> ---X---(t=0.75)---> end_value

```

Imagine we’re drawing a line from `(x1, y1, color1)` to `(x2, y2, color2)`:

1. **Bresenham** decides which pixels are on the line.  
    Ex: `(1,2) → (5,6)` = 5 pixels.
    
2. At pixel #`step`, compute:
    
    t=steptotal_stepst = \frac{step}{total\_steps}t=total_stepsstep​
3. Interpolate the color:
    
    pixel_color=LERP(color1,color2,t)pixel\_color = LERP(color1, color2, t)pixel_color=LERP(color1,color2,t)
4. Plot that pixel with its interpolated color.
    

Result = a smooth line, not just a flat one-color line.
---
## Concept learnt
- Parametric thinking (every point on a line can be represeneed with a parmeter `t` )
- LERP as a general tool (not only for colors, but also for heights, shading, animations, camera movement, etc.)
- Using normalized ratios (`step / total_steps`) to drive interpolation