
---

## **1. Stack**
A stack follows **LIFO (Last In, First Out)** principle.

### **Implementation Methods**
- **Array-based**
- **Linked List-based**

### **Operations**
1. **Push (Insert)**
2. **Pop (Remove)**
3. **Peek (Top Element)**
4. **isEmpty (Check if stack is empty)**
5. **isFull (Check if stack is full, for arrays)**

---

### **1.1 Stack Using Array**
#### **Algorithm**
```plaintext
1. If TOP == MAX_SIZE - 1
     Print "Stack Overflow"
     Exit
2. Increment TOP by 1
3. Insert DATA at stack[TOP]
```
#### **Pseudocode**
```plaintext
PUSH(STACK, TOP, DATA)
    IF TOP == MAX_SIZE - 1 THEN
        PRINT "Stack Overflow"
        EXIT
    ENDIF
    TOP = TOP + 1
    STACK[TOP] = DATA
END
```

---

### **1.2 Stack Using Linked List**
#### **Algorithm**
```plaintext
1. Create a new NODE
2. If memory allocation fails, print "Stack Overflow"
3. Set newNode->data = DATA
4. Set newNode->next = TOP
5. Update TOP to newNode
```
#### **Pseudocode**
```plaintext
PUSH(TOP, DATA)
    NEW_NODE = CREATE_NODE()
    IF NEW_NODE == NULL THEN
        PRINT "Stack Overflow"
        EXIT
    ENDIF
    NEW_NODE->DATA = DATA
    NEW_NODE->NEXT = TOP
    TOP = NEW_NODE
END
```

---

### **1.3 Applications of Stack**
- **Undo/Redo in Text Editors**
- **Parentheses Matching**
- **Function Call Stack (Recursion)**

---

## **2. Queue**
A queue follows **FIFO (First In, First Out)** principle.

### **Operations**
1. **Enqueue (Insert)**
2. **Dequeue (Remove)**
3. **Front (Get front element)**
4. **isEmpty (Check if queue is empty)**
5. **isFull (Check if queue is full, for arrays)**

---

### **2.1 Queue Using Array**
#### **Algorithm**
```plaintext
ENQUEUE(DATA)
1. If REAR == MAX_SIZE - 1, print "Queue Overflow" and exit
2. If FRONT == -1, set FRONT = 0
3. Increment REAR
4. Set QUEUE[REAR] = DATA
```
#### **Pseudocode**
```plaintext
ENQUEUE(QUEUE, FRONT, REAR, DATA)
    IF REAR == MAX_SIZE - 1 THEN
        PRINT "Queue Overflow"
        EXIT
    ENDIF
    IF FRONT == -1 THEN
        FRONT = 0
    ENDIF
    REAR = REAR + 1
    QUEUE[REAR] = DATA
END
```

---

### **2.2 Circular Queue**
A circular queue overcomes the **wasted space** issue in normal queues.

### **Algorithm**
```plaintext
1. If (REAR + 1) % MAX_SIZE == FRONT, print "Queue is Full"
2. If FRONT == -1, set FRONT = 0
3. REAR = (REAR + 1) % MAX_SIZE
4. Insert DATA at QUEUE[REAR]
```
#### **Pseudocode**
```plaintext
ENQUEUE_CIRCULAR(QUEUE, FRONT, REAR, DATA)
    IF (REAR + 1) % MAX_SIZE == FRONT THEN
        PRINT "Queue is Full"
        EXIT
    ENDIF
    IF FRONT == -1 THEN
        FRONT = 0
    ENDIF
    REAR = (REAR + 1) % MAX_SIZE
    QUEUE[REAR] = DATA
END
```

---

## **3. Deque (Double-Ended Queue)**
A **deque** allows insertion and deletion from both ends.

### **Operations**
1. **Insert Front**
2. **Insert Rear**
3. **Delete Front**
4. **Delete Rear**
5. **Get Front**
6. **Get Rear**

---

### **Algorithm for Insert at Front**
```plaintext
1. If FRONT == 0, move FRONT to MAX_SIZE - 1
2. Else, decrement FRONT
3. Insert DATA at QUEUE[FRONT]
```
#### **Pseudocode**
```plaintext
INSERT_FRONT(QUEUE, FRONT, REAR, DATA)
    IF (FRONT == 0) THEN
        FRONT = MAX_SIZE - 1
    ELSE
        FRONT = FRONT - 1
    ENDIF
    QUEUE[FRONT] = DATA
END
```

---

## **4. Priority Queue**
A **priority queue** assigns a priority to each element, where elements with higher priority are dequeued before lower priority elements.

### **Operations**
1. **Insert (Insert an element based on priority)**
2. **Delete (Remove highest priority element)**
3. **Peek (Get highest priority element)**

---

### **Algorithm for Insert**
```plaintext
1. If QUEUE is empty, insert DATA at first position
2. Else, find the correct position based on priority
3. Shift elements to make space for the new element
4. Insert DATA at the correct position
```
#### **Pseudocode**
```plaintext
INSERT_PRIORITY(QUEUE, SIZE, DATA, PRIORITY)
    IF SIZE == 0 THEN
        QUEUE[0] = (DATA, PRIORITY)
    ELSE
        FIND correct POSITION based on PRIORITY
        SHIFT elements to right
        INSERT (DATA, PRIORITY) at correct POSITION
    ENDIF
END
```

---
