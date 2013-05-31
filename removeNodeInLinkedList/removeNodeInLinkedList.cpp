void remove( Node* node ) {
    if( !node ) return;

    if( node->next ) {
        Node* nextNode = node->next;
        node->data = nextNode->data;
	node->next = nextNode->next;
	delete nextNode;
    }
    else {
        delete node;
	//do we need to set prev node's next to NULL?
    }
}
