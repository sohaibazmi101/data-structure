### **🔹 Hashing**
Hashing is a technique used to map data (keys) to specific locations (indexes) in an array using a **hash function**.  
This allows for **fast insertion, deletion, and lookup** operations, typically in **O(1) time**.

---

### **1️⃣ Hash Table Algorithm**
A **hash table** stores key-value pairs using a hash function.

#### **Algorithm (Basic Hash Table)**
1. Create an array of size `N` (hash table).
2. Compute the index using `index = hashFunction(key) % N`.
3. Store the key-value pair at the computed index.
4. Handle collisions if the index is already occupied.
5. Retrieve data using the same hash function.

#### **Pseudocode**
```plaintext
Initialize hashTable[N] with NULL
Function insert(key, value):
    index = hashFunction(key) % N
    If hashTable[index] is empty:
        Store (key, value) at hashTable[index]
    Else:
        Handle collision (e.g., chaining or probing)

Function search(key):
    index = hashFunction(key) % N
    If hashTable[index] contains key:
        Return value
    Else:
        Return "Key not found"

Function delete(key):
    index = hashFunction(key) % N
    If hashTable[index] contains key:
        Remove key-value pair
```

---

### **2️⃣ Collision Handling Techniques**
When multiple keys hash to the same index, we use these techniques:

#### **(A) Chaining (Using Linked List)**
- Each index stores a linked list of key-value pairs.
- If a collision occurs, append the new element to the list.

#### **(B) Open Addressing**
- **Linear Probing** → If a collision occurs, check the next available index.
- **Quadratic Probing** → Check indices in a quadratic pattern.
- **Double Hashing** → Use a secondary hash function for collision resolution.

---

### **3️⃣ LRU Cache Algorithm (Least Recently Used Cache)**
LRU Cache is used in memory caching to store frequently used elements while removing the least used ones.

#### **Algorithm**
1. Use a **hash map** for quick lookup.
2. Use a **doubly linked list** to track recent usage.
3. When accessing an element:
   - Move it to the front (most recently used).
4. When inserting a new element:
   - If full, remove the **least recently used** element.
   - Add the new element to the front.

#### **Pseudocode**
```plaintext
Initialize hashMap and doublyLinkedList
Function get(key):
    If key exists in hashMap:
        Move key to front of list
        Return value
    Else:
        Return -1 (Not found)

Function put(key, value):
    If key exists:
        Update value and move key to front
    Else:
        If cache is full:
            Remove least recently used (last element in list)
        Insert key at front
        Add to hashMap
```

---