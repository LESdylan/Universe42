the parser of the combination of splitting each word on a buffer line retrieved by a function has been introduced in the context of [[READMES/FDF]]

# Core concept to understand before startng
- how do we define a word ?
- what is our counting algorithm ?
- how do we handle multiple consecutive space ?
- do we need exact allocation  or over_allocation  is okay ? (simplicity vs memory trade off)
- how does this fit with our `ft_split` function internatlly ?
we know for sure that if our ft_split could do the counting in the inner algorithm our life would be a lot easier. Now we have to think about recreating a special with the good data structure or maybe use our ft_split currently into the libft wihtout doing a counting precise or even pass 2 times into this implementation.

1. I could image easily 
```bash
Split array contents:
  [0]: "hello"
  [1]: "my"
  [2]: "name"
  [3]: "is"
  [4]: "dylan"
  [5]: "\n"
  [6]: "dfjsfdhshaddf"
  Total tokens: 7
```

using split and get_next_line is really comfortable as implementation 
because from what we can see in this diagram we just need a variable that hold the whole line; then be divided into chunk separated by the separator `' '` and put all the chunk again and again altogether in a double array

![[parse_map_gnl]]
