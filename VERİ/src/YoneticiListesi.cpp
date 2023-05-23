
#include "YoneticiListesi.hpp"

YoneticiNode* YoneticiListesi::FindPreviousByPosition(int index)throw (NoSuchElement) {
    if (index < 0 || index > boyut) throw NoSuchElement("No Such Element");
    YoneticiNode *prv = head;
    int i = 1;
    for (YoneticiNode *itr = head; itr->Sonraki != NULL && i != index; itr = itr->Sonraki, i++) {
        prv = prv->Sonraki;
    }
    return prv;
}

YoneticiNode* YoneticiListesi::FindPosition(int index)throw (NoSuchElement) {
    if (index < 0 || index >= boyut) throw NoSuchElement("No Such Element");
    return this->FindPreviousByPosition(index + 1);

}

YoneticiListesi::YoneticiListesi() {
    head = NULL;
    boyut = 0;
}

int YoneticiListesi::Count()const {
    return boyut;
}

bool YoneticiListesi::isEmpty()const {
    return boyut == 0;
}

void YoneticiListesi::add(SatirListesi*& item) {
    insert(boyut, item);
}

void YoneticiListesi::insert(int index, SatirListesi*& item) {
    if (index < 0 || index > boyut) throw "Index out of Range";
    if (index == 0) {
        head = new YoneticiNode(item, head);
        if (head->Sonraki != NULL) head->Sonraki->Onceki = head;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(index);
        prv->Sonraki = new YoneticiNode(item, prv->Sonraki, prv);
        if (prv->Sonraki->Sonraki != NULL)
            prv->Sonraki->Sonraki->Onceki = prv->Sonraki;
    }
    boyut++;
}

SatirListesi*& YoneticiListesi::first()throw (NoSuchElement) {
    if (isEmpty()) throw NoSuchElement("No Such Element");
    return head->Veri;
}

SatirListesi*& YoneticiListesi::last()throw (NoSuchElement) {
    if (isEmpty()) throw NoSuchElement("No Such Element");
    return FindPreviousByPosition(boyut)->Veri;
}

int YoneticiListesi::indexOf(SatirListesi*& item)throw (NoSuchElement) {
    int index = 0;
    for (YoneticiNode *itr = head; itr != NULL; itr = itr->Sonraki) {
        if (itr->Veri == item) return index;
        index++;
    }
    throw NoSuchElement("No Such Element");
}

void YoneticiListesi::remove(SatirListesi*& item) {
    int index = indexOf(item);
    removeAt(index);
}

void YoneticiListesi::randomRemoveAtSatirListesi(int index, int inlineIndex)throw (IndexOutOfBounds, NoSuchElement) {

    int hesap = this->Count();
    if (index < 0 || index >= hesap)
        throw IndexOutOfBounds("Index out of bounds");

    SatirListesi* satirListesi = this->elementAt(index);

    satirListesi->removeAt(inlineIndex);
    calculateAveragee(index);

}

void YoneticiListesi::calculateAveragee(int index) {
    YoneticiNode* yoneticiNode = this->FindPosition(index);

    if (yoneticiNode == NULL) {

        throw "HATA";
    }


    double toplam = 0;
    if (yoneticiNode->Veri->isEmpty()) {

        yoneticiNode->ort = toplam;
        return;
    }


    int hesap = yoneticiNode->Veri->Count();
    for (int i = 0; i < hesap; ++i) {
        toplam += yoneticiNode->Veri->elementAt(i);
    }
    yoneticiNode->ort = toplam/ hesap;



}

int YoneticiListesi::randomGenerator(int index)throw (IndexOutOfBounds, NoSuchElement) {
    int hesap = this->Count();

    if (index < 0 || index >= hesap)
        throw IndexOutOfBounds("Index out of bounds");

    srand(time(NULL));
    SatirListesi* satirListesi = this->elementAt(index);

    int aralik = satirListesi->Count();
    if (aralik == 0) {
        throw NoSuchElement("No Such Element");
    }
    int inlineIndex = rand() % aralik;

    return inlineIndex;
}

void YoneticiListesi::removeAt(int index) {
    if (index < 0 || index >= boyut) throw "Index out of Range";
    YoneticiNode *del;
    if (index == 0) {
        del = head;
        head = head->Sonraki;
        if (head != NULL) head->Onceki = NULL;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(index);
        del = prv->Sonraki;
        prv->Sonraki = del->Sonraki;
        if (del->Sonraki != NULL)
            del->Sonraki->Onceki = prv;
    }
    boyut--;
    delete del;
}

void YoneticiListesi::moveNode(int from, int to)throw (IndexOutOfBounds) {
    if (from < 0 || from >= boyut) throw IndexOutOfBounds("index out of bound");
    YoneticiNode *del;
    if (from == 0) {
        del = head;
        head = head->Sonraki;
        if (head != NULL) head->Onceki = NULL;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(from);
        del = prv->Sonraki;
        prv->Sonraki = del->Sonraki;
        if (del->Sonraki != NULL)
            del->Sonraki->Onceki = prv;
    }
    boyut--;
    if (to < 0 || to > boyut) throw "Index out of Range";
    if (to == 0) {

        del->Sonraki = head;
        del->Onceki = NULL;
        head = del;
        if (head->Sonraki != NULL) head->Sonraki->Onceki = head;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(to);

        del->Sonraki = prv->Sonraki;
        del->Onceki = prv;
        prv->Sonraki = del;
        if (prv->Sonraki->Sonraki != NULL)
            prv->Sonraki->Sonraki->Onceki = prv->Sonraki;
    }
    boyut++;
}

bool YoneticiListesi::find(SatirListesi*& item) {
    for (YoneticiNode *itr = head; itr != NULL; itr = itr->Sonraki) {
        if (itr->Veri == item) return true;
    }
    return false;
}

void YoneticiListesi::reverse() {
    for (YoneticiNode *itr = head; itr != NULL;) {
        YoneticiNode *tmp = itr->Sonraki;
        itr->Sonraki = itr->Onceki;
        itr->Onceki = tmp;
        if (tmp == NULL) {
            head = itr;
            break;
        }
        itr = tmp;
    }
}

void YoneticiListesi::sortByAverage() {
    if (this->boyut <= 1)
        return;

    for (int adim = 0; adim < boyut; ++adim) {


        for (int i = 0; i < boyut - adim - 1; ++i) {
            YoneticiNode *tmp = this->FindPosition(i);
            YoneticiNode *tmp2 = tmp->Sonraki;

            if (tmp->ort > tmp2->ort) {


                this->moveNode(i + 1, i);
            }
        }
    }

}

SatirListesi*& YoneticiListesi::elementAt(int index)throw (NoSuchElement) {
    if (index < 0 || index >= boyut) throw NoSuchElement("No Such Element");
    if (index == 0) return head->Veri;
    return FindPreviousByPosition(index)->Sonraki->Veri;
}

void YoneticiListesi::clear() {
    while (!isEmpty())
        removeAt(0);
}

void YoneticiListesi::printIndex(int index, int x, int y) {
    YoneticiNode *node = this->FindPosition(index);
    ConsolePosition.gotoxy(x, y);
    cout << fixed << setprecision(2);
    cout << node << endl;
    ConsolePosition.gotoxy(x, y + 1);
    cout << "-----------\n";
    ConsolePosition.gotoxy(x, y + 2);
    cout << "|" << node->Onceki << setw(3) << "|\n";
    ConsolePosition.gotoxy(x, y + 3);
    cout << "-----------\n";
    ConsolePosition.gotoxy(x, y + 4);
    cout << "|" << setw(3) << node->ort << setw(5) << "|" << endl;
    ConsolePosition.gotoxy(x, y + 5);
    cout << "-----------\n";
    ConsolePosition.gotoxy(x, y + 6);
    cout << "|" << node->Sonraki << setw(3) << "|\n";
    ConsolePosition.gotoxy(x, y + 7);
    cout << "-----------\n\n";

}

YoneticiListesi::~YoneticiListesi() {
    clear();
}