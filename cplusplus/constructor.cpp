class Foo
{
public:
    Foo();
    Foo( int n );
    ~Foo();
    Foo( const Foo& f );
    Foo& operator=(const Foo& f );

private:
    int* dataPtr;
};

Foo::Foo() {
    dataPtr = new int;
}

Foo::Foo( int n ) {
    dataPtr = new int;
    *dataPtr = n;
}

Foo::~Foo() {
    delete dataPtr;
}

//prevent from shallow copy
Foo::Foo( const Foo& f ) {
    dataPtr = new int;
    *dataPtr = *(f.dataPtr);
}

//prevent from shallow copy
Foo& Foo::operator=( const Foo& f ) {
    //self assignment, do nothing
    if( this == &f ) {
        return *this;
    }
    
    //release old resource
    delete dataPtr;
    //acquire new resource
    dataPtr = new int;
    *dataPtr = *(f.dataPtr);

    return *this;
}
