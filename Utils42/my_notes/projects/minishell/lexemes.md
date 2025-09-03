lexeme is a sequence of characters in the source code that represents a single, meaningful unit before it is categorized. It's the raw text taht matches a pattern in the language's grammar.

`role`: lexemes are the input to the lexer. They are substrings of the source code that will be transformed into tokens.
- **Example**: In the source code x = 42;, the lexemes are:
    - x (a sequence of characters forming an identifier)
    - = (a sequence forming an operator)
    - 42 (a sequence forming a number)
    - ; (a sequence forming punctuation)
- **Key Point**: A lexeme is just the raw string, without any categorization or additional data.
