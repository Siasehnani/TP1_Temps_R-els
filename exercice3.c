// Fonction exécutée par le premier thread
void *Tache1(void *arg){
 int i = 0;
 while(i < 5) {
 printf("Execution de Tache1\n"); // Affiche un message
 sleep(1); // Pause d'une seconde
 i++; }
 return NULL; // Termine le thread}
// Fonction exécutée par le deuxième thread
void *Tache2(void *arg)
{ int j = 0;
 while(j < 3) {
 printf("Execution de Tache2\n"); // Affiche un message
 sleep(2); // Pause de deux secondes
 j++; }
 return NULL; // Termine le thread}
int main(int argc, char *argv[])
{
 pthread_t thread1, thread2; // Identifiants des threads
 // Création du premier thread
 pthread_create(&thread1, NULL, Tache1, NULL);
 // Création du deuxième thread
 pthread_create(&thread2, NULL, Tache2, NULL);
 // Attente de la fin de l'exécution du premier thread
 pthread_join(thread1, NULL);
 // Attente de la fin de l'exécution du deuxième thread
 pthread_join(thread2, NULL);
 return EXIT_SUCCESS; // Fin du programme avec un code de succès}
 // représente la tâche exécutée par thread 1
void *Tache1(void *arg) {
 int i = 0;
 while(i < 5) { // afficher "Execution de Tache1" cinq fois avec un intervalle de 1 seconde entre chaque
affichage.
 printf("Execution de Tache1\n");
 sleep(1);
 i++; }
 return NULL;}
// représente la tâche exécutée par thread 2
void *Tache2(void *arg) {
 int j = 0;
 while(j < 3) { // afficher "Execution de Tache2" trois fois avec un intervalle de 2 secondes entre
chaque affichage.
 printf("Execution de Tache2\n");
 sleep(2);
 j++; }
 return NULL;}
int main(int argc, char *argv[]) {
 pthread_t thread1, thread2;
 // Création du premier thread pour exécuter Tache1
 pthread_create(&thread1, NULL, Tache1, NULL);
 // Attente de la fin du premier thread
 pthread_join(thread1, NULL);
 // Création du deuxième thread pour exécuter Tache2
 pthread_create(&thread2, NULL, Tache2, NULL);
 // Attente de la fin du deuxième thread
 pthread_join(thread2, NULL);
 return EXIT_SUCCESS;
