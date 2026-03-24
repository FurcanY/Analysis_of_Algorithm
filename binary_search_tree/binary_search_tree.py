# Tree yapısı
class Node:
    def __init__(self, value, left: 'Node | None' = None, right: 'Node | None' = None):
        self.value = value
        self.left: Node | None = left
        self.right: Node | None = right

class Tree:
    def __init__(self):
        self.root: Node | None = None
        self.comparisons: int = 0

    def insert(self, value):
        if self.root is None:
            self.root = Node(value)
            return
        curr = self.root
        while True:
            self.comparisons += 1
            if value < curr.value:
                if curr.left is None:
                    curr.left = Node(value)
                    return
                curr = curr.left
            else:
                if curr.right is None:
                    curr.right = Node(value)
                    return
                curr = curr.right

    def inorder(self):
        self._inorder(self.root)

    def _inorder(self, node: 'Node | None'):
        if node is None:
            return
        self._inorder(node.left)
        print(node.value)
        self._inorder(node.right)

    def depth(self) -> int:
        return self._depth(self.root)

    def _depth(self, node: 'Node | None') -> int:
        if node is None:
            return 0
        return 1 + max(self._depth(node.left), self._depth(node.right))

    def leaf_count(self) -> int:
        return self._leaf_count(self.root)

    def _leaf_count(self, node: 'Node | None') -> int:
        if node is None:
            return 0
        if node.left is None and node.right is None:
            return 1
        return self._leaf_count(node.left) + self._leaf_count(node.right)

def main():
    unsorted_lists = [
        [3, 6, 1, 7],
        [5, 3, 7, 1, 4, 6, 8],
        [10, 5, 15, 2, 7, 12, 20, 1, 3],
        [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
        [10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
        [50, 25, 75, 10, 40, 60, 90, 5, 15],
        [100, 50, 150, 25, 75, 125, 175],
    ]
    col_w = [38, 8, 14, 10, 14]
    headers = ["Liste", "Uzunluk", "Karşılaştırma", "Derinlik", "Yaprak Sayısı"]
    sep = "+" + "+".join("-" * w for w in col_w) + "+"
    print(sep)
    print("|" + "|".join(h.center(w) for h, w in zip(headers, col_w)) + "|")
    print(sep)
    for lst in unsorted_lists:
        tree = Tree()
        for val in lst:
            tree.insert(val)
        row = [
            str(lst),
            str(len(lst)),
            str(tree.comparisons),
            str(tree.depth()),
            str(tree.leaf_count()),
        ]
        print("|" + "|".join(v.center(w) for v, w in zip(row, col_w)) + "|")
        print(sep)

if __name__ == "__main__":
    main()