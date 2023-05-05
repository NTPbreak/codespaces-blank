#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct 
{
    float Ict_102;
    float Ict_104;
    float Ict_106;
    float Ict_108;
    float Ict_110;
    int  Langue;
    float Moyenne_s20;
    int Rang_s20;
    char Mention_s20[2];
    float MGP;
    int Rang_MGP;
    char Mention_MGP[2];
}Bulletin;

/*2*/typedef struct 
{ 
	char matricule[8];
    char nom [30];
	char prenom[30];
	char date_de_naissance[10];
    Bulletin Bulletin;

}Etudiant;

// int random_between(int min,int max);
// /*3*/void passer_examen(Etudiant*tab,int n,int code_UE);
// /*4*/int ordre_alphabetique(Etudiant*tab,int n);
// /*5*/int ordre_de_merite_s20(Etudiant*tab,int n);
// /*6*/int ordre_de_merite_MGP(Etudiant*tab,int n);
// /*7*/int topk_20(Etudiant*tab,int n,int k);
// /*8*/int topk_MGP(Etudiant*tab,int n,int k);
// /*9*/int afficher_tab_etudiants(Etudiant*tab,int n,int type);
// /*10*/Etudiant*generer_tab_etudiant(int n,char** noms,char**prenoms,int m,int a_min,int a_max);
// void fonction_speciale(char *chaine, int k);

void afficher_tab_etudiant(Etudiant* tab, int n,int type) {
    if(type==0){
    printf("|Matricule\t|Nom\t\t|Prenom\t\t|Date de naissance\t|ICT102\t|ICT104\t|ICT106\t|ICT108\t|ICT110\t|langue |Moyenne|Rang | Mention|\n");
    for (int i=0; i<n; i++) {
    printf(" %s\t%s\t\t%s\t\t%s\t\t %.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2d\t%.2f\t%d\t%s\n",
            tab[i].matricule, tab[i].nom, tab[i].prenom,tab[i].date_de_naissance,tab[i].Bulletin.Ict_102,tab[i].Bulletin.Ict_104,tab[i].Bulletin.Ict_106,tab[i].Bulletin.Ict_108,tab[i].Bulletin.Ict_110,tab[i].Bulletin.Langue,tab[i].Bulletin.Moyenne_s20,tab[i].Bulletin.Rang_s20,tab[i].Bulletin.Mention_s20);
    }
    }
    if(type==1)
    {
        printf("|Matricule\t|Nom\t\t|Prenom\t\t|Date de naissance\t|ICT102\t|ICT104\t|ICT106\t|ICT108\t|ICT110\t|langue |Moyenne|Rang | Mention|\n");
    for (int i=0; i<n; i++) {
    printf(" %s\t%s\t\t%s\t\t%s\t\t %.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2d\t%.2f\t%d\t%s\n",
            tab[i].matricule, tab[i].nom, tab[i].prenom,tab[i].date_de_naissance,tab[i].Bulletin.Ict_102,tab[i].Bulletin.Ict_104,tab[i].Bulletin.Ict_106,tab[i].Bulletin.Ict_108,tab[i].Bulletin.Ict_110,tab[i].Bulletin.Langue,tab[i].Bulletin.MGP,tab[i].Bulletin.Rang_MGP,tab[i].Bulletin.Mention_MGP);
    }
    }
}
int random_between(int min, int max) {
    return rand() % (max - min + 1) + min;
}
void fonction_speciale(char *chaine, int k)
{ 
	if(chaine[k]=='9')
	{
		chaine[k]='0';
		if(chaine[k-1]=='9')
		{
			chaine[k-1]='0';
			if(chaine[k-2]=='9')
			{
				chaine[k-2]='0';
				chaine[k-3]++;
			}
			else
			{
				chaine[k-2]++;
			}
		}
		else
		{
    			chaine[k-1]++;
		}
	}
	else
	{
		chaine[k]++;
	}
}

Etudiant*generer_tab_etudiant(int n,char** noms,char**prenoms,int m,int a_min,int a_max)
{
    Etudiant*tab=(Etudiant*)malloc(sizeof(Etudiant)*n);
    if(tab==NULL)
    {
        printf("ERROR MEMORY ACCESS\n");;
        return NULL;
    }
    int p=3;
    int x=0;
    srand(time(NULL)); 
     char sup[3]="22v";
     char post[4]="0000";
    for(int i=0;i<n;i++)
    {
         int nom_index = rand() % m;
        int prenom_index = rand() % m;
        int annee_naissance =random_between(a_min, a_max);
        int mois_naissance = random_between(1,12);
        int jour_naissance = random_between(1,28);
        fonction_speciale(post, p);
        sprintf(tab[i].matricule,"%s",sup);
        sprintf(tab[i].date_de_naissance, "%.2d-%.2d-%d", jour_naissance, mois_naissance, annee_naissance);
        strcpy(tab[i].nom,noms[nom_index]);
        strcpy(tab[i].prenom,prenoms[prenom_index]);
    }
    return tab;

}

void passer_examen(Etudiant*tab,int n,int code_UE)
{   
   
    int coef_UE[]={5,6,8,6,5,3};
    float tab_MGP[]={0,0,0,0,0,0,1,1.3,1.7,1.2,2.3,2.7,3,3.3,3.7,4,4,4,4,4};
    int som_coef=33;
    int note;
    for(int i=0 ;i<n;i++)
    {
        if(code_UE==0)
        {
        tab[i].Bulletin.Ict_102=rand()%(17-5+1)+5;
        note=tab[i].Bulletin.Ict_102;
        tab[i].Bulletin.Moyenne_s20+=tab[i].Bulletin.Ict_102*coef_UE[code_UE]/som_coef;
        tab[i].Bulletin.MGP+=tab_MGP[note]*coef_UE[code_UE]/som_coef;
        }
        if(code_UE==1){
        tab[i].Bulletin.Ict_104=rand()%(17-5+1)+5;
        note=tab[i].Bulletin.Ict_104;
        tab[i].Bulletin.Moyenne_s20+=note*coef_UE[code_UE]/som_coef;
        tab[i].Bulletin.MGP+=tab_MGP[note]*coef_UE[code_UE]/som_coef;
        }
        if(code_UE==2){
        tab[i].Bulletin.Ict_106=rand()%(17-5+1)+5;
        note=tab[i].Bulletin.Ict_106;
        tab[i].Bulletin.Moyenne_s20+=note*coef_UE[code_UE]/som_coef;
        tab[i].Bulletin.MGP+=tab_MGP[note]*coef_UE[code_UE]/som_coef;
        }
        if(code_UE==3){
        tab[i].Bulletin.Ict_108=rand()%(17-5+1)+5;
        note=tab[i].Bulletin.Ict_108;
        tab[i].Bulletin.Moyenne_s20+=note*coef_UE[code_UE]/som_coef;
        tab[i].Bulletin.MGP+=tab_MGP[note]*coef_UE[code_UE]/som_coef;
        }
        if(code_UE==4)
        {
        tab[i].Bulletin.Ict_110=rand()%(17-5+1)+5;
        note= tab[i].Bulletin.Ict_110;
        tab[i].Bulletin.Moyenne_s20+=note*coef_UE[code_UE]/som_coef;
        tab[i].Bulletin.MGP+=tab_MGP[note]*coef_UE[code_UE]/som_coef;
        }
        if(code_UE==5)
        {
        tab[i].Bulletin.Langue=rand()%(17-5+1)+5;
        note=tab[i].Bulletin.Langue;
        tab[i].Bulletin.Moyenne_s20+=note*coef_UE[code_UE]/som_coef;
        tab[i].Bulletin.MGP+=tab_MGP[note]*coef_UE[code_UE]/som_coef;
        }
    }
}
void permuter(Etudiant*tab,int i,int j)
{
    Etudiant perm;
    perm=tab[i];
    tab[i]=tab[j];
    tab[j]=perm;
}
int comparer(char* a , char* b)
{
    int i=0 ;
    while (a[i]!= '\0' && b[i]!= '\0' && a[i]==b[i])
    {
        i++;
    }
    if(a[i]==b[i])
    {
        return 0 ;
    }
    if(b[i]!='\0' && a[i]=='\0')
    {
        return 1;
    }
    if(b[i]=='\0' && a[i]!='\0')
    {
        return -1;
    }
    if(a[i] > b[i])
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int comparer_etudiant(Etudiant a,Etudiant b)
{ 
    int c_nom=comparer(a.nom,b.nom);
    if(c_nom!=0)
    {
        return c_nom;
    }
    else{
        return comparer(a.prenom,b.prenom);
    }
}
void ordre_alphabetique(Etudiant *tab ,int n)
{
    int i ,j , imin;
    for (i=0 ;i<n ;i++)
    {
        imin=i;
        for(j=i ; j<n ;j++)
        {
            if(comparer_etudiant(tab[imin], tab[j] )== -1)
            {
                imin=j;
            }
        }
        permuter(tab ,i ,imin);
    }
}

void definir_rang_et_mention(Etudiant *tab,int n,int type)
{
	int i;
	if(type==0)
	{
		for(i=0;i<n;i++)
		{
			tab[i].Bulletin.Rang_s20=i+1; //definir le rang
			
			if(tab[i].Bulletin.Moyenne_s20<10)
			{
				tab[i].Bulletin.Mention_s20[0]='E';
			}
			else if(tab[i].Bulletin.Moyenne_s20>=10 && tab[i].Bulletin.Moyenne_s20<12)
			{
				tab[i].Bulletin.Mention_s20[0]='P';
			}
			else if(tab[i].Bulletin.Moyenne_s20>=12 && tab[i].Bulletin.Moyenne_s20<14)
			{
				tab[i].Bulletin.Mention_s20[0]='A';
				tab[i].Bulletin.Mention_s20[1]='B';
			}
			else if(tab[i].Bulletin.Moyenne_s20>=14 && tab[i].Bulletin.Moyenne_s20<16)
			{
				tab[i].Bulletin.Mention_s20[0]='B';
			}
			else if(tab[i].Bulletin.Moyenne_s20>=16 && tab[i].Bulletin.Moyenne_s20<=20)
			{
				tab[i].Bulletin.Mention_s20[0]='T';
				tab[i].Bulletin.Mention_s20[1]='B';
			}
		}
		
	}
	if(type==1)
	{
		for(i=0;i<n;i++)
		{
			tab[i].Bulletin.Rang_MGP=i+1; //definir le rang
			
			if(tab[i].Bulletin.MGP<2)
			{
				tab[i].Bulletin.Mention_MGP[0]='E';
			}
			else if(tab[i].Bulletin.MGP>=2 && tab[i].Bulletin.MGP<2.4)
			{
				tab[i].Bulletin.Mention_MGP[0]='P';
			}
			else if(tab[i].Bulletin.MGP>=2.4 && tab[i].Bulletin.MGP<2.8)
			{
				tab[i].Bulletin.Mention_MGP[0]='A';
				tab[i].Bulletin.Mention_MGP[1]='B';
			}
			else if(tab[i].Bulletin.MGP>=2.8 && tab[i].Bulletin.MGP<3.2)
			{
				tab[i].Bulletin.Mention_MGP[0]='B';
			}
			else if(tab[i].Bulletin.MGP>=3.2 && tab[i].Bulletin.MGP<=4)
			{
				tab[i].Bulletin.Mention_MGP[0]='T';
				tab[i].Bulletin.Mention_MGP[1]='B';
			}
		}
	}
}


void ordreDeMerite_mgp(Etudiant* tab, int n)
{
	int i,j,k,m,trouve,p;
    Etudiant *tab2;
    tab2=(Etudiant*)malloc(sizeof(Etudiant)*n);
    for(i=0;i<n;i++)
    {
        j=0;
        trouve=1;
        p=i;
        while(j<i && trouve==1)
        {
            if(tab2[j].Bulletin.MGP>tab[i].Bulletin.MGP)
            {
                p=j;
                trouve=0;
            }
            j++;
        }
        for(k=n-1;k>p;k--)
        {
            tab2[k]=tab2[k-1];
        }
        tab2[p]=tab[i];
    }
    for(i=0;i<n;i++)
    {
    	m=n-1-i;//ordre decroissant
    	tab[i]=tab2[m];
    }
    definir_rang_et_mention(tab,n,1);
}


void ordreDeMerite_s20(Etudiant* tab, int n)
{
	int i,j,k,m,trouve,p;
    Etudiant *tab2;
    tab2=(Etudiant*)malloc(sizeof(Etudiant)*n);
    for(i=0;i<n;i++)
    {
        j=0;
        trouve=1;
        p=i;
        while(j<i && trouve==1)
        {
            if(tab2[j].Bulletin.Moyenne_s20>tab[i].Bulletin.Moyenne_s20)
            {
                p=j;
                trouve=0;
            }
            j++;
        }
        for(k=n-1;k>p;k--)
        {
            tab2[k]=tab2[k-1];
        }
        tab2[p]=tab[i];
    }
    for(i=0;i<n;i++)
    {
    	m=n-1-i;//ordre decroissant
    	tab[i]=tab2[m];
    }
    definir_rang_et_mention(tab,n,0);
}

void topK_s20(Etudiant *tab, int n, int K)
{
    int i;
    ordreDeMerite_s20(tab,n);
    afficher_tab_etudiant(tab, K, 0);
}
void topK_mgp(Etudiant *tab, int n, int K)
{
    int i;
    ordreDeMerite_mgp(tab,n);
    afficher_tab_etudiant(tab, K, 1);
}
// void ordre_de_merite_s20
int main()
{   int k=10;
    int n=20;
    int a_min,a_max;
    char* noms [] = {"Girard", "Martin", "Dubois", "Durand", "Moreau", "Simon", "Fourni", "Lefe","Negoue","ABAKOU","ABBA","Nzekon","HAOUA","MAIPA","MADINA","TIAKO"};
    char* prenoms [] = {"Jean", "Pierre", "Marie", "Luc", "Sylvie", "Emilie", "Paul", "Jacques","Patrick","SALEH","Armel","TOM","PAUL","Sorel","EVA","HIVIDI"};
    int m = 9+7;
    //  
   a_min=1989;
   a_max=2003;
    Etudiant*tab=generer_tab_etudiant(n,noms,prenoms,m,a_min,a_max);
    for(int i=0;i<6;i++)
    {passer_examen(tab,n,i);
    }
    ordre_alphabetique(tab,n);
     int c;
    printf("0.Afficher les etudiants et leurs moyennes en fonction de la moyenne sur 20 OU 1.Afficher en fonction de la MGp: ");
    scanf("%d",&c);  
    definir_rang_et_mention(tab,n,c);
    afficher_tab_etudiant(tab, n,c);
    printf("\t\t------------------ Odre de merite des 10 premiers sur 20 -----------\n");
    topK_s20(tab, n, k);
    
      printf("\t\t------------------ Odre de merite des 10 premiers  pour la MGP -----------\n");  
      topK_mgp(tab, n,k);
        free(tab);
    
    }


