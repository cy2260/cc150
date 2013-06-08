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

Node* lowestCommonAncestorBst( Node* root, int val1, int val2 ) {
    if( !root ) return NULL;
    
    if( max(val1, val2) < root->data ) {
        return lowestCommonAncestorBst( root->left, val1, val2 );
    }
    else if( min(val1, val2) > root->data ) {
        return lowestCommonAncestorBst( root->right, val1, val2 );
    }
    else {
        return root;
    }
}

