Understand the concept of Space complexity of algorithms and how to calculate space complexity.


Definition: The space complexity of an algorithm or a computer program is the amount of memory space 
required to solve an instance of the computational problem as a function of the size of the input.
Simple words : It is the memory required by an algorithm to execute a program and produce output.
Similar to time complexity, Space complexity is often expressed asymptotically in big O notation, 
such as O(n), O(nlog(n)), O(n^2) etc., where n is the input size in units of bits needed to represent the input.



For any algorithm, memory is required for the following purposes - 
1) To store program instructions.
2) To store constant values.
3) To store variable values.
4) And for few other things like function calls, jumping statements etc.



Auxiliary Space : 
is the temporary space (excluding the input size) allocated by your algorithm to solve the problem, with respect to input size.
Space complexity includes both Auxiliary space and space used by input. 
Space Complexity = Input Size + Auxiliary space.