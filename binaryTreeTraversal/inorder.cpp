void inorder( Node* root ) {
    if( !root ) return;

    inorder( root->left );
    visit( root );
    inorder( root->right );
}

void inorder( Node* root ) {
    if( !root ) return;
    
    stack<Node*> nodeStack;
    Node* currNode = root;

    while( !nodeStack.empty() || currNode ) {
        if( currNode ) {
	    nodeStack.push( currNode );
	    currNode = currNode->left;
	}
	else {
	    currNode = nodeStack.top();
	    visit( currNode );
	    nodeStack.pop();
            currNode = currNode->right;
	}
    } 
}
