#include <iostream>
#include <iomanip>
#include <vector>
#include <array>

using namespace std;
// partie 1
void saisirNotes(vector<double>& v, int n) {
	double note;
	for (int i = 0; i < n; ++i) {
		cout << "Entrer la note de l'etudiant " << i + 1 << " :";
		cin >> note;
		v.push_back(note);
	}
}
void afficherNotes(const vector<double>& v) {
	
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}

double calculerMoyenne(const vector<double>& v) {
	double m = 0;
	for (size_t i = 0; i < v.size(); i++) {
		m += v[i];
	}
	return m / v.size();
}
double trouverNoteMaximale(const vector<double>& v) {
	double max = 0;
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i] > max)
			max = v[i];

	}
	return max;
}
void ajouterNotes(vector<double>& v, int n) {
	saisirNotes(v, n);
}
int main_p1() {
	
	int N1, N2;
	vector<double> notes;
	// Saisie des notes initiales
	cout << "Combien d'etudiants dans la classe initiale ? ";
	cin >> N1;
	saisirNotes(notes, N1);
	// Affichage des notes
	afficherNotes(notes);
	// Calcul et affichage de la moyenne des notes
	double moyenne = calculerMoyenne(notes);
	cout << "Moyenne des notes : " << fixed << setprecision(2) <<
		moyenne << endl;
	// Recherche et affichage de la note maximale
	double noteMax = trouverNoteMaximale(notes);
	cout << "Note maximale : " << noteMax << endl;
	// Ajout des notes des nouveaux etudiants
	cout << "Combien de nouveaux etudiants rejoignent la classe ?";
	cin >> N2;
	ajouterNotes(notes, N2);
	// Affichage des notes apres ajout
	afficherNotes(notes);
	// Recalcul et affichage de la nouvelle moyenne des notes
	moyenne = calculerMoyenne(notes);
	cout << "Nouvelle moyenne des notes : " << moyenne << endl;
	// Recherche et affichage de la nouvelle note maximale
	noteMax = trouverNoteMaximale(notes);
	cout << "Nouvelle note maximale : " << noteMax << endl;
	return 0;
}
// partie 2




const int N1 = 5;
const int N2 = 3;

void saisirNotes(array<double,N1>& arr, int& count ) {
	
	for (int i = 0; i < N1; i++) {
		cout << "Entrer la note de l'etudiant " << i + 1 << " :";
		cin >> arr[i];
		count++;
	}
	

}

void etendreTableau(const array<double, N1>& arr1, array<double, N1 + N2>& arr2, int& count) {
	for (int i = 0; i < N1; ++i) {
		arr2[i] = arr1[i];
	
	}
}

void afficherNotes(const array<double, N1 + N2>& arr, int count) {
	for (int i = 0; i < count; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void ajouterNotes(array < double, N1 + N2>& notesEtendues, int& count) {
	for (int i = N1; i < N1+N2; i++) {
		cout << "Entrer la note de l'etudiant " << i+1 << " :";
		cin >> notesEtendues[i];
		count++;
	}
	
}
double calculerMoyenne(const array<double, N1 + N2>& arr, int count) {
	double m = 0;
	for (size_t i = 0; i < count; i++) {
		m += arr[i];
	}
	return m / count;
}
double trouverNoteMaximale(const array<double, N1 + N2>& arr, int count) {
	double max = 0;
	for (size_t i = 0; i < count; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int main() {
	array<double, N1> notesInitiales = { 0 };
	int count = 0; // contient le nombre d’etudiants saisi
	// Saisie des notes initiales
	cout << "Saisie des notes des " << N1 << " etudiants de la classe initiale." << endl;
		saisirNotes(notesInitiales, count);
	// Extension du tableau pour inclure les nouveaux	etudiants
		array<double, N1 + N2> notesEtendues = { 0 };
	etendreTableau(notesInitiales, notesEtendues, count);
	// Affichage des notes
	afficherNotes(notesEtendues, count);
	// Calcul et affichage de la moyenne des notes
	double moyenne = calculerMoyenne(notesEtendues, count);
	cout << "Moyenne des notes : " << fixed << setprecision(2)
		<< moyenne << endl;
	// Recherche et affichage de la note maximale
	double noteMax = trouverNoteMaximale(notesEtendues,count);
	cout << "Note maximale : " << noteMax << endl;
	// Ajout des notes des nouveaux etudiants
	cout << "Saisie des notes des " << N2 << " nouveaux etudiants." << endl;
		ajouterNotes(notesEtendues, count);
	 
		// Affichage des notes apres ajout
		afficherNotes(notesEtendues, count);
	// Recalcul et affichage de la nouvelle moyenne des notes
	moyenne = calculerMoyenne(notesEtendues, count);
	cout << "Nouvelle moyenne des notes : " << moyenne << 		endl;
	// Recherche et affichage de la nouvelle note maximale
	noteMax = trouverNoteMaximale(notesEtendues, count);
	cout << "Nouvelle note maximale : " << noteMax << endl;
	return 0;
}