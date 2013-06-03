void split( Node* head, Node** front, Node** back ) {
    if( !head ) return;

    Node* slow = head;
    Node* fast = head;
    Node* frontLastNode = head;

    while( fast ) {
        frontLastNode = slow;
	slow = slow->next;
	fast = fast->next ? fast->next->next : NULL;
    }

    frontLastNode->next = NULL;
    *front = head;
    *back  = slow;
}
