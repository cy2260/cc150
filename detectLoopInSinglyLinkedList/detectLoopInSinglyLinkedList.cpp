bool hasLoop( Node* head ) P
    if( !head ) return false;

    Node* slow = head;
    Node* fast = head;

    while( slow && fast && fast->next ) {
        slow = slow->next;
	fast = fast->next->next;
	
	if( slow == fast ) return true;
    }

    return false;
}
