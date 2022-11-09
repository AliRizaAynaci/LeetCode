class Solution 
{
    const int    intgr[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string roman[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    //const degisken degerinin sabit oldugunu belirtir ve degismesini engeller
public:
    string intToRoman(int num)
    {
        string rom = "";
		
        for (int i = 0; num > 0; i++)
		    // each digit is repeated as many times as needed to 
			// completely cover the decimal representation 
            while (num >= intgr[i]) rom += roman[i], num -= intgr[i];
        return rom;
    }
};