#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
class PreparatMeniu

{
private:
    const int  id;
    static int CONTORID;
    char* numePreparat;
    double pret;
    int gramaj;
    vector <string> Ingrediente;


public:
    PreparatMeniu():id(CONTORID++)//constructor fara parametrii
    {
        numePreparat=new char[strlen("necunoscut")+1];
        strcpy(numePreparat,"necunoscut");
        pret=0;
        gramaj=0;
        Ingrediente= {};


    }
    //constructori cu parametrii
    PreparatMeniu(char* numePreparat ):id(CONTORID++)
    {
        this->numePreparat=new char[strlen(numePreparat)+1];
        strcpy(this->numePreparat,numePreparat);
        pret=0;
        gramaj=0;
        Ingrediente= {};

    }

    PreparatMeniu(char* numePreparat,double pret):id(CONTORID++)
    {
        this->numePreparat=new char[strlen(numePreparat)+1];
        strcpy(this->numePreparat,numePreparat);
        this->pret=pret;
        gramaj=0;
        Ingrediente= {};
    }
    PreparatMeniu(char* numePreparat,double pret,int gramaj,vector <string>Ingrediente):id(CONTORID++)
    {
        this->numePreparat=new char[strlen(numePreparat)+1];
        strcpy(this->numePreparat,numePreparat);
        this->pret=pret;
        this->gramaj=gramaj;
        this->Ingrediente=Ingrediente;
    }
    //copyconst
    PreparatMeniu(const PreparatMeniu& obj):id(CONTORID++)
    {
        this->numePreparat=new char[strlen(obj.numePreparat)+1];
        strcpy(this->numePreparat,obj.numePreparat);
        this->pret=obj.pret;
        this->gramaj=obj.gramaj;
        this->Ingrediente=obj.Ingrediente;
    }
    // Getters and setters
    const char* getNumePreparat() const
    {
        return numePreparat;
    }

    void setNumePreparat(const char* nume)
    {
        if (numePreparat != nullptr)
        {
            delete[] numePreparat;
        }
        numePreparat = new char[strlen(nume) + 1];
        strcpy(numePreparat, nume);
    }


    double getPret() const
    {
        return pret;
    }

    void setPret(double newPret)
    {
        pret = newPret;
    }


    int getGramaj() const
    {
        return gramaj;
    }

    void setGramaj(int newGramaj)
    {
        gramaj = newGramaj;
    }

    const vector<string>& getIngrediente() const
    {
        return Ingrediente;
    }

    void setIngrediente(const vector<string>& newIngrediente)
    {
        Ingrediente = newIngrediente;
    }
    //operator =
    PreparatMeniu& operator = (const PreparatMeniu& obj)
    {
        if(this != &obj)
        {
            if(this->numePreparat!=NULL)
                delete[] this->numePreparat;
            this->numePreparat=new char[strlen(obj.numePreparat)+1];
            strcpy(this->numePreparat,obj.numePreparat);
            this->pret=obj.pret;
            this->gramaj=obj.gramaj;
            this->Ingrediente=obj.Ingrediente;
        }
        return *this;
    }

// Suprascrierea operatorului <<pentru afisarea datelor
    friend ostream& operator << (ostream &out, const PreparatMeniu &obj)
    {
        out<<"Nr.Preparat: "<<obj.id<<endl;
        if (obj.numePreparat != nullptr)
            out<<"Nume Preparat: "<<obj.numePreparat<<endl;
        out<<"Pret: "<<obj.pret<<" lei"<<endl;
        out<<"Gramaj: "<<obj.gramaj<<" grame"<<endl;
        out<<"Ingredieante: "<<obj.Ingrediente[0];
        for(int i=1; i<obj.Ingrediente.size(); i++)
            out<<" , "<<obj.Ingrediente[i];
        out<<endl;
        return out;


    }

// Suprascrierea operatorului >> pentru citirea datelor
    friend istream& operator >> (istream &in, PreparatMeniu &obj)
    {
        cout<<"Nume preparat: ";
        char nume[100];
        in.getline(nume, 100);
        if(obj.numePreparat!=NULL)
            delete[] obj.numePreparat;
        obj.numePreparat=new char[strlen(nume)+1];
        strcpy(obj.numePreparat,nume);

        cout<<"Pret: ";
        in>>obj.pret;
        cout<<"Gramaj ";
        in>>obj.gramaj;

        cout<<"Ingrediente "<<endl;
        cout<<"Introduceti ingredientele iar apoi apasati tasta 0";
        string ingredient;
        while(true)
        {
            cin>>ingredient;
            if(ingredient=="0")
                break;
            obj.Ingrediente.push_back(ingredient);
        }

        return in;
    }
    // Suprascrierea operatorului ==
    bool operator==(const PreparatMeniu& other) const
    {
        return strcmp(numePreparat, other.numePreparat) == 0 && pret == other.pret && gramaj == other.gramaj && Ingrediente == other.Ingrediente;
    }

    // Suprascrierea operatorului <
    bool operator<(const PreparatMeniu& other) const
    {
        return pret < other.pret;
    }

    // Suprascrierea operatorului >
    bool operator>(const PreparatMeniu& other) const
    {
        return pret > other.pret;
    }

    // Suprascrierea operatorului de indexare []
    string operator[](size_t index) const
    {
        if (index >= Ingrediente.size())
        {
            throw out_of_range("Index out of range");
        }
        return Ingrediente[index];
    }

    // Suprascrierea operatorului de conversie către șir de caractere
    operator string() const
    {
        string result = "ID: " + to_string(id) + "\n";
        result += "Nume preparat: " + string(numePreparat) + "\n";
        result += "Pret: " + to_string(pret) + "\n";
        result += "Gramaj: " + to_string(gramaj) + "\n";
        result += "Ingrediente:\n";
        for (const auto& ingredient : Ingrediente)
        {
            result += "- " + ingredient + "\n";
        }
        return result;
    }
    // Prefix increment (++obj)
    PreparatMeniu& operator++()
    {
        ++gramaj;
        return *this;
    }

    // Postfix increment (obj++)
    PreparatMeniu operator++(int)
    {
        PreparatMeniu temp(*this);
        ++gramaj;
        return temp;
    }

    // Suprascrierea operatorului +
    PreparatMeniu operator+(const PreparatMeniu& other) const
    {
        PreparatMeniu result(*this);
        result.pret += other.pret;
        return result;
    }

    // Suprascrierea operatorului -
    PreparatMeniu operator-(const PreparatMeniu& other) const
    {
        PreparatMeniu result(*this);
        result.pret -= other.pret;
        return result;
    }

    friend class Comanda;

//destructor

    ~PreparatMeniu()
    {
        if(this->numePreparat!=NULL)
            delete[] this->numePreparat;
    }


};


class MasaRestaurant
{
private:
    const int  id;
    static int CONTORID;
    char zona;
    int numarlocuri;
    bool disponibilitate;

public:
    // Constructori
    MasaRestaurant() : id(CONTORID++), zona('A'), numarlocuri(4), disponibilitate(true) {}

    MasaRestaurant(int id, char zona, int numarlocuri, bool disponibilitate)
        : id(id), zona(zona), numarlocuri(numarlocuri), disponibilitate(disponibilitate)
    {
        if (id >= CONTORID)
        {
            CONTORID = id + 1;
        }
    }

    MasaRestaurant(char zona) : id(CONTORID++), zona(zona), numarlocuri(4), disponibilitate(true) {}

    MasaRestaurant(char zona, int numarlocuri) : id(CONTORID++), zona(zona), numarlocuri(numarlocuri), disponibilitate(true) {}

    // Getters
    int getId() const
    {
        return id;
    }

    char getZona() const
    {
        return zona;
    }

    int getNumarLocuri() const
    {
        return numarlocuri;
    }

    bool getDisponibilitate() const
    {
        return disponibilitate;
    }

    // Setters
    void setZona(char zona)
    {
        this->zona = zona;
    }

    void setNumarLocuri(int numarlocuri)
    {
        this->numarlocuri = numarlocuri;
    }

    void setDisponibilitate(bool disponibilitate)
    {
        this->disponibilitate = disponibilitate;
    }

    // Supraincarcarea operatorului <<
    friend ostream& operator<<(ostream& out, const MasaRestaurant& masa)
    {
        out << "ID: " << masa.id << endl;
        out << "Zona: " << masa.zona << endl;
        out << "Numar locuri: " << masa.numarlocuri << endl;
        out << "Disponibilitate: " << (masa.disponibilitate ? "Disponibila" : "Indisponibila") << endl;
        return out;
    }

    // Supraincarcarea operatorului >>
    friend istream& operator>>(istream& in, MasaRestaurant& masa)
    {
        cout << "Introduceti zona: ";
        in >> masa.zona;
        cout << "Introduceti numarul de locuri: ";
        in >> masa.numarlocuri;
        cout << "Este masa disponibila? (1 pentru da, 0 pentru nu): ";
        in >> masa.disponibilitate;
        return in;
    }

    // Supraincarcarea operatorului ==
    bool operator==(const MasaRestaurant& other) const
    {
        return (id == other.id && zona == other.zona && numarlocuri == other.numarlocuri && disponibilitate == other.disponibilitate);
    }

    // Supraincarcarea operatorului <
    bool operator<(const MasaRestaurant& other) const
    {
        return numarlocuri < other.numarlocuri;
    }

    // Supraincarcarea operatorului >
    bool operator>(const MasaRestaurant& other) const
    {
        return numarlocuri > other.numarlocuri;
    }

    // Supraincarcarea operatorului =
    MasaRestaurant& operator=(const MasaRestaurant& other)
    {
        if (this != &other)
        {
            zona = other.zona;
            numarlocuri = other.numarlocuri;
            disponibilitate = other.disponibilitate;
        }
        return *this;
    }

    // Supraincarcarea operatorului cast
    operator bool() const
    {
        return disponibilitate;
    }

    // Supraincarcarea operatorului index

    // Metoda pentru pre-incrementare (++obj)
    MasaRestaurant& operator++()
    {
        ++numarlocuri;
        return *this;
    }

    // Metoda pentru post-incrementare (obj++)
    MasaRestaurant operator++(int)
    {
        MasaRestaurant copie(*this);
        ++(*this);
        return copie;
    }
    // Supraincarcarea operatorului +
    MasaRestaurant operator+(int value) const
    {
        MasaRestaurant result(*this);
        result.numarlocuri += value;
        return result;
    }

    // Supraincarcarea operatorului -
    MasaRestaurant operator-(int value) const
    {
        MasaRestaurant result(*this);
        result.numarlocuri -= value;
        return result;
    }
};






class Angajati
{
private:
    string Nume;
    string Prenume;
    string post;
    int salariu;
public:
    //Constructori
    Angajati(string nume, string prenume, string post, int salariu) :
        Nume(nume), Prenume(prenume), post(post), salariu(salariu) {}
    Angajati(string nume, string prenume) : Nume(nume), Prenume(prenume), post(""), salariu(0) {}
    Angajati(string nume) : Nume(nume), Prenume(""), post(""), salariu(0) {}
    Angajati() : Nume(""), Prenume(""), post(""), salariu(0) {}
    Angajati(const Angajati& other) :
        Nume(other.Nume), Prenume(other.Prenume), post(other.post), salariu(other.salariu) {}
    // Setters
    void setNume(string nume)
    {
        Nume = nume;
    }

    void setPrenume(string prenume)
    {
        Prenume = prenume;
    }

    void setPost(string post)
    {
        this->post = post;
    }

    void setSalariu(int salariu)
    {
        this->salariu = salariu;
    }

    // Getters
    string getNume() const
    {
        return Nume;
    }

    string getPrenume() const
    {
        return Prenume;
    }

    string getPost() const
    {
        return post;
    }

    int getSalariu() const
    {
        return salariu;
    }

    // Operator de indexare
    string& operator[](int index)
    {
        switch (index)
        {
        case 0:
            return Nume;
        case 1:
            return Prenume;
        case 2:
            return post;
        default:
            throw out_of_range("Index out of range");
        }
    }
    int operator[](size_t index) const
    {
        if (index == 3)
        {
            return salariu;
        }
        else
        {
            throw out_of_range("Index out of range");
        }
    }
    // Operator de conversie către șir de caractere
    operator string() const
    {
        return "Nume: " + Nume + "\n" +
               "Prenume: " + Prenume + "\n" +
               "Post: " + post + "\n" +
               "Salariu: " + to_string(salariu);
    }

    // Suprascrierea operatorului < pentru compararea obiectelor Angajati bazată pe salariu
    bool operator<(const Angajati& other) const
    {
        return salariu < other.salariu;
    }

    // Suprascrierea operatorului > pentru compararea obiectelor Angajati bazată pe salariu
    bool operator>(const Angajati& other) const
    {
        return salariu > other.salariu;
    }

    // Suprascrierea operatorului << pentru afișarea rezultatelor
    friend ostream& operator<<(ostream& os, const Angajati& angajat)
    {
        os << "Nume: " << angajat.Nume << endl;
        os << "Prenume: " << angajat.Prenume << endl;
        os << "Post: " << angajat.post << endl;
        os << "Salariu: " << angajat.salariu << endl;
        return os;
    }

    // Suprascrierea operatorului >> pentru citirea datelor
    friend istream& operator>>(istream& is, Angajati& angajat)
    {
        cout << "Nume: ";
        is >> angajat.Nume;
        cout << "Prenume: ";
        is >> angajat.Prenume;
        cout << "Post: ";
        is >> angajat.post;
        cout << "Salariu: ";
        is >> angajat.salariu;
        return is;
    }

    // Suprascrierea operatorului == pentru comparația de egalitate
    bool operator==(const Angajati& other) const
    {
        return (Nume == other.Nume && Prenume == other.Prenume && post == other.post && salariu == other.salariu);
    }
    // Suprascrierea operatorului de atribuire
    Angajati& operator=(const Angajati& other)
    {
        if (this != &other)   // Check for self-assignment
        {
            Nume = other.Nume;
            Prenume = other.Prenume;
            post = other.post;
            salariu = other.salariu;
        }
        return *this;
    }





};



class Comanda
{
private:
    int idComanda;
    static int CONTOR_ID;
    vector<string> preparate;
    int* cantitati;

public:
    // Constructor implicit
    Comanda() : idComanda(++CONTOR_ID), cantitati(nullptr) {}

    // Constructor cu un singur parametru
    Comanda(const vector<string>& preparate) : idComanda(++CONTOR_ID), preparate(preparate), cantitati(nullptr) {}

    // Constructor cu doi parametri
    Comanda(const vector<string>& preparate, const vector<int>& cantitati) : idComanda(++CONTOR_ID), preparate(preparate)
    {
        if (preparate.size() != cantitati.size())
        {
            throw invalid_argument("Preparate and Cantitati sizes do not match");
        }
        this->cantitati = new int[preparate.size()];
        for (int i = 0; i < preparate.size(); ++i)
        {
            this->cantitati[i] = cantitati[i];
        }
    }

    // Constructor de copiere
    Comanda(const Comanda& other) : idComanda(other.idComanda), preparate(other.preparate)
    {
        if (other.cantitati != nullptr)
        {
            cantitati = new int[preparate.size()];
            for (int i = 0; i < preparate.size(); ++i)
            {
                cantitati[i] = other.cantitati[i];
            }
        }
        else
        {
            cantitati = nullptr;
        }
    }

    // Operatorul de citire
    friend istream& operator>>(istream& in, Comanda& comanda)
    {
        cout << "Introduceti numarul de preparate: ";
        int numarPreparate;
        in >> numarPreparate;

        cout << "Introduceti preparatele:\n";
        comanda.preparate.resize(numarPreparate);
        comanda.cantitati = new int[numarPreparate];
        for (int i = 0; i < numarPreparate; ++i)
        {
            cout << "Preparatul " << i + 1 << ": ";
            in >> comanda.preparate[i];
            cout << "Cantitatea pentru " << comanda.preparate[i] << ": ";
            in >> comanda.cantitati[i];
        }

        return in;
    }

    // Operatorul de afișare
    friend ostream& operator<<(ostream& out, const Comanda& comanda)
    {
        out << "Comanda #" << comanda.idComanda << ":\n";
        for (size_t i = 0; i < comanda.preparate.size(); ++i)
        {
            out << "Preparatul: " << comanda.preparate[i] << ", Cantitate: " << comanda.cantitati[i] << "\n";
        }
        return out;
    }

    Comanda& operator=(const Comanda& other)
    {
        if (this != &other)
        {
            idComanda = other.idComanda;
            preparate = other.preparate;
            // Dealocarea resursei alocate dinamic pentru cantitati (dacă este cazul)
            delete[] cantitati;
            // Realocarea și copierea cantitatilor
            cantitati = new int[preparate.size()];
            for (int i = 0; i < preparate.size(); ++i)
            {
                cantitati[i] = other.cantitati[i];
            }
        }
        return *this;
    }
    // Suprascrierea operatorului ==
    bool operator==(const Comanda& other) const
    {
        return idComanda == other.idComanda && preparate == other.preparate;
    }

    // Suprascrierea operatorului <
    bool operator<(const Comanda& other) const
    {
        return idComanda < other.idComanda;
    }

    // Suprascrierea operatorului >
    bool operator>(const Comanda& other) const
    {
        return idComanda > other.idComanda;
    }
    // Operatorul de indexare
    int operator[](int index) const
    {
        if (index >= preparate.size())
        {
            throw out_of_range("Index out of range");
        }
        return cantitati[index];
    }

    // Operatorul de conversie către șir de caractere
    operator string() const
    {
        string str = "Comanda #" + to_string(idComanda) + ": ";
        for (size_t i = 0; i < preparate.size(); ++i)
        {
            str += preparate[i] + " - " + to_string(cantitati[i]) + " buc; ";
        }
        return str;
    }
    Comanda operator+(const PreparatMeniu& preparat) const
    {
        Comanda result(*this); //
        result.preparate.push_back(preparat.getNumePreparat()); //// Adaugă numele preparatului din obiectul PreparatMeniu
        int* cantitatiCopy = new int[result.preparate.size()];
        for (size_t i = 0; i < result.preparate.size() - 1; ++i)
        {
            cantitatiCopy[i] = result.cantitati[i];
        }
        cantitatiCopy[result.preparate.size() - 1] = 1; // Setare cantitate pentru preparatul nou adăugat
        delete[] result.cantitati;
        result.cantitati = cantitatiCopy; // Actualizare vector de cantități
        return result;
    }


    ~Comanda()
    {
        delete[] cantitati;
    }

};
int MasaRestaurant::CONTORID=1;
int PreparatMeniu::CONTORID=1;
int Comanda::CONTOR_ID = 0;

vector<MasaRestaurant> mese;
vector<Comanda> comenzi;
vector<Angajati> angajati;
vector<PreparatMeniu> preparate;

void adaugaMasa()
{
    MasaRestaurant masa;
    cin >> masa;
    mese.push_back(masa);
}

void adaugaComanda()
{
    Comanda comanda;
    cin >> comanda;
    comenzi.push_back(comanda);
}

void adaugaAngajat()
{
    Angajati angajat;
    cin >> angajat;
    angajati.push_back(angajat);
}

void adaugaPreparat()
{
    PreparatMeniu preparat;
    cin >> preparat;
    preparate.push_back(preparat);
}

void afiseazaMese()
{
    cout << "\n=== Mese ===" << endl;
    for (const auto& masa : mese)
    {
        cout << masa << endl;
    }
}

void afiseazaComenzi()
{
    cout << "\n=== Comenzi ===" << endl;
    for (const auto& comanda : comenzi)
    {
        cout << comanda << endl;
    }
}

void afiseazaAngajati()
{
    cout << "\n=== Angajati ===" << endl;
    for (const auto& angajat : angajati)
    {
        cout << angajat << endl;
    }
}

void afiseazaPreparate()
{
    cout << "\n=== Preparate ===" << endl;
    for (const auto& preparat : preparate)
    {
        cout << preparat << endl;
    }
}

int main()
{
    char optiune;

    do
    {
        cout << "\n======= Sistem de Management al Restaurantului =======\n";
        cout << "1. Adauga Masa\n";
        cout << "2. Adauga Comanda\n";
        cout << "3. Adauga Angajat\n";
        cout << "4. Adauga Preparat\n";
        cout << "5. Afiseaza Mese\n";
        cout << "6. Afiseaza Comenzi\n";
        cout << "7. Afiseaza Angajati\n";
        cout << "8. Afiseaza Preparate\n";
        cout << "9. Iesire\n";
        cout << "=====================================================\n";
        cout << "Introdu optiunea: ";
        cin >> optiune;

        switch (optiune)
        {
        case '1':
            adaugaMasa();
            break;
        case '2':
            adaugaComanda();
            break;
        case '3':
            adaugaAngajat();
            break;
        case '4':
            adaugaPreparat();
            break;
        case '5':
            afiseazaMese();
            break;
        case '6':
            afiseazaComenzi();
            break;
        case '7':
            afiseazaAngajati();
            break;
        case '8':
            afiseazaPreparate();
            break;
        case '9':
            cout << "Iesire din program...\n";
            break;
        default:
            cout << "Optiune invalida! Te rog introdu o optiune valida.\n";
        }
    }
    while (optiune != '9');
    return 0;
}
