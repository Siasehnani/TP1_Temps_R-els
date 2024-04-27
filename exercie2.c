#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// fonction print_message qui affiche un message passé en argument
void *print_message(void *ptr) {
 char *message = (char *)ptr; // Conversion du pointeur en chaîne de caractères
 printf("%s\n", message); // Affichage du message
 pthread_exit(NULL); // Fin du thread
}
int main() {
 pthread_t thread; // Identifiant du thread
 char *message = "Bonjour, je suis un thread !"; // Message à afficher
 // Création d'un thread en lui passant la fonction print_message et le message comme argument
 if (pthread_create(&thread, NULL, print_message, (void *)message))
{
 fprintf(stderr, "Erreur lors de la création du thread\n");
 return 1;
}
 // Attente de la fin de l'exécution du thread
 if (pthread_join(thread, NULL)) {
 fprintf(stderr, "Erreur lors de l'attente de la fin du thread\n");
 return 1; }
 return 0; // Fin du programme
}
