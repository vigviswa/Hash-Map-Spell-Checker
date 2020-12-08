# Hashing
Design a Hash-Map to work as a spell-checker for words in the dictionary

# Functions of the Hash Table

<ul> 
  <li> The hash table implements a spell checker.</li>
  <li> Created a file of 100 words of varying length(max 8 characters)</li>
  <li> All the words are in lower case.</li>
  <li> Designed the hash table and enter each word in the hash table.</li>
</ul>

Once the hash table is created, run it as a spell checker. You enter a word(interactive), find
the word in your hash table. Display an error message if the word not found.

<ul>
  <li> Used the linear probing & quadratic probing and count the number of collisions and
    printed it. </li>
  <li> Start with a table size that is about 53. So, 100 words have a load factor of more than
0.5 the program should increase table size accordingly. Add 10 more words. The
    program should automatically determine that table size needs to increase. </li>
  <li> Rehash all the old words when you increase the table size. </li>
  
# Running the Code

Download the C++ code named `spellchecker.cpp` and the `words.txt` file and place them in the same directory. To Run the code, compile the code as:
```
g++ -o spellchecker spellchecker.cpp
``` 
and run as 
```
./spellchecker
```
