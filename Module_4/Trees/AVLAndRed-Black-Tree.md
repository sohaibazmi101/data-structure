### **AVL Tree (Adelson-Velsky and Landis Tree)**
An **AVL Tree** is a self-balancing **Binary Search Tree (BST)** where the difference between the heights of the left and right subtrees (Balance Factor) of any node is at most **1**. If the balance factor becomes more than 1 or less than -1, the tree is rebalanced using **rotations**.

#### **Balance Factor**  
The balance factor of a node is calculated as:  
\[
\text{Balance Factor} = \text{Height of Left Subtree} - \text{Height of Right Subtree}
\]
For an AVL Tree, **Balance Factor** must be in the range **{-1, 0, 1}**.

#### **Rotations in AVL Tree**  
When inserting or deleting a node, if the tree becomes unbalanced, we perform **rotations** to restore balance. There are **four types of rotations**:

1. **Left Rotation (LL Rotation)** → Applied when there is an imbalance in the left subtree.
2. **Right Rotation (RR Rotation)** → Applied when there is an imbalance in the right subtree.
3. **Left-Right Rotation (LR Rotation)** → Applied when there is a left-right imbalance (Left subtree is deeper, but new node is in the right child).
4. **Right-Left Rotation (RL Rotation)** → Applied when there is a right-left imbalance (Right subtree is deeper, but new node is in the left child).

#### **Time Complexity**
- **Insertion**: \(O(\log n)\)
- **Deletion**: \(O(\log n)\)
- **Searching**: \(O(\log n)\)  
AVL trees provide faster lookup times than unbalanced BSTs.

---

### **Red-Black Tree**
A **Red-Black Tree** is another self-balancing BST where nodes follow certain color rules. Unlike AVL Trees, Red-Black Trees allow a little imbalance to minimize the number of rotations, making them more efficient for **frequent insertions and deletions**.

#### **Properties of Red-Black Tree**
1. **Every node is either Red or Black.**
2. **Root is always Black.**
3. **No two consecutive Red nodes appear (No Red-Red parent-child relationship).**
4. **Every path from a node to its descendant NULL pointers has the same number of Black nodes.**
5. **Newly inserted nodes are always Red.**

#### **Balancing Red-Black Tree**
When an insertion or deletion violates the Red-Black properties, we fix the tree using:
- **Recoloring** (Changing Red to Black and vice versa)
- **Rotations** (LL, RR, LR, RL like AVL Tree)

#### **Time Complexity**
- **Insertion**: \(O(\log n)\)
- **Deletion**: \(O(\log n)\)
- **Searching**: \(O(\log n)\)

