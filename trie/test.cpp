#include "Trie.h"

int main() {

    Trie* trie = new Trie();

    trie->addWord( "greatest" );
    trie->addWord( "great" );
    trie->addWord( "cool" );

    if( trie->searchWord( "great" ) )    cout << "find!" << endl;
    if( trie->searchWord( "greatest" ) ) cout << "find!" << endl;
    if( trie->searchWord( "coll" ) )     cout << "find!" << endl;

    delete trie;

    return 0;
}
