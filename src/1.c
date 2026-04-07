#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "travel.dat"
#define MAX 50

// -------- STRUCTURE --------
typedef struct {
    char destinations[MAX][50];
    int graph[MAX][MAX];   // connection price
    int destCount;
} TravelGraph;

TravelGraph g;

// -------- FUNCTION DECLARATIONS --------
void saveData();
void loadData();

int findDestination(char name[]);
void addDestination();

void addRoute();
void deleteRoute();
void updateRoute();
void searchRoute();

void bookTrip();
void displayGraph();

// -------- SAVE DATA --------
void saveData() {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) {
        printf("Error saving data\n");
        return;
    }

    fwrite(&g, sizeof(TravelGraph), 1, fp);
    fclose(fp);
}

// -------- LOAD DATA --------
void loadData() {
    FILE *fp = fopen(FILE_NAME, "rb");

    if (!fp) {
        g.destCount = 0;
        return;
    }

    fread(&g, sizeof(TravelGraph), 1, fp);
    fclose(fp);
}

// -------- FIND DESTINATION --------
int findDestination(char name[]) {

    for(int i=0;i<g.destCount;i++) {
        if(strcmp(g.destinations[i],name)==0)
            return i;
    }

    return -1;
}

// -------- ADD DESTINATION --------
void addDestination() {

    char name[50];

    printf("Enter destination name: ");
    getchar();
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")] = '\0';

    if(findDestination(name)!=-1){
        printf("Destination already exists!\n");
        return;
    }

    strcpy(g.destinations[g.destCount],name);

    for(int i=0;i<=g.destCount;i++){
        g.graph[g.destCount][i]=0;
        g.graph[i][g.destCount]=0;
    }

    g.destCount++;

    saveData();

    printf("Destination added successfully!\n");
}

// -------- ADD ROUTE --------
void addRoute(){

    char src[50],dest[50];
    int price;

    printf("Enter source destination: ");
    getchar();
    fgets(src,sizeof(src),stdin);
    src[strcspn(src,"\n")] = '\0';

    printf("Enter destination: ");
    fgets(dest,sizeof(dest),stdin);
    dest[strcspn(dest,"\n")] = '\0';

    int s=findDestination(src);
    int d=findDestination(dest);

    if(s==-1 || d==-1){
        printf("Destination not found!\n");
        return;
    }

    printf("Enter travel price: ");
    scanf("%d",&price);

    g.graph[s][d]=price;

    saveData();

    printf("Route added successfully!\n");
}

// -------- DELETE ROUTE --------
void deleteRoute(){

    char src[50],dest[50];

    printf("Enter source: ");
    getchar();
    fgets(src,sizeof(src),stdin);
    src[strcspn(src,"\n")] = '\0';

    printf("Enter destination: ");
    fgets(dest,sizeof(dest),stdin);
    dest[strcspn(dest,"\n")] = '\0';

    int s=findDestination(src);
    int d=findDestination(dest);

    if(s==-1 || d==-1 || g.graph[s][d]==0){
        printf("Route not found!\n");
        return;
    }

    g.graph[s][d]=0;

    saveData();

    printf("Route deleted successfully!\n");
}

// -------- UPDATE ROUTE --------
void updateRoute(){

    char src[50],dest[50];
    int price;

    printf("Enter source: ");
    getchar();
    fgets(src,sizeof(src),stdin);
    src[strcspn(src,"\n")] = '\0';

    printf("Enter destination: ");
    fgets(dest,sizeof(dest),stdin);
    dest[strcspn(dest,"\n")] = '\0';

    int s=findDestination(src);
    int d=findDestination(dest);

    if(s==-1 || d==-1 || g.graph[s][d]==0){
        printf("Route not found!\n");
        return;
    }

    printf("Enter new price: ");
    scanf("%d",&price);

    g.graph[s][d]=price;

    saveData();

    printf("Route updated successfully!\n");
}

// -------- SEARCH ROUTE --------
void searchRoute(){

    char src[50],dest[50];

    printf("Enter source: ");
    getchar();
    fgets(src,sizeof(src),stdin);
    src[strcspn(src,"\n")] = '\0';

    printf("Enter destination: ");
    fgets(dest,sizeof(dest),stdin);
    dest[strcspn(dest,"\n")] = '\0';

    int s=findDestination(src);
    int d=findDestination(dest);

    if(s==-1 || d==-1 || g.graph[s][d]==0){
        printf("Route not available!\n");
        return;
    }

    printf("Travel route available! Price = %d\n",g.graph[s][d]);
}

// -------- BOOK TRIP --------
void bookTrip(){

    char src[50],dest[50];
    int seats;

    printf("Enter source destination: ");
    getchar();
    fgets(src,sizeof(src),stdin);
    src[strcspn(src,"\n")] = '\0';

    printf("Enter destination: ");
    fgets(dest,sizeof(dest),stdin);
    dest[strcspn(dest,"\n")] = '\0';

    int s=findDestination(src);
    int d=findDestination(dest);

    if(s==-1 || d==-1 || g.graph[s][d]==0){
        printf("Route not available!\n");
        return;
    }

    printf("Enter number of seats: ");
    scanf("%d",&seats);

    int total = seats * g.graph[s][d];

    printf("\nTrip Booked Successfully!\n");
    printf("Total Cost = %d\n",total);
}

// -------- DISPLAY GRAPH --------
void displayGraph(){

    printf("\nDestination Connection Graph\n\n");

    printf("\t");

    for(int i=0;i<g.destCount;i++)
        printf("%s\t",g.destinations[i]);

    printf("\n");

    for(int i=0;i<g.destCount;i++){

        printf("%s\t",g.destinations[i]);

        for(int j=0;j<g.destCount;j++){
            printf("%d\t",g.graph[i][j]);
        }

        printf("\n");
    }
}

// -------- MAIN --------
int main(){

    int choice;

    loadData();

    do{

        printf("\nTravel Booking Platform\n");
        printf("1.Add Destination\n");
        printf("2.Add Route\n");
        printf("3.Delete Route\n");
        printf("4.Update Route\n");
        printf("5.Search Route\n");
        printf("6.Book Trip\n");
        printf("7.Display Graph\n");
        printf("8.Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1: addDestination(); break;
            case 2: addRoute(); break;
            case 3: deleteRoute(); break;
            case 4: updateRoute(); break;
            case 5: searchRoute(); break;
            case 6: bookTrip(); break;
            case 7: displayGraph(); break;
            case 8: printf("Exiting...\n"); break;

            default: printf("Invalid choice!\n");
        }

    }while(choice!=8);

    return 0;
}
