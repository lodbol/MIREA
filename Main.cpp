#include <iostream>
#include <cstdlib>

using namespace std;

class Data{
public:
	int key;
    int value;
    Data(int key){
        this->key = key;
        value = 10101 * key;
    }
};

class Item{

public:
    Data *data;
    Item *next;

    Item(Data *data){
        this->data = data;
        this->next = NULL;
    }
    ~Item(){
        delete data;
    }
};


class List{
    Item *head;
public:	
    List(){
        head = NULL;
    }
   void addItem (Data *data) {
    	Item *item = new Item(data);
		item->next = head;
		head = item;
		
		Item *current = head;
		Item *temp = NULL;
		Item *prev = NULL;
		while(current->next != NULL){
            if(current->data->key > current->next->data->key){
                if(current == head){
                	temp = current;
                    current = temp->next;
                    temp->next = current->next;
                    current->next = temp;
                    head = current;
                } else {
                	temp = current;
                    current = temp->next;
                    temp->next = current->next;
                    current->next = temp;
                    prev->next = current;    
                }
            }
            prev = current;
            current = current->next;
        }
	}

	void deleteItem (int d) {
		Item *current = head;
		Item *last = NULL;
		while(current != NULL){
			if(d == current->data->key) last = current;
			current = current->next;
		}
		if (last == NULL) {		
			system("cls");
			cout << "Incorrect input! Try again!" << endl;
			system("pause");
		}else if (last == head) {
			head = last->next;
			delete last;
		} else {
			current = head;
			while(current != NULL){
				if(current->next == last) current->next = last->next;
				current = current->next;	
			}
			delete last;
		} 		
	}

	void searchItem (int s) {
		Item *current = head;
		Item *it = NULL;
		while(current != NULL){
			if(s == current->data->key) it = current;
			current = current->next;
		}
		system("cls");
		if (it == NULL) {
			cout << "Incorrect input! Try again!" << endl;
		} else {
			cout << "KEY : VALUE" << endl;
			cout << "-----------" << endl;
			cout << "  " << it->data->key << " : " << it->data->value << endl;
		}
		system("pause");
	}

	void printList () {
		
		system("cls");
		if (head == NULL) {
			cout << "List is empty!" << endl;
		} else {
			Item *current = head;
			cout << "KEY : VALUE" << endl;
			cout << "-----------" << endl;
	    	while(current != NULL){
	       		cout << "  " << current->data->key << " : " << current->data->value << endl;
	        	current = current->next;
	   		}
		}
		system("pause");
	}
	
    ~List(){
    	Item *current = head;
    	Item *dtmp;
		while(current != NULL){
			dtmp = current->next;
			delete current;
			current = dtmp;
		}
	}
};


int main(){
    int n = 1;
	List list;
	while (n!= 0) {
		system("cls");
		cout << " THE MENU " << endl;
		cout << "----------" << endl;
		cout << "1. Add" << endl;
		cout << "2. Delete" << endl;
		cout << "3. Search" << endl;
		cout << "4. Show" << endl;
		cout << "5. Quit" << endl;
		cout << "----------" << endl;
		cout << "Enter: " ;
		cin >> n;
		cout << endl;
		switch(n){
			case 1: {
				int k;
				system("cls");
				cout << "Enter KEY: " << endl;
				cin >> k;
				Data *tdata = new Data(k);
				list.addItem(tdata);
				break;
			};
			case 2: {
				int d;
				system("cls");
				cout << "Enter KEY: " << endl;
				cin >> d;
				list.deleteItem(d);
				break;
			}
			case 3: {
				int s;
				system("cls");
				cout << "Enter KEY: " << endl;
				cin >> s;
				list.searchItem(s);
				break;
			}
	
			case 4: list.printList(); 
			break;
			case 5: {
				list.~List();
				exit(0);
				break;
			}
			break;
			default: {
				system("cls");
				cout << "Incorrect input! Try again!" << endl; 
				system("pause");	
			}
		}
	}
    
    return 0;

}


