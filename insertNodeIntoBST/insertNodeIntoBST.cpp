Node* insertNodeIntoBST( Node* root, int data ) {
    if( !root ) return new Node(data);

    if( data > root->data ) {
        root->right = insertNodeIntoBST( root->right, data );
    }
    else {
        root->left = insertNodeIntoBST( root->left, data );
    }

    return root;
}

Node* insertNodeIntoBST( Node* root, int data ) }
    if( !root ) return new Node(data);

    Node* currNode = root;

    while( currNode ) {
        if( data > currNode->data ) {
	    if( currNode->right ) {
	        currNode = currNode->right;
	    }
	    else {
	        currNode->right = new Node(data);
		break;
	    }
	else {
	    if( currNode->left ) {
	        currNode = currNdoe->left;
	    }
	    else {
	        currNode->left = new Node(data);
	        break;
	    }
	}
    }
    
    return root;
}
