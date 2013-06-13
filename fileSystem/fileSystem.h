class Entry
{
public:
    Entry( const string& n, Directory* p )
    : name( n )
    , parent( p )
    {}
    virtual ~Entry();
    
    string getFullPath() {
        return parent->getFullPath() + "/" + name;
    }

    virtual int size() = 0; //file size differs from dir size
   
    bool delete() {
        if( parent == NULL ) return false; //cannot delete root
	return parent->deleteEntry( this );
    }

    void rename( const string& newName );
    string getName();
    
    int getCreationTime();
    int getLastUpdatedTime();
    int getLastAccessedTiem();

protected:
    string name;
    Directory* parent;
    int creationTime;
    int lastUpdatedTime;
    int lastAccessedTime;
};

class File : public Entry
{
public:
    File( const string& n, Directory* p, int sz )
    : Entry( n, p )
    , size = sz
    {}
    ~File();

    int size() { return size; }
    string getContent();
    void setContent( const string& content );
protected:
    string content;
    int size;
};

class Directory : public Entry
{
public:
    Directory( const string& n, Directory* p )
    : Entry( n, p )
    {}

    int size() {
        int size = 0;
	for( int i = 0; i < entries.size(); ++i ) {
	    size += entries[i]->size();
	}
	return size;
    }

    void listAll();
    void listEntry( const string& name );

protected:
    vector<Entry*> entries;

};
