#ifndef XLIST_H
#define XLIST_H
#include <exception>

template <class T>
struct Entry{
    Entry<T>* prev;
    Entry<T>* next;
    T data;

    Entry(const T& data) : data(data){
    }
};

template <class T>
class XList;


template <class T>
class XListConstIterator{
    friend XList<T>;

    Entry<T>* nextEntry;

    XListConstIterator(Entry<T>* head) : nextEntry(head){
    }

public:
    T& next(){
        T& data = nextEntry->data;
        nextEntry = nextEntry->next;
        return data;
    }

    bool hasNext() const{
        return nextEntry != NULL;
    }
};

template <class T>
class XList{
    Entry<T>* head;
    Entry<T>* tail;
    size_t sz;

public:
    XList() : head(NULL), tail(NULL), sz(0){
    }

    void push_back(const T& t){ //добавление элемента в конец списка
        Entry<T>* e = new Entry<T>(t);
        if (sz == 0){
            e->next = NULL;
            e->prev = NULL;
            head = tail = e;
        }
        else{
            e->next = NULL;
            e->prev = tail;
            tail->next = e;
            tail = e;
        }
        sz++;
    }

    void push_front(const T& t){ //добавление элемента в начало списка
        Entry<T>* e = new Entry<T>(t);
        if (sz == 0){
            e->next = e;
            e->prev = e;
            head = tail = e;
        }
        else{
            e->next = head;
            e->prev = NULL;
            head->prev = e;
            head = e;
        }
        sz++;
    }

    void pop_back(){ //удаление последнего элемента
        if (sz == 0){
            throw std::exception("empty list");
        }
        if (sz == 1){
            delete head;
            head = tail = NULL;
        }
        else{
            Entry<T>* oldTail = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete oldTail;
        }
        sz--;
    }

    void pop_front(){ //удаление первого элемента
        if (sz == 0){
            throw std::exception("empty list");
        }
        if (sz == 1){
            delete head;
            head = tail = NULL;
        }
        else{
            Entry<T>* oldHead = head;
            head = head->next;
            head->next = NULL;
            delete oldHead;
        }
        sz--;
    }

    T& front(){
        if (size == 0){
            throw std::exception("empty list");
        }
        return head->data;
    }

    const T& front() const{
        if (size == 0){
            throw std::exception("empty list");
        }
        return head->data;
    }

    T& back(){
        if (size == 0){
            throw std::exception("empty list");
        }
        return tail->data;
    }

    const T& back() const{
        if (size == 0)
            throw std::exception("empty list");
        return tail->data;
    }

    size_t size() const{
        return sz;
    }

    bool empty() const{
        return sz == 0;
    }

    void clear(){
        Entry<T>* e = head;
        while (e){
            Entry<T>* olde = e;
            e = e->next;
            delete olde;
        }
        head = tail = NULL;
        sz = 0;
    }

    XListConstIterator<T> begin() const{
        return XListConstIterator<T>(head);
    }

    ~XList(){
        Entry<T>* e = head;
        while (e){
            Entry<T>* olde = e;
            e = e->next;
            delete olde;
        }
    }
};
#endif // XLIST_H
