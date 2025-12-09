# AoC-2025
My attempt at AoC 2025

Code is written in c++.

## Thought Process
<details>
  <summary><h3>Day 1</h3></summary>
  <p>
    Part 1:  
    Left turn is minus, Right turn is plus. If the final dial value is below 0, add 100, if it is above, subtract 100. Check if the dial is at zero, the add to counter.
  </p>
  <p>
    Part 2:  
    Now everytime I add or subtract 100, I increase my counters since it means that the dial passed 0. Then check for double counting: If I turn left from zero, my dial will be negative and I would have to add 100, increasing counter when it is not needed. If I turn right and land on 0, i.e. dial will be 100, i will subtract 100, counting once, and since now the dial is at zero, it will be counted twice.
  </p>
</details>

<details>
  <summary><h3>Day 2</h3></summary>
  <p>
    Part 1:  
    I parse the input into a vector of numbers, where every even index is the start, and odd the end of the range. I take the half prefix (rounded down for odd digits) of the starting number (1234 will be split to 12, 67890 will be split to 67) and generate possible invalid ids by splicing the prefix together (12 becomes 1212). Special consideration for single digits was added. The ids will be checked to see if they lie within the range, and the prefix will be iterated up by one. The numbers generated for 66-102 will be 66, 77, 88, 99, 1010. If the id is bigger than the range, there is no need to continue to generate.
  </p>
  <p>
    Part 2:  
    The above method will be hard to replicate for part 2. Instead, I iterate from the start to the end number, checking if each number within the range fits the pattern. The check now consist of breaking the ids into smaller same sized chunks, and checking if each chunk is the same.
  </p>
</details>

<details>
  <summary><h3>Day 3</h3></summary>
  <p>
    Part 1:  
    Since the digits must be in order, the last number in the line cannot be the first digit. Hence, I just need to check the first length-1 digits for the biggest number (A), then the remaining digits after A, for the next biggest number.
  </p>
  <p>
    Part 2:  
    Taking a similar approach from above. since I need 12 digits, the last 11 digits cannot be the 1st number, the last 10 digits cannot be the 2nd number and so on. Hence I just need to find the larges number in the limited range and apply the same concept on the rest of the 11 numbers.
  </p>
</details>

<details>
  <summary><h3>Day 4</h3></summary>
  <p>
    Part 1:  
    Treating the input like a matrix, I went through each entry, counting the number of rolls around the entry, and increasing the counter only if there is less than 4 rolls around the entry.
  </p>
  <p>
    Part 2:
    I added a new variable to keep track of how mnay rolls can be removed. While the variale is not zero, I will keep rechecking and counting based on part 1. Furthermore, I store the coordinated to those rolls that will be removed and removed them after each round. When the number of rools that can be removed is 0, it reached the end. Another counter keeps track of all the rolls removed for all the rounds.
  </p>
</details>

<details>
  <summary><h3>Day 5</h3></summary>
  <p>
    Part 1:  
    I parsed the range as pairs now (improvement from Day 2 I guess), checking recursively if the ids lie within the range.
  </p>
  <p>
    Part 2:  
    I tried iterating each number from every range, storing unique ids in a vector until the end and taking the size of the vector is my answer. Obviously it did not work since the numbers get very large. Instead, I merge the ranges together, simplifying the intervals. For each interval, I just need to take end-start+1.
  </p>
</details>

<details>
  <summary><h3>Day 6</h3></summary>
  <p>
    Part 1:  
    I parsed all the data into vectors. First vector contains lists of numbers in each row, with whitespace removed, and second vector contains all the operands, with whitespace removed. Afterwards, just combine each number from the rows together.
  </p>
  <p>
    Part 2:  
    A different approach was needed. Instead of parsing the numbers, I slowly iterated through each column, storing the number in a vector. When I reach a column of with no numbers, I will proceed to add or multiple the numbers in the vector, and adding it to the total count. A last check is needed for the last column as there is no empty column to trigger the combination.
  </p>
</details>

<details>
  <summary><h3>Day 7</h3></summary>
  <p>
    Part 1:  
    A array was used to store the state of the beam using 0s and 1s. when a beam hits a splitter, the position on the left and right will become 1, and the position in the middle will become zero. This keeps track of beam positions. A counter will increment when a beam hits the splitter.
  </p>
  <p>
    Part 2:  
    Using a similar concept, except now the array means the number of ways the beam can reach that position. So when the beam hits a splitter, its value will be added to the left and right, while the middle becomes zero.
  </p>
</details>

<details>
  <summary><h3>Day 8</h3></summary>
  <p>
    Part 1:  
    When parsing the input, each coordinate is given an index based on its position in the input file. While computing all possible distances, the information is stored as an array of [distance, coordinate 1, coordinate 2]. The vector id distances is sorted and the first 10/1000 is used. To determine whether the coordinates are connected, I created an array of indexes. The numbers at index 0 means are the numbers coordinate 0 is linked with. (If the 0th index is {2, 5, 6}, it means that there are connections 0-2, 0-5, 0-6. The 5th index will also have the number 0). When all connections are keyed in, a loop will merge the links together. (Since the loop starts from 0, where the numbers are {2, 5, 6}, it will head to the 2nd postion. If the 2nd position contains {0, 4}, it will absorb the unique numbers, excluding itself (0). Then it delete all numbers from the 2nd position. Afterwards, it heads to position 5, then 6, then 4, which was added earlier. By the time the loops ends, all numbers connected to 0 will be at position 0. Then it will head off to the next non-empty position, which will be a different circuit). After the processing, the size is calculated.
  </p>
  <p>
    Part 2:  
    So the above method will not work for this (it works but the complexity is too high). For this part, more graph theory-ish terminology will be used. The same array, albeit renamed, [distance, vertex 1, vertex 2] will be used. An empty global vector "graph" is used to keep track of the connectedness. If both vertices are in the graph, then check if they are in the same subgraph (subgraphs are not connected, i.e. 1-3, 2-4). If yes, I am essentially creating a cycle, no further processing is needed. If no, that means that the vertices will be a bridge between the two subgraphs, and hence the two subgraphs will be merged. If only one of the vertices are in the graph, then add the other vertex into the same subgraph. If non of the vertices are in the graph, then create a new subgraph with both vertices. The algorithm will stop when the graph consist only only 1 subgraph, with a size equal to the number of inputs. You can also use this solution for part 1 (probably).
  </p>
</details>

<details>
  <summary><h3>Day 9</h3></summary>
  <p>
    Part 1:  
  </p>
  <p>
    Part 2:  
  </p>
</details>

<details>
  <summary><h3>Day 10</h3></summary>
  <p>
    Part 1:  
  </p>
  <p>
    Part 2:  
  </p>
</details>

<details>
  <summary><h3>Day 11</h3></summary>
  <p>
    Part 1:  
  </p>
  <p>
    Part 2:  
  </p>
</details>

<details>
  <summary><h3>Day 12</h3></summary>
  <p>
    Part 1:  
  </p>
  <p>
    Part 2:  
  </p>
</details>




