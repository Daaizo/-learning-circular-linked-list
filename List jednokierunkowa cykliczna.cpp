#include <iostream>

using namespace std;

struct element
{
    element *next;
    int number;

};

void add_before(element *&, int);
void add_after(element *&, int);
void delete_before(element *&);
void delete_after(element *&);
void delete_current(element *&);
bool is_Empty(element *);
void print_list_from_current(element *);
int main()
{
    element *List = nullptr ;
    int choice = -1;
    while(choice != 9)
    {

        if(!is_Empty(List)) cout << "\nelement biezacy : " << List->number ;
        if(!is_Empty(List))
        {
                cout << "\n list : " ;
                print_list_from_current(List) ;
        }
        cout << "\n\nMenu\n1.sprawdzenie czy lista jest pusta\n2.dodanie za element biezacy\n3.dodanie przed element biezacy\n4.usuniecie elementu stojacego za elementem biezacym\n5.usuniecie elementu stojacego przed elementem biezacym";
        cout << "\n6.usuniecie elementu biezacego, a element stojacy za nim staje sie elementem biezacym\n7.wyswietlenie elementow listy od biezacego\n8.usuniecie calej listy\n9.wyjscie z programu\n";
        cin >> choice;

        system("cls");

        switch(choice)
        {
            case 1:
                {
                    cout << ( is_Empty(List) ? " lista jest pusta " : " lista nie jest pusta");
                    break;
                }
            case 2:
                {
                    int number;
                    cout << " podano liczbe jaka ma zostac dodana : ";
                    cin >> number;
                    add_after(List, number);
                    break;
                    break;
                }
            case 3:
                {
                    int number;
                    cout << " podano liczbe jaka ma zostac dodana : ";
                    cin >> number;
                    add_before(List, number);
                    break;
                }
            case 4:
                {
                    if(is_Empty(List))
                    {
                        cout << " list ja pusta i nie ma co usunac";
                    }
                    else if(List == List->next)
                    {
                        cout << " w liscie jest tylko jeden element, wiec nie ma elementu za biezacym!";
                    }
                    else
                    {
                        delete_after(List);
                    }

                    break;
                }
            case 5:
                {
                    if(is_Empty(List))
                    {
                        cout << " list ja pusta i nie ma co usunac";
                    }
                    else if(List == List->next)
                    {
                        cout << " w liscie jest tylko jeden element, wiec nie ma poprzedniego!";
                    }
                    else
                    {
                        delete_before(List);
                    }

                    break;
                }
            case 6:
                {
                    if(is_Empty(List))
                    {
                        cout << " list ja pusta i nie ma co usunac";
                    }
                    else
                    {
                        delete_current(List);
                    }

                    break;
                }
            case 7:
                {
                    if(!is_Empty(List))
                    {
                        cout << "\n list : ";
                        print_list_from_current(List);
                    }
                    else
                    {
                        cout << " lista jest pusta ";
                    }
                    break;
                }
            case 8:
                {
                    while(!is_Empty(List))delete_current(List);

                    break;
                }
            case 9:
                {
                    cout << "wychodzenie .. " ; exit(1);
                    break;
                }
            default :
                {
                    cout << " Podano zly numer, sprobuj ponownie";
                    break;
                }
        }

    }
    return 0;
}



void add_before(element *&current, int value_too_add)
{

    if(is_Empty(current))
    {
       current = new element;
       current->number = value_too_add;
       current->next = current;
    }
    else
    {
        element *el = new element;
        element *temp = current;

        while(temp->next != current)
        {
            temp = temp->next;
        }
        // wyjdziemy z ostatnim elem w temp
        el->number = value_too_add;
        el->next = current;
        temp->next = el;
        current = el;
    }
}


void add_after(element *&current, int value_too_add)
{
    if(is_Empty(current))
    {
       current = new element;
       current->number = value_too_add;
       current->next = current;
    }
    else
    {
        element *el = new element;
        element *temp = current->next;
        el->number = value_too_add;
        el->next = temp;
        current->next = el;
        current = el;

    }



}


void delete_before(element *&current)
{
    if(current != current->next)
    {
        element *temp = current;
        while( temp->next->next != current)
        {
            temp = temp->next; // temp to wskaznik na wezel przed tym do usuniecia
        }
        temp->next = temp->next->next; // rowna sie 2 pozniej czyli do poczatku
    }


}
void delete_after(element *&current)
{
    if(current != current->next)
    {
        element *temp = current;
        temp->next = temp->next->next;

    }


}
void delete_current(element *&current)
{
    element *temp = current;
    if(current == current->next)
    {
        delete temp;
        current = nullptr;

    }
    else
    {
        while(temp->next != current ) temp = temp->next;
        temp->next = temp->next->next;
        current = temp->next;
    }
}




bool is_Empty(element *current)
{
    return !current;
}

void print_list_from_current(element *current)
{
    element *temp = current;
    while(temp->next != current)
    {
        cout << temp->number << " ";
        temp = temp->next;
    }
    cout << temp->number << " ";
}
