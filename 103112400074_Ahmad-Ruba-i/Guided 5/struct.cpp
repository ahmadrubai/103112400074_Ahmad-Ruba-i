#include <iostream>
using namespace std;

int main(){
    const int MAX = 3;
    struct rapot{
        char nama [3];
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukan nama siswa : ";
        cin >> siswa[i].nama;
        cout << endl;
        cout << "masukan nilai siswa : ";
        cin >> siswa[i].nilai;
    }
    int j = 0;
    while(j < MAX){
        cout << "nama siswa : " << siswa[j].nama << ", Nilai : " << siswa[j].nilai << endl;
        j++;
    }
    return 0;
}