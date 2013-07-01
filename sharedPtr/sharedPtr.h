template<class T>
class SharedPtr
{
private:
    RefCount<T>* refCnt;
    static void* operator new( size_T ) {};
    static void delete( void* ) {};

public:
    SharedPtr( T* p ) {
        refCnt = new RefCount<T>(p);
        refCnt->increase();
    }

    ~SharedPtr() {
        if( refCnt->decrease() == 0 ) {
            delete refCnt;
        }
    }

    void operator=( const SharedPtr<T>& p ) {
        if( this == &p ) return;

        if( refCnt->decrease() == 0 ) {
            delete refCnt;
        }
        refCnt = p.refCnt;
        refCnt->increase();
    }

    T* operator->() { return refCnt->raw(); }
};
