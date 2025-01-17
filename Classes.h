#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Transaction {
private:
	double sum;
	string data;
	string tip; //Venit sau Cheltuiala
	string categorie; //cumparaturi la magazin, mancare fast food, etc
	string descriere; //de unde vine venitul sau unde pleaca cheltuielile

public:
	// Constructori pentru clasa
	Transaction(double sum, const string& data, const string& tip, const string& cat, const string& desc) //Introduc manual detaliile
		: sum(sum), data(data), tip(tip), categorie(cat), descriere(desc) {} 
	Transaction() : sum(0), data(""), tip(""), categorie(""), descriere("") {} //Introduc la rulare detaliile
	~Transaction() {} //Destructor pentru clasa
	//Metode GET / SET
	//GET
	double getSuma() const {return sum;}
	string getData() const { return data;}
	string getTip() const { return tip;}
	string getCat() const { return categorie;}
	string getDesc() const { return descriere;}
	//SET
	void setSuma(double sum) { this->sum = sum; }
	void setData(const string& data) { this->data = data; }
	void setTip(const string& tip) { this->tip = tip; }
	void setCat(const string& cat) { this->categorie = cat; }
	void setDesc(const string& desc) { this->descriere = desc; }
	//Aratam detaliile tranzactiilor
	void detalii() const {
		cout << "Suma: " << sum << ", Data: " << data
			<< ", Tip: " << tip << ", Categorie: " << categorie
			<< ", Descriere: " << descriere << endl;
	}
	void read() {
		cout << "Introduceti suma: ";
		cin >> sum;
		cout << "Introduceti data (ex: YYYY-MM-DD): ";
		cin >> data;
		cout << "Introduceti tipul (Venit/Cheltuiala): ";
		cin >> tip;
		cout << "Introduceti categoria: ";
		cin >> categorie;
		cout << "Introduceti descrierea: ";
		cin.ignore(); 
		getline(cin, descriere);
	}
};

class Account {
private:
	string nume;
	double balanta;
	vector<Transaction> listaTranz; //aici va fi istoricul tranzactiilor

public:
	//Constructori
	Account(const string& nume, double balanta)
		: nume(nume), balanta(balanta) {}
	Account() : nume(""), balanta(0) {}
	~Account() {}

	//GET
	string getNume() const { return nume; }
	const vector<Transaction>& getListaTranz() const { return listaTranz; }
	double getBalanta() const { return balanta; }
	//SET
	void setNume(const string& nume) { this->nume = nume; }
	void setBalanta(double balanta) { this->balanta = balanta; }

	void AddTransaction(const Transaction& tranzactie) {
		listaTranz.push_back(tranzactie);
		if (tranzactie.getTip() == "Venit" || tranzactie.getTip() == "venit") {
			balanta += tranzactie.getSuma();
		}
		else if (tranzactie.getTip() == "Cheltuiala" || tranzactie.getTip() == "cheltuiala") {
			balanta -= tranzactie.getSuma();
		}
	}

	void AccountDetails() const {
		cout << "Nume: " << nume << ", Balanta: " << balanta << endl;
		cout << "Lista de tranzactii: " << endl;
		for (const auto& tranzactie : listaTranz) {
			tranzactie.detalii();
		}
	}

	void AccountRead() {
		cout << "Introduceti numele contului: ";
		cin >> nume;
		cout << "Introduceti balanta: ";
		cin >> balanta;
	}
};