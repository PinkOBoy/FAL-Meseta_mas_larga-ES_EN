/*
* Solucion aportada por el profesor de la FdI (UCM):
* Solution given by FdI's (UCM) professor:
*   ANTONIO ALEJANDRO SANCHEZ RUIZ-GRANADOS
* Editada y completada por:
* Edited and completed by:
*   JAIME B.
*/
#include <iostream>
#include <vector>

using namespace std;

// PRE: v.size() > 0
int longest_plateau(const vector<int>& v) {
    int i = 1;   // next element to process // siguiente elemento a procesar
    int cp = 1;  // length of the current plateau // longitud de la meseta actual
    int lp = 1;  // length of the longest plateau so far (v[0..i-1]) // longitud de la meseta mas larga hasta ahora

    // Inv: 0 <= i <= v.size() and
    //      cp = Max a: 0 <= a < i and same_value(v, a, i-1): i-a and
    //      lp = Max a,b: 0 <= a <= b < i and same_value(v, a, b): b-a+1
    // T: v.size() - i
    while (i < v.size()) {
        if (v[i] == v[i - 1]) {
            // the plateau goes on // sigue habiendo meseta que procesar
            ++cp;
            lp = max(lp, cp);
        }
        else {
            // new value // terminamos la meseta y comenzamos a analizar una nueva
            cp = 1;
        }
        ++i;
    }
    return lp;
}
// POST:
//  lp = Max a,b: 0 <= a <= b < v.size() and same_value(v, a, b): b-a+1
//  same_value(v, a, b) =  Forall c: a <= c <= b: v[a] = v[c] 


/*COMPLEJIDAD DEL ALGORITMO
*   Sabemos que todas las instrucciones ejecutadas tienen coste constante.
*
*   Existe un bucle dentro del algoritmo que ejecuta instrucciones de coste
*   constante para, en el peor de los casos, todos los elementos del vector
*   v.
*
*   Por ello, definiendo n como el numero de elementos del vector v, podemos
*   afirmar que el coste del algoritmo será:
*
*       O(n)
*/
/*COMPLEXITY OF THE ALGORITHM
*   We know all executed instructions belong to O(1).
*
*   Inside our algorithm exists a loop, which executes instructions of constant
*   cost for, in the worst case scenario, every element of vector v.
*
*   Therefore, defining n as the number of elements of vector v, we can affirm
*   that the cost of our algorithm equals to:
*
*       O(n)
*/

bool solve() {
    // read case
    int n;
    cin >> n;
    if (n == 0)
        return false;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute and write the solution
    cout << longest_plateau(v) << endl;
    return true;
}

int main() {
    while (solve());

    return 0;
}