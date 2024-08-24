#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    Node* cloneGraph(Node* node) {
        list<pair<Node*,Node*>> processed;

        Node* head = new Node(*node);
        processed.push_back(make_pair(head,node));

        queue<Node*> q;
        q.push(head);

        while(q.size()>0)
        {
            Node* current = q.front();
            q.pop();
            auto has_been_processed = [current](const pair<Node*,Node*> p){
                                        if(p.second == current || p.first == current) return true;
                                        return false;
                                    };
            if(find_if(processed.begin(),processed.end(),has_been_processed) == processed.end())
            {
                Node* old = current;
                current = new Node(*current);
                processed.push_back(make_pair(current,old));
            }

            for(int i=0;i<current->neighbors.size();i++)
            {
                Node* neighbour = current->neighbors.at(i);
                auto has_been_processed = [neighbour](const pair<Node*,Node*> p){
                                            if(p.first == neighbour || p.second == neighbour) return true;
                                            return false;
                                        };
                auto itr = find_if(processed.begin(),
                                processed.end(),
                                has_been_processed);
                if(itr == processed.end())
                {
                    Node* old = current->neighbors.at(i);
                    current->neighbors.at(i) = new Node(*current->neighbors.at(i));
                    processed.push_back(make_pair(current->neighbors.at(i),old));
                    q.push(current->neighbors.at(i));
                }
                else
                {
                    current->neighbors.at(i) = itr->first;
                }

            }
        }

        return head;

    }
};

int main()
{
    cout<<"Hello World";
    Node* a = new Node(0);
    Node* b = new Node(1);
    Node* c = new Node(2);
    
    a->neighbors.push_back(b);
    b->neighbors.push_back(c);
    c->neighbors.push_back(a);
    Solution s = Solution();
    s.cloneGraph(a);

    return 0;
}