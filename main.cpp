#include "fotbal.h"

using namespace std;

//structura jucatorilor
jucatori j[100];
//structura echipelor
echipe e[50];
//numar de jucatori si numar de echipe
int nrJuc,nrEch;
//nume si prenume jucator pentru functia de afisare a unuia
char numeJucator[20], prenumeJucator[20];
//nume pentru functia de afisare a echipei
char numeEchipa[20];



int main(){
	citireJuc(j,nrJuc);
	citireEch(e,nrEch);
	int nr;//numarul optiunii
	char verif;//(y/n) pentru a verifica intoarcere la meniu
	do{
		cout<<"----------------------\n";
		cout<<"JUCATORI: \n";
		cout<<"----------------------\n";
		cout<<"1.Afisare jucator\n";
		cout<<"2.Top 3 al jucatorilor\n";
		cout<<"3.Adaugare jucator\n";
		cout<<"4.Stergere Jucator\n";
		cout<<"----------------------\n";
		cout<<"ECHIPE: \n";
		cout<<"----------------------\n";
		cout<<"5.Afisare echipa\n";
		cout<<"6.Top 3 echipe\n";
		cout<<"7.Adaugare echipa\n";
		cout<<"8.Stergere echipa\n";
		cout<<"----------------------\n";
		cout<<"9.IESIRE\n";
		cout<<"----------------------\n";
		cout<<"ALEGE OPTIUNEA:";cin>>nr;
		switch(nr){
			case 1:
				afisareJucFull(j,nrJuc);//Afiseaza lista full de jucatori
				cout<<"Introduceti jucatorul al carui date doriti sa le afisati:\n";
				afisareJuc(j,numeJucator,prenumeJucator,nrJuc);//Afiseaza date despre un anumit jucator
				cout<<endl;
				cout<<"Doresti sa aflii detalii despre echipa jucatorului?(y/n) : ";
				char yn;//(y/n) verifica daca se doreste afisarea echipei jucatorului
				cin>>yn;
				if(yn=='y'){
					cout<<endl;
					//se afiseaza detaliile echipei jucatorului
					afisareEchipaJucatorului(j,e,nrJuc,nrEch,numeJucator,prenumeJucator);
					break;
				}
				else
					break;
			case 2:
				cout<<"Top 3 Jucatori in functie de numarul golurilor:\n";
				top3Juc(j,nrJuc);
				break;
			case 3:
				cout<<"Introduceti datele noului jucator:\n";
				adaugareJuc(j,nrJuc);
				break;
			case 4:
				afisareJucFull(j,nrJuc);
				cout<<"Introdu numele si prenumele jucatorului de sters:\n";
				stergereJuc(j,nrJuc);
				break;
			case 5:
				afisareFullEchipe(e,nrEch);
				cout<<"Introduceti datele echipei de afisat:\n";
				afisareEch(e,numeEchipa,nrEch);
				cout<<endl;
				cout<<"Doresti sa aflii detalii despre un anumit jucator din echipa?(y/n) : ";
				char yn1;
				cin>>yn1;
				if(yn1=='y'){
					int nrinitiala;
					cout<<endl;
					cout<<"Introdu numarul jucatorului:";cin>>nrinitiala;
					cout<<endl;
					afisareJucatorulEchipei(j,e,numeEchipa,nrinitiala,nrJuc,nrEch);
					break;
				}
				else
					break;
			case 6:
				cout<<"Top 3 echipe in functie de numarul de campionate\n";
				top3Ech(e,nrEch);
				break;
			case 7:
				cout<<"Introduceti datele noii echipe:\n";
				adaugareEch(e,nrEch);
				break;
			case 8:
				afisareFullEchipe(e,nrEch);
				cout<<"Introduceti datele echipei de sters:\n";
				stergereEch(e,nrEch);
				break;
		}
		if(nr!=9){
			cout<<endl;
			cout<<"Doresti sa revii la meniu(y/n)? : ";
			cin>>verif;
		}
	}while(nr!=9 && verif=='y');
	return 0;
}