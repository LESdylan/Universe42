when building an interpreter, the [[lexer-scanner]] is a critical component that lays the foundation for processing source code. A lexer, short for lexical analyzer, is responsiblel for breaking down the raw source code into a sequence of meaningful units called tokens. 

## What  is a lexer?

A lexer takes the raw input of a  [[source code]] - a string of characters - and convert it into a stream of [[lexemes and tokens]] .We need to think of the lexxer as a translator that transforms `human readable code` into a structured format that the interpreter can process further.


> [!NOTE]
> The lexer is the part of C program that scans the source code, identifies lexemes, and produces tokens ( usign a function like `lexer_next_token` . The lexer reads the source code, groups characters into lexemes based on predifined rules, and assign each [[lexemes]] a token type . it also attaches metadata like like and column



    ```bash
	    x = 42 + 3
    ```

![[lexer]]

> Each  token tipically includes its type (`e.g.`, `IDENTIFIER`, `NUMBER`) and value (`X`, `42`)

## Why is the lexer important ?
The lexer leverage the role of the first stage in interpretation pipeline, preparing the source code for subsequent stages like parsing and execution. Its role is crcial for the following reasons:
1. Simplifies Parsing: By converting raw text into tokens, the lexer reduces the complexity of the [[Parser fdf]]'s job The parser works with structured tokens rather than raw characters, making it easier to analyze the code's syntax
2. Handles whitespace and comments: The lexer filters out irrelevan format like `whitespace`, newlines, and comments, ensuring only meaningful tokens reach the parser.ç
3. Improves Error detection: The lexer can catch basic errors, such as invalid characters or malformed tokesn (an unrecognized  patterns like `#$?`) before the parser processes the input
### How  does a  lexer work ?

The lexer processes the source code character by character, using a set of rules (often defined by [[REGEXP]] or a [[Finite State Machine]]) to identify tokens. Here's a simplifieed overview of its workflow.
1. Read input: The lexer reads the source code as a string tracking its position (e.g., line and column numbers for error reporting)
2. `identify tokens` : it matches sequences of characters against predefined patterns for tokens (e.g, digits for numbers, letters for identifiers). This is often implemented using a `finite state machine`or handwritten logic in C. 
3. `Emit tokens` : For each match, the lexer creates a token object containing the token's type, value and optional, metadata (line number...)
4. `Advance and repeat` : The lexer advances its position in the input string and continues until it reaches the end fo the input or encounters an error.

**Example**: For the input x = 42;, the lexer:

- Reads x, recognizes it as an identifier, and outputs a token: 
    ```c
  {
  type: TOKEN_ID,
  content: "x",
  metadata: {line: 1, column: 1}
  }
 ```
 
- Reads =, recognizes it as an operator, and outputs: 
    ```c
  {
  type: TOKEN_OPERATOR,
  content: "="sd,
  metadata: {line: 1, column: 3}
  }
```
 
- Reads 42, recognizes it as a number, and outputs: 
    ```c
  {
  type: TOKEN_NUMBER,
  content: 42,
  metadata: {line: 1, column: 5}
  }
 ```
- Reads ;, recognizes it as punctuation, and outputs: 
  ```c
  {
  type: TOKEN_PUNCTUATION,
  content: ";",
  metadata: {line: 1, column: 7}
  }
 ```
### Implementing a lexer in C
To  implement a lexer in C, we'll need to define token types, create a mechanism to scan the input, and generate tokens.

```c
typedef enum e_token_type
{
	TOKEN_ID,
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_EQUAL,
	TOKEN_SEMICOLON,
	TOKEN_EOF,
	TOKEN_ERROR
}t_token_type;

typedef struct s_token
{
 t_token_type type;
 char *value;
 int line;
 int column;
}
typedef struct s_lexer
{
	char *source;
	int position;
	int line;
	int column;
}t_lexer
```

## WARNING 
Performance: For large inputs, optimize by minimizing memory allocations and using efficient string handling (avoid excessive copying)
Extensibility: Design our lexer to handle new token types as our language evolves
Testing: Test our lexer with various inputs, including edgee cases (empty strings, invalid charcters)