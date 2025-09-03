the interpreter  is like speaking with a friend that speks another language, but the communication is not fluid and lack of detail or just global understanding for both of them to get along as the day go.. But one of them has a solution, the solution of using an interpreter like the glasses of meta that traduces litterally all the conversations and print those information into the app of phone to follow and track the conversation... either for debugging purposes, clarifications or just to recall the themes of the conversation.
ç
Using an interpreter today it's not only useful, it's necessary for any things in life, from traduction of natural languages to creating a new semantinc with a bunch of rules  to simplify a workflow or things like that...
bash as a [[shell]]  use its own interpreter integrated to make communicate powerful command of combinations with the [[kernel]] 

In programming land:
- An interpreter is a program that executes code directly, line by line without first converting the whole program into machine code (like a [[compiler]] would)
- Example : Python is interpreted, we write print("hello"), the interpreter seesjj it, parses it, and executes it immedialtely
- For our minishell, the shell is kind of acting like a `partial interpreter` , it takes user commands (like `ls -la`) and then interprets what those mean to the OS (usually just delegating execution).



## the interpreter is build from several components
![[Interpreter_shelll]]

The interpreter is build from several step : 
[[lexer-scanner]] -> [[Parser fdf]] -->  [[Semantic analyzer]] --> [[IR / intermediate representation]] --> [[Executor / Runtime]] 