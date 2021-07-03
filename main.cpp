#include <iostream>
using namespace std;

template <class T>

class Node
{
  public:
  T data;
  Node* next;

  Node(){
    data = 0;
    next = NULL;
  }
  Node(T d){
    data = d;
    next = NULL;
  }
  void print(){
    cout<<data<<",";
  }
};

template <class T,class O>

class List
{
  private:
  Node<T>* m_head;
  Node<T>* m_end;

  public:
  List(){
    m_head = NULL;
    m_end = NULL;
  }
  ~List(){//Liberar toda la memoria utilizada
    Node<T>* sig;
     while (m_head) {
        sig = m_head->next;//segundo, tercero, cuarto
        delete m_head;//primero, segundo, tercero
        m_head = sig;//segundo, tercero, cuarto
      }   
  }
  void add_head(T d){//Añadir al inicio
    Node<T>*new_node = new Node<T>(d);

    if(!m_head){//Vacia
      m_head = new_node;
      m_end = new_node;
    }else{//Con elementos
      new_node->next = m_head;//apunta al anterio primero
      m_head = new_node;
    }
  }
  void add_end(T d){//Añadir al inicio
    Node<T>*new_node = new Node<T>(d);

    if(!m_head){//Vacia
      m_head = new_node;
      m_end = new_node;
    }else{//Con elementos
      m_end->next = new_node;
      m_end = new_node;
    }
  }
  void print(){
    cout << "Head->";
    for (Node<T>* p = m_head; p; p = p->next)
        p->print();
    cout << endl;
  }
  Node<T>* findAnt(T d){//Cuando el dato a buscar esta desde la 2da
    Node<T>* ant = m_head;
    Node<T>* p = NULL;
    for (p = m_head->next; p; p = p->next,ant = ant->next) {
        if (p->data == d) break;
    }
    if (!p)//No encontrado
      return NULL;
    return ant;
  }
  void del(T d){//Eliminar un nodo
    Node<T>* ant;
    Node<T>* tmp;
    if (!m_head){cout<<"No encontrado"<<"\n";return;}
    if (m_head && m_head->data == d){//Dato está en el primer nodo
      Node<T>* tmp = m_head;
      m_head = tmp->next;
      delete tmp;
      if (m_head == NULL)//Un elemento
        m_end = NULL;
    }else{//El dato está a partir del segundo elemento
      ant = findAnt(d);//Dos o mas elementos
      if(ant == NULL)cout<<"No encontrado"<<"\n";
      else{
        tmp = ant->next;
        ant->next = ant->next->next;
        delete tmp;
        if (ant->next==NULL){//Cuando borramos el utlimo nodo
          m_end = ant;//anterio al ultimo , penultimo
        }
      }
    }
  }
  void insert(T newNode,T node){
    Node<T>* ant;
    Node<T>* tmp;
    if (!m_head){cout<<"No encontrado"<<"\n";return;}        
    if(m_head->data == node){//INSERTAR AL INICIO
      add_head(newNode);
    }
    else{
        ant = findAnt(node);//Dos o mas elementos
        if(ant == NULL)cout<<"No encontrado"<<"\n";
        else{
          Node<T>*new_node = new Node<T>(newNode);
          tmp=ant->next;
          ant->next=new_node;
          new_node->next=tmp;
        }
    }
  }

 void transform(O criterio)
 {
    int s=0;
 for (Node<T>* p = m_head; p; p = p->next)
 { 
   criterio(p);
//  
/*Node<T>*a=p;

    p->next;
    cout<<a+p;
    cout << endl;*/

 }
 }

};

template <class T,class O>

class eliminar{
 public:
 O criterio;
 T operator()(Node <T>*& n){
 Node<T>*list = n ;
if (criterio(n->data)){
 del(n);
}
 }
  };

template <class T>

class par{
public:
bool operator()(T n){
  return (n%2==0);
}


};


int main() {


  List<float,class O> l;//vacia
  l.insert(6,5);
  l.add_head(8);
  l.insert(6,8);
  l.print();
  l.del(11);
  l.del(6);
  l.del(8);
  l.add_end(3);
  l.add_head(5.2);
  l.add_end(10);
  l.print();
  l.del(10);
  l.print();
  l.add_end(22);
  l.print();
  l.insert(7,5);
  l.print();
  l.insert(9,5);
  l.print();
  l.insert(10,3);
  l.print();
  l.insert(2,22);
  l.print();
 eliminar<class T, class O>
  //l.transform(List<eliminar, par>);
  p.transform();
}