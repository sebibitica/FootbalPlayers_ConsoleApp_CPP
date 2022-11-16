#include "functii.h"

using namespace std;

//fisierul cu jucatori si detalii despre ei
ifstream juc("jucatori.txt");
//fisierul cu echipe si detalii despre acestea
ifstream ech("echipe.txt");
//cu aceasta putem scrie in continuare in fisier, noi jucatori
ofstream out("jucatori.txt", ofstream::app);
//cu aceasta putem scrie in continuare in fisier, noi echipe
ofstream oute("echipe.txt", ofstream::app);

//CITIREA JUCATORILOR DIN FISIERUL "jucatori.txt"
void citireJuc(jucatori j[100], int &nrJuc){
	juc>>nrJuc;
	for(int i=1;i<=nrJuc;i++){
		juc>>j[i].nume>>j[i].prenume;
		juc>>j[i].varsta>>j[i].echipa;
		juc>>j[i].goluri>>j[i].pozitie;
	}

}

//AFISEAZA INTREAGA LISTA DE JUCATORI(NUME PRENUME)
void afisareJucFull(jucatori j[100],int nrJuc){
	cout<<"Lista full jucatori:\n";
	for(int i=1;i<=nrJuc;i++){
		cout<<"-->"<<j[i].nume<<" "<<j[i].prenume<<endl;
	}
}

//AFISAREA DETALIILOR(din baza de date) A UNUI JUCATOR CITIT DE LA TASTATURA
void afisareJuc(jucatori j[100],char numeJucator[20],char prenumeJucator[20], int nrJuc){
	cout<<"nume: ";cin>>numeJucator;
	cout<<"prenume: ";cin>>prenumeJucator;
	int gasit=0;
	for(int i=1;i<=nrJuc;i++){
		if(strcmp(j[i].nume,numeJucator)==0 && strcmp(j[i].prenume,prenumeJucator)==0){
			gasit=1;
			cout<<j[i].nume<<" "<<j[i].prenume;
			cout<<", "<<j[i].varsta<<" ani, "<<j[i].echipa;
			cout<<", "<<j[i].goluri<<" goluri, "<<j[i].pozitie;
			cout<<endl;
		}
	}
	if(gasit==0)
		cout<<"Jucatorul nu se afla in baza de date!"<<endl;
}

//FUNCTIA SORTEAZA JUCATORII IN FUNCTIE DE NR DE GOLURI
//SI AFISEAZA PRIMII 3 JUCATORI CU CELE MAI MULTE GOLURI
void top3Juc(jucatori j[100],int nrJuc){
	sortareJucatori(j,nrJuc);
	for(int i=1;i<=3;i++){
		cout<<j[i].nume<<" "<<j[i].prenume<<" -> ";
		cout<<j[i].goluri<<" goluri"<<endl;
	}
}

void adaugareJuc(jucatori j[100],int &nrJuc){
	nrJuc++;
	//out -> scrie noii jucatori introdusi de la tastatura
	//si in fisierul jucatori.txt, trebuind doar sa se schimbe numarul Jucatorilor cu +1
	out<<endl;
	cout<<"nume:";cin>>j[nrJuc].nume;out<<j[nrJuc].nume<<" ";
	cout<<"prenume:";cin>>j[nrJuc].prenume;out<<j[nrJuc].prenume<<" ";
	cout<<"varsta:";cin>>j[nrJuc].varsta;out<<j[nrJuc].varsta<<" ";
	cout<<"echipa:";cin>>j[nrJuc].echipa;out<<j[nrJuc].echipa<<" ";
	cout<<"goluri:";cin>>j[nrJuc].goluri;out<<j[nrJuc].goluri<<" ";
	cout<<"pozitie:";cin>>j[nrJuc].pozitie;out<<j[nrJuc].pozitie;
	cout<<"NOUL JUCATOR A FOST INTRODUS!"<<endl;
}

void stergereJuc(jucatori j[100], int &nrJuc){
	int gasit=0;
	char numeJucSters[20],prenumeJucSters[20];
	cout<<"nume:";cin>>numeJucSters;
	cout<<"prenume:";cin>>prenumeJucSters;
	for(int i=1;i<=nrJuc && gasit==0;i++){
		if(strcmp(numeJucSters,j[i].nume)==0 && strcmp(prenumeJucSters,j[i].prenume)==0){
			gasit=1;
			for(int q=i;q<nrJuc;q++)
				j[q]=j[q+1];
			nrJuc--;
		}
	}
	if(gasit==0)
		cout<<"Jucatorul nu se afla in baza de date!"<<endl;
	else
		cout<<"Jucatorul a fost sters cu succes din baza de date!"<<endl;
}

//CITIREA ECHIPELOR DIN FISIERUL"echipe.txt"
void citireEch(echipe e[50], int &nrEch){
	ech>>nrEch;
	for(int i=1;i<=nrEch;i++){
		ech>>e[i].nume>>e[i].nrCampionate;
		ech>>e[i].nrJucatori;
		for(int q=1;q<=e[i].nrJucatori;q++){
			ech>>e[i].numeJuc[q];
			ech>>e[i].prenumeJuc[q];
		}
	}
}

void afisareFullEchipe(echipe e[50],int nrEch){
	cout<<"Lista cu numele echipelor:"<<endl;
	for(int i=1;i<=nrEch;i++){
		cout<<e[i].nume<<endl;
	}
	cout<<endl;
}

//AFISAREA DETALIILOR UNEI ECHIPE CITITE DE LA TASTATURA
void afisareEch(echipe e[50],char numeEchipa[20],int nrEch){
	cout<<"nume echipa: ";cin>>numeEchipa;
	int gasit=0;
	for(int i=1;i<=nrEch;i++){
		if(strcmp(e[i].nume,numeEchipa)==0){
			gasit=1;
			cout<<e[i].nume<<", "<<e[i].nrCampionate<<" campionate castigate, "<<endl;
			cout<<e[i].nrJucatori<<" jucatori ai echipei:"<<endl;
			for(int q=1;q<=e[i].nrJucatori;q++){
				cout<<q<<"."<<e[i].numeJuc[q]<<" "<<e[i].prenumeJuc[q]<<endl;
			}
		}
	}
	if(gasit==0)
		cout<<"Echipa nu se afla in baza de date!"<<endl;
}

//FUNCTIA SORTEAZA ECHIPELE IN FUNCTIE DE NR CAMPIONATELOR
//SI AFISEAZA PRIMELE 3 ECHIPE CU CELE MAI MULTE CAMPIONATE
void top3Ech(echipe e[50],int nrEch){
	sortareEchipa(e,nrEch);
	for(int i=1;i<=3;i++){
		cout<<e[i].nume<<" -> ";
		cout<<e[i].nrCampionate<<" campionate castigate"<<endl;
	}
}

void adaugareEch(echipe e[50], int &nrEch){
	nrEch++;
	//oute -> scrie in fisierul echipe.txt noua echipa
	//ramanand doar sa se schimbe manul numarul Echipelor cu +1
	oute<<endl;
	cout<<"nume:";cin>>e[nrEch].nume;oute<<e[nrEch].nume<<" ";
	cout<<"Numar Campionate Castigate:";cin>>e[nrEch].nrCampionate;oute<<e[nrEch].nrCampionate<<" ";
	cout<<"Numar Jucatori de inregistrati:";cin>>e[nrEch].nrJucatori;oute<<e[nrEch].nrJucatori<<endl;
	for(int q=1;q<=e[nrEch].nrJucatori;q++){
		cout<<"Jucator "<<q<<" nume:";cin>>e[nrEch].numeJuc[q];oute<<e[nrEch].numeJuc[q]<<" ";
		cout<<"Jucator "<<q<<" prenume:";cin>>e[nrEch].prenumeJuc[q];oute<<e[nrEch].prenumeJuc[q]<<endl;
	}
	oute<<endl;
}

void stergereEch(echipe e[50], int &nrEch){
	int gasit=0;
	char numeEchipaSters[20];
	cout<<"numele echipei:";cin>>numeEchipaSters;
	for(int i=1;i<=nrEch && gasit==0;i++){
		if(strcmp(numeEchipaSters,e[i].nume)==0){
			gasit=1;
			for(int q=i;q<nrEch;q++)
				e[q]=e[q+1];
			nrEch--;
		}
	}
	if(gasit==0)
		cout<<"Echipa de sters nu este in baza de date."<<endl;
	else
		cout<<"Echipa a fost stearsa cu succes din baza de date."<<endl;
}

void afisareEchipaJucatorului(jucatori j[100],echipe e[50],int nrJuc, int nrEch,char numeJucator[20],char prenumeJucator[20]){
	if(existaEchipaJucatorului(j,e,nrJuc,nrEch,numeJucator,prenumeJucator)){
		int indice=existaEchipaJucatorului(j,e,nrJuc,nrEch,numeJucator,prenumeJucator);
		cout<<"Datele despre Echipa Jucatorului: "<<endl;
		cout<<e[indice].nume<<", "<<e[indice].nrCampionate<<" campionate castigate, "<<endl;
		cout<<e[indice].nrJucatori<<" jucatori ai echipei:"<<endl;
		for(int y=1;y<=e[indice].nrJucatori;y++){
			cout<<e[indice].numeJuc[y]<<" "<<e[indice].prenumeJuc[y]<<endl;
		}
	}
	else
		cout<<"Echipa Jucatorului nu se afla in baza de date!"<<endl;
}

void afisareJucatorulEchipei(jucatori j[100],echipe e[50],char numeEchipa[20],int nrinitiala,int nrJuc,int nrEch){
	if(existaJucatorulEchipei(j,e,numeEchipa,nrinitiala,nrJuc,nrEch)){
		int indice=existaJucatorulEchipei(j,e,numeEchipa,nrinitiala,nrJuc,nrEch);
		cout<<"Datele despre Jucator:"<<endl;
		cout<<j[indice].nume<<" "<<j[indice].prenume;
		cout<<", "<<j[indice].varsta<<" ani, "<<j[indice].echipa;
		cout<<", "<<j[indice].goluri<<" goluri, "<<j[indice].pozitie;
		cout<<endl;
	}
	else
		cout<<"Jucatorul respectiv nu se afla in baza de date!"<<endl;
}
