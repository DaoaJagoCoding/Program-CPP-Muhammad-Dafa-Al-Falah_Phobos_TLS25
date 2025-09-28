#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//bikin menghilangkan vokal
bool vokal (char vok){
    vok = tolower(vok);
    return vok == 'a'|| vok == 'i'|| vok == 'e'|| vok == 'u'|| vok =='o';
}

//reverse
string reverse (string kata){
    string rev;
    for (int i=kata.length(); i>=0; i--){
        rev += kata[i];
    } return rev;
}
void bikinPass (string kata){
    char awal = kata[0];
    int asciiawal = (int)awal;
    string asciis = to_string(asciiawal);

    string katanoVok;
    for (char vok : kata ){
        if (!vokal(vok)){
            katanoVok += vok;
        }
    }
    string passrev = reverse(katanoVok);
    int posisi = passrev.length()/2;
    string password = passrev.substr(0,posisi) + asciis + passrev.substr(posisi);
    cout<<password;

}

void kataAsli (string kata){
    //declare posisi
    int posisi;
    for (int i = 0;i<kata.length();i++){
        if (isdigit(kata[i])){
            posisi = i;
            break;
        }
    } 

    string ASCII;
    while (posisi < kata.length() and isdigit (kata[posisi])){
        ASCII += kata [posisi];
        posisi ++;
    }
    
    string katasli = kata.substr(0,kata.find(ASCII)) + kata.substr(posisi);
    string asli = reverse(katasli);

    cout << asli;


}
int main (){
    string sandi, katasandi, kataasli, input;
    cout << "Mau cari katasandi atau kataasli : "<<endl;
    cin>>input;
    if (input == "katasandi"){
        cout << "Masukkan kata"<<endl;
        cin >> sandi;
        bikinPass (sandi);
    }
    else if (input == "kataasli"){
        cout << "Sandimu apa?"<<endl;
        cin >> kataasli;
        kataAsli(kataasli);
    }
    else {
        cout << "Yang bener dong! mau katasandi atau kataasli";
    }

    return 0;
}