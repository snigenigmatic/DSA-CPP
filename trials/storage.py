"""

This is a class that has three functions.
1. initialises an object
2. add an element(no duplicate elements allowed)
3. remove an element
4. getRandom() : get a random number from the object already inserted(with equal probability of picking for all elements)

"""

import random

class Store:
    def __init__(self):
        self.store = []
        self.index_map = {}
        
    def add(self, element):
        if element not in self.index_map:
            self.store.append(element) # add the element to the store
            self.index_map[element] = len(self.store) - 1 # store the index of the element in the hash map for quick access
        
    def remove(self, element):
        if element in self.index_map:
            index = self.index_map[element]
            last_element = self.store[-1] # get the last element in the store
            
            # Move the last element to the index of the element to be removed
            self.store[index] = last_element
            
            # Update the index of the last element only if it's different from the element being removed
            if last_element != element:
                self.index_map[last_element] = index
            
            self.store.pop() # remove the last element from the store
            del self.index_map[element] # remove the element from the index map
            
    def getRandom(self):
        if not self.store:
            return None
        return random.choice(self.store)  # return a random element from the store
    

def main():
    store = Store()
    store.add(1)
    store.add(2)
    store.add(3)
    print(store.getRandom())  # Should print a random element from 1, 2, or 3
    store.remove(1)
    print(store.getRandom())  # Should print a random element from 1 or 3
    
    
if __name__ == "__main__":
    main()