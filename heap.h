#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <iostream>

using namespace std;

template <typename H>
 class Heap
 {

 private:
 H *h;
 size_t size;
 size_t count;
 H com;


 public:
 Heap();
 Heap(size_t size);
 Heap(const Heap &obj);
 ~Heap();

 Heap<H> & operator=(const Heap<H> &hs);

 bool insert(H value);
 bool deletee(size_t pos);
 bool set(size_t pos, H value);
 bool get(size_t pos) const;
 void clear();
 void print () const;
 bool isEmpty();
 bool isContains();
 void check(size_t pos);
 };

 template <typename H>
 Heap<H>::Heap()
{
    size = 1;
    count = 0;
    h = new H[size];
}

 template <typename H>
 Heap<H>::Heap(size_t size)
 {
     if(size < 1)
     {
         size = 1;
     }

     this->size = size;
     this->count = 0;
     this->h = new H[size];
 }

  template <typename H>
  Heap<H>::Heap(const Heap &obj)
  {
      this->size = obj.size;
      this->count = obj.count;
      this->h = new H[obj.size];

      for(size_t i = 0; i < obj.count; i++)
      {
          this->h[i] = obj.h[i];
      }
  }

   template <typename H>
   Heap<H>::~Heap()
   {
       delete [] h;
   }

   template <typename H>
   Heap<H> & Heap<H>::operator=(const Heap<H> &obj)
  {
      delete [] this->h;

      this->size = obj.size;
      this->count = obj.count;
      this->h = new H[obj.size];

      for(size_t i = 0; i < obj.count; i++)
      {
          this->h[i] = obj.h[i];
      }
  }


    template <typename H>
    bool Heap<H>::insert(H value)
  {
      if(count < size)
      {
          h[count] = value;
          ++count;
          return true;
      }

      return false;
  }

  template <typename H>
  bool Heap<H>::deletee(size_t pos)
  {
   if (size <= pos)
    return false;
   for (int i = pos-1; i < size-1; i++)
   {
    h[i] = h[i+1];
   }
   size--;
   return true;
  }

  template <typename H>
  bool Heap<H>::set(size_t pos, H value)
  {
      if(pos < count && pos >= 1)
      {
          h[pos-1] = value;
          return true;
      }

      return false;
  }

  template <typename H>
  bool Heap<H>::get(size_t pos) const
  {
      if(pos < count && pos >= 0)
      {
          return true;
      }
     return false;
  }

  template <typename H>
  void Heap<H>::clear()
  {
      count = 0;
  }

  template <typename H>
  void Heap<H>::print() const
  {
      cout << "Heap size: " << size << ", count: " << count << endl;
      for(size_t i = 0; i < size; i++)
      {
          cout << h[i] << " ";
      }
      cout << endl;
  }

  template <typename H>
  bool Heap<H>::isEmpty()
  {
       if (size==0)
      {
          return true;
      }
      return false;
  }

  template <typename H>
  bool Heap<H>::isContains()
  {
      for (size_t i = 0; i < size; i++)
      {
          if (h[i] == com)
          {
              return true;
          }

      }
      return false;
  }

  template <typename H>
  void Heap<H>::check(size_t pos)
  {
      for (size_t i = pos - 1;i >= 1; i--)
      {
          if (i%2==0)
          {
              if (h[i] > h[(i-2)/2])
              {
                  H zam=0;
                  zam = h[i];
                  h[i] = h[(i-2)/2];
                  h[(i-2)/2] = zam;
              }
          }
          else
          {
              if (h[i] > h[(i-1)/2])
              {
                  H zam=0;
                  zam = h[i];
                  h[i] = h[(i-1)/2];
                  h[(i-1)/2] = zam;
              }
          }
      }
  }





#endif // HEAP_H_INCLUDED
