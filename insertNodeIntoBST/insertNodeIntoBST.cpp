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
