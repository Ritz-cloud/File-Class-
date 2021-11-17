// File_fprintf_fscanf.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
using namespace std;
#include <iostream>
#include <fstream>

class FileByRiz
{
private:
	FILE* pFile;

public:
	FileByRiz(const char nomeFile[], const char metodoDiApertura[])
	{
		fopen_s(&pFile, nomeFile, metodoDiApertura);
	}

	FileByRiz()
	{
		fopen_s(&pFile, "nonamed.txt", "w+");
	}

	void WriteFile(string dati)
	{
		fprintf(pFile, "%s", dati.c_str());
	}

	string ReadAllFile()
	{
		char buffer[1024];
		string dati = "";

		while (!feof(pFile))
		{
			fgets(buffer, _countof(buffer), pFile);
			dati += buffer;
		}

		return dati;
	}

	string ReadLineOfFile(int riga)
	{
		char buffer[1024];
		string dati = "";
		int cont = 0;

		while (!feof(pFile))
		{
			fgets(buffer, _countof(buffer), pFile);

			if(riga == cont)
			dati += buffer;

			cont++;
		}

		return dati;
	}

	void Close()
	{
		fclose(pFile);
	}
};

int main()
{
  //Sovrascrivi/scrivi il file 
	FileByRiz prova("prova.txt", "w");
	prova.WriteFile("Emiddio e' BLL");
	prova.Close();

  //Leggi tutto il file
	FileByRiz prova1("prova.txt", "r");
	cout << prova1.ReadAllFile();
	prova1.Close();
  
  //Leggi la riga che vuoi tu
	//FileByRiz prova2("prova.txt", "r");
	//cout << prova2.ReadLineOfFile(1);
	//prova2.Close();
}
