#include <iostream>
#include <iomanip>
#include <vector>
#include <array>

using namespace std;

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
int main() {
	
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