//  job sequencing - huffman code

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  char character;
  int frequency;
  Node *left;
  Node *right;

  Node(char ch, int freq) {
    character = ch;
    frequency = freq;
    left = nullptr;
    right = nullptr;
  }
};

struct compare {
  bool operator()(Node *a, Node *b) { return a->frequency > b->frequency; }
};

void printCodes(Node *root, string code) {
  if (root == nullptr) {
    return;
  }

  if (root->left == nullptr && root->right == nullptr) {
    if (code == "") {
      code = "0";
    }

    cout << root->character << ": " << code << endl;
    return;
  }

  printCodes(root->left, code + "0");
  printCodes(root->right, code + "1");
}

int main() {
  int n;
  cout << "Enter No. of characters: ";
  cin >> n;
  cout << "\n";

  if (n <= 0) {
    cout << "Enter Positive Number!!" << endl;
    return 0;
  }

  priority_queue<Node *, vector<Node *>, compare> minHeap;

  cout << "Enter Each Character and its Frequency: " << endl;

  for (int i = 0; i < n; i++) {
    char character;
    int frequency;

    cin >> character >> frequency;
    minHeap.push(new Node(character, frequency));
  }

  while (minHeap.size() > 1) {
    Node *first = minHeap.top();
    minHeap.pop();

    Node *second = minHeap.top();
    minHeap.pop();

    Node *parent = new Node('\0', first->frequency + second->frequency);
    parent->left = first;
    parent->right = second;

    minHeap.push(parent);
  }

  Node *root = minHeap.top();
  cout << "\nHuffman Code: " << endl;

  printCodes(root, "");
  return 0;
}
