struct Node
{
    int data;
    Node* left;
    Node* right;

    Node() : data(0), left(NULL), right(NULL) {}
};

void bstToDList( Node* currNode, Node*& prevNode, Node*& headNode ) {
    if( !currNode ) return;

    bstToDList( currNode->left, prevNode, headNode );

    if( !prevNode ) {
         headNode = currNode;
    }
    else {
        prevNode->right = currNode;
	currNode->left  = prevNode;
    }

    prevNode = currNode;

    bstToDList( currNode->right, prevNode, headNode );
}
