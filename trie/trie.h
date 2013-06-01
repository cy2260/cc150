#include "Node.h"

class Trie
{
public:
    Trie();
    ~Trie();

    void addWord( const string& s );
    bool searchWord( const string& s );
    void deleteWord( const string& s );


private:
    Node* root;

};
