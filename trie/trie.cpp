#include "Trie.h"

Trie::Trie() {
    root = new Node(); //empty root node
}

Trie::~Trie() {
    //free memory
}

Trie::freeChild( Node* childNode ) {
    if( childNode->getSize() == 0 ) {
        delete childNode;
	return;
    }

    for( int i = 0; i < childNode->getSize(); ++i ) {
        freeChild( childNode->getChildren().at(i) );
    }

    delete childNode;
}

void Trie::addWord( const string& s ) {
    if( s.size() == 0 ) return;

    Node* currNode = root;

    for( int i = 0; i < s.size(); ++i ) {
        Node* childNode = currNode->findChild( s.at(i) );
	if( childNode != NULL ) {
	    currNode = childNode;
	}
	else {
	    Node* newNode = new Node( s.at(i) );
	    currNode.appendChild( newNode );
	    currNode = newNode;
	}
	if( i == s.size() - 1 ) { //last letter
	    currNode->setIsWord();
	}
    }
}

bool Trie::searchWord( const string& s ) {
    Node* currNode = root;

    while( currNode != NULL ) {
        for( int i = 0; i < s.size(); ++i ) {
	    Node* childNode = currNode->find( s.at(i) );
	    if( childNode == NULL ) return false;
	    else                    currNode = childNode;
	}
        
	if( currNode->isWord() ) return true;
	else                     return false;
    }

    return false;
}
