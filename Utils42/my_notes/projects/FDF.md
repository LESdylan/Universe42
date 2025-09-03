---
banner: Pasted image 20250724133817.png
banner_y: "31"
sticker: emoji//1f9d0
---
# PARSER

[[REAL Detection collision time]]

[[Parser fdf]]
[[Transform]]
[[render]]

Here we can see [[type of variables stdint]] that are mandatory to understand why chosing the good type is better for the project sake. 
- `red`: `(color >> 16) & 0FF`
- Green: (color >> 8) & 0xFF
- Blue : (color) & 0xFF

This way is faster than using a structure with separate fields for each channel (e.g., struct { uint8_t r, g, b, a; }) because it avoids multiple memory accesses and allows single-instruction operations.

[[parse color]]
