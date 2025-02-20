#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Struct Station
struct DataBase {
    char Location[105];
    char City[105];
    long int Price;
    int Rooms;
    int Bathroom;
    char Carpark[5];
    char Type[105];
    char Furnish[105];
} DB[9999];

typedef enum SortOrder{ascending,descending,Error}Order;
typedef enum SortBy{Location,City,Price,Rooms,Bathroom,Carpark,Type,Furnish,Error}Mode;
const char col[8][20] = {"Location","City","Price","Rooms","Bathroom","Carpark","Type","Furnish"};

Order GetOrder(char *x){
    int i;
    for(i=0;i<2;i++){
        if(strcmp(x,col[i])==0){
            return (Order)i;
        }
    }
    return (Order)2;
}

Mode GetMode(char *x) {
    int i;
    for(i=0;i<8;i++) {
        if(strcmp(x,col[i])==0) {
            return (Mode)i;
        }
    }
    return (Mode)8;
}

// Scan Function [v]
void Scaning(FILE* fp, struct DataBase DB[], int *i){
    char unusedstring[105];
    fscanf(fp, "%[^\n]\n", unusedstring);
    // Buat hilangin kalimat Location 1,Location 2,Price,Rooms,Bathrooms,CarParks,Type,Furnish
    while (!feof(fp)){
        fscanf(fp, "%[^,],%[^,],%ld,%d,%d,%[^,],%[^,],%[^\n]\n", DB[*i].Location, DB[*i].City, &DB[*i].Price, &DB[*i].Rooms, &DB[*i].Bathroom, DB[*i].Carpark, DB[*i].Type, DB[*i].Furnish);
        (*i)++;
        // Scaning File sisanya selain Location 1,Location 2,Price,Rooms,Bathrooms,Car Parks,Type,Furnish
    }
}

// Function untuk 1. Display Data [v]
void DisplayData(struct DataBase DB[], int row){
    printf("Location\tCity\t\tPrice\t\tRooms\t\tBathroom\tCarpark\t\tType\t\t\tFurnish\n");
    for (int i = 0; i < row; i++) {
        printf("%-14s\t%-10s\t%-10ld\t%-10d\t%-10d\t%-10s\t%-10s\t\t%-10s\n", DB[i].Location, DB[i].City, DB[i].Price, DB[i].Rooms, DB[i].Bathroom, DB[i].Carpark, DB[i].Type, DB[i].Furnish);
    }
}

// Function untuk 2. Search Data [v]
// Menurut Location
void SearchDataLocation(struct DataBase DB[], int size, char* data){
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(DB[i].Location, data) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("Data found. Detail of data:\n");
        printf("Location\t\tCity\t\tPrice\t\tRooms\t\tBathroom\tCarpark\t\tType\t\t\tFurnish\n");
    } else {
        printf("Data not Found!\n");
    }

    for (int i = 0; i < size; i++) {
        if (strcmp(DB[i].Location, data) == 0) {
            printf("%-17s\t%-10s\t%-10ld\t%-10d\t%-10d\t%-10s\t%-10s\t\t%-10s\n", DB[i].Location, DB[i].City, DB[i].Price, DB[i].Rooms, DB[i].Bathroom, DB[i].Carpark, DB[i].Type, DB[i].Furnish);
        }
    }
}

// Menurut City
void SearchDataCity(struct DataBase* DB, int size, char* data){
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(DB[i].City, data) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Data found. Detail of data:\n");
        printf("Location\t\tCity\t\tPrice\t\tRooms\t\tBathroom\tCarpark\t\tType\t\t\tFurnish\n");
    }
    else
    {
        printf("Data not Found!\n");
    }
    for (int i = 0; i < size; i++)
    {
        if (strcmp(DB[i].City, data) == 0)
        {
            printf("%-17s\t%-10s\t%-10ld\t%-10d\t%-10d\t%-10s\t%-10s\t\t%-10s\n", DB[i].Location, DB[i].City, DB[i].Price, DB[i].Rooms, DB[i].Bathroom, DB[i].Carpark, DB[i].Type, DB[i].Furnish);
        }
    }
}

// Menurut Price
void SearchDataPrice(struct DataBase* DB, int size, char* data) {
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (DB[i].Price == atoi(data)) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("Data found. Detail of data:\n");
        printf("Location\t\tCity\t\tPrice\t\tRooms\t\tBathroom\tCarpark\t\tType\t\t\tFurnish\n");
    } else {
        printf("Data not Found!\n");
    }
    for (int i = 0; i < size; i++) {
        if (DB[i].Price == atoi(data)) {
            printf("%-17s\t%-10s\t%-10ld\t%-10d\t%-10d\t%-10s\t%-10s\t\t%-10s\n", DB[i].Location, DB[i].City, DB[i].Price, DB[i].Rooms, DB[i].Bathroom, DB[i].Carpark, DB[i].Type, DB[i].Furnish);
        }
    }
}

// Menurut Rooms
void SearchDataRooms(struct DataBase* DB, int size, char* data) {
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (DB[i].Rooms == atoi(data)) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("Data found. Detail of data:\n");
        printf("Location\t\tCity\t\tPrice\t\tRooms\t\tBathroom\tCarpark\t\tType\t\t\tFurnish\n");
    } else {
        printf("Data not Found!\n");
    }

    for (int i = 0; i < size; i++) {
        if (DB[i].Rooms == atoi(data)) {
            printf("%-17s\t%-10s\t%-10ld\t%-10d\t%-10d\t%-10s\t%-10s\t\t%-10s\n", DB[i].Location, DB[i].City, DB[i].Price, DB[i].Rooms, DB[i].Bathroom, DB[i].Carpark, DB[i].Type, DB[i].Furnish);
        }
    }
}

// Menurut Bathroom
void SearchDataBathroom(struct DataBase* DB, int size, char* data) {
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (DB[i].Bathroom == atoi(data)) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("Data found. Detail of data:\n");
        printf("Location\t\tCity\t\tPrice\t\tRooms\t\tBathroom\tCarpark\t\tType\t\t\tFurnish\n");
    } else {
        printf("Data not Found!\n");
    }
    for (int i = 0; i < size; i++) {
        if (DB[i].Bathroom == atoi(data)) {
            printf("%-17s\t%-10s\t%-10ld\t%-10d\t%-10d\t%-10s\t%-10s\t\t%-10s\n", DB[i].Location, DB[i].City, DB[i].Price, DB[i].Rooms, DB[i].Bathroom, DB[i].Carpark, DB[i].Type, DB[i].Furnish);
        }
    }
}

// Menurut Carpark
void SearchDataCarpark(struct DataBase* DB, int size, char* data){
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(DB[i].Carpark, data) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("Data found. Detail of data:\n");
        printf("Location\t\tCity\t\tPrice\t\tRooms\t\tBathroom\tCarpark\t\tType\t\t\tFurnish\n");
    } else {
        printf("Data not Found!\n");
    }
    for (int i = 0; i < size; i++) {
        if (strcmp(DB[i].Carpark, data) == 0) {
            printf("%-17s\t%-10s\t%-10ld\t%-10d\t%-10d\t%-10s\t%-10s\t\t%-10s\n", DB[i].Location, DB[i].City, DB[i].Price, DB[i].Rooms, DB[i].Bathroom, DB[i].Carpark, DB[i].Type, DB[i].Furnish);
        }
    }
}

// Menurut Type
void SearchDataType(struct DataBase* DB, int size, char* data){
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(DB[i].Type, data) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("Data found. Detail of data:\n");
        printf("Location\t\tCity\t\tPrice\t\tRooms\t\tBathroom\tCarpark\t\tType\t\t\tFurnish\n");
    } else {
        printf("Data not Found!\n");
    }
    for (int i = 0; i < size; i++) {
        if (strcmp(DB[i].Type, data) == 0) {
            printf("%-17s\t%-10s\t%-10ld\t%-10d\t%-10d\t%-10s\t%-10s\t\t%-10s\n", DB[i].Location, DB[i].City, DB[i].Price, DB[i].Rooms, DB[i].Bathroom, DB[i].Carpark, DB[i].Type, DB[i].Furnish);
        }
    }
}

// Menurut Furnish
void SearchDataFurnish(struct DataBase* DB, int size, char* data){
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(DB[i].Furnish, data) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("Data found. Detail of data:\n");
        printf("Location\t\tCity\t\tPrice\t\tRooms\t\tBathroom\tCarpark\t\tType\t\t\tFurnish\n");
    } else {
        printf("Data not Found!\n");
    }
    for (int i = 0; i < size; i++) {
        if (strcmp(DB[i].Furnish, data) == 0) {
            printf("%-17s\t%-10s\t%-10ld\t%-10d\t%-10d\t%-10s\t%-10s\t\t%-10s\n", DB[i].Location, DB[i].City, DB[i].Price, DB[i].Rooms, DB[i].Bathroom, DB[i].Carpark, DB[i].Type, DB[i].Furnish);
        }
    }
}



// Function untuk 3. Sort Data [v]
// Sorting Function
Order GetOrder(char *x){
    if(strcmp(x,"asc") == 0 || strcmp(x,"ascending") == 0 || strcmp(x,"Ascending") == 0 || strcmp(x,"Asc") == 0) {
        return ascending;
    } else if (strcmp(x,"des") == 0 || strcmp(x,"descending") == 0 || strcmp(x,"Descending") == 0 || strcmp(x,"dsc") == 0 || strcmp(x,"Dsc") == 0 || strcmp(x,"Des") == 0) {
        return descending;
    } else {
        return Error;
    }
}

int CompareData(struct DataBase A,struct DataBase B, Mode mode,Order order){
    int result;
    if(mode == Location)
    {
        result = strcmp(A.Location,B.Location);
    }
    else if(mode == City)
    {
        result = strcmp(A.City,B.City);
    }
    else if(mode == Price)
    {
        result = A.Price-B.Price;
    }
    else if(mode == Rooms)
    {
        result = A.Rooms-B.Rooms;
    }
    else if(mode == Bathroom)
    {
        result = A.Bathroom-B.Bathroom;
    }
    else if(mode == Carpark)
    {
        result = A.Carpark-B.Carpark;
    }
    else if(mode == Type)
    {
        result = strcmp(A.Type,B.Type);
    }
    else if(mode == Furnish)
    {
        result = strcmp(A.Furnish,B.Furnish);
    }
    if(order == descending)
    {
        return result;
    }
    else if(order == ascending)
    {
        return result*-1;
    }
}

void MergeAll(struct DataBase* arr,int low,int mid,int high,Mode mode,Order order){
    int L = mid - low + 1;
    int R = high - mid;
    struct DataBase A[L],B[R];
    int i,j,k=low;
    for(i=0;i<L;i++)A[i]=arr[low+i];
    for(j=0;j<R;j++)B[j]=arr[mid+j+1];
    i=0;j=0;
    while(i < L && j < R){
        if(CompareData(A[i],B[j],mode,order) > 0){
            arr[k++]=A[i++];
        }else{
            arr[k++]=B[j++];
        }
    }
    while(i<L){
        arr[k++]=A[i++];
    }
    while(j<R){
        arr[k++]=B[j++];
    }
}

void SortData(struct DataBase* arr,int low,int high,Mode mode,Order order){
    if(low < high){
        int mid = low + (high-low)/2;
        SortData(arr,low,mid,mode,order);
        SortData(arr,mid+1,high,mode,order);
        MergeAll(arr,low,mid,high,mode,order);
    }
}

int main(){
    // Declare station
    int choice;
    int idx = 0;

    // Starting Process
    FILE* fp = fopen("file.csv", "r");
    Scaning(fp, DB, &idx);
    fclose(fp);

    do {
        printf("Press Enter to Continue..."); getchar();
        system("cls");
        printf("What do you want to do?\n1. Display data\n2. Search Data\n3. Sort Data\n4. Export Data\n5. Exit\nYour choice: ");
        scanf("%d", &choice); getchar();
        // Starting Choose
        if (choice < 5) {
            // 1. Display data
            if (choice == 1) {
                int row;
                printf("Number of rows: ");
                scanf("%d", &row); getchar();
                DisplayData(DB, row);
            }
            // 2. Search Data
            else if (choice == 2) {
                char data[25];
                char col[25];
                FILE* fp = fopen("file.csv", "r");
                printf("Choose column: ");
                scanf("%[^\n]", &col); getchar();
                printf("What data do you want to find? ");
                scanf("%s", &data); getchar();
                if (strcmp(col,"Location") == 0) {
                    SearchDataLocation(DB, idx, data);
                } else if (strcmp(col,"City") == 0) {
                    SearchDataCity(DB, idx, data);
                } else if (strcmp(col,"Price") == 0) {
                    SearchDataPrice(DB, idx, data);
                } else if (strcmp(col,"Rooms") == 0) {
                    SearchDataRooms(DB, idx, data);
                } else if (strcmp(col,"Bathroom") == 0) {
                    SearchDataBathroom(DB, idx, data);
                } else if (strcmp(col,"Carpark") == 0) {
                    SearchDataCarpark(DB, idx, data);
                } else if (strcmp(col,"Type") == 0) {
                    SearchDataType(DB, idx, data);
                } else if (strcmp(col,"Furnish") == 0) {
                    SearchDataFurnish(DB, idx, data);
                } else {
                    printf("Data Not Found!\n");
                }
                fclose(fp);
            }
            // 3. Sort Data
            else if (choice == 3)
            {
                char col[25];
                char ketentuan[5];
                int row = 10;
                FILE* fp = fopen("file.csv", "r");
                printf("Choose column: ");
                scanf("%[^\n]", &col); getchar();
                printf("Sort ascending or descending? ");
                scanf("%[^\n]", &ketentuan); getchar();
                SortData(DB,0,idx-1,GetMode(col),GetOrder(ketentuan));
                DisplayData(DB, row);
                fclose(fp);
            }
            // 4. Export Data
            else if (choice == 4)
            {
                char namafile[15];
                printf("File name: ");
                scanf("%s", &namafile); getchar();
                strcat(namafile,".csv");
                FILE* fp = fopen(namafile, "w");
                printf("Data successfully written to file %s!\n", namafile);
                fprintf(fp,"Location 1,Location 2,Price,Rooms,Bathrooms,CarParks,Type,Furnish\n");
                for(int i = 0; i < idx; i++)
                {
                    fprintf(fp, "%s,%s,%ld,%d,%d,%s,%s,%s\n", DB[i].Location, DB[i].City, DB[i].Price, DB[i].Rooms, DB[i].Bathroom, DB[i].Carpark, DB[i].Type, DB[i].Furnish);
                }
                fclose(fp);
            }
        }
        else
        {
            continue;
        }
    } while (choice != 5);
    return 0;
}