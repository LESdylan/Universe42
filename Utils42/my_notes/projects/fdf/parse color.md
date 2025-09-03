suppose `color->low = 0xFF00000` (red), color_mid = 0x00ff00 (green), and t = 0.25

The fucntions calls `blend_rgb(0xFF0000, 000FF00, 0.5)` (since t / 0.5f = 0.5)

`blend_rgb` interpolates:
- : (255 * 0.5 + 0 *0.5) = 127.5 ~= 128
- Green: (0 * 0.5 + 255 * 0.5) = 127.5 ≈ 128
- Blue: (0 * 0.5 + 0 * 0.5) = 0
- Result: 0x808000 (yellowish).

The format uint32_t format allows this result to be directly used in a graphic context.
