Node* LCA( Node* root, int val1, int val2 ) {
    if( !root ) return NULL;

    if( root->val == val1 || root->val == val2 ) return root;

    root* leftN  = LCA( root->left, val1, val2 );
    root* rightN = LCA( root->right, val1, val2 );
    
    if( leftN && rightN ) return root; //this is the LCA
    else                  return leftN ? leftN : rightN;
}

