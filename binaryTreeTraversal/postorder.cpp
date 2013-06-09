void postorder( Node* root ) {
    if( !root ) return;

    postorder( root->left );
    postorder( root->right );
    visit( root );
}

void postorder( Node* root ) {
    if( !root ) return;

    stack<Node*> nodesStack;
    stack<Node*> resultStack;

    nodesStack.push( root );
    
    while( !nodesStack.empty() ) {
        Node* currNode = nodesStack.top();
	resultStack.push( currNode );
	nodesStack.pop();
	//reversed preorder traversal, visit right subtree first
	if( currNode->left  ) nodesStack.push( currNode->left  );
	if( currNode->right ) nodesStack.push( currNode->right );
    }

    while( !resultStack.empty() ) {
        visit( resultStack.top() );
	resultStack.pop();
    }
}
