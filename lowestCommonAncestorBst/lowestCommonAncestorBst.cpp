Node* lowestCommonAncestorBst( Node* root, int val1, int val2 ) {
    if( !root ) return NULL;

    while( root ) {
        if( root->data > val1 && root->data > val2 )      
	    root = root->left;
	else if( root->data < val1 && root->data < val2 ) 
	    root = root->right
	else
	    return root;
    }

    return NULL;
}
