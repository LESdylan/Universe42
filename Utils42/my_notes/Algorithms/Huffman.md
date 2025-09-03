it is an algorithm that allow to compressdata (like ZIP files). 
huffman algorithm is greedy algorithm used for lossless data compression. It's all about reduncing th number of bit used to represent characters in a file, especially when some characters appear more than others

# key idea 
More frequent  = shorter code. Less frequent = longer code.
> imagine we're texting and we use the laughin emojij wayy more than the licorn. we can ask ourselves why waste 8 bits every time for both when we can just say le't use  2 bits for laughing emoji and maybe 6 remaining for the licorn

### frequency table & code generation
- the client builds a huffman tree from the frequency table
- each character is assigned a unique bit code: more frequent character get shorter codes

the client encodes the message using the huffman codesm producittin a bit string (not a byte string)
### Transmission protocol
- the client sends:
	1. the number of unique characters (1 byte)
	2. for each unique character: the character ( 1 byte) and its frequency (4 bytes)
	3. the encoded message as a bit stream (one signal per bit)
	4. an end marker (8 zero bits)
- The server receives the frequency table, reconstructs the huffman tree, and decodes the bit stream back into the original message
### Trade-off
Huffman is best when the message is logn and or highly repetitive
- for example a message like "aaaaaaaaaaaaaa...." is encoded very efficiently
for short or diverses messages, the overhead of sending the frequency table outweighs the saving from encoding
- for `hello`, the classic approach (8 bit per char) is more efficient

## So in this implementation
```c
int classic_signals = 8 * strlen(message);
int huffman_signals = table_signals + encoded_signals + 8;
if (huffman_signals < classic_signals)
	use_huffman();
else
	use_classic();
```

- to analyze the string cost we should analyze number of unique characters and their frequencies
- Estimate the total number of bits for the encodes message (sum of code lengths)
- calculate the method with fewer signals
#### Example: 
>[!info]
> 
> for "hello" : 
>	- classic: 5 chars * 8bits = 40 signals
>	- huffman: table ( 4 unique) = 168, encoded = 18, total = 194 signals
>
>for "aaaaaaaaaaa..." 100's a:
>	- classic : 800 signals
>	- huffman: table = 48, encoded = 100, END = 8, TOTAL = 156 signals
>> [!tip]
>> huffman is a powerful optimization for the right data, but not always the best. So the need to analyze the data and choose the most efficeint protocol dynamically for optimal performance

