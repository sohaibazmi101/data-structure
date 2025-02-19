# **Arrays: Static and Dynamic Arrays**

Arrays are fundamental data structures used to store elements of the same type in contiguous memory locations. They provide fast access to elements but have different memory allocation strategies based on whether they are static or dynamic.

1️⃣ Static Arrays

A static array is an array with a fixed size, allocated at compile time (for languages like C/C++). The size cannot be changed during runtime.

Characteristics:
✅ Fixed size (declared at compile-time)
✅ Contiguous memory allocation
✅ Fast access (O(1) for indexing)
🚫 Cannot grow or shrink dynamically

Advantages:
Memory efficiency: No extra overhead of resizing.
Cache-friendly: Data is stored in contiguous memory blocks, improving performance.
Disadvantages:
Fixed size: Cannot be resized dynamically.
Wasted memory: If unused elements exist, they still occupy space.

2️⃣ Dynamic Arrays

A dynamic array can resize itself during runtime. In C++, it is implemented using pointers (new keyword) or std::vector. In Python, lists are dynamic arrays by default.

Characteristics:
✅ Flexible size (can expand or shrink)
✅ Uses heap memory
✅ More memory-efficient than static arrays when resizing is needed
🚫 Slightly slower than static arrays due to resizing overhead

Advantages:
Flexible size: Can grow/shrink dynamically.
Efficient memory usage: Uses heap allocation only when needed.
Disadvantages:
Memory overhead: Requires extra space for resizing.
Resizing cost: Expanding may involve copying elements to a new memory location.

4️⃣ When to Use?

Use Static Arrays when the size is known beforehand and will not change.
Use Dynamic Arrays when flexibility is required, and the size may change during execution.