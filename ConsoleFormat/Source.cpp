#include <iostream>
#define Log(x) std::cout << x << std::endl

class DispGrid
{
public:
    //Size and location information of Array
    unsigned int Rows, Cols, ArrSize;
    char* CharArr;
    DispGrid()
    {
        Rows = 0;
        Cols = 0;
        ArrSize = 0;
        CharArr = new char[0];
    }
    DispGrid(unsigned int R = 0, unsigned int C = 0): Rows(R),Cols(C)
    {
        ArrSize = R * C;
        CharArr = new char[ArrSize ];
    }
    void ChangeValue(unsigned int Row, unsigned int Col, char Value)
    {
        this->CharArr[Row * this->Cols + Col] = Value;
    }
    void GenDisplay()
    {
        //Clears Console
        Log("\x1B[2J\x1B[H");
        //std::system("cls");
        //Creats Top aplha Index
        int PreSize = this->Cols * 3;
        char Opening = 'A';
        char* OpeningString = new char[PreSize];
        int Counter = 0;
        while (Counter < PreSize)
        {
            OpeningString[Counter++] = '|';
            OpeningString[Counter++] = Opening++;
            OpeningString[Counter++] = '|';
        }
        OpeningString[PreSize] = 0;
        printf("%-2s%s\n", "  ", OpeningString);

        for (int x = 0; x < this->Rows; x++)
        {
            Counter = 0;
            int ArrReader = x * this->Cols;
            while (Counter < PreSize)
            {
                OpeningString[Counter++] = '|';
                OpeningString[Counter++] = this->CharArr[ArrReader++];
                OpeningString[Counter++] = '|';
            }
            OpeningString[Counter] = 0;
            printf("%-2d%s\n", x, OpeningString);
        }
    }
    ~DispGrid()
    {
        delete[] CharArr;
    }
};

char CToUp(char cIn)
{
    if (cIn > 90)
        return cIn - 32;
}
int main()
{
    DispGrid MainGrid(10,10);

    MainGrid.GenDisplay();
    char cCol,cValue;
    unsigned int iRow,iCol;
    std::cout << "Select Colom: ";
    std::cin >> cCol;
    cCol = CToUp(cCol);
    iCol = cCol - 'A';
    std::cout << "Select Row: ";
    std::cin >> iRow;
    std::cout << "Value to to Change: ";
    std::cin >> cValue;
    MainGrid.ChangeValue(iRow, iCol,cValue);
    MainGrid.GenDisplay();
    return 0;
}
