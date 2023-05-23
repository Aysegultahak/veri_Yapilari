
#include "ReadAndAdd.hpp"

YoneticiListesi* ReadAndAdd::GetFillYoneticiListesi(){
    readLine();
    YoneticiListesi *tmp=new YoneticiListesi();
    int hesap=lineCount();
    for(int i=0;i<hesap;++i){
        tmp->add(this->dosyalar[i]);
    }
    return tmp;
    
}



ReadAndAdd::ReadAndAdd(std::string dosyaAdi) {
    this->dosyaAdi = dosyaAdi;


    int numlines = lineCount();
    this->dosyalar = new SatirListesi*[numlines];
    for (int i = 0; i < numlines; i++) {
        this->dosyalar[i] = new SatirListesi();
    }
}

int ReadAndAdd::lineCount() {
    int counter = 0;
    std::ifstream file(this->dosyaAdi);
    std::string unused;
    while (std::getline(file, unused))
        ++counter;

    file.close();
    return counter;
}

void ReadAndAdd::readLine() {
    std::string token;
    std::ifstream file(this->dosyaAdi);
    std::string str;
    int index = 0;
    while (std::getline(file, token)) {
        std::istringstream ss(token);

        while (std::getline(ss, str, ' ')) {
            this->dosyalar[index]->add(stoi(str));

        }
        index++;

    }
    file.close();
}

ReadAndAdd::~ReadAndAdd(){
	if(dosyalar!=0){
		int hesap =lineCount();
		for (int i = 0; i < hesap; i++){
			if(dosyalar[i]!=0) delete dosyalar[i];
		}
		delete[] dosyalar;
	}
	
}
