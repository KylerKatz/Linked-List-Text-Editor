# Linked-List-Text-Editor
A simple text editor that utilizes a linked list to store each line entry.  
This is my code originally from Sep 15, 2019, created for my Data Structures and Algorithms class.

## User commands:

insertEnd "text"  -- insert given text at the end of the document

insert 3 "text" --insert given text at the line indicated by index given

delete 3 --- delete line at index given

edit 3 "text" --- replace the line at the index given with the given text

print -- print the entire document, with line numbers

quit - quit/exit the program

search "text" -- print the line numbers and lines that contains the given text.  print "not found" if it is not found. Should also return multiple matches.

### Example - Search for lines containing 'A':

#### Input
1 A <br />
2 B <br />
3 AC <br />

search A

#### Output
1 A <br />
3 AC <br />

## Commentary On My Code
### 1. Describe the data structure you used, i.e. the type of linked list. 
For this project, I decided to go with a doubly ended linked list. That is, my linked list has a reference to two ends, a head, and a tail. I chose this type of linked list because in the past, when I have dealt with linked list, I always preferred to also have a tail. I feel that it allows me to simplify my code for some of the functions and in some cases can make performing tasks more efficient. There are two other types that I could have used a regular single linked list and a doubly linked list. A singly linked list would have worked just fine for this project; however, I just prefer a doubly ended linked list instead. As for a doubly linked list, I chose not to go with this implementation because it would have been overkill for this particular project. For instance, if this project had called for a function that prints the reverse of the linked list, then I might have gone with a doubly linked list instead just to make it simpler. 

### 2. What is the computational complexity of the methods in the implementation?

The computational complexity of each method are as follows,

insertEnd() has a time complexity of O(1) this is because the function always requires a constant runtime weather the list is empty or has n nodes. This is because my list has a tail. So, if the list is empty insert at the head, if it has n nodes just use the tail to add it to the end of the list then make that new node the tail. 

insertAt() has a time complexity of O(n) this is because this function relies a lot on traversing the list using curr = curr->next;. Everything else is either an if or else statement. 

deleteAt() has a time complexity of O(n) this function is very similar to the insertAt function, except with a few different checks and deleting instead of inserting. 

print() has a time complexity of O(n) this is because curr = curr->next; is also used in this function to print the current data in the node and then move onto the next node to do the same thing until the size of the list is reached. 

search() has a time complexity of O(n) this is because just like the previous function, this function traverses each node in the list. It doesn’t matter if the text is in one, all, or none of the nodes, the list will always be fully traversed. 

The way I implemented quit is just with a bool and a while loop. If the bool goes from true to false, then the program terminates. If I made this a function such as bool quit(bool off) {return off} then the time complexity would be O(1) because it is just returning off which in this case would be false, and this would cause the program to jump out of the while loop and end.

### 3. Your thoughts on the use of linked lists for implementing a line editor. What are the advantages and disadvantages of using a linked list?

The use of a linked list for a line editor is a strong choice because it is very efficient. For instance, if you want to insert a new node (line) between two other nodes then you only effect the node in front of it and behind it. As opposed to something like a vector, which would required creating a temp array that is one larger then the current size, copying over all of the elements that are before the desired location, then inserting the new node, and then copying over all of 
the nodes after it. This would be a much more inefficient way of doing the same task. However, one disadvantage of a linked list could be when you want to access the data at a node. You have to traverse the list until you get to the node you want making it a time complexity of O(n). However, if you tried the same thing with something like a vector, you can access the element by the index without having to deal with anything else. The time complexity for this would be O(1). 

### 4. What did you learn from this assignment and what would you do differently if you had to start over?

From this assignment, I felt like I learned how to start thinking about a data structure in terms of time complexity. Now that I have a basic understanding of time complexity it helps me look at functions differently. If I had to start over, I think I would work on simplifying my code in some of my functions a bit more. Right now, there are a lot of if statements for checking certain occurrences. I feel that there are probably cleaner and simpler ways to write some of them. 
