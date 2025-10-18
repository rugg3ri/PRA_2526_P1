#include <ostream>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {
	private:
		Node<T>* first;
		int n;
	public:
		ListLinked(){
			first = nullptr;
			n = 0;
		}
		
		~ListLinked(){
			Node<T>* current = first;
			while(current != nullptr){
				Node<T>* next_node = current -> next;
				delete current;
				current = next_node;
			}
		}

		T operator[](int pos){
			if(pos<0 || pos>=n){
				throw out_of_range("Posicion fuera de rango");
			}
			Node<T>*current = first;
			for(int i=0; i<pos; i++){
				current = current->next;
			}
			return current->data;
		}

		friend ostream& operator<<(ostream &out, const ListLinked<T> &list){
			out << "List => ";
   			if (list.n == 0) {
        			out << "[]";
    			} else {
        			out << "[\n";
        			Node<T>* current = list.first;
        			while (current != nullptr) {
            				out << "  " << current->data << "\n";
            				current = current->next;
       				}
       			 	out << "]";
   			}
    			return out;
		}
};
