

#include "SatirListesi.hpp"
#include "ConsolePosition.hpp"

SatirListesiNode* SatirListesi::FindPreviousByPosition(int index)throw (NoSuchElement) {
    if (index < 0 || index > boyut) throw NoSuchElement("No Such Element");
    SatirListesiNode *prv = head;
    int i = 1;
    for (SatirListesiNode*itr = head; itr->Sonraki != NULL && i != index; itr = itr->Sonraki, i++) {
        prv = prv->Sonraki;
    }
    return prv;
}

SatirListesi::SatirListesi() {
    head = NULL;
    boyut = 0;
}

int SatirListesi::Count()const {
    return boyut;
}

bool SatirListesi::isEmpty()const {
    return boyut == 0;
}

void SatirListesi::add(const int& item) {
    insert(boyut, item);
}

void SatirListesi::insert(int index, const int& item) {
    if (index < 0 || index > boyut) throw "Index out of Range";
    if (index == 0) {
        head = new SatirListesiNode(item, head);
        if (head->Sonraki != NULL) head->Sonraki->Onceki = head;
    } else {
        SatirListesiNode *prv = FindPreviousByPosition(index);
        prv->Sonraki = new SatirListesiNode(item, prv->Sonraki, prv);
        if (prv->Sonraki->Sonraki != NULL)
            prv->Sonraki->Sonraki->Onceki = prv->Sonraki;
    }
    boyut++;
}

const int& SatirListesi::first()throw (NoSuchElement) {
    if (isEmpty()) throw NoSuchElement("No Such Element");
    return head->Veri;
}

const int& SatirListesi::last()throw (NoSuchElement) {
    if (isEmpty()) throw NoSuchElement("No Such Element");
    return FindPreviousByPosition(boyut)->Veri;
}

int SatirListesi::indexOf(const int& item)throw (NoSuchElement) {
    int index = 0;
    for (SatirListesiNode *itr = head; itr != NULL; itr = itr->Sonraki) {
        if (itr->Veri == item) return index;
        index++;
    }
    throw NoSuchElement("No Such Element");
}

void SatirListesi::remove(const int& item) {
    int index = indexOf(item);
    removeAt(index);
}

void SatirListesi::removeAt(int index) {
    if (index < 0 || index >= boyut) throw "Index out of Range";
    SatirListesiNode *del;
    if (index == 0) {
        del = head;
        head = head->Sonraki;
        if (head != NULL) head->Onceki = NULL;
    } else {
        SatirListesiNode *prv = FindPreviousByPosition(index);
        del = prv->Sonraki;
        prv->Sonraki = del->Sonraki;
        if (del->Sonraki != NULL)
            del->Sonraki->Onceki = prv;
    }
    boyut--;
    delete del;
}

bool SatirListesi::find(const int& item) {
    for (SatirListesiNode *itr = head; itr != NULL; itr = itr->Sonraki) {
        if (itr->Veri == item) return true;
    }
    return false;
}

void SatirListesi::reverse() {
    for (SatirListesiNode *itr = head; itr != NULL;) {
        SatirListesiNode *tmp = itr->Sonraki;
        itr->Sonraki = itr->Onceki;
        itr->Onceki = tmp;
        if (tmp == NULL) {
            head = itr;
            break;
        }
        itr = tmp;
    }
}

const int& SatirListesi::elementAt(int index)throw (NoSuchElement) {
    if (index < 0 || index >= boyut) throw NoSuchElement("No Such Element");
    if (index == 0) return head->Veri;
    return FindPreviousByPosition(index)->Sonraki->Veri;
}

void SatirListesi::clear() {
    while (!isEmpty())
        removeAt(0);
}

ostream& operator <<(ostream& screen, SatirListesi& rgt) {

    for (SatirListesiNode *itr = rgt.head; itr != NULL; itr = itr->Sonraki) {
        screen<<itr<<"\n";
        screen<<"-----------\n";
        screen<<"|"<<setw(5)<<itr->Veri<<setw(5)<<"|"<<endl;
        screen<<"-----------\n";
        screen<<"|"<<itr->Sonraki<<setw(3)<<"|\n";
        screen<<"-----------\n\n";
    }
    screen << endl;
    return screen;
}

void SatirListesi::printNodesFromPositionInReverseOrder(int index)throw (NoSuchElement) {
    if (index < 0 || index >= boyut) throw NoSuchElement("No Such Element");
    for (SatirListesiNode *itr = FindPreviousByPosition(index + 1); itr != NULL; itr = itr->Onceki) {
        
        cout << itr->Veri << " <-> ";
    }
    cout << endl;
}

void SatirListesi::printReverseOrder() {
    printNodesFromPositionInReverseOrder(boyut - 1);
}
void SatirListesi::printSatirListesi(int x,int y){
    int yIndex=y; 
    ConsolePosition.gotoxy(x,yIndex);
    cout<<"vvvvvvvv\n"; 
     for (SatirListesiNode *itr = this->head; itr != NULL; itr = itr->Sonraki) {
      
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<itr<<endl;
        
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"-----------\n";
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"|"<<setw(5)<<itr->Veri<<setw(5)<<"|"<<endl;
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"-----------\n";
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"|"<<itr->Sonraki<<setw(3)<<"|\n";
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"-----------\n\n";
    }
}

SatirListesi::~SatirListesi() {
    clear();
}
