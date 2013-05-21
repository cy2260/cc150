class Node
{
public:
    string query;
    string result;
    Node* next;
    Node* prev;
};


class LRUCache
{
public:
    static int MAX_SIZE = 10;

public:
    LRUCache() 
    : size(0)
    , head(NULL)
    , tail(NULL)  
    {}

    ~LRUCache() { deleteQueryResultMap(); }

public:
    Node* processQuery( const string& query );

private:
    void moveNodeToFront( Node* node );
    void insertNodeToFront( Node* node );
    void removeNodeFromTail();
    Node* getResultFromCache( const string& query );
    Node* getResultFromDB( const string& query );
    void insertResult( node );
    void deleteQueryResultMap();
private:
    int size;
    Node* head;
    Node* tail;
    unordered_map<string, Node*> queryResultMap;
};
