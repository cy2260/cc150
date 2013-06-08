void levelorder( Node* root ) {
    if( !root ) return;

    queue<Node*> nodesQueue;

    int numOfNodesInCurrLevel = 1;
    int numOfNodesInNextLevel = 0;

    nodesQueue.push( root );

    while( !nodesQueue.empty() ) {
        Node* currNode = nodesQueue.front();
	visit( currNode );
	nodesQueue.pop();
	--numOfNodesInCurrLevel;

        cout << "Node " << currNode ", ";

        if( currNode->left ) {
	    nodesQueue.push( currNode->left );
	    ++numOfNodesInNextLevel;
	}
        if( currNode->right ) {
	    nodesQueue.push( currNode->right );
	    ++numOfNodesInNextLevel;
	}

	if( numOfNodesInCurrLevel == 0 ) {
	    cout << "---------------" << endl;
	    numOfNodesInCurrLevel = numOfNodesInNextLevel;
	    numOfNodesInNextLevel = 0;
	}
    }
}
	
