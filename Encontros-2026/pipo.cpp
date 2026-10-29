#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[]) {
	// Acelera entrada/saída no terminal.
	// Em problemas de programação competitiva isso evita lentidão desnecessária.
	std::ios::sync_with_stdio(false);
	// Evita flush automático de cout antes de cada leitura em cin.
	// Também melhora desempenho.
	std::cin.tie(nullptr);

	// Usamos um ponteiro para std::istream para unificar a leitura:
	// tanto faz se a origem é teclado (cin) ou arquivo (ifstream).
	std::istream* in = &std::cin;
	// ifstream é a classe padrão da STL para leitura de arquivos.
	std::ifstream arquivo;

	// Se veio argumento de linha de comando, interpretamos como arquivo de entrada.
	// Exemplo: PipoFoguete.exe entrada.txt
	if (argc > 1) {
		arquivo.open(argv[1]);
		if (!arquivo.is_open()) {
			std::cerr << "Erro ao abrir arquivo de entrada.\n";
			return 1;
		}
		in = &arquivo;
	} else {
		// Sem argumento, tenta um arquivo padrão para facilitar execução no Visual Studio.
		// Se não existir, o programa continua lendo do teclado (cin).
		arquivo.open("entrada.txt");
		if (arquivo.is_open()) {
			in = &arquivo;
		}
	}

	int n;
	// Se não conseguir ler N, encerramos silenciosamente.
	// Isso evita comportamento indefinido em entrada vazia.
	if (!(*in >> n)) {
		return 0;
	}

	// vector é usado porque o tamanho só é conhecido em tempo de execução (N).
	// Ele gerencia memória automaticamente e é a escolha idiomática em C++ moderno.
	std::vector<int> cargas(n);
	for (int i = 0; i < n; ++i) {
		*in >> cargas[i];
		// Regra do problema: cargas zero ou negativas devem virar 1.
		if (cargas[i] <= 0) {
			cargas[i] = 1;
		}
	}

	// Imprime em uma única linha, separados por espaço, sem espaço no final.
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			std::cout << ' ';
		}
		std::cout << cargas[i];
	}
	std::cout << '\n';

	return 0;
}
