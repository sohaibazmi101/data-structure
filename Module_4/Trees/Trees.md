## **Binary Trees and BST Algorithms & Pseudocode**  

---

## **1️⃣ Binary Tree Traversals**  

### **🔹 Preorder Traversal (Root → Left → Right)**
📌 **Algorithm:**  
1. Visit the **root** node.  
2. Recursively traverse the **left subtree**.  
3. Recursively traverse the **right subtree**.

📌 **Pseudocode:**  
```plaintext
PREORDER(root)
    if root is NOT NULL
        print(root → data)
        PREORDER(root → left)
        PREORDER(root → right)
```

---

### **🔹 Inorder Traversal (Left → Root → Right)**
📌 **Algorithm:**  
1. Recursively traverse the **left subtree**.  
2. Visit the **root** node.  
3. Recursively traverse the **right subtree**.

📌 **Pseudocode:**  
```plaintext
INORDER(root)
    if root is NOT NULL
        INORDER(root → left)
        print(root → data)
        INORDER(root → right)
```

---

### **🔹 Postorder Traversal (Left → Right → Root)**
📌 **Algorithm:**  
1. Recursively traverse the **left subtree**.  
2. Recursively traverse the **right subtree**.  
3. Visit the **root** node.

📌 **Pseudocode:**  
```plaintext
POSTORDER(root)
    if root is NOT NULL
        POSTORDER(root → left)
        POSTORDER(root → right)
        print(root → data)
```

---

## **2️⃣ Binary Search Tree (BST) Operations**  

### **🔹 Insert in BST**  
📌 **Algorithm:**  
1. If the tree is **empty**, create a new node as root.  
2. If the key is **less** than the root, insert it in the **left subtree**.  
3. If the key is **greater**, insert it in the **right subtree**.  

📌 **Pseudocode:**  
```plaintext
INSERT(root, key)
    if root is NULL
        return new node(key)
    if key < root → data
        root → left = INSERT(root → left, key)
    else if key > root → data
        root → right = INSERT(root → right, key)
    return root
```

---

### **🔹 Search in BST**  
📌 **Algorithm:**  
1. If the root is **NULL**, return false (key not found).  
2. If the key matches the root, return true.  
3. If the key is **less**, search in the **left subtree**.  
4. If the key is **greater**, search in the **right subtree**.

📌 **Pseudocode:**  
```plaintext
SEARCH(root, key)
    if root is NULL or root → data == key
        return root
    if key < root → data
        return SEARCH(root → left, key)
    else
        return SEARCH(root → right, key)
```

---

### **🔹 Delete in BST**  
📌 **Algorithm:**  
1. Find the **node to delete**.  
2. If the node has **no children**, delete it.  
3. If the node has **one child**, replace it with the child.  
4. If the node has **two children**, replace it with the **inorder successor** (smallest node in the right subtree).  

📌 **Pseudocode:**  
```plaintext
DELETE(root, key)
    if root is NULL
        return root
    if key < root → data
        root → left = DELETE(root → left, key)
    else if key > root → data
        root → right = DELETE(root → right, key)
    else
        if root → left is NULL
            return root → right
        else if root → right is NULL
            return root → left
        temp = MIN_VALUE_NODE(root → right)
        root → data = temp → data
        root → right = DELETE(root → right, temp → data)
    return root
```

---

## **3️⃣ AVL Tree Operations (Self-Balancing BST)**
### **🔹 Insert in AVL Tree**
📌 **Algorithm:**  
1. Insert the node using **BST insertion**.  
2. Update the **height** of the current node.  
3. Calculate **balance factor**.  
4. If the tree is **unbalanced**, perform **rotations**:
   - **Left-Left (Right Rotation)**
   - **Right-Right (Left Rotation)**
   - **Left-Right (Left Rotation → Right Rotation)**
   - **Right-Left (Right Rotation → Left Rotation)**

📌 **Pseudocode:**  
```plaintext
INSERT_AVL(root, key)
    if root is NULL
        return new node(key)
    if key < root → data
        root → left = INSERT_AVL(root → left, key)
    else if key > root → data
        root → right = INSERT_AVL(root → right, key)
    
    update height(root)
    balance = height(root → left) - height(root → right)
    
    if balance > 1 and key < root → left → data
        return RIGHT_ROTATE(root)
    if balance < -1 and key > root → right → data
        return LEFT_ROTATE(root)
    if balance > 1 and key > root → left → data
        root → left = LEFT_ROTATE(root → left)
        return RIGHT_ROTATE(root)
    if balance < -1 and key < root → right → data
        root → right = RIGHT_ROTATE(root → right)
        return LEFT_ROTATE(root)

    return root
```

---

## **4️⃣ Red-Black Tree (Self-Balancing BST with Colors)**
📌 **Red-Black Tree Properties**:  
✅ **Each node is either Red or Black**  
✅ **Root is always Black**  
✅ **Red nodes cannot have Red children (No two consecutive Red nodes)**  
✅ **Every path from root to a leaf must have the same number of Black nodes**  

### **🔹 Insertion in Red-Black Tree**
📌 **Algorithm:**  
1. Insert the node **like in BST** (color it Red).  
2. If there is a **Red-Red violation**, fix it using:  
   - **Recoloring** (if parent and uncle are Red)  
   - **Rotations** (if parent is Red, uncle is Black)  

📌 **Pseudocode:**  
```plaintext
INSERT_RBT(root, key)
    insert BST(root, key)
    node.color = RED
    while node.parent is RED
        if node’s uncle is RED
            recolor parent, uncle, and grandparent
        else
            if node is a right child
                left rotate parent
            right rotate grandparent
    root.color = BLACK
```

---