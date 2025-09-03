https://gameprogrammingpatterns.com/dirty-flag.html

---
A dirty flag pattern is a boolean variable (often called `dirty`) used to indicate that some datas has changed and needs to be updated, recalculated, or redrawn. 
In our code eaach transformation like rotation on X, X2, Z axes sets a specific dirty flag to `true` when the corresponding value changes.

## Why use dirty flags ?
- Efficiency : Only updates or recalculate things that have actually changed. 
- Tracking changes helps manage complex state updates in graphics UI, or game engines


    ```c
	t->dirty[M_VIEW_ROTATE_X] = true; // Mark rotation X as changed
	t->px += dx;                      // Apply the transformation
    ```

## the pattern
A set of primary data changes over time. A set of derived data is determined from the useing some expensive process. A `dirty` flag tracks when the derived data is out of sync with the primary data. If it set when the primary data changes. If the flag is set when  the derived data is needed. then it is reprocessed and the flag is cleared. Otherwise the previous `cached derived data` is used.


## See also
- this pattern is common outside in browser-side web frameworks like `Angular` . They use dirty flags to track which data has been changed in the browser and needs to be pushed up to the server.
- 