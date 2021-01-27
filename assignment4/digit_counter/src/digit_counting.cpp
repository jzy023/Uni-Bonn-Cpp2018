#include <iostream>
#include <cmath>

double Wrap(double number, double factor) {
	number += factor;
	number -= factor;
	return number;
}


// count from roght to left
int CountSameSignificantDigits(double a, double b) {
	double aAbs = std::fabs(a);
	double bAbs = std::fabs(b);
	if(a/aAbs != b/bAbs){
		std::cout << "the numbers are with different sign\n";
	}

	// detecting scaling for the last smallest digit 
	int scale = -1;
	double aFlag, bFlag = 1;
	while(aFlag != 0 || bFlag != 0){
		aFlag = aAbs - floor(aAbs);
		bFlag = bAbs - floor(bAbs);
		aAbs = aAbs*10;
		bAbs = bAbs*10;
		scale++;
	}
	// int scale1 = pow(10,scale);
	// std::cout << "scaling: " << scale1 << std::endl;
	// std::cout << "scaled a: " << aAbs << ", " <<
	// 			 "scaled b: " << bAbs << "\n" << std::endl;

	// count for same digit 
	int ans = 0;
	for (int i = 0; i < 20; ++i)
	{
		aAbs = aAbs/10.0;
		bAbs = bAbs/10.0;
		int aDigit = 10*(aAbs - (int) aAbs);
		int bDigit = 10*(bAbs - (int) bAbs);
		aAbs = (int) aAbs; 
		bAbs = (int) bAbs; 
		// std::cout << "flag: " << (aDigit == bDigit & aDigit*bDigit != 0) << std::endl;
		// std::cout << "digit: " << aDigit << ", " << bDigit << std::endl;
		// std::cout << "ans: " << ans << "\n" << std::endl;
		if(aDigit == bDigit && aDigit*bDigit != 0){
			ans++;
		}
	}
	return ans;	
}

int main(int argc, char const *argv[])
{
	std::cout << Wrap(1.4241, 100000000) << std::endl;
	std::cout << CountSameSignificantDigits(-12552.22222, 2.42) << std::endl;
	return 0;
}