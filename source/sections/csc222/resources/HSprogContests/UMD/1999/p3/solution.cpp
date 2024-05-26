//-----------------------------------------------------------------------
// sparse vectors
//-----------------------------------------------------------------------
 
#include <iostream>
#include <assert.h>
using namespace std;

class Node {
public:
    Node* next;
    double value;
    int index;
    Node(int i, double h, Node* t);
    Node& operator=(Node& L);
    Node& operator=(double d);
    ostream& printTo(ostream& os) const;
};

Node::Node(int i, double h, Node* t) {
    index = i;
    value = h;
    next = t;
};

Node& Node::operator=(Node& L) {
    value = L.value;
    return *this;
};

Node& Node::operator=(double d) {
    value = d;
    return *this;
};

ostream& Node::printTo(ostream& os) const {
    return os << "[" << index << ", " << value << "]";
}

ostream& operator<< (ostream &os, const Node& v) {
    return v.printTo(os);
}

class SpVector {
private:
   int numNodes;
   Node* firstNode;
   Node* lastNode;
   SpVector(Node* f, Node * l, int n);
   static void addNode(Node** first, Node** last, int* eltcount,
                       int index, double value);
public:
   SpVector ();
   ~SpVector ();
   Node& operator[](int n);
   SpVector operator+(const SpVector& v) const;
   ostream& printTo(ostream& os) const;
};

ostream& operator<< (ostream &os, const SpVector& v) {
    return v.printTo(os);
}

SpVector::SpVector(Node* f, Node * l, int n) {
    numNodes = n;
    firstNode = f;
    lastNode = l;
};

SpVector::SpVector () {
    numNodes = 0;
    firstNode = lastNode = NULL;
}

SpVector::~SpVector () {
    Node *prevEltPtr, *eltPtr;
    eltPtr = firstNode;
    numNodes = 0;
    firstNode=lastNode= NULL;
    while (eltPtr != NULL) {
        prevEltPtr = eltPtr;
        eltPtr = eltPtr->next;
        delete prevEltPtr;
    };
};

Node& SpVector::operator[] (int index) {
    Node* eltPtr;
    Node* newPtr;
    Node* prevPtr;
    eltPtr = firstNode;
    while (eltPtr != NULL && eltPtr->index < index) {
        prevPtr = eltPtr;
        eltPtr = eltPtr->next;
    }
    if (eltPtr == NULL) {
        newPtr = new Node(index,0.0,NULL);
        numNodes++;
        if (firstNode == NULL)
            firstNode = lastNode = newPtr;
        else lastNode = lastNode->next = newPtr;
        return *newPtr;
    }
    else if (eltPtr->index == index) return *eltPtr;
    else {
        newPtr = new Node(index,0.0,eltPtr);
        numNodes++;
        if(eltPtr==firstNode) firstNode=newPtr;
        else prevPtr->next = newPtr;
        return *newPtr;
    }
};

void SpVector::addNode(Node** first, Node** last,
                        int* eltcount, int index, double value) {
    Node* e;
    Node* newPtr = newPtr = new Node(index, value, NULL);
    if (value != 0.0 ) {
        (*eltcount)++;
        if (*first == NULL){
            *first = newPtr;
            *last = newPtr;
        }
        else {
            e=*last;
            e->next = newPtr;
            *last = newPtr;
        }
    }
}

SpVector SpVector::operator+ (const SpVector& v) const{
    Node* first = NULL;
    Node* last = NULL;
    Node* rightPtr = firstNode;
    Node* leftPtr = v.firstNode;
    double sum;
    int n = 0;
    while(rightPtr != NULL && leftPtr != NULL) { 
	if (rightPtr->index == leftPtr->index) {
	    sum = rightPtr->value + leftPtr->value;
            if (sum != 0.0)
                addNode(&first,&last,&n,rightPtr->index,sum);
            rightPtr = rightPtr->next;
            leftPtr = leftPtr->next;
        }
	else if (rightPtr->index < leftPtr->index) {
	    addNode(&first,&last,&n,rightPtr->index,rightPtr->value);
	    rightPtr = rightPtr->next;
        }
	else {
	    addNode(&first,&last,&n,leftPtr->index,leftPtr->value);
	    leftPtr = leftPtr->next;
	}
    }
    while (rightPtr != NULL) {
	addNode(&first, &last,&n,rightPtr->index,rightPtr->value);
	rightPtr = rightPtr->next;
    }
    while (leftPtr != NULL) {
	addNode(&first,&last,&n,leftPtr->index,leftPtr->value);
	leftPtr = leftPtr->next;
    }
    return SpVector(first,last,n);
}

ostream& SpVector::printTo(ostream& os) const {
    if (numNodes == 0)
        return (os << "empty vector");
    else {
        Node* eltPtr = firstNode;
        while (eltPtr != NULL) {
            os << *eltPtr;
            eltPtr = eltPtr->next;
            if (eltPtr != NULL) os << ", ";
        };
        return os;
    }
}

int readvector(SpVector& a) {
    int index;
    int length;
    double d;
    char ch;

    length = 0;

    while (true) {
        cin.get(ch);           // check whether eoln
        if (ch == '\n')
            return length;
        cin.putback(ch);

        cin >> index; 
        if (length == 0 && index == -1) {
            cin.get(ch);           // check whether eoln
            if (ch == '\n')    
                return -1;    
            cin.putback(ch);
        }
        cin >> d;

        a[index] = d;
        length++;
    }
}

int main () {
    int len;
    SpVector a;
    SpVector b;

    while (true) {
        len = readvector(a);
        if (len == -1)
            return 0;
        assert (len > 0);

        len = readvector(b);
        assert (len > 0);

        cout << (a+b) << endl;

        a.~SpVector();
        b.~SpVector();
    }

    return 0;
}
