# Last updated: 12/8/2025, 11:28:42 PM
class CacheBlock():
    def __init__(self, key, value, freq_node, prev, nextv):
        self.key = key
        self.value = value
        self.freq_node = freq_node
        self.previous = prev
        self.next = nextv
    
    def free(self):
        if self.freq_node.cache_head == self.freq_node.cache_tail:
            self.freq_node.cache_head = self.freq_node.cache_tail = None
        elif self.freq_node.cache_head == self:
            self.next.previous = None
            self.freq_node.cache_head = self.next
        elif self.freq_node.cache_tail == self:
            self.previous.next = None
            self.freq_node.cache_tail = self.previous
        else:
            self.previous.next = self.next
            self.next.previous = self.previous

        self.previous = None
        self.next = None
        self.freq_node = None

class FrequencyNode():
    def __init__(self, frequency, previous, nextv):
        self.freq = frequency
        self.previous = previous
        self.next = nextv
        self.cache_head = None
        self.cache_tail = None
    
    def count_blocks(self):
        if self.cache_head is None and self.cache_tail is None:
            return 0
        elif self.cache_head == self.cache_tail:
            return 1
        else:
            return 2
    
    def free(self):
        if self.previous is not None:
            self.previous.next = self.next
        if self.next is not None:
            self.next.previous = self.previous
        prev = self.previous
        nextv = self.next
        self.previous = self.next = self.cache_head = self.cache_tail = None
        return (prev, nextv)
    
    def pop_head(self):
        if self.cache_head is None and self.cache_tail is None:
            return None
        elif self.cache_head == self.cache_tail:
            cache_head = self.cache_head
            self.cache_head = self.cache_tail = None
            return cache_head
        else:
            cache_head = self.cache_head
            self.cache_head.next.previous = None
            self.cache_head = self.cache_head.next
            return cache_head
    
    def append_cache_to_tail(self, cache_node):
        cache_node.freq_node = self
        if self.cache_head is None and self.cache_tail is None:
            self.cache_head = self.cache_tail = cache_node
        else:
            cache_node.previous = self.cache_tail
            cache_node.next = None
            self.cache_tail.next = cache_node
            self.cache_tail = cache_node

    def insert_after_me(self, freq_node):
        freq_node.previous = self
        freq_node.next = self.next
        if self.next is not None:
            self.next.previous = freq_node
        self.next = freq_node

    def insert_before_me(self, freq_node):
        if self.previous is not None:
            self.previous.next = freq_node
        freq_node.previous = self.previous
        freq_node.next = self
        self.previous = freq_node

class LFUCache:
    def __init__(self, capacity: int):
        self.cache = {}
        self.capacity = capacity
        self.freq_link_head = None
        
    def get(self, key: int) -> int:
        if key in self.cache:
            cache_node = self.cache[key]
            freq_node = cache_node.freq_node
            value = cache_node.value
            self.move_forward(cache_node, freq_node)
            return value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if self.capacity <= 0:
            return -1
        if key not in self.cache:
            if len(self.cache) >= self.capacity:
                self.dump_cache()
            self.create_cache(key, value)
        else:
            cache_node = self.cache[key]
            freq_node = cache_node.freq_node
            cache_node.value = value
            self.move_forward(cache_node, freq_node)
    
    def move_forward(self, cache_node, freq_node):
        if freq_node.next is None or freq_node.next.freq != freq_node.freq + 1:
            target_freq_node = FrequencyNode(freq_node.freq + 1, None, None)
            target_empty = True
        else:
            target_freq_node = freq_node.next
            target_empty = False
        cache_node.free()
        target_freq_node.append_cache_to_tail(cache_node)
        if target_empty:
            freq_node.insert_after_me(target_freq_node)
        if freq_node.count_blocks() == 0:
            if self.freq_link_head == freq_node:
                self.freq_link_head = target_freq_node
            freq_node.free()

    def dump_cache(self):
        head_freq_node = self.freq_link_head
        self.cache.pop(head_freq_node.cache_head.key)
        head_freq_node.pop_head()
        if head_freq_node.count_blocks() == 0:
            self.freq_link_head = head_freq_node.next
            head_freq_node.free()

    def create_cache(self, key, value):
        cache_node = CacheBlock(key, value, None, None, None)
        self.cache[key] = cache_node
        if self.freq_link_head is None or self.freq_link_head.freq != 0:
            new_freq_node = FrequencyNode(0, None, None)
            new_freq_node.append_cache_to_tail(cache_node)
            if self.freq_link_head is not None:
                self.freq_link_head.insert_before_me(new_freq_node)
            self.freq_link_head = new_freq_node
        else:
            self.freq_link_head.append_cache_to_tail(cache_node)

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)