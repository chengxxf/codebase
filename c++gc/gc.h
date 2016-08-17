#include <iostream>
#include <list>
#include <typeinfo>
#include <cstdlib>

using namespace std;
class OutOfRangeExc{


};

template <class T> class Iter{
	T *ptr;
	T *end;
	T *begin;
	unsigned length;
public:
	Iter(){
		ptr=end=begin=NULL;
		length=0;
	}

	Iter(T *p,T *first,T *last){
		ptr=p;
		end=last;
		begin=first;
		length=last-first;
	}

	unsigned size(){return length;}

	T &operator*(){
		if((ptr>=end)||(ptr<begin))
				throw OutOfRangeExc();
		return *ptr;
	}

	T *operator->(){
		if((ptr->end)||(ptr<begin))
				throw OutOfRangeExc();
		return ptr;
	}

	// prefix
	Iter operator++(){
		ptr++;
		return *this;
	}

	Iter operator--(){
		ptr--;
		return *this;
	}

	Iter operator++(int notused){
		T *tmp=ptr;
		ptr++;
		return Iter<T>(tmp,begin,end);
	}

	Iter operator--(int notused){
		T *tmp=ptr;
		ptr--;
		return Iter<T>(tmp,begin,end);
	}

	T &operator[](int i){
		if((i<0)|| (i>=(end-begin)))
				throw OutOfRangeExc();
		return ptr[i];
	}

	bool operator!=(Iter op2){
		return ptr!=op2.ptr;
	}

	bool operator<(Iter op2){
		return ptr<op2.ptr;
	}

	bool operator<=(Iter op2){
		return ptr<=op2.ptr;
	}

	bool operator>(Iter op2){
		return ptr>op2.ptr;
	}

	bool operator>=(Iter op2){
		return ptr>=op2.ptr;
	}

	Iter operator-(int n){
		ptr-=n;
		return *this;
	}
	
	Iter operator+(int n){
		ptr +=n;
		return *this;
	}

	int operator-(Iter<T> &itr2){
		return ptr-itr2.ptr;
	}

};

// This class defines an element that is stroed
// in the garbage collection information list.
//
template<class T> class GCInfo{
public:
	unsigned refcount;
	T *memPtr;
	bool isArray;
	unsigned arraySize;

	GCInfo(T* mPtr,unsigned size=0){
		refcount=1;
		memPtr=mPtr;
		if(size!=0)
			isArray=true;
		else
			isArray=false;

		arraySize=size;

	}	

};


//overloading operator== allows GCInfos to be compared

template<class T> bool operator==(const GCInfo<T> &ob1,
				const GCInfo<T> &ob2){
	return (ob1.memPtr==ob2.memPtr);
}


//GCPtr implements a pointer type that uses
//garbage collection to release unused memory.
//A GCPtr must only be used to point to memory
//that was dynamically allocated using new.
//when used to refer to an allocated array.
//specify the array size.
//

template <class T,int size=0> class GCPtr{
	//gclist maintains the garbage collection list.
	static list<GCInfo<T> >gclist;
	T *addr;

	bool isArray;

	unsigned arraySize;
	static bool first;// true when first GCPtr is created
	// return an iterator to pointer info in gclist.
	typename list<GCInfo<T> >::iterator findPtrInfo(T *ptr);
public:
	typedef Iter<T> CGiterator;
	GCPtr(T *t=NULL){
		if(first) atexit(shutdown);
		first=false;
		list<GCInfo<T> >::iterator p;

		p=findPtrInfo(t);

		if(p!=gclist.end())
			p->refcount++;
		else{
			GCInfo<T> gcObj(t,size);
			gclist.push_front(gcObj);
		}

		addr=t;
		arraySize=size;
		if(size>0) isArray=true;
		else isArray=false;


#ifdef DISPLAY
		cout<<"Constructing GCPTr. ";
		if(isArray)
				cout<<"Size is "<<arraySize<<endl;
		else
				cout<<endl;
#endif

	}
	
	GCPtr(const GCPtr &ob){
		lsit<GCInfo<T> >::iterator p;
		p=findPtrInfo(ob.addr);
		p->refcount++;

		addr=ob.addr;
		arraySize=ob.arraySize;
		if(arraySize>0)isArray=true;
		else isArray=false;

	}

	~GCPtr();

	static bool collect();

	T *operator=(T *t);
	GCPtr &operator=(GCPtr &rv);

	T &operator*(){
		return *addr;
	}

	T *operator->(){return addr;}

	T &operatorp[](int i){
		return addr[i];
	}

	// Conversion function to T *
	operator T *(){return addr;}

	Iter<T> begin(){
		int size;
		if(isArray)size=arraySize;
		else size=1;

		return Iter<T>(addr,addr,addr+size);

	}

	//Return an Iter to one past the end of an allocated array.
	Iter<T> end(){
		int size;
		if(isArray) size=arraySize;
		else size=1;
		return Iter<T>(addr+size,addr,addr+size);

	}

	static int gclistSize(){return gclist.size();}

	static void showlist();

	static void shutdown();

};

// Creates storage for the static variables
template <class T,int size>
	list<GCInfo<T> > GCPtr<T,size>::gclist;

template<class T,int size>
	bool GCPtr<T,size>::first=true;

template<class T,int size>
GCPtr<T,size>::~GCPtr(){
	list<GCInfo<T> >::iterator p;
	p=findPtrInfo(addr);
	if(p->refcount)p->refcount--;
#ifdef DISPLAY
	count<<"GCPtr going out of scope.\n";
#endif
	collect();
}

template<class T,int size>
bool GCPtr<T,size>::collect(){
	bool memfreed=false;
#ifdef DISPALY
	cout<<"Before garbage collection for ";
	showlist();
#endif
	list<GCInfo<T> >::iterator p;
	do{
		for(p=gclist.begin();p!=gclist.end();p++){
			if(p->refcount>0) continue;
			memfreed=true;

			gclist.remove(*p);
			if(p->memPtr){
				if(p->isArray){
#ifdef DISPLAY
					cout<<"Deleting array of size"
							<<p->arraySize<<endl;
#endif
					delete[] p->memPtr;
				}
				else{
#ifdef DISPLAY
					cout<<"Deleting :"
							<<*(T *) p->memPtr<<"\n";
#endif
					
					delete p->memPtr;
				}
			}

			break;

		}

	}while(p!=gclist.end());
#ifdef DISPALY
		cout<<"After garbage collection for ";
		showlist();
#endif
		return memfreed;
}

template <class T,int size>
T *GCPtr<T,size>::operator-(T *t){
	list<GCInfo<T> >::iterator p;

	p=findPtrInfo(addr);
	p->refcount--;

	p=findPtrInfo(t);
	if(p!=gclist.end())
			p->refcount++;
	else{
		GCInfo<T> gcObj(t,size);
		gclist.push_front(gcObj);
	}

	addr=t;
	return t;			
}

template <class T,int size>
GCPtr<T,size> &GCPtr<T,size>::operator=(GCPtr &rv){
	list<GCInfo<T> >::iterator p;
	p=findPtrInfo(addr);
	p->refcount--;

	addr=rv.addr;
	return rv;

}

template <class T,int size>
void GCPtr<T,size>::showlist(){
	list<GCInfo<T> >::iterator p;

	cout<<"gclist<"<<typeid(T).name()<<", "
			<<size<<">:\n";
	cout<<"memPtr refcount value\n";

	if(gclist.begin()==gclist.end()){
		cout<<"-- Empty --\n\n";
		return;
	}

	for(p=pclist.begin();p!=gclist.end();p++){
		cout<<"["<<(void *)p->memPtr<<"]"
				<<" "<<p->refcount<<" ";
		if(p->memPtr)cout<<" "<<*p->memPtr;
		else cout<<" ---";
		cout<< endl;

	}

	cout<<endl;

}

template <class T,int size>
typename list<GCInfo<T> >::iterator
GCPtr<T,size>::findPtrInfo(T *ptr){
	list<GCInfo<T> >::iterator p;

	for(p=gclist.begin();p!=gclist.end();p++)
		if(p->memPtr==ptr)
			return p;

	return p;
}

// clear gclist when program exits.

template <class T,int size>
void GCPtr<T ,size>::shutdown(){
	if(gclistSize()==0) return;
	
	list<GCInfo<T> >::iterator p;
	
	for(p=gclist.begin();p!=gclist.end();p++){
		p->refcount=0;
	}
	
#ifdef DISPLAY
	cout<<"Before collecting for shutdown() for "
		<<typeid(T).name()<<"\n" ;
#endif

	collect();

#ifdef DISPLAY
	cout<<"After collecting for shutdown() for "
		<<typeid(T).name()<<"\n";
#endif
}


