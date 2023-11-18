//============================================================================
// Name        : LP3_Assignment-02.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

void printCodes(MinHeapNode *root, string str) {
    if (root == nullptr) {
        return;
    }
    if (root->data != '$') {
        cout << root->data << ": " << str << endl;
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

struct compare {
    bool operator()(MinHeapNode *a, MinHeapNode *b) {
        return (a->freq > b->freq);
    }
};

bool isNumber(const string &s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void HuffmanCode() {
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
    string input;
    char character;
    int frequency;

    do {
        cout << "Enter a character: ";
        cin >> input;

        if (input.length() == 1 && isalpha(input[0])) {
            character = input[0];
            break;
        } else {
            cout << "Please enter a valid character." << endl;
        }
    } while (true);

    do {
        cout << "Enter the frequency for character " << character << ": ";
        cin >> input;

        if (isNumber(input)) {
            frequency = stoi(input);
            break;
        } else {
            cout << "Please enter a number as frequency." << endl;
        }
    } while (true);

    minHeap.push(new MinHeapNode(character, frequency));

    while (true) {
    char choice;
    cout << "Do you want to add another character? (Y/N): ";
    cin >> choice;

    if (toupper(choice) == 'N') {
        break;
    } else if (toupper(choice) == 'Y') {
        do {
            cout << "Enter a character: ";
            cin >> input;

            if (input.length() == 1 && isalpha(input[0])) {
                character = input[0];
                break;
            } else {
                cout << "Please enter a valid character." << endl;
            }
        } while (true);

        do {
            cout << "Enter the frequency for character " << character << ": ";
            cin >> input;

            if (isNumber(input)) {
                frequency = stoi(input);
                break;
            } else {
                cout << "Please enter a number as frequency." << endl;
            }
        } while (true);

        minHeap.push(new MinHeapNode(character, frequency));
    } else {
        cout << "Invalid input. Please enter either 'Y' or 'N'." << endl;
    }
}


    while (minHeap.size() != 1) {
        MinHeapNode *left = minHeap.top();
        minHeap.pop();
        MinHeapNode *right = minHeap.top();
        minHeap.pop();
        MinHeapNode *temp = new MinHeapNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        minHeap.push(temp);
    }
    cout << "Huffman Codes:" << endl;
    printCodes(minHeap.top(), "");
}

int main() {
    HuffmanCode();
    return 0;
}


// Time Complexity : O(n log(n))
//extraction of the two nodes with the lowest frequencies from the priority queue typically takes O(log n) time
//process of extracting two minimum elements and inserting a new element back into the priority queue or heap happens 'n-1' times, where 'n' is the number of symbols or nodes


//5
//a b c d e
//3
//5
//6
//4
//2
//d 00
//b 01
//e 100
//a 101
//c 11
