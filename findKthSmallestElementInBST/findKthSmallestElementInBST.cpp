int getNumOfNodes( Node* root ) {
     if( !root ) return 0;

     int leftCount  = getNumOfNodes( root->left  );
     int rightCount = getNumOfNodes( root->right );
     
     root->leftCount = leftCount;

     return leftCount + rightCount + 1;
}

Node* findKthSmallestElement( Node* root, int kth ) {
    if( !root ) return NULL;

    Node* currNode = root;
    while( currNode ) {
        if( currNode->leftCount + 1 > kth ) {
	    currNode = currNode->left;
	}
	else if( currNode->leftCount + 1 < kth ) {
	    currNode = currNode->right;
	    kth = kth - 1 - currNode->leftCount;
	}
	else {
	    return currNode;
    }
    return NULL;
}

Node* findKthSmallestElement( Node* root, int kth ) {
    if( !root ) return NULL;
    if( currNode->leftCount + 1 > kth ) {
        return findKthSmallestElement( root->left, kth );
    }
    else if( currNode->leftCount + 1 < kth ) {
        return findKthSmallestElement( root->right, kth - root->leftCount - 1 );
    }
    else {
        return root;
    }
}
