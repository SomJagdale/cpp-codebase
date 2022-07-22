#include <iostream>

int main()
{
    char*  trackingAreaId = "00";
    char  TemptrackingAreaId[1 + 1] = {0};
    if(strcmp(trackingAreaId, "0") == 0)
        std::cout <<"both arrays are same "<<std::endl;
        else
        std::cout <<"both arrays are not same "<<trackingAreaId<<std::endl;

    return 0;
}
