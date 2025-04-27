/*
Implementati clasa Student
-notele(vector)
-adaugarea unei note
-calculul mediei
*/

#include <iostream>

using namespace std;

class Student {
public:
    int note[10] = {10, 5, 4, 7, 8};
    int nr_note = 5;
      
    void afisare() {
        for(int i = 0; i < nr_note; i++)
            cout << note[i] << ' ';
        cout << '\n';
    }
      
    void adaugare_nota(int nota) {
        note[nr_note+1] = nota;
        nr_note++;
    }
      
    float media() {
        float s = 0;
        for(int i = 0; i<nr_note; i++)
            s += note[i];
        return s/nr_note;
    }
};
  
  int main() {
      Student Iustin;

      Iustin.afisare();
      Iustin.adaugare_nota(7);
      Iustin.afisare();
      cout<<Iustin.media();

      return 0;
  }