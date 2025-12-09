# Last updated: 12/8/2025, 11:28:15 PM
from collections import defaultdict
class TNode:
    def __init__(self):
        self.map = defaultdict(TNode)
        self.files = defaultdict(str)

class FileSystem:

    def __init__(self):
        self.trie = TNode()

    def ls(self, path: str) -> List[str]:
        currNode = self.trie
        paths = [p for p in path.split("/") if p]
        for i, d in enumerate(paths):
            if i == len(paths) - 1 and d not in currNode.map:
                return [d]
            currNode = currNode.map[d]

        arr = list(currNode.map.keys())
        arr.extend(list(currNode.files.keys()))
        arr.sort()
        return arr

    def mkdir(self, path: str) -> None:
        currNode = self.trie
        paths = [p for p in path.split("/") if p]
        for d in paths:
            if d not in currNode.map:
                currNode.map[d] = TNode()
            
            currNode = currNode.map[d]
        
    def addContentToFile(self, filePath: str, content: str) -> None:
        currNode = self.trie
        paths = [p for p in filePath.split("/") if p]

        for i in range(0, len(paths) - 1):
            currNode = currNode.map[paths[i]]

        currNode.files[paths[len(paths) - 1]] += content

    def readContentFromFile(self, filePath: str) -> str:
        currNode = self.trie
        paths = [p for p in filePath.split("/") if p]

        for i in range(0, len(paths) - 1):
            currNode = currNode.map[paths[i]]

        return currNode.files[paths[len(paths) - 1]]