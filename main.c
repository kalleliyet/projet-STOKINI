#include<stdio.h>
#include<string.h>
#include <stdlib.h>	
#define true 0 
#define false 1     

struct historique
	{
		int jour;
		int mois;
		char type[20];
	 };       
int count = 0;	


struct produit
	{
		char id[10];   
		char nom[20]; 
		int  quantite; 
		float prix;   
	};
	struct produit prod[30];
 	FILE *f;	

 	int writefile()
{
    int i;
    f = fopen("NOTRE_MAGASIN.txt", "w");  
    if (f == NULL)
        return -1;			
    fprintf(f, "%d\n", count);
    for (i = 0; i < count; ++i) 
    {
        // MODIFICATION IC MR 
        fputs(prod[i].id, f);
        fprintf(f, "\n");
        fputs(prod[i].nom, f);
        fprintf(f, "\n");
        fprintf(f, "%d\n", prod[i].quantite);
        fprintf(f, "%f\n", prod[i].prix);
    }
    fclose(f);
    return 0;
}
int readFile() // PARCOURIR LE FICHER ET LE LIRE :D 
{
    int n = 0;
    int i;
    f = fopen("NOTRE_MAGASIN.txt", "r");
    if (f == NULL)
        return -1;
    fscanf(f, "%d\n", &n);
    for (i = 0; i < n; i++)
    {
        fgets(prod[i].id, 10, f);
        prod[i].id[strlen(prod[i].id) - 1] = 0; // SUPPRIMER LA LIGNE
        fgets(prod[i].nom, 20, f);
        prod[i].nom[strlen(prod[i].nom)-1] = 0;
        fscanf(f, "%d", &prod[i].quantite);
        fscanf(f, "%f", &prod[i].prix);
    }
    fclose(f);
    return n;
}

void 	AFFICHER_LA_DESCRIPTON_D_UN_PRODUIT(){      // fonction afficher la description du produit 
	int i;
	int ok=1;
	int k;
	char ch[30];
     	printf("donner le produit que vous desirez:\n");
        scanf("%s",&ch);
 	     count = readFile();
        for (i=0;i<count;i++){
        k=strcmp(ch,prod[i].nom);
		if(k==0){
		  
  		  printf("%d     %-10s       %-8s     %-5d       %-6.2f\n",i+1,prod[i].nom,prod[i].id,prod[i].quantite,prod[i].prix);
	
          ok=0;
		  break;
		  }}
     
    if(ok==1){
    	printf("votre produit n'existe pas");}
}
    


void SUPPRIMER(){     //fonction supprimer
	count=readFile();
	char id[10]; 
	int i,j;
	int z=false;
printf("veuillez saisir l 'ID du produit que vous voulez supprimer : "); 
fflush(stdin);
gets(id);

for(i=0;i<count;i++){	
		z=true;
	if(strcmp(prod[i].id,id)==0){ 
	for( j=i; j<(count-1); j++)
			{
				prod[j]=prod[j+1];
			}
			count--;
	}
}
if(z==false){	
	printf("ID introuvable  %s .",id);
}
writefile();
}

 

void AJOUTER(){	// FONCTION AJOUTER

  	printf("Veuillez saisir le nouveau produit \n");
	readFile();		//LIRE TOUS LE FICHIER.
  	    if (count>0) {
  	    count=readFile();
  		verifID(0,count); // VERIFER SI L'ID EXISTE
		}
	else{
		printf("\nID du produit: ");
		fflush(stdin); 
		gets(prod[count].id);
		}
		printf("Nom du produit: ");gets(prod[count].nom);
		printf("Quantité du produit: ");scanf("%d",&prod[count].quantite);
		printf("Prix du produit: ");scanf("%f",&prod[count].prix);
		++count; 

	writefile(); //ENREGISTRER LE CONTENUE DE FICHIER
}



int verifID(int i, int j)	//Vérification de l'ID
{
	count=readFile();
    printf("produit ID: ");
    fflush(stdin);
	gets(prod[count].id);
    if (strcmp(prod[i].id,prod[j].id)==0){
        printf("L'ID saisi existe , essayez de nouveau '");
        return verifID(i++,j--);
		}
}


void MODIFIERProduit(){	// FONCTION MODIFIER LE PRODUIT
	char id[10];
int test;
int i;
	int choix;
  printf("Modification de votre produit");
  printf("\nVeuillez saisir l'ID du produit que vous voulez modifier: "); 
	fflush(stdin);
	gets(id);
	test=VERIF(id);
    if (test == 0)
 {
  printf("L'ID est introuvable", id); 
 }
 else
 {
 		readFile();
  {
	for(i=0;i<count;i++){
	
  if(strcmp(id,prod[i].id)!=0) 
	writefile();
   else
   {
    printf("\n1. Modifier Le ID ?");
    printf("\n2. modifier le nom d'un produit? ");
    printf("\n3. modifier la quantité d'un produit ?");
    printf("\n4. modifier le prix d'un produit?");
    printf("\n5. modifier le jour d'entrée d'un produit? ");
    printf("\n6. modifier le mois d'entrée d'un produit? ");
    printf("\nVeuillez saisir votre choix choix:");
    fflush(stdin);
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
    
     printf("Veuillez saisir le nouveau ID: ");
 		fflush(stdin);
        gets(prod[i].id);
     break;
    case 2:
     printf("Veuillez saisir le nouveau nom: ");
    	fflush(stdin);
        gets(prod[i].nom);
     break;
    case 3:
     printf("Veuillez saisir la nouvelle quantité: ");
    scanf("%d",&prod[i].quantite);
    break;
    case 4:
     printf("Veuillez saisir le nouveau prix: ");
    scanf("%f",&prod[i].prix);
     break;
    default:
     printf("Choix invalide");
     break;
    }
   writefile();
   }
   
   }
  }
  fclose(f); 
  f = fopen("NOTRE_MAGASIN.txt", "r");
 readFile();
 {
   writefile();
  }
  fclose(f);
  printf("Mise à jour enregistrée, Merci!");
 }
}

int VERIF(char id[]){ 
	int i;
count=readFile();

	
 		readFile();
 		for(i=0;i<count;i++){
		 
	if(strcmp(id,prod[i].id)!=0){ 
		
			 fclose(f);
		}
   return 1;		
  }
	
 fclose(f);
 return 0; 
}


void AFFICHER_TOUS_LES_PRODUITS(){  //FONCTION AFFICHER TOUS LES PRODUITS EXISTANTS
	int i;

  count = readFile();
  if (count < 0)
    puts("Impossible d'ouvrir le fichier");
	printf(" \t\t\t\t *****  LES MAGASINS *****\n");
   printf("------------------------------------------------------------------------------------\n");
   printf("|    NOM     |  PROD ID  |  QUANTITE |   PRIX    |JOURS/MOIS                        \n");
   printf("------------------------------------------------------------------------------------\n");

   for (i=0;i<count;i++){ // LES DETAILLES DE CHAQUE PRODUIT
   printf("%d     %-10s       %-8s     %-5d       %-6.2f\n",i+1,prod[i].nom,prod[i].id,prod[i].quantite,prod[i].prix);
	}

}

int main (){
	system("COLOR 0C");
	struct historique h[100];
	int j,i=0;
	int choix;
	count = readFile(); 
	if(count < 0) // FICHIER INTROUVABLE
		printf("Impossible de localiser le fichier\n");
	printf("\n");
	printf( " +-------------------------------------BIENVENUE CHEZ **:D  STOKINI :D ** -----------------------------------+\n");
	printf( "  +-----------------------------------------------------------------------------------------------------------+\n");
    printf( "  |              BIENVENUE Mr, c'est ' 'YASSINE BOUJEBHA,MOHAMED AZIZ KALLEL ET EYA JELJLI' Project           |\n");
    printf( "  |                                         QU'EST-CE QUE VOUS AIMERIEZ FAIRE?                                |\n");
    printf( "  +-----------------------------------------------------------------------------------------------------------+\n");

do {
	printf( "  +-----------------------------------------------------------------------------------------------------------+\n");	
	printf("\n\n:");
	printf("\n 1. ajouter un produit");
	printf("\n 2. modifier un produit");
	printf("\n 3. supprimer un produit");
	printf("\n 4. afficher tous les produits");
	printf("\n 5. afficher la description d'un produit selon son nom ");
	printf("\n 6. afficher l'historique d'utilisation");
	printf("\n 7. Quitter l'application");
	printf("\nchoix--> ");
	scanf("%d", &choix);
	     switch(choix){
        case 1 :  
                AJOUTER();
                strcpy(h[i].type,"ajout d'un produit");
                printf("veuillez saisir la date d'aujoud hui \n");
                printf("jour");
                scanf("%i",&h[i].jour);
                printf("mois");
                scanf("%i",&h[i].mois);
                i++;
                break;
        case 2:
		    	MODIFIERProduit();
		    	strcpy(h[i].type,"modification d'un produit");
		    	printf("veuillez saisir la date d'aujoud hui \n");
		    	printf("jour");
                scanf("%i",&h[i].jour);
				printf("mois");
                scanf("%i",&h[i].mois);
                i++;
				break;
        case 3:
        		SUPPRIMER();
        		strcpy(h[i].type,"elimination d'un produit");
        		printf("veuillez saisir la date d'aujoud hui \n");
        		printf("jour");
                scanf("%i",&h[i].jour);
                printf("mois");
                scanf("%i",&h[i].mois);
                i++;
               	 break;
        case 4: 
               AFFICHER_TOUS_LES_PRODUITS();
                break;
       	
	   	case  5:
	   		AFFICHER_LA_DESCRIPTON_D_UN_PRODUIT(); 
		 	break;
		case  6:
	   		for(j=0;j<=i;j++){
	   			printf("%s         le  %i/%i \n",h[j].type,h[j].jour,h[j].mois);
			   }
		 	break;
		case 7:
		 	  exit(1);
		 default :
                printf("VEUILLEZ SAISIR UNE COMMANDE VALIDE");
            break;
      }
  }while(choix!=7); // REPETER JUSQUA L'UTILISATEUR TAPPE UN CHIFFRE VALIDE
  printf("Merci d'avoir utiliser STOKINI et au revoir !");
}
