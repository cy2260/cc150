void reverse( Node** head ) {
   if( *head == NULL ) return;

   Node* currNode = *head;
   Node* prevNode = NULL;

   while( currNode ) {
       Node* nextNode = currNode->next;
       currNode->next = prevNode;
       prevNode = currNode;
       currNode = nextNode;
   }

   *head = prevNode;
}

void reverse( Node** head ) {
    if( *head == NULL ) return;

    Node* first = *head;
    Node* rest  = *head->next;

    if( rest == NULL ) return;

    reverse( &rest );

    first->next->next = first;
    first->next = NULL;

    *head = rest;
}
