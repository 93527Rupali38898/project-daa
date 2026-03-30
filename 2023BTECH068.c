#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#define city_number 46
typedef struct connection
{
    char dest[30];     // the lenght of destination city is 30
    char train_id[15]; // the length of train id
    int ac1;
    int ac2;
    int ac3;
    int sleeper;
    int general;
    int time;
    struct connection *next;
}connection;

typedef struct city
{
    char name[30];    // the length of source connection
    connection *head; // head connection that will store the address of other connection's base address

} city;

// added a connection to the array
void add_connection(city *city_name, const char *destination, const char *train_id, int ac1, int ac2, int ac3, int sleeper, int general, int time)
{
    connection *newconnection = (connection *)malloc(sizeof(connection));
    if (newconnection == NULL)
    {
        printf("SORRY!!\nYour graph can't be stored due to lack of Memory");
        exit(1);
    }
    else
    {
        strcpy(newconnection->dest, destination); // we used strcpy because after the initialization of array we can't initial again, so used strcpy
        strcpy(newconnection->train_id, train_id);
        newconnection->ac1 = ac1;
        newconnection->ac2 = ac2;
        newconnection->ac3 = ac3;
        newconnection->sleeper = sleeper;
        newconnection->general = general;
        newconnection->time = time;
        newconnection->next = NULL;
        if (city_name->head == NULL)
        {
            city_name->head = newconnection;
        }
        else
        {
            connection *temp = city_name->head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newconnection;
        }
    }
}
void create_graph(city cities[])
{
    // First Adding cities to the graph
    // Our Railway network have a total of 46 cities, so adding that to the graph

    // 1.
    strcpy(cities[0].name, "Agra");
    cities[0].head = NULL;

    // 2.
    strcpy(cities[1].name, "Ahmedabad");
    cities[1].head = NULL;

    // 3.
    strcpy(cities[2].name, "Aizwal");
    cities[2].head = NULL;

    // 4.
    strcpy(cities[3].name, "Amritsar");
    cities[3].head = NULL;

    // 5.
    strcpy(cities[4].name, "Anta");
    cities[4].head = NULL;

    // 6.
    strcpy(cities[5].name, "Bengaluru");
    cities[5].head = NULL;

    // 7.
    strcpy(cities[6].name, "Baran");
    cities[6].head = NULL;

    // 8.
    strcpy(cities[7].name, "Bhopal");
    cities[7].head = NULL;

    // 9.
    strcpy(cities[8].name, "Bhubaneswar");
    cities[8].head = NULL;

    // 10.
    strcpy(cities[9].name, "Bikaner");
    cities[9].head = NULL;

    // 11.
    strcpy(cities[10].name, "Bundi");
    cities[10].head = NULL;

    // 12.
    strcpy(cities[11].name, "Chandigarh");
    cities[11].head = NULL;

    // 13.
    strcpy(cities[12].name, "Chennai");
    cities[12].head = NULL;

    // 14.
    strcpy(cities[13].name, "Chilling");
    cities[13].head = NULL;

    // 15.
    strcpy(cities[14].name, "Chittorgarh");
    cities[14].head = NULL;

    // 16.
    strcpy(cities[15].name, "Dehradun");
    cities[15].head = NULL;

    // 17.
    strcpy(cities[16].name, "Delhi");
    cities[16].head = NULL;

    // 18.
    strcpy(cities[17].name, "Goa");
    cities[17].head = NULL;

    // 19.
    strcpy(cities[18].name, "Guwahati");
    cities[18].head = NULL;

    // 20.
    strcpy(cities[19].name, "Hyderabad");
    cities[19].head = NULL;

    // 21.
    strcpy(cities[20].name, "Imphal");
    cities[20].head = NULL;

    // 22.
    strcpy(cities[21].name, "Indore");
    cities[21].head = NULL;

    // 23.
    strcpy(cities[22].name, "Itanagar");
    cities[22].head = NULL;

    // 24.
    strcpy(cities[23].name, "Jalore");
    cities[23].head = NULL;

    // 25.
    strcpy(cities[24].name, "Jaipur");
    cities[24].head = NULL;

    // 26.
    strcpy(cities[25].name, "Jammu");
    cities[25].head = NULL;

    // 27.
    strcpy(cities[26].name, "Jhalawar");
    cities[26].head = NULL;

    // 28.
    strcpy(cities[27].name, "Jodhpur");
    cities[27].head = NULL;

    // 29.
    strcpy(cities[28].name, "Kolkata");
    cities[28].head = NULL;

    // 30.
    strcpy(cities[29].name, "Kota");
    cities[29].head = NULL;

    // 31.
    strcpy(cities[30].name, "Lucknow");
    cities[30].head = NULL;

    // 32.
    strcpy(cities[31].name, "Madurai");
    cities[31].head = NULL;

    // 33.
    strcpy(cities[32].name, "Mumbai");
    cities[32].head = NULL;

    // 34.
    strcpy(cities[33].name, "Mysore");
    cities[33].head = NULL;

    // 35.
    strcpy(cities[34].name, "Nagpur");
    cities[34].head = NULL;

    // 36.
    strcpy(cities[35].name, "Panji");
    cities[35].head = NULL;

    // 37.
    strcpy(cities[36].name, "Patna");
    cities[36].head = NULL;

    // 38.
    strcpy(cities[37].name, "Pune");
    cities[37].head = NULL;

    // 39.
    strcpy(cities[38].name, "Raipur");
    cities[38].head = NULL;

    // 40.
    strcpy(cities[39].name, "Ranchi");
    cities[39].head = NULL;

    // 41.
    strcpy(cities[40].name, "Shillong");
    cities[40].head = NULL;

    // 42.
    strcpy(cities[41].name, "Shimla");
    cities[41].head = NULL;

    // 43.
    strcpy(cities[42].name, "Sikar");
    cities[42].head = NULL;

    // 44.
    strcpy(cities[43].name, "Surat");
    cities[43].head = NULL;

    // 45
    strcpy(cities[44].name, "Udaipur");
    cities[44].head = NULL;
    // 46.
    strcpy(cities[45].name, "Vishakapatnam");
    cities[45].head = NULL;

    // Adding the connection between the cities
    add_connection(&cities[1], "Surat", "T9", 1200, 900, 700, 600, 300, 300);
    add_connection(&cities[1], "Indore", "T8", 1500, 1100, 900, 800, 400, 350);

    add_connection(&cities[2], "Imphal", "T12", 1800, 1400, 1200, 1000, 500, 420);

    add_connection(&cities[3], "Jammu", "T20", 1300, 1000, 800, 700, 350, 320);

    add_connection(&cities[4], "Baran", "T7", 900, 700, 500, 500, 250, 450);
    add_connection(&cities[4], "Jhalawar", "T28", 1100, 900, 700, 600, 350, 400);
    add_connection(&cities[4], "Madurai", "T28", 1400, 1100, 900, 800, 400, 420);

    add_connection(&cities[5], "Chennai", "T18", 1700, 1300, 1100, 950, 500, 240);
    add_connection(&cities[5], "Mysore", "T15", 1000, 800, 600, 600, 300, 320);

    add_connection(&cities[7], "Nagpur", "T25", 1400, 1000, 800, 750, 400, 280);

    add_connection(&cities[8], "Vishakapatnam", "T10", 1600, 1200, 1000, 900, 450, 370);

    add_connection(&cities[9], "Agra", "T29", 2500, 2000, 1800, 1500, 800, 436);

    add_connection(&cities[10], "Anta", "T6", 900, 700, 500, 500, 250, 320);

    add_connection(&cities[12], "Surat", "T19", 2000, 1600, 1400, 1200, 600, 400);
    add_connection(&cities[12], "Mumbai", "T20", 1100, 900, 700, 700, 350, 450);

    add_connection(&cities[13], "Aizwal", "T12", 1600, 1200, 1100, 950, 400, 380);

    add_connection(&cities[14], "Jaipur", "T24", 900, 700, 500, 500, 250, 200);

    add_connection(&cities[15], "Delhi", "T21", 1000, 800, 600, 600, 300, 320);

    add_connection(&cities[16], "Jaipur", "T1", 1200, 900, 700, 700, 350, 400);
    add_connection(&cities[16], "Chandigarh", "T13", 1300, 1000, 800, 700, 350, 430);
    add_connection(&cities[16], "Lucknow", "T13", 1400, 1100, 900, 800, 400, 470);
    add_connection(&cities[16], "Patna", "T14", 1800, 1400, 1200, 1000, 500, 420);
    add_connection(&cities[16], "Kolkata", "T22", 2500, 2000, 1800, 1500, 800, 500);

    add_connection(&cities[17], "Panji", "T23", 900, 700, 500, 500, 250, 200);

    add_connection(&cities[18], "Itanagar", "T11", 2000, 1600, 1400, 1200, 600, 340);

    add_connection(&cities[19], "Bengaluru", "T4", 1600, 1200, 1000, 900, 400, 400);
    add_connection(&cities[19], "Chennai", "T4", 2500, 2000, 1800, 1500, 800, 430);
    add_connection(&cities[19], "Vishakapatnam", "T17", 2000, 1600, 1400, 1200, 600, 420);

    add_connection(&cities[21], "Bhopal", "T25", 2000, 1600, 1400, 1200, 600, 340);

    add_connection(&cities[22], "Chilling", "T11", 1600, 1200, 1000, 900, 400, 400);

    add_connection(&cities[24], "Ahmedabad", "T12", 1400, 1100, 900, 800, 400, 430);
    add_connection(&cities[24], "Delhi", "T1", 1200, 900, 700, 700, 350, 430);
    add_connection(&cities[24], "Pune", "T2", 2000, 1600, 1400, 1200, 600, 400);
    add_connection(&cities[24], "Agra", "T13", 1000, 800, 600, 600, 300, 500);

    add_connection(&cities[25], "Shimla", "T30", 1700, 1300, 1100, 950, 500, 410);

    add_connection(&cities[27], "Jalore", "T24", 900, 700, 500, 500, 250, 340);
    add_connection(&cities[27], "Delhi", "T20", 2000, 1600, 1400, 1200, 600, 300);
    add_connection(&cities[27], "Ahmedabad", "T17", 1400, 1100, 900, 800, 400, 534);

    add_connection(&cities[28], "Delhi", "T22", 2500, 2000, 1800, 1500, 800, 630);
    add_connection(&cities[28], "Guwahati", "T3", 2000, 1600, 1400, 1200, 600, 540);
    add_connection(&cities[28], "Bhubaneswar", "T15", 1600, 1200, 1000, 900, 450, 300);
    add_connection(&cities[28], "Ranchi", "T2", 1400, 1100, 900, 800, 400, 420);

    add_connection(&cities[29], "Bhopal", "T8", 1300, 1000, 800, 750, 400, 720);
    add_connection(&cities[29], "Delhi", "T6", 1200, 900, 700, 700, 350, 420);
    add_connection(&cities[29], "Udaipur", "T8", 1000, 800, 600, 600, 300, 300);

    add_connection(&cities[32], "Ahmedabad", "T16", 1800, 1400, 1200, 1000, 500, 420);
    add_connection(&cities[32], "Bhopal", "T3", 1600, 1200, 1000, 900, 450, 540);
    add_connection(&cities[32], "Pune", "T6", 1200, 900, 700, 700, 350, 620);

    add_connection(&cities[35], "Mumbai", "T23", 1400, 1100, 900, 800, 400, 500);

    add_connection(&cities[37], "Hyderabad", "T17", 1700, 1300, 1100, 950, 500, 430);

    add_connection(&cities[38], "Bhubaneswar", "T10", 1500, 1100, 900, 800, 400, 670);

    add_connection(&cities[39], "Kolkata", "T5", 2000, 1600, 1400, 1200, 600, 240);

    add_connection(&cities[40], "Aizwal", "T27", 1600, 1200, 1000, 900, 450, 320);

    add_connection(&cities[41], "Mysore", "T27", 1300, 1100, 900, 700, 300, 470);

    add_connection(&cities[42], "Bikaner", "T29", 1100, 900, 700, 700, 350, 530);
    add_connection(&cities[42], "Bundi", "T29", 900, 700, 500, 500, 250, 240);
    add_connection(&cities[42], "Jaipur", "T23", 1000, 800, 600, 600, 300, 436);

    add_connection(&cities[44], "Kota", "T26", 1100, 900, 700, 700, 350, 610);
    add_connection(&cities[44], "Jodhpur", "T2", 1300, 1100, 800, 750, 400, 730);
    add_connection(&cities[44], "Mumbai", "T7", 2000, 1600, 1400, 1200, 600, 800);
}

int get_index_city(city cities[], const char *name)
{
    for (int i = 0; i < city_number; i++)
    {
        if (strcmp(cities[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int get_cost(connection *conn, int preference)
{
    switch (preference)
    {
    case 1:
        return conn->ac1;
    case 2:
        return conn->ac2;
    case 3:
        return conn->ac3;
    case 4:
        return conn->sleeper;
    case 5:
        return conn->general;
    default:
        return INT_MAX;
    }
}

void dijkstra(city cities[], const char *source, int source_index, int dest_index, int choice, int preference)
{
    int dist[city_number];
    int visited[city_number];
    int parent[city_number];
    char train_ids[city_number][15]; // Array to store train IDs

    for (int i = 0; i < city_number; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
        strcpy(train_ids[i], ""); // Initialize train IDs
    }

    dist[source_index] = 0;

    for (int count = 0; count < city_number - 1; count++)
    {
        int min_dist = INT_MAX, min_index = -1;
        for (int v = 0; v < city_number; v++)
        {
            if (visited[v] == 0 && dist[v] <= min_dist)
            {
                min_dist = dist[v];
                min_index = v;
            }
        }

        if (min_index == -1)
            break;

        int u = min_index;
        visited[u] = 1;

        connection *curr = cities[u].head;
        while (curr != NULL)
        {
            int v = get_index_city(cities, curr->dest);
            if (v != -1 && visited[v] == 0)
            {
                int new_dist;
                if (choice == 1)
                { // Cost optimization
                    new_dist = dist[u] + get_cost(curr, preference);
                }
                else
                { // Time optimization
                    new_dist = dist[u] + curr->time;
                }

                if (new_dist < dist[v])
                {
                    dist[v] = new_dist;
                    parent[v] = u;
                    strcpy(train_ids[v], curr->train_id); // Store the train ID
                }
            }
            curr = curr->next;
        }
    }

    if (dist[dest_index] == INT_MAX)
    {
        printf("Path Between the source and destination does not exists.\n");
        printf("Sorry, for the inconvience.\n");
        return;
    }

    // Reconstruct the path
    int path[city_number];
    int path_index = 0;
    int curr_index = dest_index;

    while (curr_index != -1)
    {
        path[path_index++] = curr_index;
        curr_index = parent[curr_index];
    }

    // Calculate total cost and time
    int total_cost = 0, total_time = 0;
    for (int i = path_index - 1; i > 0; i--)
    {
        int u = path[i];
        int v = path[i - 1];

        connection *curr = cities[u].head;
        while (curr != NULL)
        {
            if (strcmp(curr->dest, cities[v].name) == 0)
            {
                if (choice == 1)
                { 
                    total_cost += get_cost(curr, preference);
                }
                else
                {                                   
                    total_cost += get_cost(curr, 4); 
                }
                total_time += curr->time;
                break;
            }
            curr = curr->next;
        }
    }

    // Ask for additional facilities like food
    int option;
    printf("Do you want a meal too?\n");
    printf("Enter 1 for YES\n");
    printf("Enter Anything else for NO\n");
    scanf("%d", &option);
    if (option == 1)
    {
        printf("Additional 60 $ Added in total cost\n");
        total_cost += 60;
    }

    // Print total cost and time
    if (choice == 1)
    {
        printf("Total Cost: %d $\n", total_cost);
    }
    else
    {
        printf("Total Cost (Sleeper if time optimized): %d $\n", total_cost);
    }

    int hour = total_time / 60;
    int min = total_time % 60;
    printf("Time taken is: %d Hour: %d mins\n", hour, min);

    // Print the path with train IDs
    printf("Path: ");
    if (strcmp(source, cities[path[path_index - 1]].name) != 0)
    {
        printf("%s -> ", source);
    }
    for (int i = path_index - 1; i >= 0; i--)
    {
        printf("%s", cities[path[i]].name);
        if (i > 0)
        {
            printf(" (Train: %s) -> ", train_ids[path[i - 1]]);
        }
    }
    printf("\n");
}


void free_all_connections(city cities[])
{
    for (int i = 0; i < city_number; i++)
    {
        connection *curr = cities[i].head;
        while (curr != NULL)
        {
            connection *temp = curr;
            curr = curr->next;
            free(temp);
        }
        cities[i].head = NULL;
    }
}

int main()
{
    city cities[city_number];
    create_graph(cities);
    printf("Welcome to Our Railway System\n\n");

    char user[50];
    printf("Enter your Name: ");
    fgets(user, 50, stdin);
    user[strcspn(user, "\n")] = '\0';

    char source[30];
    printf("Enter Start Location: ");
    scanf("%s", source);
    source[0] = toupper((unsigned char)source[0]);
    int source_index = get_index_city(cities, source);
    if (source_index == -1)
    {
        printf("Sorry, We Don't have Any such Location in Our Connection!!");
        exit(1);
    }

    char destination[30];
    printf("Enter End Location: ");
    scanf("%s", destination);
    destination[0] = toupper((unsigned char)destination[0]);
    int destination_index = get_index_city(cities, destination);
    if (destination_index == -1)
    {
        printf("Sorry, We Don't have Any such Location in Our Connection!!");
        exit(1);
    }

    int choice;
    while (1)
    {
        printf("Dear %s, What are you Interested in Optimising??\n", user);
        printf("Enter 1. For Cost\n");
        printf("Enter 2. For Time\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        if (choice == 1 || choice == 2)
        {
            break;
        }
        else
        {
            printf("Invalid choice. Please enter 1 or 2.\n");
        }
    }

    int preference = 0;
    if (choice == 1)
    {
        while (1)
        {
            printf("What you Prefer??\n");
            printf("Enter 1. For AC1.\n");
            printf("Enter 2. For AC2.\n");
            printf("Enter 3. For AC3.\n");
            printf("Enter 4. For Sleeper.\n");
            printf("Enter 5. For General.\n");
            printf("Enter your Preference: ");
            scanf("%d", &preference);
            if (preference >= 1 && preference <= 5)
            {
                break;
            }
            else
            {
                printf("Invalid preference. Please enter a number between 1 and 5.\n");
            }
        }
    }

    dijkstra(cities, source, source_index, destination_index, choice, preference);
    printf("Thanks %s for using Our Service\n", user);
    free_all_connections(cities);
    return 0;
}
