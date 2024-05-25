#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;

const string ASC_TABLE = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`.";

// Função para converter um byte em um caractere ASCII
char byteToAscChar(unsigned char byte) {
    size_t index = static_cast<size_t>(byte * (ASC_TABLE.size() - 1) / 255);
    return ASC_TABLE[index];
}

// Função para ler a largura e altura de uma imagem .foo
void readDimensions(ifstream& file, int& width, int& height) {
    file >> width >> height;
    file.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o restante da linha
}

// Função para converter uma imagem .foo em uma imagem .foo2
void convertImage(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile) {
        cerr << "Erro ao abrir o arquivo de entrada." << endl;
        exit(-1);
    }

    int width, height;
    readDimensions(inFile, width, height);

    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Erro ao abrir o arquivo de saída." << endl;
        exit(-1);
    }

    outFile << width << " " << height << endl;

    unsigned char byte;
    while (inFile.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
        outFile << byteToAscChar(byte);
    }

    inFile.close();
    outFile.close();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <arquivo .foo> <arquivo .foo2>" << endl;
        return -1;
    }

    const string inputFile = argv[1];
    const string outputFile = argv[2];

    convertImage(inputFile, outputFile);

    return 0;
}