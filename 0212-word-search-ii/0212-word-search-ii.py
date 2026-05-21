class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    def insert(self, word):
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_end = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.trie = Trie()
        for word in words:
            self.trie.insert(word)
        
        self.rows = len(board)
        self.cols = len(board[0])
        self.result = []

        def dfs(i, j, node, path):
            # 1. Boundary
            if not (0 <= i < self.rows and 0 <= j < self.cols):
                return
            char = board[i][j]
            if char == '#' or char not in node.children:
                return
            
            # 2. Process Current node
            node = node.children[char]
            path += char
            
            if node.is_end:
                self.result.append(path)
                node.is_end=False
            
            # 3. Mark
            board[i][j] = '#'

            # 4. Explore Neighbor
            for di, dj in [(0,1), (0,-1), (1, 0), (-1,0)]:
                r = i + di
                c = j + dj
                dfs(r, c, node, path)

            # 5. backtrack
            board[i][j] = char

        for r in range(self.rows):
            for c in range(self.cols):
                dfs(r, c, self.trie.root, "")
        return self.result