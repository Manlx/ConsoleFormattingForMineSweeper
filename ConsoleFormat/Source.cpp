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
    ~DispGrid()
    {
        delete[] CharArr;
    }
};
void GenDisplay()
{
    
    printf("  |A||B||C||D||E||F||G|\n");
    for (uint16_t x = 0; x < 10; x++)
        printf("%-2d%s\n", x, "|#||#||#||#||#||#||#|");
}
void GenDisplay(DispGrid* GridDisp)
{
    //Creats Top aplha Index
    DispGrid Temp = *GridDisp;
    int PreSize = Temp.ArrSize * 3 + 3;
    char Opening = 'A';
    char* OpeningString = new char[PreSize];
    int Counter = 0;
    OpeningString[Counter++] = ' ';
    OpeningString[Counter++] = ' ';
    while (Counter < PreSize)
    {
        OpeningString[Counter++] = '|';
        OpeningString[Counter++] = Opening++;
        OpeningString[Counter++] = '|';
    }
        
    OpeningString[PreSize-1] = 0;
    printf("%s\n",OpeningString);
    Counter = 0;
    PreSize -= 3;
    for (int x = 0; x < ArrLay.RowSize; x++)
    {
        int ArrReader = 0;
        while (Counter < PreSize)
        {
            OpeningString[Counter++] = '|';
            OpeningString[Counter++] = arr[ArrReader++];
            OpeningString[Counter++] = '|';
        }
        OpeningString[Counter] = 0;
        printf("%-2d%s\n",x,OpeningString);
    }
    //delete[] OpeningString;
}
int main()
{
    LayOut ArrLayout;
    ArrLayout.ColSize = 10;
    ArrLayout.RowSize = 10;
    int ArrSize = ArrLayout.ColSize * ArrLayout.RowSize;
    char* ArrPtr = new char[ArrSize];
    
    GenDisplay(ArrPtr,ArrLayout);
    delete[] ArrPtr;
    return 0;
}
