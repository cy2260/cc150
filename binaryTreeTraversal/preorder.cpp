void preorder( Node* node ) {
    if( !node ) return;
    visit( node );
    preorder( node->left );
    preorder( node->right );
}


void preorder( Node* root ) {
    if( !root ) return;
    
    stack<Node*> nodeStack;
    nodeStack.push( root );

    while( nodeStack.size() > 0 ) {
        Node* currNode = nodeStack.top();
	visit( currNode );
	nodeStack.pop();
	if( currNode->right ) nodeStack.push( currNode->right );
	if( currNode->left  ) nodeStack.push( currNode->left  );
    }
}

void visit( Node* node ) {
    //todo
}
