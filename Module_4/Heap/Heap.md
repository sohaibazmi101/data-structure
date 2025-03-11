### **Heaps Overview**  
A **Heap** is a special **binary tree** where:  
- It follows **complete binary tree** properties (all levels are filled except possibly the last level, which is filled from left to right).  
- It satisfies the **heap property**:  
  - **Min Heap**: Parent node ≤ Child nodes (smallest element at the root).  
  - **Max Heap**: Parent node ≥ Child nodes (largest element at the root).  

---

### **Heap Operations**  

#### **1. Insertion in Heap**  
- Insert the element at the last position.  
- Perform **heapify-up (bubble-up)** to maintain heap property.  

**Algorithm:**  
1. Insert the new element at the end.  
2. Compare with the parent; swap if necessary.  
3. Repeat until the heap property is restored.  

**Pseudocode (Min Heap Insertion)**  
```plaintext
insert(heap, value):
    heap.append(value)  # Add value at the end
    index = size(heap) - 1
    while index > 0 and heap[parent(index)] > heap[index]:
        swap(heap[parent(index)], heap[index])
        index = parent(index)
```
---

#### **2. Deletion (Extract Min/Max from Heap)**  
- Remove the root (smallest in Min Heap, largest in Max Heap).  
- Replace it with the last element.  
- Perform **heapify-down (bubble-down)** to maintain heap property.  

**Algorithm:**  
1. Remove root element.  
2. Replace root with the last element.  
3. Compare with the smallest/largest child and swap if needed.  
4. Repeat until heap property is restored.  

**Pseudocode (Min Heap Deletion)**  
```plaintext
deleteMin(heap):
    if heap is empty:
        return
    heap[0] = heap[last_index]  # Move last element to root
    remove last element
    heapifyDown(heap, 0)

heapifyDown(heap, index):
    left = leftChild(index)
    right = rightChild(index)
    smallest = index

    if left < size(heap) and heap[left] < heap[smallest]:
        smallest = left
    if right < size(heap) and heap[right] < heap[smallest]:
        smallest = right
    if smallest != index:
        swap(heap[index], heap[smallest])
        heapifyDown(heap, smallest)
```
---

### **Heap Sort**  
Heap Sort sorts an array using **heap properties**.  
- Build a **Max Heap** from the array.  
- Repeatedly extract the max element (swap it with the last element).  
- Perform **heapify** to maintain heap structure.  

**Algorithm:**  
1. Convert the array into a max heap.  
2. Swap the root with the last element.  
3. Reduce heap size and heapify the root.  
4. Repeat until the heap is empty.  

**Pseudocode:**  
```plaintext
heapSort(arr):
    buildMaxHeap(arr)  # Convert array into Max Heap
    for i = size(arr) - 1 to 1:
        swap(arr[0], arr[i])  # Move max element to the end
        heapifyDown(arr, 0, i)  # Restore heap property
```
---

### **Priority Queue using Heap**  
A **Priority Queue** is an optimized queue where elements are dequeued based on priority instead of FIFO order.  
- Implemented using a Min/Max Heap for efficient insertion and deletion.  

**Applications:**  
- **Dijkstra’s Algorithm (Graph Shortest Path)**  
- **Task Scheduling in OS**  
- **Event-driven simulations**  