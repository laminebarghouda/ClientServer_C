#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h> // Pour windows
#include <unistd.h>
/* Pour Linux
 * #include <netdb.h>
 * #include <netinet/in.h>
 * #include <sys/socket.h>
 * #include <sys/types.h>
 * */
#define MAX 1000
#define PORT 5000
#define SA struct sockaddr
#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)
void func(int tube_client)
{
    char buff[MAX];
    int n;
    for (;;) {
        bzero(buff, sizeof(buff));
        printf("Question : ");
        n = 0;
        while ((buff[n++] = getchar()) != '\n')
            ;
        send(tube_client, buff, sizeof(buff),0);
        // si msg contient "FIN" ou "FINFIN", alors le client se deconnecte
        if ((strncmp("FINFIN", buff, sizeof("FINFIN")) == 0)|| (strncmp("FIN", buff, 3) == 0)) {
            break;
        }
        bzero(buff, sizeof(buff));
        recv(tube_client, buff, sizeof(buff),0);
        if(strcmp(buff,"") == 0) {
            printf("Serveur non disponible ! ");
            exit(0);
        }
        printf("Reponse : %s\n", buff);
    }
}

int main()
{

    // Initialisation de la tube (Pour windows)
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);
    int wsOk = WSAStartup(ver, &wsData);
    if (wsOk != 0){
        printf("Impossible d'initialiser la tube client ! Le client va quitter ...");
        system("Pause");
        exit(EXIT_FAILURE);
    }



    int tube_client;
    struct sockaddr_in adresseServeur;

    // Creation de la tube Serveur
    tube_client = socket(AF_INET, SOCK_STREAM, 0);
    if (tube_client == -1) {
        printf("Impossible de creer la tube client ! Le client va quitter...\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    else
        printf("Tube client cree avec succes ! ..\n");
    bzero(&adresseServeur, sizeof(adresseServeur));

    // attribuer IP, PORT
    adresseServeur.sin_family = AF_INET;
    adresseServeur.sin_addr.s_addr = inet_addr("127.0.0.1");
    adresseServeur.sin_port = htons(PORT);

    // connecter la tube client au tube serveur
    if (connect(tube_client, (SA*)&adresseServeur, sizeof(adresseServeur)) != 0) {
        printf("La connection avec le serveur a echoue ! Le client va quitter...\n");
        exit(0);
    }
    else
        printf("Connection avec le serveur etablit avec succes..\n");

    // fonction pour le chat
    func(tube_client);

    // ferme la tube
    close(tube_client);
}