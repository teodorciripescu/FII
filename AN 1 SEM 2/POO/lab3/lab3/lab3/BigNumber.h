class BigNumber {

private:

	char Number[256];// ascii: 48 - 57 cifre 0 - 9

	int  CharactersCount;

public:

	BigNumber(); // Constructor implicit (creaza numarul 0 [field-ul Number contine "0", field-ul CharactersCount contine valoarea 1 - un caracter]

	BigNumber(int value);

	BigNumber(const char * number);

	BigNumber(const BigNumber & number);



	bool Set(int value);

	bool Set(const char * number);



	BigNumber operator+ (const BigNumber & number);
	//adunari repetate
	BigNumber operator* (const BigNumber & number);

	BigNumber operator- (const BigNumber & number);
	//scaderi repetate
	BigNumber operator/ (const BigNumber & number);


	friend bool operator == (const BigNumber & n1, const BigNumber & n2);

	friend bool operator != (const BigNumber & n1, const BigNumber & n2);

	friend bool operator <  (const BigNumber & n1, const BigNumber & n2);

	friend bool operator >  (const BigNumber & n1, const BigNumber & n2);

	friend bool operator >= (const BigNumber & n1, const BigNumber & n2);

	friend bool operator <= (const BigNumber & n1, const BigNumber & n2);

	operator int();
	// returneaza caracterul de pe pozitia index sau \0 in rest
	char operator[] (int index); 

	// returneaza numarul de la caracterul dat de pozitia "start" pana la caracterul dat de pozitia "end" sau "0" daca start/end nu sunt valide.
	BigNumber operator() (int start, int end); 
};