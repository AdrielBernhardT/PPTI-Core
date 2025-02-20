#include <stdio.h>
int main(){
    int loop;
    scanf("%d", &loop);
    int total_halaman[loop], halaman_ke[loop];
    int genap[loop], ganjil[loop], poin[loop];
    for (int Case_num = 1; Case_num <= loop; Case_num++)
    {
        
        scanf("%d %d", &total_halaman[Case_num], &halaman_ke[Case_num]);
        
        //If 1 buat nentuin dari belakang atau depan
        if (halaman_ke[Case_num] <= total_halaman[Case_num]/2)
        {
            //if 2 buat nentuin angka total halaman genap/ganjil
           if (total_halaman[Case_num] %2 == 0)
            {
                //if 3 buat nentuin halaman ke nya genap/ganjil
                if (halaman_ke[Case_num] %2 == 0)
                {
                    //kalau genap genap poin nambah sekian
                    poin[Case_num] = halaman_ke[Case_num]/2;
                }
                else if (halaman_ke[Case_num] %2 == 1)
                {
                    //kalau genap ganjil poin nambah sekian
                    poin[Case_num] = halaman_ke[Case_num]/2;
                }
            }
            //if 2 buat nentuin angka total halaman genap/ganjil
            else if (total_halaman[Case_num] %2 == 1)
            {
                if (halaman_ke[Case_num] %2 == 0)
                {
                    //kalau ganjil genap poin nambah sekian
                    poin[Case_num] = (halaman_ke[Case_num])/2;
                }
                else if (halaman_ke[Case_num] %2 == 1)
                {
                    //kalau ganjil ganjil poin nambah sekian
                    poin[Case_num] = (halaman_ke[Case_num]/2);
                }
            }
        }
        //If 1 buat nentuin dari belakang atau depan
        else if (halaman_ke[Case_num] > total_halaman[Case_num]/2)
        {
            //if 2 buat nentuin angka total halaman genap/ganjil
           if (total_halaman[Case_num] %2 == 0)
            {
                if (halaman_ke[Case_num] %2 == 0)
                {
                     //kalau genap genap poin nambah sekian
                    poin[Case_num] = (total_halaman[Case_num]-halaman_ke[Case_num])/2;
                }
                else if (halaman_ke[Case_num] %2 == 1)
                {
                    //kalau genap ganjil poin nambah sekian
                    poin[Case_num] = ((total_halaman[Case_num]-halaman_ke[Case_num])/2) + 1;
                }
            }
            //if 2 buat nentuin angka total halaman genap/ganjil
            else if (total_halaman[Case_num] %2 == 1)
            {
                if (halaman_ke[Case_num] %2 == 0)
                {
                    //kalau ganjil genap poin nambah sekian
                    poin[Case_num] = (total_halaman[Case_num]-halaman_ke[Case_num])/2;
                }
                else if (halaman_ke[Case_num] %2 == 1)
                {
                    //kalau ganjil ganjil poin nambah sekian
                    poin[Case_num] = ((total_halaman[Case_num]-halaman_ke[Case_num])/2);
                }
            }
        }
    }
    for (int Case_num = 1; Case_num <= loop; Case_num++)
    {
        printf("Case #%d: %d\n", Case_num, poin[Case_num]);
    }
    return 0;
}