a conversoin of base of 10 number into base-16 (hex)
hex used digis 

`char  *hex = [01245789abcdef]`
305 % 16 = 1
19 % 16 = 3
1 % 16  = 1

131 -> `0x131`

305 (decimall) = 131 (hex) = 0x131

$$

\begin{aligned}
&\text{Given } n \in \mathbb{N} \\
&q_0 = n \\
&q_{i+1} = \left\lfloor \frac{q_i}{16} \right\rfloor \\
&r_i = q_i \bmod 16 \\
&\text{Hex}(n) = \text{reverse}(\{r_i\}) \text{ (converted to 0–F)}
\end{aligned}
$$

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.6.22 - 18.56pm.drawing",
	"width": 500,
	"aspectRatio": 1
}
```
