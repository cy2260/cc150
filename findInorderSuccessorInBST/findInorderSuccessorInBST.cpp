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
}


Node* findInoderSuccessorInBST( Node* root, Node* node ) {
    if( !root || !node ) return NULL;

    if( node->right != NULL ) {
        Node* temp = node->right;
	while( temp->left != NULL ) {
	    temp = temp->left;
	}
	return temp;
    }
        
    Node* currNode  = root;
    Node* successor = NULL;
    while( currNode != NULL ) {
        if( node->data > currNode->data ) {
	    currNode = currNode->right;
	}
	else if( node->data < currNode->data ) {
	    successor = currNode;
	    currNode  = currNode->next;
	}
	else {
	    break;
	}
    }

    return successor;
}




}
