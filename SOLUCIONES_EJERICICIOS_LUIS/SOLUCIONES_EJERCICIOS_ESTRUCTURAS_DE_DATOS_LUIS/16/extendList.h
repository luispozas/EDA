//LUIS POZAS PALOMO - EDA - 11
#include "list_eda.h"
#include "persona.h"
#include <iostream>
using namespace std;

template <class T>
class extendsList : public list<T> {

public:

  void print(){
    auto it = this->begin();
    while(it != this->end()){
      cout << *it << endl;
      it++;
    }
  }

  template <class Predicate>
  void remove_if(Predicate pred){
    auto it = this->begin();

    while(it != this->end()){
      if(pred(it->edad())){
        it = this->erase(it);
      }
      else {
        it++;
      }
    }

  }
   
};

