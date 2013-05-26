Node* findInoderSuccessorInBST( Node* node ) {
    if( !node ) return NULL;

    //if node has right subtree, 
    //then get the left most node of the right subtree
    if( node->right != NULL ) {
        Node* tempNode = node->right;
	while( tempNode->left != NULL ) {
	    tempNode = tempNode->left;
	}
	return tempNode;
    }

    //if node does not have right subtree,
    //then successor is its ancestor
    //find the ancestor that makes the node in its left subtree
    Node* tempNode = node;
    while( tempNode->parent != NULL ) {
        if( tempNode->parent->left == tempNode ) {
	    return tempNode->parent;
	}
	tempNode = tempNode->parent;
    }

    return NULL;

