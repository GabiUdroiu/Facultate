#ifndef USER_H
#define USER_H

//crazi

class User {
private:
    char* nume;
    char* parola;
    int an_nastere;
public:
    //Constructori
    User();
    User(char*, char*, int);
    
    //Destructori
    ~User();

    //Metode
    void afiseaza() const;
    bool verifica_parola() const;
    void setAn(int);
    int getAn() const;

    int varsta() const;

    static int strlen(char*);
    static bool strcif(char*);
    static void strcpy(char*, char*);
};

#endif