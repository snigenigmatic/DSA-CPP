#include<bits/stdc++.h>
using namespace std;

class Store{
    unordered_map<int, int> elementIndexMap;
    vector<int> elements;
    public:
        int add(int element){
            if(elementIndexMap.find(element) != elementIndexMap.end()){
                return 0; // element already exists
            }
            elements.push_back(element);
            elementIndexMap[element] = elements.size() - 1;
            return 1; // element added successfully
        }

        int remove(int element){
            if(elementIndexMap.find(element) == elementIndexMap.end()){
                return 0; // element does not exist
            }
            int index = elementIndexMap[element];
            int lastElement = elements.back(); // get the last element
            // Move the last element to the position of the element to be removed
            elements[index] = lastElement; // replace the element to be removed with the last element
            // Update the index of the last element in the map
            elementIndexMap[lastElement] = index; // update the index of the last element
            // Remove the last element from the vector and map
            elements.pop_back(); // remove the last element
            elementIndexMap.erase(element); // remove the element from the map
            // No need to update the index of the last element in the map since it was already
            // moved to the position of the removed element
            return 1; // element removed successfully
        }

        int getRandom(){
            if(elements.empty()){
                return -1; // no elements to return
            }
            int randomIndex = rand() % elements.size(); // generate a random index
            return elements[randomIndex]; // return the element at the random index
        }

        //function to display the elements (for testing purposes)
        void display(){
            for(int element : elements){
                cout << element << " ";
            }
            cout << endl;
        }

        void clear(){
            elements.clear(); // clear the vector
            elementIndexMap.clear(); // clear the map
        }
};

int main() {
    Store store;
    store.add(1);
    store.add(2);
    store.add(3);
    store.add(2); // should not add duplicate
    store.add(4);
    store.display(); // should print 1 2 3
    cout << "Random Element: " << store.getRandom() << endl; // should print a random element from 1, 2, or 3
    store.remove(4);
    store.display(); // should print 1 2 3
    cout << "Random Element after removing 4: " << store.getRandom() << endl; // should print a random element from 2 or 3
    return 0;
}