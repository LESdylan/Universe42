Here's a detailed flowchart showing how Make parses a Makefile:

```mermaid
graph TD
    A["Start Make Process"] --> B["Read Makefile"] --> delete-comments -->
    C["Lexical Analysis: "]
    C --> D{"Parse the line"}
    D --> E["Parse Rules"]
    
    E --> F["Process Include Directives"]
    F --> G["Evaluate Conditional Statements"]
    
    E --> H["For Each Rule"]
    H --> I["Parse Target"]
    I --> J["Parse Prerequisites"]
    J --> K["Parse Commands"]
    
    D --> L["Parse Macros assignment"]
    L --> M["Simple Variables (:=)"]
    L --> N["Recursive Variables (=)"]
    L --> O["Conditional Assignment (?=)"]
    L --> P["Append Operator (+=)"]
    
    K --> Q["Command Processing"]
    Q --> R["Variable Expansion"]
    Q --> S["Shell Command Parsing"]
    
    G --> T["Create Dependency Graph"]
    T --> U["Determine Build Order"]
    U --> V["Execute Commands"]
    V --> W["End Make Process"]

    %% Subgraph for Variable Processing
    subgraph "Variable Processing"
    M
    N
    O
    P
    end

    %% Subgraph for Command Processing
    subgraph "Command Processing"
    R
    S
    end
```

This diagram shows the main steps in Makefile parsing:

1. Initial reading of the Makefile
2. Lexical analysis of the content
3. Processing of variables and their different types
4. Parsing of rules (targets, prerequisites, and commands)
5. Handling of include directives and conditionals
6. Creation of the dependency graph
7. Execution of commands in the correct order

<aside> <img src="/icons/light-bulb_yellow.svg" alt="/icons/light-bulb_yellow.svg" width="40px" />

MACROS assginment may expand to an entire rule if the rule is build on one line only because MACROS can re-split after it has expanded them. Otherwise it cannot.

```makefile
myrule = target : ; echo built
$(myrule)
```

</aside>