class Node
{
public:
    Node()
    :   letter( ' ' )
    ,   isWord( false )
    {}
    Node( char c )
    :   letter( c )
    ,   isWord( false )
    {}
    ~Node() {}

    char getLetter() { return letter; }
    void setLetter( char c ) { letter = c; }

    bool isWord() { return isWord; }
    void setIsWord() { isWord = true; }
    
    Node* findChild( char c ) {
        for( int i = 0; i < children.size(); ++i ) {
	    Node* tmp = children.at(i);
	    if( tmp->getLetter() == c ) {
	        return tmp;
	    }
	}
	return NULL;
    }
        
    void appendChild( Node* child ) { children.push_back( child ); }
    vector<Node*> getChildren() { return children; }
    int getSize() { return children.size(); }


private:
    char letter;
    bool isWord;
    vector<Node*> children;

};
