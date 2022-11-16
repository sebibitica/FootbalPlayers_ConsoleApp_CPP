#include <bits/stdc++.h>

using namespace std;

//AICI SE DECLARA STRUCTURILE JUCATORI SI ECHIPE
//SI CATEVA FUNCTII MAI MICUTE(DE SORTARE,ETC)

//structura jucatorilor de fotbal
struct jucatori{
	char nume[20],prenume[20];
	char echipa[20],pozitie[20];
	int varsta;
	int goluri;
};

//structura echipelor de fotbal
struct echipe{
	char nume[20];
	int nrCampionate;
	int nrJucatori;
	char numeJuc[10][20],prenumeJuc[10][20];
};

//aceasta sorteaza in ordine descrescatoare
//echipele in functie de nr de campionate
//pentru TOP 3
void sortareEchipa(echipe e[50],int nrEch){
	for(int i=1;i<=nrEch;i++)
		for(int q=i+1;q<=nrEch;q++)
			if(e[i].nrCampionate<e[q].nrCampionate)
				swap(e[i],e[q]);
}

//aceasta sorteaza in ordine descrescatoare
//jucatorii in functie de nr de goluri
//pentru TOP 3
void sortareJucatori(jucatori j[100],int nrJuc){
	for(int i=1;i<=nrJuc;i++)
		for(int q=i+1;q<=nrJuc;q++)
			if(j[i].goluri<j[q].goluri)
				swap(j[i],j[q]);
}

int existaEchipaJucatorului(jucatori j[100],echipe e[50],int nrJuc, int nrEch,char numeJucator[20],char prenumeJucator[20]){
	for(int i=1;i<=nrJuc;i++){
		if(strcmp(numeJucator,j[i].nume)==0 && strcmp(prenumeJucator,j[i].prenume)==0){
			for(int q=1;q<=nrEch;q++){
				if(strcmp(j[i].echipa,e[q].nume)==0)
					return q;
			}
		}
	}
	return 0;
}

int existaJucatorulEchipei(jucatori j[100],echipe e[50], char numeEchipa[20],int nrinitiala,int nrJuc,int nrEch){
	for(int i=1;i<=nrEch;i++){
		if(strcmp(e[i].nume,numeEchipa)==0){
			for(int q=1;q<=nrJuc;q++){
				if(strcmp(e[i].numeJuc[nrinitiala],j[q].nume)==0 && strcmp(e[i].prenumeJuc[nrinitiala],j[q].prenume)==0){
					return q;
				}
			}
		}
	}
	return 0;
}