Node* findNthToLast( Node* head, int n ) {
    if( n < 1 || head == NULL ) return NULL;

    Node* p1 = head;
    Node* p2 = head;

    for( int i = 0; i < n - 1; ++i ) {
        p1 = p1->next;
	if( !p1 ) return NULL; //error!
    }

    while( p1->next ) {
        p1 = p1->next;
	p2 = p2->next;
    }

    return p2;
}
