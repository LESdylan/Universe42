in the process of building an interpreter in C, tokens are the structured units produced by the [[lexer-scanner]]
that represents the meaningful element of the source code. tokens are the bridge between raw text [[lexemes]]
and the [[Parser fdf]] . 

## What is a token?
A token is a [[data structure]] that represents a categorized unit of [[source code]] ,  derivedj from a [[lexemes]] 
- **Type** : A category that indicates what kind of language element the token represents (`IDENTIFIER`, `NUMBER` , `OPERATOR`) 
- **value**: the actual string from the suorce code [[lexemes]] , such as `x`, `42`, `+`
- **metadata** : optional information like and column numbers for error reporting

```c

typedef struct s_token {

t_token_type type; // e.g., TOKEN_IDENTIFIER

char *content; // e.g., "x"

t_metadata *metadata; // e.g., {line: 1, column: 1}

} t_token;
```

