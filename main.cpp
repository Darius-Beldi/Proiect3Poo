#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <list>
#include <bits/stdc++.h>
#include <set>
using namespace std;

class IOInterface{

public:
    virtual void afisare() const = 0;
    virtual void citire() = 0;
};

class Bon;
class Medicament : public IOInterface{

protected:
    string nume;
    float pret;
    int stoc;


public:

    //constructors
    Medicament();                //CD
    Medicament(string, float, int);   //CT
    Medicament(const Medicament& obj); //CC

    Medicament operator=(const Medicament&);

    //getters
    string getnume();
    float getpret();
    virtual string getcodReteta(){
        return "nu are cod";
    }
    int getstoc();

    void decreaseStoc(){
        --stoc;
    }


    virtual void citire();
    virtual void afisare() const;

    Bon operator+(Bon);

    friend ostream& operator<<(ostream& out, Medicament& obj){
        obj.afisare();
        return out;
    };
    friend istream& operator>>(istream& in, Medicament& obj){
        obj.citire();
        return in;
    };
    virtual ~Medicament(){};
};

Medicament::Medicament() : nume("nume"), pret(0) {};
Medicament::Medicament(string nume, float pret, int stoc) : nume(nume), pret(pret), stoc(stoc) {};
Medicament::Medicament(const Medicament &obj) : nume(obj.nume), pret(obj.pret){};

void Medicament::afisare() const{
    cout << "Nume medicament: " << nume << endl;
    cout << "Pret medicament: " << pret << endl;
    cout << "Stoc medicament: " << stoc << endl;
}

void Medicament :: citire(){
    cout << "Nume produs: "; cin >> nume;
    cout << "Pret brut: "; cin >> pret;
    cout << "Stoc: "; cin >> stoc;
}
//getters

string Medicament::getnume() {
    return this -> nume;
}
float Medicament::getpret() {
    return this -> pret;
}
int Medicament::getstoc(){
    return this->stoc;
}


class Antiinflamator : public Medicament{

protected:
    string substanta;

public:
    Antiinflamator():Medicament(){
        this -> substanta = "substanta";
    }
    Antiinflamator(string nume, float pret, int stoc, string substanta):Medicament(nume, pret, stoc){
        this -> substanta = substanta;
    }
    Antiinflamator(Antiinflamator& obj):Medicament(obj){
        this -> substanta = obj.substanta;
    }

    friend ostream& operator<<(ostream& out, Antiinflamator& obj){
        obj.afisare();
        return out;
    };
    friend istream& operator>>(istream& in, Antiinflamator& obj){
        obj.citire();
        return in;
    };

    string getsubstanta(){
        return substanta;
    }

    void citire();
    void afisare() const;


    ~Antiinflamator(){};
};

void Antiinflamator::citire(){
    Medicament::citire();
    cout << "Substanta: ";
    cin >> substanta;
}

void Antiinflamator::afisare() const{
    Medicament::afisare();
    cout << "Substanta: " << substanta;
}

class Suplimentalimentar : public Medicament{

protected:
    vector <string> vitamine;

public:
    Suplimentalimentar():Medicament(){
        this -> vitamine = {"A", "A+", "B12", "C"};
    }
    Suplimentalimentar(string nume, float pret, int stoc, vector <string> vitamine):Medicament(nume, pret, stoc){
        this -> vitamine = vitamine;
    }
    Suplimentalimentar(Suplimentalimentar& obj):Medicament(obj){
        this -> vitamine = obj.vitamine;
    }

    friend ostream& operator<<(ostream& out, Suplimentalimentar& obj){
        obj.afisare();
        return out;
    };
    friend istream& operator>>(istream& in, Suplimentalimentar& obj){
        obj.citire();
        return in;
    };

    vector<string> getVitamine(){
        return vitamine;
    }

    void citire();
    void afisare() const;


    ~Suplimentalimentar(){};
};

void  Suplimentalimentar::citire(){
    Medicament::citire();
    int numarVitamine;
    cout << "Numar vitamine: "; cin >> numarVitamine;
    cout <<"Introduceti vitaminele: \n";
    string temp;
    for(int i = 0; i<numarVitamine; i++){
        cin >> temp;
        vitamine.push_back(temp);
    }
}

void  Suplimentalimentar::afisare() const{
    Medicament::afisare();
    cout << "Vitamine: ";
    for(int i=0;i<vitamine.size()-1;i++)
        cout << vitamine[i] << ", ";
   cout << vitamine[vitamine.size()-1];
}


class AntiinflamatorCuReteta : public Antiinflamator{

protected:
    string codReteta;

public:
    AntiinflamatorCuReteta():Antiinflamator(){
        this -> codReteta = "codReteta";
    }
    AntiinflamatorCuReteta(string nume, float pret,  int stoc, string substanta, string codReteta):Antiinflamator(nume, pret, stoc, substanta){
        this -> codReteta = codReteta;
    }
    AntiinflamatorCuReteta(AntiinflamatorCuReteta& obj):Antiinflamator(obj){
        this -> codReteta = obj.codReteta;
    }

    friend ostream& operator<<(ostream& out, AntiinflamatorCuReteta& obj){
        obj.afisare();
        return out;
    };
    friend istream& operator>>(istream& in, AntiinflamatorCuReteta& obj){
        obj.citire();
        return in;
    };

    void citire();
    void afisare() const;

    string getcodReteta(){
        return codReteta;
    }
    ~AntiinflamatorCuReteta(){};
};

void  AntiinflamatorCuReteta::citire(){
    Antiinflamator::citire();
    cout << "Cod reteta: ";
    cin >> codReteta;
}

void  AntiinflamatorCuReteta::afisare() const{
    Antiinflamator::afisare();
    cout << "\nMedicament cu reteta\n";

}

class Bon{

    static int idBon;
    int numarBon;
    map <string, int> medicamente;
    list <float> preturi;
    double pretFinal;


public:

    friend ostream &operator<<(ostream &,  Bon &);
    friend istream &operator>>(istream &, Bon &);
    friend Bon Medicament::operator+(Bon);

//CONSTRUCTORI

    Bon();                                  //constructorul fara parametrii
    Bon(int, double, map<string,int>, list<float>); //constructorul cu toti parametrii
    Bon(const Bon &);                       //Copy constructer


    int getidBon(){
        return idBon;
    }
    //supraincarcare operatori
    Bon& operator+(Medicament);
    Bon operator=(const Bon &);
    //destructor
    ~Bon(){
    }

    double getpretFinal();
    void addToPret(float);

};

//Constructori
Bon::Bon():numarBon(idBon++),pretFinal(0),medicamente(){}//constructorul fara parametrii
Bon::Bon(int numarBon, double pretFinal, map<string,int> medicamente, list<float> preturi) : numarBon(numarBon),pretFinal(pretFinal),medicamente(medicamente), preturi(preturi){}//constructorul cu toti parametrii
Bon::Bon(const Bon &obj) : pretFinal(obj.pretFinal), numarBon(obj.numarBon),medicamente(obj.medicamente) {}       //copy constructor

int Bon::idBon = 1124;

Bon Bon::operator=(const Bon &obj){

    if(this -> numarBon != obj.numarBon)
        this->numarBon = obj.numarBon;
    if(this -> medicamente != obj.medicamente)
        this->medicamente = obj.medicamente;
    if(this -> preturi != obj.preturi)
        this->preturi = obj.preturi;
    if(this -> pretFinal != obj.pretFinal)
        this->pretFinal = obj.pretFinal;

    return *this;
}

ostream& operator<<(ostream &out,  Bon &obj){
    system("cls");
    out << "+-------------------------------------+\n"
           "|                                     |\n"
           "|                                     |\n";
    out << "|          "<<"Numar bon: " << obj.idBon <<"            |\n";
    out << "|                                     |\n"
           "|                                     |\n";


    auto it = obj.medicamente.begin();
    auto it2 = obj.preturi.begin();
    float pretF = 0;
    int finalSize = 0;
    while(it!=obj.medicamente.end()) {
        string spaces ;
        if (it->second >= 100){
            string generator(25 - it->first.size(), ' ');
            spaces = generator;
        }
        else {
            string generator(26 - it->first.size(), ' ');
            spaces = generator;
        }

        out << "|  " <<it->first << " x" << it->second << spaces << it->second * (*it2) << " |\n";
        pretF += it->second * (*it2);
        finalSize+=it->second;
        it++;
        it2++;

    }

    out << "|                                     |\n";
    out << "|  TOTAL                     " << pretF;
    if (pretF>=100)
        out << "   |\n";
    else
        out << "    |\n";
    out << "|                                     |\n"
           "|  Item Count:  "<<finalSize <<"                     |\n"
                                                             "|                                     |\n"
                                                             "|              MULTUMIM!              |\n"
                                                             "+-------------------------------------+";

    out << endl;
    return out;
}

istream &operator>> (istream &in, Bon &obj ){
    cout << "Numar bon: "; in >> obj.numarBon;
    int size;
    string temp;
    float temp2;
    cout << "Numar de medicamente"; in >> size;
    for(int i = 0; i < size; i++){

        cout << "Nume Medicament: "; in >> temp;
        cout << "Pret: "; in >> temp2;
        obj.medicamente.insert(pair<string, float>(temp, temp2));
        obj.pretFinal += temp2;
    }
    return in;
}



//De aici incepe functionalitate

Bon& Bon::operator+(Medicament obj) {

    if(this->medicamente.find(obj.getnume()) != this->medicamente.end()) {
        this->medicamente[obj.getnume()]++;

    }
    else {
        this->medicamente.insert(pair<string, int>(obj.getnume(), 1));
        this->preturi.push_back(obj.getpret());
    }
    return *this;
}
Bon Medicament::operator+(Bon bon) {

   if(bon.medicamente.find(this->nume) != bon.medicamente.end()) {
       bon.medicamente[this->nume]++;

   }
   else {
       bon.medicamente.insert(pair<string, int>(this->nume, 1));
       bon.preturi.push_back(this->pret);
   }

   return bon;
}


double Bon::getpretFinal() {
    return this -> pretFinal;
}

void Bon::addToPret(float pret){
    this -> pretFinal += pret;
}

class Meniu
{

private:

    static Meniu* instance;
    vector <Medicament*> vectorMedicamente;
    set<string> numePrenume;
    float pretFinal;
    Meniu() {}

public:

    static Meniu* getInstance()
    {
        if(Meniu::instance != NULL)
        {
            return Meniu::instance;
        }
        else
        {
            instance = new Meniu();
            return instance;
        }
    }

    void meniu();
    vector<string> split (const string& , char );
    void inputF(const string&);
    int selectInput();
    void manualInput();
    void pacient();
    void start();
};

void Meniu::meniu(){

//start menu
    int exit = 0;
    while (exit != 1) {
        system("cls");
        cout << "Buna ziua! Va rugam sa completati datele dumneavoasta: " << endl;
        pacient();
        system("cls");
        cout << "Bine ati venit! Selectati adresa farmaciei dorite: " << endl;
        cout << "1) Strada Lacul Ursului nr. 18" << endl;
        cout << "2) Exit" << endl;
        string selects;
        int select;
        int ok = 0;
        while(ok==0) {
            cin >> selects;
            try {
                select = stoi(selects);
            }
            catch (invalid_argument) {
                cout << "Introduceti o optiune valida\n";
            }
            if(select == 1 || select == 2)
                ok = 1;
        }
        switch (select) {
            case 1: {
                Bon bon1;
                //vector<string> medicamenteSelectate;
                int ok = 1;
                system("cls");
                while (ok) {

                    cout << "Stocul farmaciei: " << endl;
                    for (int i = 0; i < size(vectorMedicamente); i++) {

                        string dots(50 - vectorMedicamente[i]->getnume().size(), '.');
                        cout << i + 1 << ")" << vectorMedicamente[i]->getnume() << dots
                             << vectorMedicamente[i]->getpret() << " lei" << "............ In Stoc: "
                             << vectorMedicamente[i]->getstoc() << endl;
                    }


                    cout << size(vectorMedicamente) + 1 << ") Finalizare comanda" << endl;
                    cout << "Alegeti medicamentul: ";
                    string selects;
                    int select;
                    int okk = 0;
                    while(okk==0) {
                        cin >> selects;
                        try {
                            select = stoi(selects);
                        }
                        catch (invalid_argument) {
                            cout << "Introduceti o optiune valida\n";
                        }
                        if(select > 0 && select <= size(vectorMedicamente)+1 || select-1 >= 100 && select-1 <size(vectorMedicamente) + 100)
                            okk = 1;
                    }
                    system("cls");
                    if (select > 0 && select <= size(vectorMedicamente)) {

                        if (dynamic_cast<AntiinflamatorCuReteta*>(vectorMedicamente[select - 1]) != nullptr)
                        {
                            string codIntrodus;
                            cout << "Introduceti codul retetei: "; cin >> codIntrodus;
                            if(codIntrodus == vectorMedicamente[select - 1]->getcodReteta()){
                                //medicamenteSelectate.push_back(vectorMedicamente[select - 1]->getnume());
                                bon1 = bon1 + *vectorMedicamente[select - 1];
                                vectorMedicamente[select - 1]->decreaseStoc();
                                cout << "Medicamentul a fost adaugat in cos. Pretul total este de: " << bon1.getpretFinal()
                                     << " lei" << endl;
                            }
                            else
                                cout << "Cod Gresit\n";

                        }
                        else{
                            try{
                                if(vectorMedicamente[select - 1]->getstoc() == 0)
                                    throw "Stoc epuizat";
                                else{
                                    bon1.addToPret(vectorMedicamente[select - 1]->getpret());
                                    bon1 = bon1 + *vectorMedicamente[select-1];
                                    vectorMedicamente[select - 1]->decreaseStoc();
                                    cout << "Medicamentul a fost adaugat in cos. Pretul total este de: " << bon1.getpretFinal()
                                         << " lei" << endl;
                                }
                            }
                            catch(const char* msg){
                                cout << msg << endl;
                            }

                        }


                    } else {
                        if(select-1 > 100 && select-1 <size(vectorMedicamente) + 100){
                            system("cls");
                            cout << *vectorMedicamente[select-101] << endl;
                        }else{
                            if (select == size(vectorMedicamente) + 1) {system("cls");
                                int bon;
                                cout << "Doriti bonul?" << endl;
                                cout << "0) Nu" << endl;
                                cout << "1) Da" << endl;
                                cin >> bon;
                                switch (bon) {
                                    case 0: {
                                        cout << "Total: " << bon1.getpretFinal();
                                        cout << "Va multumim!";
                                    }
                                    case 1: {
                                        string numeFisier = "../bonuri/";
                                        for(auto it = numePrenume.begin(); it != numePrenume.end(); it++){
                                            numeFisier += *it + " ";
                                        }
                                        numeFisier += to_string(bon1.getidBon()) + ".txt";
                                        ofstream fisier(numeFisier);
                                        fisier << bon1;
                                        cout << bon1;
                                        fisier.close();
                                    }
                                    default:{
                                        cout<<"Introduceti o optiune valida\n";
                                    }
                                }
                                ok = 0;
                            }
                            cin >> select;
                        }}


                }
                break;
            }


            case 2:{
                system("cls");
                cout << "Zi buna!";
                exit = 1;
            }
        }
    }
}

vector<string> Meniu::split (const string& str, char separator)
{
    string s;
    stringstream ss(str);
    vector<string> v;
    while (getline(ss, s, separator)) {
        v.push_back(s);
    }
    return v;
}

void Meniu::inputF(const string& inputFile){

    ifstream file(inputFile);
    string line;
    while(getline(file, line)){
        vector <string> linie;
        linie = split(line,',');
        //Acum am in linie fiecare linie splituita intr un vector
        if(linie[0] == "1") // Codul 1 pentru Suplimentalimentar
        {
            vector <string> vitamineDeAdaugat;
            for(int i = 4;i<linie.size();i++){
                vitamineDeAdaugat.push_back(linie[i]);
            }
            Suplimentalimentar *p = new Suplimentalimentar(linie[1], stof(linie[2]), stoi(linie[3]), vitamineDeAdaugat);
            vectorMedicamente.push_back(p);
        }
        if(linie[0]=="2") //Codul 2 pentru Anti-inflamator simplu
        {
            Antiinflamator *p = new Antiinflamator(linie[1], stof(linie[2]), stoi(linie[3]), linie[4]);
            vectorMedicamente.push_back(p);
        }
        if(linie[0]=="3") //Codul 3 pentru Anti-inflamator cu reteta
        {
            AntiinflamatorCuReteta *p = new AntiinflamatorCuReteta(linie[1], stof(linie[2]), stoi(linie[3]), linie[4], linie[5]);
            vectorMedicamente.push_back(p);
        }
    }


}

int Meniu::selectInput(){
    cout << "Doriti sa incarcati datele dintr-un fisier?" << endl;
    cout << "1) Da" << endl;
    cout << "2) Nu" << endl;
    string select;
    int selectInt=3;
    bool ok = 1;
    while(ok){
        cin >> select;
        try {
            selectInt=stoi(select);
        }
        catch(invalid_argument){
            cout << "Introduceti o optiune valida\n" ;
        }
        if(selectInt == 1  || selectInt == 2)
            ok = 0;
    }
    return selectInt;
}

void Meniu::manualInput(){
    string text;
    int stillAdding = 1;
    while(stillAdding == 1){
        cout << "Ce tip de medicament doriti sa adaugati?\n";
        cout << "1) Supliment alimentar\n";
        cout << "2) Anti-inflamator fara reteta\n";
        cout << "3) Anti-inflamator cu reteta\n";
        cout << "4) Exit\n";
        string select;
        int selectInt;
        int ok = 1;
        while(ok){


            cin >> select;
            try {
                selectInt=stoi(select);
            }
            catch(invalid_argument){
                cout<< "Introduceti o optiune valida\n" ;
            }
            if(selectInt > 0 && selectInt < 5)
                ok = 0;
        }
        switch(selectInt) {
            case 1: {
                Suplimentalimentar* p = new Suplimentalimentar();
                p->citire();
                vectorMedicamente.push_back(p);
                text = text + "1," + p->getnume() + "," + to_string(p->getpret()) + "," + to_string(p->getstoc());
                for(int i = 0; i < p->getVitamine().size(); i++){
                    text += "," + p->getVitamine()[i];
                }
                text = text + "\n";
                break;
            }
            case 2: {
                Antiinflamator* p= new Antiinflamator();
                p->citire();
                vectorMedicamente.push_back(p);
                text = text + "2," + p->getnume() + "," + to_string(p->getpret()) + "," + to_string(p->getstoc()) + "," + p->getsubstanta() +"\n";
                break;
            }
            case 3: {
                AntiinflamatorCuReteta* p= new AntiinflamatorCuReteta();
                p->citire();
                vectorMedicamente.push_back(p);
                text = text + "3," + p->getnume() + "," + to_string(p->getpret()) + "," + to_string(p->getstoc()) + "," + p->getsubstanta() + "," + p->getcodReteta() + "\n";
                break;
            }
            case 4: {
                stillAdding = 0;
                break;
            }
            default: {
                cout<< "Introduceti o optiune valida\n" ;
            }
        }

    }

    string select;
    int ok = 1;
    int selectInt;
    while(ok){
        system("cls");
        cout << "Doriti sa salvati medicamentele intr-un fisier?\n";
        cout << "1) Da\n";
        cout << "2) Nu\n";
        cin >> select;
        try {
            selectInt=stoi(select);
        }
        catch(invalid_argument){
            cout << "Introduceti o optiune valida\n" ;
        }
        if(selectInt >= 1 && selectInt <= 2)
            ok = 0;
    }
    if(selectInt == 1){
        cout << "Introduceti numele fisierului: ";
        string numeFisier;
        cin >> numeFisier;
        numeFisier = "../" + numeFisier;
        ofstream file(numeFisier);
        file << text;
        file.close();
    }
}

void Meniu::pacient(){
    system("cls");
    cout << "Introduceti numele: ";
    string temp;
    cin >> temp;
    numePrenume.insert(temp);
    cout << "Introduceti prenumele: ";
    cin >> temp;
    numePrenume.insert(temp);
}

void Meniu::start(){
    string numeFisier;
    if(selectInput() == 1) {
        cout << "Introduceti numele fisierului: ";
        cin >> numeFisier;
        numeFisier = "../" + numeFisier;
        inputF(numeFisier);
    }
    else
        manualInput();

    meniu();
}



Meniu* Meniu::instance=NULL;


int main(){

    Meniu* menu=Meniu::getInstance();

    menu -> start();


    return 0;
}