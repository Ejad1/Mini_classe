#include <stdio.h>
#include <stdlib.h>
struct Eleve{
    char nom[100];
    char prenom[100];
    char ddn[100];
    char sexe[100];
    float nF;
    float nA;
    float nM;
    float mo;
};

struct Eleve feleve() {
    struct Eleve eleve;
    printf("\nEntrer le nom de l'élève : ");
    scanf("%s",&eleve.nom);
    printf("Entrer le prénom de l'élève : ");
    scanf("%s",&eleve.prenom);
    printf("Entrer la date de naissance de l'élève : ");
    scanf("%s",&eleve.ddn);
    printf("Entrer le sexe de l'élève : ");
    scanf("%s",&eleve.sexe);

    return(eleve);
};

void notes(struct Eleve tab[10]) {
    int i;

    for (i=0;i<10;i++) {
        printf("\nSaisir la note de français : ");
        scanf("%f",&tab[i].nF);
        printf("Saisir la note d'anglais : ");
        scanf("%f",&tab[i].nA);
        printf("Saisir la note de mathématiques : ");
        scanf("%f",&tab[i].nM);
    }
}

void moyennes(struct Eleve tab[10]) {
    int i;
    float s;

    for (i=0;i<10;i++) {
        s = tab[i].nA + tab[i].nF + tab[i].nM;
        tab[i].mo = s/3;
    }
}

void classement(struct Eleve tab[10]) {
    int i,j,max;
    struct Eleve permu[10];

    for (i=0;i<9;i++) {
        max = i;
        for (j=i+1;j<10;j++) {
            if (tab[j].mo > tab[max].mo) {
                max = j;
            }
        }
        permu[i] = tab[i];
        tab[i] = tab[max];
        tab[max] = permu[i];
    }
}

void afficher_resultat(struct Eleve tab[10]) {
    int i;

    for (i=0;i<10;i++) {
        printf("%d-%s %s : %f",i+1,tab[i].nom,tab[i].prenom,tab[i].mo);
    }
}

int main()
{
    struct Eleve Liste[10];
    int i;

    printf("Veuillez entrer les informations des élèves : \n");
    for (i=0;i<10;i++) {
        Liste[i] = feleve();
    }

    notes(Liste);
    moyennes(Liste);
    classement(Liste);
    afficher_resultat(Liste);

    return 0;
}
