/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// here we use Map to store the new Node's connections. Original Node does not have any idea about the next Node of the Copied Node. PFB the map sample.
// A -- A'
// B -- B'
// C -- C'
// D -- D'
// if A -> next = B this means A' -> next must be B'
// Thus Map[A] -> next = Map[A->next]
// Same goes with random

class Solution {
public:
  Node* copyRandomList(Node* head) {
    Node* temp = NULL;
    if(!head) return temp;
    Node* prev = new Node(head->val);
    Node* prev2 = new Node(head->val);
    prev = head;
    prev2 = head;
    
    unordered_map<Node*,Node*> Map;
    
    while(prev){
      // Add { Node - Node' } in map
      Node* temp = new Node(prev->val);
      Map[prev] = temp;
      prev = prev->next;
    }
    
    while(prev2){
      // next of Node_a' (value of Map[Node_a]) is the corresponding Node_b' (value of Map[Node_b]). Same goes with random.
      Map[prev2]->next = Map[prev2 -> next];
      Map[prev2]->random = Map[prev2 -> random];
      prev2 = prev2->next;
    }    
    return Map[head]; // returns the start Node of our newly created Node
  }
};
