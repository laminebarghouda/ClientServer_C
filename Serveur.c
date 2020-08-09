#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#define MAX 1000
#define PORT 5000
#define SA struct sockaddr
#pragma comment(lib, "ws2_32")
#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)


/* La fonction est utilisée pour diviser une chaîne
 * en une série de jetons en fonction d'un délimiteur
 * particulier et les retourner dans un tableau */
char** split (char string[])
{
    char ** array = (char**)malloc(4 * sizeof(char*));
    for (int j =0 ; j < 10; ++j) {
        array[j] = (char *) malloc(10 * sizeof(char));
        array[j] = NULL;
    }

    int i=0;
    array[i] = strtok(string,",");
    while(array[i]!=NULL)
    {
        array[++i] = strtok(NULL,",");
    }
    return (char **) array;
}

// Fonction qui manipule la requete du client
char* handleRequest(char** request){
    char* response = (char*) malloc(100 * sizeof(char));

    // Calcul de surface
    if(strcmp(request[2],"Su*") == 0) {
            // Cas d'un carre
        if (strncmp(request[3], "C*",2) == 0) {
            if(strcmp(request[0],request[1]) == 0) // Un carre doit avoir des cotes egaux
                sprintf(response,"La surface du carre est %d",atoi(request[0]) * atoi(request[1]));
            else
                sprintf(response,"Erreur ! Format invalide");
        }
            // Cas d'un rectangle
        else if(strncmp(request[3],"R",1) == 0){
            sprintf(response,"La surface du rectangle est %d",atoi(request[0]) * atoi(request[1]));
        }
            // Cas d'un triangle
        else if(strncmp(request[3], "T",1) == 0){
            sprintf(response,"La surface du triangle est %f",(float)(atoi(request[0]) * atoi(request[1]))/2);
        }
            // Cas d'une cercle
        else if(strncmp(request[3], "Cr",2) == 0){
            if(strcmp(request[0],request[1]) == 0) // Le cercle doit avoir des rayons egaux
                sprintf(response,"La surface du cercle est %f",(float)(3.14 * atoi(request[0]) * atoi(request[1])));
            else
                sprintf(response,"Erreur ! Format invalide");
        }
            // Erreur
        else{
            sprintf(response,"Erreur ! Format invalide");
        }

    }
        // Calcul de perimetre
    else if(strcmp(request[2],"Pr") == 0){
            // Cas d'un Carre
        if (strncmp(request[3], "C*",2) == 0) {
            if(strcmp(request[0],request[1]) == 0) // Un carre doit avoir des cotes egaux
                sprintf(response,"Le perimetre du carre est %d",(atoi(request[0]) * 4));
            else
                sprintf(response,"Erreur ! Format invalide");
        }
            // Cas d'un triangle
        else if(strncmp(request[3], "R",1) == 0){
            sprintf(response,"Le perimetre du rectangle est %d",((atoi(request[0]) * 2) + (atoi(request[1]) * 2)));
        }
            // Cas d'une cercle
        else if(strncmp(request[3], "Cr",2) == 0){
            if(strcmp(request[0],request[1]) == 0) // Le cercle doit avoir des rayons egaux
                sprintf(response,"Le perimetre du cercle est %f",(float)(3.14 * atoi(request[0]) * 2));
            else
                sprintf(response,"Erreur ! Format invalide");
        }
            // Erreur
        else{
            sprintf(response,"Erreur ! Format invalide");
        }
    }
        // Erreur
    else{
        sprintf(response,"Erreur ! Format invalide");
    }

    return (char*)response;
}


FILE* open_archive_file(){
    // Ouvrez le fichier en mode ajout a (append).
    FILE *archive;
    archive = fopen("archive_clients.txt", "a");

    if (archive == NULL) {
        // Fichier non créé donc quitter
        printf("Unable to create file.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    return archive;
}

void show_score(){
    // Ouvrez le fichier en mode lecture r (read).
    FILE *archive;
    archive = fopen("archive_clients.txt", "r");

    if (archive == NULL) {
        /* File not opened hence exit */
        printf("Unable to open file.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

}


// Fonction conçue pour le chat entre le client et le serveur.
int run(int tube_client)
{
    char buff[MAX];
    int n;

    // boucle infinie pour le chat
    for (;;) {
        // Vider le tampon
        bzero(buff, MAX);

        // lire le message du client et le copier dans le tampon
        recv(tube_client, buff, sizeof(buff),0);

        // si msg contient «FINFIN», alors le serveur quitte et le chat est terminé.
        if (strncmp("FINFIN", buff, 6) == 0) {
            printf("Merci d'utiliser mon service!...\n");
            show_score();
            return 0;
        }

        // si msg contient «FIN», alors le chat est terminé et le serveur se met en attente
        if (strncmp("FIN", buff, 3) == 0) {
            printf("Un client vient de quitter!...\n");
            break;
        }

        // Ouvrir le fichier de l'archive
        FILE* archive = open_archive_file();
        // archiver la requete dans le fichier d'archive
        fputs(buff, archive);
        // Fermer le fichier pour enregistrer les données
        fclose(archive);

        // Manipulation du question et preparation du résultat
        char **array = split(buff) ;
        char* response = handleRequest(array);

        // Envoyer la reponse au client
        send(tube_client, response, sizeof(buff),0);
    }

    return 1;
}



int main()
{
    // Initialisation de la tube
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsOk = WSAStartup(ver, &wsData);
    if (wsOk != 0){
        printf("Impossible d'initialiser la tube serveur ! Le serveur s'arrete ...");
        system("Pause");
        exit(EXIT_FAILURE);
    }

    // Initialisation des variables
    struct sockaddr_in adresseServeur, adresseClient;
    int tube_serveur, tube_client, l;

    // Creation de la tube Serveur
    tube_serveur = socket(AF_INET, SOCK_STREAM, 0);
    if (tube_serveur == -1) {
        printf("Impossible de creer la tube serveur ! Le serveur s'arrete...\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Tube serveur cree avec succes ! ..\n");

    bzero(&adresseServeur, sizeof(adresseServeur));

    // attribuer IP, PORT
    adresseServeur.sin_family = AF_INET;
    adresseServeur.sin_addr.s_addr = htonl(INADDR_ANY);
    adresseServeur.sin_port = htons(PORT);

    // Liaison du tube serveur nouvellement créé à l'adresse IP donnée et vérification
    if ((bind(tube_serveur, (SA*)&adresseServeur, sizeof(adresseServeur))) != 0) {
        printf("La tube serveur ne parvient pas à se lier à l'adresse IP...\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Tube serveur liee a l'adresse IP avec succes !..\n");

    // Le serveur est maintenant prêt à écouter et à vérifier
    if ((listen(tube_serveur, 5)) != 0) {
        printf("Le serveur ne parvient pas à écouter les requetes ! Le serveur s'arrete...\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    else
        printf("Le serveur est maintenant a l'ecoute des requetes ..\n");

    l = sizeof(adresseClient);

    int running = 1;
    while(running) {
        // Accepter le paquet de données du client et vérification
        tube_client = accept(tube_serveur, (SA *) &adresseClient, &l);
        if (tube_client < 0) {
            printf("Erreur ! Le serveur ne parvient pas à accepter le client !...\n");
            exit(EXIT_FAILURE);
        } else
            printf("Un client vient de se connecter ...\n");

        // Fonction de discussion entre client et serveur
        running = run(tube_client);
    }

    // Après avoir discuté, fermer la tube serveur
    close(tube_serveur);
}