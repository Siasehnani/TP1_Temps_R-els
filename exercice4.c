#include<pthread.h>//déclaration de la biblioteque qui permet de faire la gestion des threads
#include<stdio.h>//déclaration de la biblioteque qui permet de faire les entrées/sorties
#include<stdlib.h> //déclaration de la biblioteque qui permet de faire la gestion de la mémoire
#include<unistd.h> // Inclut les fonctions standard de gestion des processus (utilisé pour la fonction
sleep).
void *thread_func1(void *arg){//la première fonction exécutée par le thread 1.
printf("Thread1:Bonjour!\n");// Affiche un message "Bonjour!".
return NULL; // Renvoie NULL pour indiquer la fin de la fonction.
}
void *thread_func2(void *arg){//la deuxième fonction exécutée par le thread 2.
printf("Thread2:Salut!\n");// Affiche un message "Salut!".
return NULL;// Renvoie NULL pour indiquer la fin de la fonction.
}
int main(int argc, char *argv[]){// Fonction principale du programme.
 pthread_t thread1, thread2; // Déclare deux identifiants de thread.
 pthread_create(&thread1, NULL, thread_func1, NULL); // Crée le thread 1, exécutant la fonction
thread_func1.
 pthread_create(&thread2, NULL, thread_func2, NULL); // Crée le thread 2, exécutant la fonction
thread_func2.
 pthread_join(thread1, NULL); // Attends que le thread 1 se termine.
 pthread_join(thread2, NULL);// Attends que le thread 2 se termine.
 return EXIT_SUCCESS; // Termine le programme avec succès.
}
