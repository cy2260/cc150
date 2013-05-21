Node* LRUCache::processQuery( const string& query ) {
    Node* node = getResultFromCache( query );
    if( node ) {
        return node;
    }
    else {
        node = getResultFromDB( query );
	return node;
    }
}

Node* LRUCache::getResultFromCache( const string& query ) {
    unordered_map<string, Node*>::iterator it = queryResultMap.find(query);
    if( it != queryResultMap.end() ) {
        Node* node = it->second;
	moveNodeToFront( node );
	return node;
    }
    else {
        return NULL;
    }
}

Node* LRUCache::getResultFromDB( const string& query ) {
    string result = getDBResult( query );
    Node* node = new Node(query, result);
    insertResult( node );
    return node;
}

void LRUCache::insertResult( Node* node ) {
    unordered_map<string, Node*>::iterator it = queryResultMap.find(query);
    if( it != queryResult.end() ) {
        moveNodeToFront( it->second);
    }
    else {
        queryResultMap[node->query] = node;
        insertNodeToFront( node );
        ++size;
    
        if( size > MAX_SIZE ) {
            map.erase( tail->query );
	    removeNodeFromTail();
        }
    }
}

void LRUCache::insertNodeToFront( Node* node ) {
    if( head == NULL ) {
        head = node;
	tail = node;
    }
    else {
        Node* next = head;
	head = node;
	node->next = next;
	next->prev = node;
    }
}

void LRUCache::moveNodeToFront( Node* node ) {
   if( head == node ) return;
   
   if( node->next == NULL ) { //last node
       node->prev->next = NULL;
       tail = node->prev;
   }
   else {
       node->prev->next = node->next;
       node->next->prev = node->prev;
   }
   
   Node* next = head;
   head = node;
   node->next = next;
   next->prev = node;
}
