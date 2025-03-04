#include <bits/stdc++.h>
using namespace std;

struct Node {
	char data;
	int freq;
	Node* left;
	Node* right; 
	Node( char data,int freq){
		this -> data = data;
		this -> freq = freq;
		left = right = nullptr;
	}
};

void printTree(Node* root, string str , unordered_map<char, string>& huffmanCode){
	if(!root){
		return;
	}
	
	if(root -> data != '$'){
		huffmanCode[root->data] = str;
	}
	
	printTree(root -> left, str + "0",huffmanCode);
	printTree(root -> right, str + "1",huffmanCode);
}

void decodeHuffman(Node* root, string binaryString) {
    Node* currentNode = root;
    for (int i = 0; i < binaryString.size(); i++) {
        char bit = binaryString[i];

        if (bit == '0') {
            currentNode = currentNode->left; 
        } else {
            currentNode = currentNode->right; 
        }

        
        if (!currentNode->left && !currentNode->right) {
            cout << currentNode->data; 
            currentNode = root; 
        }
    }
}



int main(){
	string text /*= "HUFFMANcode"*/;
	cin >> text;
	//          key    val
	unordered_map<char, int> F;
	
	for(int i = 0;i < text.size() ; i++){  // <-- count freq
		F[text[i]]++;
	}
	
//	unordered_map<char,int>::iterator it ;
//	for(it = F.begin(); it != F.end(); ++it){
//		cout << it -> first << " : " << it -> second << "\n"; // <-- print freq
//	}
	
	
	priority_queue<Node*, vector<Node*>, function<bool(Node*, Node*)>> minHeap([](Node* a, Node* b) {
	   
	    if (a->freq == b->freq)        //
	        return a->data > b->data;  // <-- for fix binary code
	    return a->freq > b->freq;      //
	});
	
	for (auto it = F.begin(); it != F.end(); ++it) {
        minHeap.push(new Node(it->first, it->second));// <-- keep data in minHeap
    }
		
	
	
	while (minHeap.size() > 1){
		Node* left = minHeap.top();
		minHeap.pop();
		Node* right = minHeap.top();
		minHeap.pop();
		
		Node* node = new Node('$', left->freq + right->freq); // <-- creat tree
		node -> left = left;
		node -> right = right;
		
		minHeap.push(node);
	}
	
	Node* root = minHeap.top();
	
	unordered_map<char, string> huffmanCode;
	printTree(root,"",huffmanCode);
	
	for (auto pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << "\n";
    }
    
    string encodedString = "";
    for (int i =0; i< text.size(); i++) {
        encodedString += huffmanCode[text[i]];
        //encodedString += " ";
    }
    cout << encodedString <<"\n";
	
	string encode = "110010111001111";
	decodeHuffman(root, encode);
}
