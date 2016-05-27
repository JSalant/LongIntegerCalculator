#include "LongInt.hh"
#include <iostream>
using namespace std;

int main(){
	LongInt A;
	LongInt B;
	LongInt C;
	LongInt D;
	LongInt AX;
	LongInt AZ;
	LongInt result;
	LongInt testAdd;
	LongInt E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V;
	//extended test case variables
	LongInt E1,E2,E3,E4,E5,E6,E7,E8;
	//part 3 test case variables
	LongInt W,X,Y,Z,AA,AB,AC,AD,AE,AF,AG,AH;

	A.INITIALIZE("2222");
	B.INITIALIZE("99999999");
	C.INITIALIZE("246813575732");
	D.INITIALIZE("180270361023456789");
	AX.INITIALIZE("29302390234702973402973420937420973420937420937234872349872934872893472893749287423847");
	AZ.INITIALIZE("-98534342983742987342987339234098230498203894209928374662342342342356723423423");


/*
	AC = B / D;
	cout << "AC = B / D = ";
	AC.PRINT();
	cout << "AC has numDigits = " << AC.numDigits << endl;
//	cout << "B = ";
//	B.PRINT();
//	cout << "B has " << B.numDigits << endl;
//	D.PRINT();
//	cout << "D has " << D.numDigits << endl;
/**/
	A.PRINT();
	B.PRINT();
	C.PRINT();
	D.PRINT();
	AZ.PRINT();

	cout << "A's digit count = " << A.GETDIGITCOUNT() << endl;
	cout << "B's digit count = " << B.GETDIGITCOUNT() << endl;
	cout << "C's digit count = " << C.GETDIGITCOUNT() << endl;
	cout << "D's digit count = " << D.GETDIGITCOUNT() << endl;
	cout << "AX's digit count = " << AX.GETDIGITCOUNT() << endl;
	cout << "AZ's digit count = " << AZ.GETDIGITCOUNT() << endl;

	cout << "*** For the following comparisons, 0 = false and 1 = true ***\n";
	cout << "A's comparisons:\n";
	cout << "A > B is " << A.GREATERTHAN(&B) << endl;
	cout << "A < B is " << A.LESSTHAN(&B) << endl;
	cout << "A = B is " << A.EQUALTO(&B) << endl;
	cout << "A > C is " << A.GREATERTHAN(&C) << endl;
	cout << "A < C is " << A.LESSTHAN(&C) << endl;
	cout << "A = C is " << A.EQUALTO(&C) << endl;
	cout << "A > D is " << A.GREATERTHAN(&D) << endl;
	cout << "A < D is " << A.LESSTHAN(&D) << endl;
	cout << "A = D is " << A.EQUALTO(&D) << endl;
	cout << "A > AX is " << A.GREATERTHAN(&AX) << endl;
	cout << "A < AX is " << A.LESSTHAN(&AX) << endl;
	cout << "A = AX is " << A.EQUALTO(&AX) << endl;
	cout << "A > AZ is " << A.GREATERTHAN(&AZ) << endl;
	cout << "A < AZ is " << A.LESSTHAN(&AZ) << endl;
	cout << "A = AZ is " << A.EQUALTO(&AZ) << endl;

	cout << "B's comparisons:\n";

	cout << "B > A is " << B.GREATERTHAN(&A) << endl;
	cout << "B < A is " << B.LESSTHAN(&A) << endl;
	cout << "B = A is " << B.EQUALTO(&A) << endl;

	cout << "B > C is " << B.GREATERTHAN(&C) << endl;
	cout << "B < C is " << B.LESSTHAN(&C) << endl;
	cout << "B = C is " << B.EQUALTO(&C) << endl;

	cout << "B > D is " << B.GREATERTHAN(&D) << endl;
	cout << "B < D is " << B.LESSTHAN(&D) << endl;
	cout << "B = D is " << B.EQUALTO(&D) << endl;

	cout << "B > AX is " << B.GREATERTHAN(&AX) << endl;
	cout << "B < AX is " << B.LESSTHAN(&AX) << endl;
	cout << "B = AX is " << B.EQUALTO(&AX) << endl;

	cout << "B > AZ is " << B.GREATERTHAN(&AZ) << endl;
	cout << "B < AZ is " << B.LESSTHAN(&AZ) << endl;
	cout << "B = AZ is " << B.EQUALTO(&AZ) << endl;

	cout << "C's comparisons:\n";

	cout << "C > A is " << C.GREATERTHAN(&A) << endl;
	cout << "C < A is " << C.LESSTHAN(&A) << endl;
	cout << "C = A is " << C.EQUALTO(&A) << endl;

	cout << "C > B is " << C.GREATERTHAN(&B) << endl;
	cout << "C < B is " << C.LESSTHAN(&B) << endl;
	cout << "C = B is " << C.EQUALTO(&B) << endl;

	cout << "C > D is " << C.GREATERTHAN(&D) << endl;
	cout << "C < D is " << C.LESSTHAN(&D) << endl;
	cout << "C = D is " << C.EQUALTO(&D) << endl;

	cout << "C > AX is " << C.GREATERTHAN(&AX) << endl;
	cout << "C < AX is " << C.LESSTHAN(&AX) << endl;
	cout << "C = AX is " << C.EQUALTO(&AX) << endl;

	cout << "C > AZ is " << C.GREATERTHAN(&AZ) << endl;
	cout << "C < AZ is " << C.LESSTHAN(&AZ) << endl;
	cout << "C = AZ is " << C.EQUALTO(&AZ) << endl;

	cout << "D's comparisons:\n";

	cout << "D > A is " << D.GREATERTHAN(&A) << endl;
	cout << "D < A is " << D.LESSTHAN(&A) << endl;
	cout << "D = A is " << D.EQUALTO(&A) << endl;

	cout << "D > B is " << D.GREATERTHAN(&B) << endl;
	cout << "D < B is " << D.LESSTHAN(&B) << endl;
	cout << "D = B is " << D.EQUALTO(&B) << endl;

	cout << "D > C is " << D.GREATERTHAN(&C) << endl;
	cout << "D < C is " << D.LESSTHAN(&C) << endl;
	cout << "D = C is " << D.EQUALTO(&C) << endl;

	cout << "D > AX is " << D.GREATERTHAN(&AX) << endl;
	cout << "D < AX is " << D.LESSTHAN(&AX) << endl;
	cout << "D = AX is " << D.EQUALTO(&AX) << endl;

	cout << "D > AZ is " << D.GREATERTHAN(&AZ) << endl;
	cout << "D < AZ is " << D.LESSTHAN(&AZ) << endl;
	cout << "D = AZ is " << D.EQUALTO(&AZ) << endl;

	cout << "AX's comparisons:\n";

	cout << "AX > A is " << AX.GREATERTHAN(&A) << endl;
	cout << "AX < A is " << AX.LESSTHAN(&A) << endl;
	cout << "AX = A is " << AX.EQUALTO(&A) << endl;

	cout << "AX > B is " << AX.GREATERTHAN(&B) << endl;
	cout << "AX < B is " << AX.LESSTHAN(&B) << endl;
	cout << "AX = B is " << AX.EQUALTO(&B) << endl;

	cout << "AX > C is " << AX.GREATERTHAN(&C) << endl;
	cout << "AX < C is " << AX.LESSTHAN(&C) << endl;
	cout << "AX = C is " << AX.EQUALTO(&C) << endl;

	cout << "AX > D is " << AX.GREATERTHAN(&D) << endl;
	cout << "AX < D is " << AX.LESSTHAN(&D) << endl;
	cout << "AX = D is " << AX.EQUALTO(&D) << endl;

	cout << "AX > AZ is " << AX.GREATERTHAN(&AZ) << endl;
	cout << "AX < AZ is " << AX.LESSTHAN(&AZ) << endl;
	cout << "AX = AZ is " << AX.EQUALTO(&AZ) << endl;

	cout << "AZ's comparisons:\n";

	cout << "AZ > A is " << AZ.GREATERTHAN(&A) << endl;
	cout << "AZ < A is " << AZ.LESSTHAN(&A) << endl;
	cout << "AZ = A is " << AZ.EQUALTO(&A) << endl;

	cout << "AZ > B is " << AZ.GREATERTHAN(&B) << endl;
	cout << "AZ < B is " << AZ.LESSTHAN(&B) << endl;
	cout << "AZ = B is " << AZ.EQUALTO(&B) << endl;

	cout << "AZ > C is " << AZ.GREATERTHAN(&C) << endl;
	cout << "AZ < C is " << AZ.LESSTHAN(&C) << endl;
	cout << "AZ = C is " << AZ.EQUALTO(&C) << endl;

	cout << "AZ > D is " << AZ.GREATERTHAN(&D) << endl;
	cout << "AZ < D is " << AZ.LESSTHAN(&D) << endl;
	cout << "AZ = D is " << AZ.EQUALTO(&D) << endl;

	cout << "AZ > AX is " << AZ.GREATERTHAN(&AX) << endl;
	cout << "AZ < AX is " << AZ.LESSTHAN(&AX) << endl;
	cout << "AZ = AX is " << AZ.EQUALTO(&AX) << endl;


	E = A + D;
	cout << "E = A + D = ";
	E.PRINT();

	F = B + C;
	cout << "F = B + C = ";
	F.PRINT();

	G = C + D;
	cout << "G = C + D = ";
	G.PRINT();

	H = E + E;
	cout << "H = E + E = ";
	H.PRINT();

	I = A + E;
	cout << "I = A + E = ";
	I.PRINT();

	J = B + G;
	cout << "J = B + G = ";
	J.PRINT();

	K = A - D;
	cout << "K = A - D = ";
	K.PRINT();

	L = C - D;
	cout << "L = C - D = ";
	L.PRINT();

	M = D - C;
	cout << "M = D - C = ";
	M.PRINT();

	N = H - H;
	cout << "N = H - H = ";
	N.PRINT();

	O = L - K;
	cout << "O = L - K = ";
	O.PRINT();

	P = J - M;
	cout << "P = J - M = ";
	P.PRINT();

	Q = A * D;
	cout << "Q = A * D = ";
	Q.PRINT();

	R = B * C;
	cout << "R = B * C = ";
	R.PRINT();

	S = D * D;
	cout << "S = D * D = ";
	S.PRINT();

	T = K * E;
	cout << "T = K * E = ";
	T.PRINT();

	U = F * L;
	cout << "U = F * L = ";
	U.PRINT();
	
	V = I * J;
	cout << "V = I * J = ";
	V.PRINT();

	E1 = AX * AZ;
	cout << "E1 = AX * AZ = ";
	E1.PRINT();

	E2 = AX * AX;
	cout << "E2 = AX * AX = ";
	E2.PRINT();

	E3 = AZ * AZ;
	cout << "E3 = AZ * AZ = ";
	E3.PRINT();

	E4 = E2 * E3;
	cout << "E4 = E2 * E3 = ";
	E4.PRINT();

	E5 = AX ^ 10;
	cout << "E5 = AX ^ 10 = ";
	E5.PRINT();

	E6 = AZ ^ 14;
	cout << "E6 = AZ ^ 14 = ";
	E6.PRINT();

	E7 = E2 ^ 4;
	cout << "E7 = E2 ^ 4 = ";
	E7.PRINT();

	E8 = E3 ^ 7;
	cout << "E8 = E3 ^ 7 = ";
	E8.PRINT();

	W = D ^ 2;
	cout << "W = D ^ 2 = ";
	W.PRINT();

	X = A ^ 5;
	cout << "X = A ^ 5 = ";
	X.PRINT();

	Y = B ^ 10;
	cout << "Y = B ^ 10 = ";
	Y.PRINT();

	Z = W ^ 4;
	cout << "Z = W ^ 4 = ";
	Z.PRINT();

	AA = E ^ 2;
	cout << "AA = E ^ 2 = ";
	AA.PRINT();

	AB = K ^ 2;
	cout << "AB = K ^ 2 = ";
	AB.PRINT();

	AC = D / B;
	cout << "AC = D / B = ";
	AC.PRINT();

//crashes program, I think because I did not deal with guesses being too small
//	AD = D / A;
//	cout << "AD = D / A = ";
//	AD.PRINT();

	AE = Q / D;
	cout << "AE = Q / D = ";
	AE.PRINT();

	AF = T / K;
	cout << "AF = T / K = ";
	AF.PRINT();

	AG = H / E;
	cout << "AG = H / E = ";
	AG.PRINT();

	AH = U / U;
	cout << "AH = U / U = ";
	AH.PRINT();
}