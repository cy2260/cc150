class Node
{
public:
    Node()
    :   letter( ' ' )
    ,   isWord( false )
    {}
    ~Node() {}

    char getLetter() { return letter; }
    void setLetter( char c ) { letter = c; }

    bool isWord() { return isWord; }
    void setIsWord() { isWord = true; }
    
    Node* findChild( char c );
        
    void appendChild( Node* child ) { children.push_back( child ); }
    vector<Node*> getChildren() { return children; }


private:
    char letter;
    bool isWord;
    vector<Node*> children;

};
