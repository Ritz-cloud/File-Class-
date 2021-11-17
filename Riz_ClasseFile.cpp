//Rizvani David
using namespace std;
#include <iostream>
#include <fstream>

class FileByRiz
{
private:
	FILE* pFile;
	string nomeFile;

public:
	FileByRiz(string pNomeFile)
	{
		nomeFile = pNomeFile;
	}

	void WriteToFile(string dati, const char metod[])
	{
		int err = fopen_s(&pFile, nomeFile.c_str(), metod);
		if (err == 0)
		{
			fprintf(pFile, "%s", dati.c_str());
			fclose(pFile);
		}
	}

	void WriteLineToFile(string dati, const char metod[])
	{
		int err = fopen_s(&pFile, nomeFile.c_str(), metod);
		if (err == 0)
		{
			fprintf(pFile, "%s\n", dati.c_str());
			fclose(pFile);
		}
	}

	string ReadAllFile()
	{
		string dati = "";

		int err = fopen_s(&pFile, nomeFile.c_str(), "r");
		if (err == 0)
		{
			while (!feof(pFile))
			{
				char buffer = fgetc(pFile);
				if (feof(pFile) && (buffer == '\n'))
					break;

				dati += buffer;
			}
			fclose(pFile);
		}
		else
			cout << "Impossibile aprire file!";

		return dati;
	}

	string ReadLineOfFile(int riga)
	{
		char buffer[1024];
		string dati = "";
		int cont = 0;

		int err = fopen_s(&pFile, nomeFile.c_str(), "r");
		if (err == 0)
		{
			while (!feof(pFile))
			{
				fgets(buffer, _countof(buffer), pFile);

				if (riga == cont)
					dati += buffer;

				cont++;
			}
			fclose(pFile);
		}
		else
			cout << "Impossibile aprire file!";

		return dati;
	}
};

int main()
{
	FileByRiz prova("prova.txt");
	prova.WriteLineToFile("Tua nona", "a");

	cout << prova.ReadAllFile();
}
