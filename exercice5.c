typedef struct { // Définit une structure nommée PeriodTask
 int id; // Un champ pour l'identifiant de la tâche
 int P; // Un champ pour le temps de période de la tâche
} PeriodTask;
void *TaskFunction(void *arg){ // Définit la fonction TaskFunction qui sera exécutée par chaque
thread
 PeriodTask task = (PeriodTask)arg; // Convertit l'argument en un pointeur vers PeriodTask
 pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL); // Active l'annulation des threads
 while(1) { // Boucle infinie
 sleep(task->P); // Pause l'exécution du thread pendant la période spécifiée dans P
 printf("task %d executed\n", task->id); // Affiche un message indiquant l'exécution de la tâche
 pthread_testcancel(); // Teste si le thread a été annulé
 }
 return NULL; // Renvoie NULL (cette ligne ne sera jamais atteinte)
}
int main(){ // Définit la fonction principale du programme
 int nt = 3; // Déclare et initialise la variable nt à 3 (nombre de tâches)
 int Task_P[] = {1, 2, 3}; // Déclare et initialise un tableau représentant les périodes des tâches
 pthread_t Tr[nt]; // Déclare un tableau de threads
 PeriodTask T[nt]; // Déclare un tableau de structures PeriodTask pour stocker les informations sur
les tâches
 for(int i = 0; i < nt; i++){ // Boucle pour chaque tâche
 T[i].id = i + 1; // Affecte un identifiant unique à chaque tâche
 T[i].P = Task_P[i]; // Affecte la période spécifiée à chaque tâche
 pthread_create(&Tr[i], NULL, TaskFunction, (void *)&T[i]); // Crée un thread pour chaque tâche,
en passant les informations de la tâche comme argument
 sleep(2); // Délai de 2 secondes entre la création de chaque thread
 for(i = 0; i < nt; i++){ // Boucle pour annuler et attendre chaque thread
 pthread_cancel(Tr[i]); // Annule le thread
 pthread_join(Tr[i], NULL); // Attend la terminaison du thread

pthread_cancel(Tr[i]); // Annule le thread
 pthread_join(Tr[i], NULL); // Attend la terminaison du thread
 }
 }
 return EXIT_SUCCESS; // Termine le programme avec succès
}
