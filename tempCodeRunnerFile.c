#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#define railway_node 51
#define bus_node 22
#define aeroplane_node 24

typedef struct connection_train
{
    char dest_train[30]; // the lenght of destination city is 30
    char train_id[15];   // the length of train id
    int ac1;
    int ac2;
    int ac3;
    int sleeper;
    int general;
    int time_train;
    struct connection_train *next;
} connection_train;

typedef struct train
{
    char name_train[30];    // the length of source connection
    connection_train *head; // head connection that will store the address of other connection's base address

} train;

typedef struct connection_bus
{
    char dest_bus[30]; // the lenght of destination city is 30
    char bus_id[15];   // the length of bus id
    int ac_sleeper;
    int ac_seating;
    int nac_sleeper;
    int nac_seating;
    int time_bus;
    struct connection_bus *next;
} connection_bus;

typedef struct bus
{
    char name_bus[30];    // the length of source connection
    connection_bus *head; // head connection that will store the address of other connection's base address

} bus;

typedef struct connection_aeroplane
{
    char dest_aeroplane[30]; // the lenght of destination city is 30
    char aeroplane_id[15];   // the length of aeroplane id
    int first_class;
    int business_class;
    int premium_economic_class;
    int economic_class;
    int time_aeroplane;
    struct connection_aeroplane *next;
} connection_aeroplane;

typedef struct aeroplane
{
    char name_aeroplane[30];    // the length of source connection
    connection_aeroplane *head; // head connection that will store the address of other connection's base address

} aeroplane;

typedef struct
{
    int src;
    int dest;
    int time;
    int cost_type; // To indicate which cost to use (1: First, 2: Business, etc.)
    int cost;      // The selected cost
} Edge;

// added a connection in train
void add_connection_train(train *city_name, const char *destination_train, const char *train_id, int ac1, int ac2, int ac3, int sleeper, int general, int time_train)
{
    connection_train *newconnection = (connection_train *)malloc(sizeof(connection_train));
    if (newconnection == NULL)
    {
        printf("SORRY!!\nYour graph can't be stored due to lack of Memory");
        exit(1);
    }
    else
    {
        strcpy(newconnection->dest_train, destination_train); // we used strcpy because after the initialization of array we can't initial again, so used strcpy
        strcpy(newconnection->train_id, train_id);
        newconnection->ac1 = ac1;
        newconnection->ac2 = ac2;
        newconnection->ac3 = ac3;
        newconnection->sleeper = sleeper;
        newconnection->general = general;
        newconnection->time_train = time_train;
        newconnection->next = NULL;
        if (city_name->head == NULL)
        {
            city_name->head = newconnection;
        }
        else
        {
            connection_train *temp = city_name->head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newconnection;
        }
    }
}

void create_graph_train(train cities_train[])
{
    // First Adding cities_train to the graph
    // Our Railway network have a total of 70 cities_train, so adding that to the graph

    // 1.
    strcpy(cities_train[0].name_train, "Agra");
    cities_train[0].head = NULL;

    // 2.
    strcpy(cities_train[1].name_train, "Ajmer");
    cities_train[1].head = NULL;

    // 3.
    strcpy(cities_train[2].name_train, "Aligarh");
    cities_train[2].head = NULL;

    // 4.
    strcpy(cities_train[3].name_train, "Allahabad");
    cities_train[3].head = NULL;

    // 5.
    strcpy(cities_train[4].name_train, "Amritsar");
    cities_train[4].head = NULL;

    // 6.
    strcpy(cities_train[5].name_train, "Aurangabad");
    cities_train[5].head = NULL;

    // 7.
    strcpy(cities_train[6].name_train, "Bareilly");
    cities_train[6].head = NULL;

    // 8.
    strcpy(cities_train[7].name_train, "Belgaum");
    cities_train[7].head = NULL;

    // 9.
    strcpy(cities_train[8].name_train, "Bhavnagar");
    cities_train[8].head = NULL;

    // 10.
    strcpy(cities_train[9].name_train, "Bhopal");
    cities_train[9].head = NULL;

    // 11.
    strcpy(cities_train[10].name_train, "Bikaner");
    cities_train[10].head = NULL;

    // 12.
    strcpy(cities_train[11].name_train, "Coimbatore");
    cities_train[11].head = NULL;

    // 13.
    strcpy(cities_train[12].name_train, "Cuttack");
    cities_train[12].head = NULL;

    // 14.
    strcpy(cities_train[13].name_train, "Dehradun");
    cities_train[13].head = NULL;

    // 15.
    strcpy(cities_train[14].name_train, "Dibrugarh");
    cities_train[14].head = NULL;

    // 16.
    strcpy(cities_train[15].name_train, "Gorakhpur");
    cities_train[15].head = NULL;

    // 17.
    strcpy(cities_train[16].name_train, "Guntur");
    cities_train[16].head = NULL;

    // 18.
    strcpy(cities_train[17].name_train, "Guwahati");
    cities_train[17].head = NULL;

    // 19.
    strcpy(cities_train[18].name_train, "Hubli");
    cities_train[18].head = NULL;

    // 20.
    strcpy(cities_train[19].name_train, "Hyderabad");
    cities_train[19].head = NULL;

    // 21.
    strcpy(cities_train[20].name_train, "Indore");
    cities_train[20].head = NULL;

    // 22.
    strcpy(cities_train[21].name_train, "Jabalpur");
    cities_train[21].head = NULL;

    // 23.
    strcpy(cities_train[22].name_train, "Jaipur");
    cities_train[22].head = NULL;

    // 24.
    strcpy(cities_train[23].name_train, "Jamshedpur");
    cities_train[23].head = NULL;

    // 25.
    strcpy(cities_train[24].name_train, "Jhansi");
    cities_train[24].head = NULL;

    // 26.
    strcpy(cities_train[25].name_train, "Jodhpur");
    cities_train[25].head = NULL;

    // 27.
    strcpy(cities_train[26].name_train, "Kanpur");
    cities_train[26].head = NULL;

    // 28.
    strcpy(cities_train[27].name_train, "kolhapur");
    cities_train[27].head = NULL;

    // 29.
    strcpy(cities_train[28].name_train, "Kozhikode");
    cities_train[28].head = NULL;

    // 30.
    strcpy(cities_train[29].name_train, "Lucknow");
    cities_train[29].head = NULL;

    // 31.
    strcpy(cities_train[30].name_train, "Madurai");
    cities_train[30].head = NULL;

    // 32.
    strcpy(cities_train[31].name_train, "Merrut");
    cities_train[31].head = NULL;

    // 33.
    strcpy(cities_train[32].name_train, "Mumbai");
    cities_train[32].head = NULL;

    // 34.
    strcpy(cities_train[33].name_train, "Mysore");
    cities_train[33].head = NULL;

    // 35.
    strcpy(cities_train[34].name_train, "Nagpur");
    cities_train[34].head = NULL;

    // 36.
    strcpy(cities_train[35].name_train, "Nashik");
    cities_train[35].head = NULL;

    // 37.
    strcpy(cities_train[36].name_train, "Nanital");
    cities_train[36].head = NULL;

    // 38.
    strcpy(cities_train[37].name_train, "Patna");
    cities_train[37].head = NULL;

    // 39.
    strcpy(cities_train[38].name_train, "Pune");
    cities_train[38].head = NULL;

    // 40.
    strcpy(cities_train[39].name_train, "Ranchi");
    cities_train[39].head = NULL;

    // 41.
    strcpy(cities_train[40].name_train, "Satna");
    cities_train[40].head = NULL;

    // 42.
    strcpy(cities_train[41].name_train, "Shimla");
    cities_train[41].head = NULL;

    // 43.
    strcpy(cities_train[42].name_train, "Siliguri");
    cities_train[42].head = NULL;

    // 44.
    strcpy(cities_train[43].name_train, "Solapur");
    cities_train[43].head = NULL;

    // 45.
    strcpy(cities_train[44].name_train, "Surat");
    cities_train[44].head = NULL;

    // 46.
    strcpy(cities_train[45].name_train, "Thrissur");
    cities_train[45].head = NULL;

    // 47.
    strcpy(cities_train[46].name_train, "Trivandrum");
    cities_train[46].head = NULL;

    // 48.
    strcpy(cities_train[47].name_train, "Udaipur");
    cities_train[47].head = NULL;

    // 49.
    strcpy(cities_train[48].name_train, "Vadodara");
    cities_train[48].head = NULL;

    // 50.
    strcpy(cities_train[49].name_train, "Varanasi");
    cities_train[49].head = NULL;

    // 51.
    strcpy(cities_train[50].name_train, "Warangal");
    cities_train[50].head = NULL;

    // Adding the connection between the cities_train
    add_connection_train(&cities_train[0], "Mysore", "T11", 1200, 900, 700, 600, 300, 310);

    add_connection_train(&cities_train[1], "Nashik", "T2", 1500, 1100, 900, 800, 400, 122);

    add_connection_train(&cities_train[2], "Shimla", "T1", 1800, 1400, 1200, 1000, 500, 326);

    add_connection_train(&cities_train[2], "Tirupati", "T4", 1300, 1000, 800, 700, 350, 281);
    add_connection_train(&cities_train[3], "Aurangabad", "T8", 1600, 1200, 1000, 900, 450, 326);
    add_connection_train(&cities_train[3], "Bhavanagar", "T11", 1700, 1300, 1100, 950, 500, 448);
    add_connection_train(&cities_train[3], "Jalgaon", "T12", 1400, 1100, 900, 800, 400, 152);
    add_connection_train(&cities_train[4], "Dehradun", "T1", 1000, 800, 600, 600, 300, 178);
    add_connection_train(&cities_train[5], "Bhubaneshwar", "T3", 1400, 1000, 800, 750, 400, 358);
    add_connection_train(&cities_train[5], "Guwahati", "T4", 2000, 1600, 1400, 1200, 600, 473);
    add_connection_train(&cities_train[6], "Gorakhpur", "T2", 1100, 900, 700, 700, 250, 266);
    add_connection_train(&cities_train[6], "Guntur", "T3", 900, 700, 500, 500, 250, 173);
    add_connection_train(&cities_train[7], "Merrut", "T7", 1300, 1000, 800, 700, 350, 366);
    add_connection_train(&cities_train[8], "Jalgaon", "T12", 1400, 1100, 900, 800, 400, 152);
    add_connection_train(&cities_train[9], "Bilaspur", "T6", 1800, 1400, 1200, 1000, 500, 535);
    add_connection_train(&cities_train[9], "Jaipur", "T9", 2500, 2000, 1800, 1500, 800, 300);
    add_connection_train(&cities_train[10], "Mangalore", "T10", 1200, 900, 700, 700, 350, 307);
    add_connection_train(&cities_train[11], "varanasi", "T7", 1000, 800, 600, 600, 300, 240);
    add_connection_train(&cities_train[12], "Bangalore", "T4", 900, 700, 500, 500, 250, 492);
    add_connection_train(&cities_train[12], "Solapur", "T1", 1200, 900, 700, 700, 350, 297);
    add_connection_train(&cities_train[13], "Bilaspur", "T11", 1000, 800, 600, 800, 250, 244);
    add_connection_train(&cities_train[13], "Kolkata", "T12", 2000, 1600, 1400, 800, 350, 592);
    add_connection_train(&cities_train[14], "Jhansi", "T10", 1400, 1100, 900, 900, 300, 181);
    add_connection_train(&cities_train[15], "Ranchi", "T9", 1400, 1100, 900, 950, 250, 311);
    add_connection_train(&cities_train[16], "Dibrugarh", "T4", 1600, 1200, 1000, 500, 350, 184);
    add_connection_train(&cities_train[16], "Satna", "T10", 1700, 1300, 1100, 1500, 300, 599);
    add_connection_train(&cities_train[17], "Pune", "T7", 900, 700, 500, 800, 600, 307);
    add_connection_train(&cities_train[18], "Jodhpur", "T12", 2500, 2000, 1800, 700, 400, 240);
    add_connection_train(&cities_train[19], "lucknow", "T4", 1400, 1100, 900, 750, 400, 157);
    add_connection_train(&cities_train[20], "Ranchi", "T12", 1200, 900, 700, 1200, 450, 240);
    add_connection_train(&cities_train[21], "Ranchi", "T3", 1300, 1000, 800, 900, 500, 184);
    add_connection_train(&cities_train[22], "Aligarh", "T8", 2000, 1600, 1400, 600, 250, 76);
    add_connection_train(&cities_train[23], "Kolkata", "T1", 1600, 1200, 1100, 700, 800, 492);
    add_connection_train(&cities_train[24], "Darbhanga", "T3", 1600, 1400, 1200, 700, 600, 122);
    add_connection_train(&cities_train[25], "Indore", "T4", 1800, 1600, 1330, 1000, 300, 310);
    add_connection_train(&cities_train[26], "Thrissur", "T3", 1900, 1200, 1100, 1500, 500, 326);
    add_connection_train(&cities_train[27], "Gorakhpur", "T11", 2000, 1500, 700, 900, 400, 448);
    add_connection_train(&cities_train[27], "Rajkot", "T8", 1200, 1100, 800, 800, 200, 590);
    add_connection_train(&cities_train[28], "Jammu", "T8", 1700, 1600, 600, 900, 600, 281);
    add_connection_train(&cities_train[29], "Patna", "T12", 1400, 900, 400, 600, 500, 473);
    add_connection_train(&cities_train[30], "Aligarh", "T4", 1100, 900, 300, 700, 300, 266);
    add_connection_train(&cities_train[30], "kolhapur", "T3", 900, 750, 650, 500, 200, 178);
    add_connection_train(&cities_train[30], "Udaipur", "T10", 750, 600, 400, 400, 250, 358);
    add_connection_train(&cities_train[31], "Kozhikode", "T1", 1250, 1100, 900, 300, 400, 191);
    add_connection_train(&cities_train[32], "Bhopal", "T11", 1450, 1200, 700, 1200, 250, 119);
    add_connection_train(&cities_train[33], "Udaipur", "T7", 1700, 1600, 900, 1100, 400, 363);
    add_connection_train(&cities_train[34], "Hyderabad", "T12", 900, 700, 200, 900, 600, 313);
    add_connection_train(&cities_train[34], "Udaipur", "T8", 900, 700, 500, 1400, 300, 521);
    add_connection_train(&cities_train[34], "Vadodara", "T3", 1900, 1500, 1100, 1300, 300, 166);
    add_connection_train(&cities_train[35], "Udaipur", "T12", 1700, 1400, 1100, 1100, 500, 556);
    add_connection_train(&cities_train[36], "Delhi", "T1", 1800, 1300, 940, 500, 400, 75);
    add_connection_train(&cities_train[36], "Rajkot", "T2", 1500, 1400, 1000, 700, 200, 282);
    add_connection_train(&cities_train[37], "Coimbatore", "T12", 1600, 1100, 700, 900, 600, 595);
    add_connection_train(&cities_train[37], "Visakhapatnam", "T7", 1750, 1450, 850, 1000, 500, 182);
    add_connection_train(&cities_train[38], "Jamshedpur", "T10", 1400, 1100, 800, 1500, 300, 537);
    add_connection_train(&cities_train[39], "Kolhapur", "T5", 1300, 1100, 800, 800, 250, 349);
    add_connection_train(&cities_train[40], "Hubli", "T12", 1200, 900, 700, 900, 200, 252);
    add_connection_train(&cities_train[40], "Kharagpur", "T4", 1800, 1700, 700, 1400, 400, 483);
    add_connection_train(&cities_train[41], "Cuttack", "T5", 1900, 1700, 600, 1660, 250, 444);
    add_connection_train(&cities_train[42], "Shimla", "T4", 1300, 1100, 1000, 1500, 600, 120);
    add_connection_train(&cities_train[43], "Gwalior", "T2", 1100, 700, 400, 1400, 300, 131);
    add_connection_train(&cities_train[44], "Mumbai", "T10", 1600, 900, 800, 900, 450, 348);
    add_connection_train(&cities_train[45], "Jaipur", "T10", 1800, 900, 700, 800, 250, 347);
    add_connection_train(&cities_train[46], "New Delhi", "T5", 1900, 1700, 550, 700, 250, 163);
    add_connection_train(&cities_train[47], "Bhubaneswar", "T11", 1500, 1300, 600, 1600, 500, 412);
    add_connection_train(&cities_train[48], "Rajkot", "T6", 1400, 1100, 1000, 1500, 450, 77);
    add_connection_train(&cities_train[49], "Guntur", "T7", 1300, 900, 700, 600, 700, 381);
    add_connection_train(&cities_train[49], "Shimla", "T6", 1100, 700, 650, 800, 600, 521);
    add_connection_train(&cities_train[50], "Chennai", "T5", 1200, 1100, 900, 660, 500, 418);
    add_connection_train(&cities_train[50], "Mysore", "T11", 1400, 900, 400, 900, 660, 584);
    add_connection_train(&cities_train[50], "Guntur", "T9", 1800, 900, 500, 1000, 900, 341);
}

// added a connection in bus
void add_connection_bus(bus *city_name, const char *destination_bus, const char *bus_id, int ac_sleeper, int ac_seating, int nac_sleeper, int nac_seating, int time_bus)
{
    connection_bus *newconnection = (connection_bus *)malloc(sizeof(connection_bus));
    if (newconnection == NULL)
    {
        printf("SORRY!!\nYour graph can't be stored due to lack of Memory");
        exit(1);
    }
    else
    {
        strcpy(newconnection->dest_bus, destination_bus); // we used strcpy because after the initialization of array we can't initial again, so used strcpy
        strcpy(newconnection->bus_id, bus_id);
        newconnection->ac_sleeper = ac_sleeper;
        newconnection->ac_seating = ac_seating;
        newconnection->nac_sleeper = nac_sleeper;
        newconnection->nac_seating = nac_seating;
        newconnection->time_bus = time_bus;
        newconnection->next = NULL;
        if (city_name->head == NULL)
        {
            city_name->head = newconnection;
        }
        else
        {
            connection_bus *temp = city_name->head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newconnection;
        }
    }
}

void create_graph_bus(bus cities_bus[])
{
    // First Adding cities_bus to the graph
    // Our Bus network have a total of 22 cities, so adding that to the graph

    // 1.
    strcpy(cities_bus[0].name_bus, "Ahmedabad");
    cities_bus[0].head = NULL;

    // 2.
    strcpy(cities_bus[1].name_bus, "Agra");
    cities_bus[1].head = NULL;

    // 3.
    strcpy(cities_bus[2].name_bus, "Bengaluru");
    cities_bus[2].head = NULL;

    // 4.
    strcpy(cities_bus[3].name_bus, "Bhubaneshwar");
    cities_bus[3].head = NULL;

    // 5.
    strcpy(cities_bus[4].name_bus, "Bhopal");
    cities_bus[4].head = NULL;

    // 6.
    strcpy(cities_bus[5].name_bus, "Chennai");
    cities_bus[5].head = NULL;

    // 7.
    strcpy(cities_bus[6].name_bus, "Delhi");
    cities_bus[6].head = NULL;

    // 8.
    strcpy(cities_bus[7].name_bus, "Hyderabad");
    cities_bus[7].head = NULL;

    // 9.
    strcpy(cities_bus[8].name_bus, "Jaipur");
    cities_bus[8].head = NULL;

    // 10.
    strcpy(cities_bus[9].name_bus, "Kanpur");
    cities_bus[9].head = NULL;

    // 11.
    strcpy(cities_bus[10].name_bus, "Kolkata");
    cities_bus[10].head = NULL;

    // 12.
    strcpy(cities_bus[11].name_bus, "Lucknow");
    cities_bus[11].head = NULL;

    // 13.
    strcpy(cities_bus[12].name_bus, "Mumbai");
    cities_bus[12].head = NULL;

    // 14.
    strcpy(cities_bus[13].name_bus, "Nagpur");
    cities_bus[13].head = NULL;

    // 15.
    strcpy(cities_bus[14].name_bus, "Nashik");
    cities_bus[14].head = NULL;

    // 16.
    strcpy(cities_bus[15].name_bus, "Patna");
    cities_bus[15].head = NULL;

    // 17.
    strcpy(cities_bus[16].name_bus, "Pune");
    cities_bus[16].head = NULL;

    // 18.
    strcpy(cities_bus[17].name_bus, "Raipur");
    cities_bus[17].head = NULL;

    // 19.
    strcpy(cities_bus[18].name_bus, "Ranchi");
    cities_bus[18].head = NULL;

    // 20.
    strcpy(cities_bus[19].name_bus, "Surat");
    cities_bus[19].head = NULL;

    // 21.
    strcpy(cities_bus[20].name_bus, "Varanasi");
    cities_bus[20].head = NULL;

    // 22.
    strcpy(cities_bus[21].name_bus, "Viskhapatnam");
    cities_bus[21].head = NULL;

    // Adding the connection between the cities_train
    add_connection_bus(&cities_bus[0], "Surat", "B6", 700, 550, 400, 300, 180);
    add_connection_bus(&cities_bus[1], "Lucknow", "B3", 950, 750, 600, 400, 330);
    add_connection_bus(&cities_bus[2], "Chennai", "B4", 1000, 850, 650, 450, 360);
    add_connection_bus(&cities_bus[3], "Jaipur", "B7", 1000, 800, 650, 450, 480);
    add_connection_bus(&cities_bus[4], "Indore", "B4", 700, 550, 450, 300, 150);
    add_connection_bus(&cities_bus[5], "Viskhapatnam", "B5", 1200, 1000, 800, 600, 450);
    add_connection_bus(&cities_bus[6], "Agra", "B2", 850, 650, 500, 350, 210);
    add_connection_bus(&cities_bus[7], "Bengaluru", "B3", 1100, 900, 700, 500, 390);
    add_connection_bus(&cities_bus[8], "Delhi", "B1", 900, 700, 600, 400, 300);
    add_connection_bus(&cities_bus[9], "varanasi", "B5", 800, 600, 500, 300, 240);
    add_connection_bus(&cities_bus[10], "Ranchi", "B8", 750, 600, 450, 300, 210);
    add_connection_bus(&cities_bus[11], "kanpur", "B4", 600, 500, 400, 250, 150);
    add_connection_bus(&cities_bus[12], "Pune", "B8", 600, 500, 400, 300, 240);
    add_connection_bus(&cities_bus[13], "Bhopal", "B3", 800, 600, 500, 550, 420);
    add_connection_bus(&cities_bus[14], "Hyderabad", "B2", 1150, 950, 750, 500, 450);
    add_connection_bus(&cities_bus[15], "Kolkata", "B7", 1200, 900, 700, 300, 180);
    add_connection_bus(&cities_bus[16], "Nashik", "B1", 750, 600, 450, 350, 280);
    add_connection_bus(&cities_bus[17], "Nagpur", "B2", 850, 700, 550, 350, 300);
    add_connection_bus(&cities_bus[18], "Raipur", "B1", 850, 700, 550, 350, 300);
    add_connection_bus(&cities_bus[19], "Mumbai", "B7", 850, 650, 500, 350, 270);
    add_connection_bus(&cities_bus[20], "Patna", "B6", 850, 650, 550, 400, 300);
    add_connection_bus(&cities_bus[21], "Bhubaneswar", "B6", 950, 750, 600, 500, 450);
}

// added a connection in aeroplane
void add_connection_aeroplane(aeroplane *city_name, const char *destination_aeroplane, const char *aeroplane_id, int first_class, int business_class, int premium_economic_class, int economic_class, int time_aeroplane)
{
    connection_aeroplane *newconnection = (connection_aeroplane *)malloc(sizeof(connection_aeroplane));
    if (newconnection == NULL)
    {
        printf("SORRY!!\nYour graph can't be stored due to lack of Memory");
        exit(1);
    }
    else
    {
        strcpy(newconnection->dest_aeroplane, destination_aeroplane); // we used strcpy because after the initialization of array we can't initial again, so used strcpy
        strcpy(newconnection->aeroplane_id, aeroplane_id);
        newconnection->first_class = first_class;
        newconnection->business_class = business_class;
        newconnection->premium_economic_class = premium_economic_class;
        newconnection->economic_class = economic_class;
        newconnection->time_aeroplane = time_aeroplane;
        newconnection->next = NULL;
        if (city_name->head == NULL)
        {
            city_name->head = newconnection;
        }
        else
        {
            connection_aeroplane *temp = city_name->head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newconnection;
        }
    }
}

void create_graph_aeroplane(aeroplane cities_aeroplane[])
{
    // First Adding cities_aeroplane to the graph
    // Our Aeroplane network have a total of 27 cities, so adding that to the graph

    // 1.
    strcpy(cities_aeroplane[0].name_aeroplane, "Ahmedabad");
    cities_aeroplane[0].head = NULL;

    // 2.
    strcpy(cities_aeroplane[1].name_aeroplane, "Agra");
    cities_aeroplane[1].head = NULL;

    // 3.
    strcpy(cities_aeroplane[2].name_aeroplane, "Amritsar");
    cities_aeroplane[2].head = NULL;

    // 4.
    strcpy(cities_aeroplane[3].name_aeroplane, "Bengaluru");
    cities_aeroplane[3].head = NULL;

    // 5.
    strcpy(cities_aeroplane[4].name_aeroplane, "Bhopal");
    cities_aeroplane[4].head = NULL;

    // 6.
    strcpy(cities_aeroplane[5].name_aeroplane, "Bhubaneswar");
    cities_aeroplane[5].head = NULL;

    // 7.
    strcpy(cities_aeroplane[6].name_aeroplane, "Chandigarh");
    cities_aeroplane[6].head = NULL;

    // 8.
    strcpy(cities_aeroplane[7].name_aeroplane, "Chennai");
    cities_aeroplane[7].head = NULL;

    // 9.
    strcpy(cities_aeroplane[8].name_aeroplane, "Dehradun");
    cities_aeroplane[8].head = NULL;

    // 10.
    strcpy(cities_aeroplane[9].name_aeroplane, "Delhi");
    cities_aeroplane[9].head = NULL;

    // 11.
    strcpy(cities_aeroplane[10].name_aeroplane, "Goa");
    cities_aeroplane[10].head = NULL;

    // 12.
    strcpy(cities_aeroplane[11].name_aeroplane, "Guwahati");
    cities_aeroplane[11].head = NULL;

    // 13.
    strcpy(cities_aeroplane[12].name_aeroplane, "Hyderabad");
    cities_aeroplane[12].head = NULL;

    // 14.
    strcpy(cities_aeroplane[13].name_aeroplane, "Indore");
    cities_aeroplane[13].head = NULL;

    // 15.
    strcpy(cities_aeroplane[14].name_aeroplane, "Jaipur");
    cities_aeroplane[14].head = NULL;

    // 16.
    strcpy(cities_aeroplane[15].name_aeroplane, "Jalandar");
    cities_aeroplane[15].head = NULL;

    // 17.
    strcpy(cities_aeroplane[16].name_aeroplane, "Jammu");
    cities_aeroplane[16].head = NULL;

    // 18.
    strcpy(cities_aeroplane[17].name_aeroplane, "Kanpur");
    cities_aeroplane[17].head = NULL;

    // 19.
    strcpy(cities_aeroplane[18].name_aeroplane, "Kochi");
    cities_aeroplane[18].head = NULL;

    // 20.
    strcpy(cities_aeroplane[19].name_aeroplane, "Kolkata");
    cities_aeroplane[19].head = NULL;

    // 21.
    strcpy(cities_aeroplane[20].name_aeroplane, "Kota");
    cities_aeroplane[20].head = NULL;

    // 22.
    strcpy(cities_aeroplane[21].name_aeroplane, "Lucknow");
    cities_aeroplane[21].head = NULL;

    // 23.
    strcpy(cities_aeroplane[22].name_aeroplane, "Mumbai");
    cities_aeroplane[22].head = NULL;

    // 24.
    strcpy(cities_aeroplane[23].name_aeroplane, "Nagpur");
    cities_aeroplane[23].head = NULL;

    add_connection_aeroplane(&cities_aeroplane[0], "Jaipur", "A4", 9500, 7200, 5200, 3900, 135);

    add_connection_aeroplane(&cities_aeroplane[1], "Bengaluru", "A1", 9500, 7200, 5200, 3900, 135);
    add_connection_aeroplane(&cities_aeroplane[1], "Chennai", "A2", 10200, 7600, 5400, 4200, 150);

    add_connection_aeroplane(&cities_aeroplane[2], "Kolkata", "A3", 12000, 9000, 6000, 4500, 180);

    add_connection_aeroplane(&cities_aeroplane[3], "Jaipur", "A1", 6100, 4700, 3500, 2800, 95);
    add_connection_aeroplane(&cities_aeroplane[3], "Kochi", "A2", 11300, 8600, 6100, 4800, 180);

    add_connection_aeroplane(&cities_aeroplane[4], "Delhi", "A3", 8800, 6800, 4800, 3600, 120);
    add_connection_aeroplane(&cities_aeroplane[4], "Hyderabad", "A1", 6200, 4600, 3400, 2600, 90);

    add_connection_aeroplane(&cities_aeroplane[5], "Mumbai", "A2", 6900, 5100, 3800, 2800, 95);

    add_connection_aeroplane(&cities_aeroplane[6], "Pune", "A3", 7600, 5800, 4200, 3100, 120);

    add_connection_aeroplane(&cities_aeroplane[7], "Ahmedabad", "A1", 8300, 6200, 4700, 3500, 140);

    add_connection_aeroplane(&cities_aeroplane[8], "Kolkata", "A2", 9800, 7400, 5600, 4300, 150);
    add_connection_aeroplane(&cities_aeroplane[8], "Delhi", "A3", 9100, 6900, 5100, 3800, 120);

    add_connection_aeroplane(&cities_aeroplane[9], "Jaipur", "A1", 6700, 4900, 3700, 2900, 100);

    add_connection_aeroplane(&cities_aeroplane[10], "Kochi", "A2", 11400, 8800, 6600, 5000, 185);
    add_connection_aeroplane(&cities_aeroplane[10], "Lucknow", "A3", 5800, 4300, 3100, 2400, 85);

    add_connection_aeroplane(&cities_aeroplane[11], "Bengaluru", "A1", 5400, 4000, 2900, 2200, 80);
    add_connection_aeroplane(&cities_aeroplane[11], "Jaipur", "A2", 7400, 5600, 4300, 3200, 110);

    add_connection_aeroplane(&cities_aeroplane[12], "Kolkata", "A3", 6700, 5000, 3600, 2700, 95);

    add_connection_aeroplane(&cities_aeroplane[13], "Pune", "A1", 6200, 4600, 3400, 2600, 90);

    add_connection_aeroplane(&cities_aeroplane[14], "Mumbai", "A2", 6900, 5100, 3800, 2800, 95);
    add_connection_aeroplane(&cities_aeroplane[15], "Chennai", "A3", 9100, 7000, 5300, 4000, 140);
    add_connection_aeroplane(&cities_aeroplane[15], "Kota", "A1", 3900, 2900, 2100, 1500, 55);
    add_connection_aeroplane(&cities_aeroplane[16], "Delhi", "A2", 6100, 4700, 3500, 2700, 85);
    add_connection_aeroplane(&cities_aeroplane[17], "Lucknow", "A3", 7000, 5100, 3700, 2800, 105);
    add_connection_aeroplane(&cities_aeroplane[18], "Kolkata", "A1", 8200, 6200, 4600, 3400, 125);
    add_connection_aeroplane(&cities_aeroplane[19], "Mumbai", "A2", 9200, 7100, 5300, 4000, 135);
    add_connection_aeroplane(&cities_aeroplane[20], "Ahmedabad", "A3", 8700, 6700, 4900, 3700, 140);
    add_connection_aeroplane(&cities_aeroplane[21], "Pune", "A1", 7600, 5800, 4200, 3100, 120);
    add_connection_aeroplane(&cities_aeroplane[22], "Hyderabad", "A2", 8200, 6100, 4500, 3400, 115);
    add_connection_aeroplane(&cities_aeroplane[23], "Nagpur", "A3", 7000, 5200, 3900, 2900, 100);
    add_connection_aeroplane(&cities_aeroplane[24], "Bengaluru", "A1", 8300, 6400, 4700, 3500, 120);
}

int get_index_train(train cities_train[], const char *name)
{
    for (int i = 0; i < railway_node; i++)
    {
        if (strcmp(cities_train[i].name_train, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int get_cost_train(connection_train *conn, int preference)
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

void dijkstra_train(train cities_train[], const char *source, int source_index, int dest_index, int choice)
{
    int preference;
    printf("\nChoose your preferred travel class:\n");
    printf("1. AC First Class\n");
    printf("2. AC 2-Tier\n");
    printf("3. AC 3-Tier\n");
    printf("4. Sleeper\n");
    printf("5. General\n");
    printf("Enter your preference (1-5): ");
    scanf("%d", &preference);

    int dist[railway_node];  // to find the shortest distance
    int visited[railway_node];  // to track of visited node
    int parent[railway_node];   // to recreate the path
    char train_ids[railway_node][15]; // Store train IDs

    for (int i = 0; i < railway_node; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
        strcpy(train_ids[i], "");
    }

    dist[source_index] = 0;

    for (int count = 0; count < railway_node - 1; count++)
    {
        int min_dist = INT_MAX, min_index = -1;
        for (int v = 0; v < railway_node; v++)
        {
            if (!visited[v] && dist[v] <= min_dist)
            {
                min_dist = dist[v];
                min_index = v;
            }
        }

        if (min_index == -1)
            break;

        int u = min_index;
        visited[u] = 1;

        connection_train *curr = cities_train[u].head;
        while (curr != NULL)
        {
            int v = get_index_train(cities_train, curr->dest_train);
            if (v != -1 && !visited[v])
            {
                int new_dist;
                if (choice == 1)
                    new_dist = dist[u] + get_cost_train(curr, preference);
                else
                    new_dist = dist[u] + curr->time_train;

                if (new_dist < dist[v])
                {
                    dist[v] = new_dist;
                    parent[v] = u;
                    strcpy(train_ids[v], curr->train_id);
                }
            }
            curr = curr->next;
        }
    }

    if (dist[dest_index] == INT_MAX)
    {
        printf("Path between source and destination does not exist.\n");
        return;
    }

    int path[railway_node], path_index = 0;
    int curr_index = dest_index;
    while (curr_index != -1)
    {
        path[path_index++] = curr_index;
        curr_index = parent[curr_index];
    }

    int total_cost = 0, total_time = 0;
    for (int i = path_index - 1; i > 0; i--)
    {
        int u = path[i];
        int v = path[i - 1];
        connection_train *curr = cities_train[u].head;
        while (curr != NULL)
        {
            if (strcmp(curr->dest_train, cities_train[v].name_train) == 0)
            {
                total_cost += get_cost_train(curr, preference);
                total_time += curr->time_train;
                break;
            }
            curr = curr->next;
        }
    }

    int option;
    printf("\nDo you want a meal too?\n");
    printf("Enter 1 for YES\n");
    printf("Enter anything else for NO\n");
    scanf("%d", &option);
    if (option == 1)
    {
        printf("Additional $60 added to the total cost\n");
        total_cost += 60;
    }

    printf("\nTotal Cost: %d $\n", total_cost);
    int hour = total_time / 60;
    int min = total_time % 60;
    printf("Time taken: %d Hour(s) %d Minute(s)\n", hour, min);

    printf("\nPath: ");
    if (strcmp(source, cities_train[path[path_index - 1]].name_train) != 0)
        printf("%s -> ", source);

    for (int i = path_index - 1; i >= 0; i--)
    {
        printf("%s", cities_train[path[i]].name_train);
        if (i > 0)
            printf(" (Train: %s) -> ", train_ids[path[i - 1]]);
    }
    printf("\n");
}

int get_index_bus(bus stops_bus[], const char *name)
{
    for (int i = 0; i < bus_node; i++)
    {
        if (strcmp(stops_bus[i].name_bus, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int get_cost_bus(connection_bus *conn, int preference)
{
    switch (preference)
    {
    case 1:
        return conn->ac_sleeper; // AC Sleeper
    case 2:
        return conn->ac_seating; // AC Seating
    case 3:
        return conn->nac_sleeper; // Non-AC Sleeper
    case 4:
        return conn->nac_seating; // Non-AC Seating
    default:
        return INT_MAX; // Return a high cost in case of invalid input
    }
}

void dijkstra_bus(bus cities_bus[], const char *source, int source_index, int dest_index, int choice)
{
    int preference;
    printf("\nChoose your preferred bus class:\n");
    printf("1. AC Sleeper\n");
    printf("2. AC Seating\n");
    printf("3. Non-AC Sleeper\n");
    printf("4. Non-AC Seating\n");
    printf("Enter your preference (1-4): ");
    scanf("%d", &preference);

    int dist[bus_node];
    int visited[bus_node];
    int parent[bus_node];
    char bus_ids[bus_node][15]; // Store bus IDs

    for (int i = 0; i < bus_node; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
        strcpy(bus_ids[i], "");
    }

    dist[source_index] = 0;

    for (int count = 0; count < bus_node - 1; count++)
    {
        int min_dist = INT_MAX, min_index = -1;
        for (int v = 0; v < bus_node; v++)
        {
            if (!visited[v] && dist[v] <= min_dist)
            {
                min_dist = dist[v];
                min_index = v;
            }
        }

        if (min_index == -1)
            break;

        int u = min_index;
        visited[u] = 1;

        connection_bus *curr = cities_bus[u].head;
        while (curr != NULL)
        {
            int v = get_index_bus(cities_bus, curr->dest_bus);
            if (v != -1 && !visited[v])
            {
                int new_dist;
                if (choice == 1) // Cost optimization
                    new_dist = dist[u] + get_cost_bus(curr, preference);
                else // Time optimization
                    new_dist = dist[u] + curr->time_bus;

                if (new_dist < dist[v])
                {
                    dist[v] = new_dist;
                    parent[v] = u;
                    strcpy(bus_ids[v], curr->bus_id);
                }
            }
            curr = curr->next;
        }
    }

    if (dist[dest_index] == INT_MAX)
    {
        printf("No bus route exists between %s and %s.\n", source, cities_bus[dest_index].name_bus);
        return;
    }

    // Rest of the function remains the same...
    int path[bus_node], path_index = 0;
    int curr_index = dest_index;
    while (curr_index != -1)
    {
        path[path_index++] = curr_index;
        curr_index = parent[curr_index];
    }

    int total_cost = 0, total_time = 0;
    for (int i = path_index - 1; i > 0; i--)
    {
        int u = path[i];
        int v = path[i - 1];
        connection_bus *curr = cities_bus[u].head;
        while (curr != NULL)
        {
            if (strcmp(curr->dest_bus, cities_bus[v].name_bus) == 0)
            {
                total_cost += get_cost_bus(curr, preference);
                total_time += curr->time_bus;
                break;
            }
            curr = curr->next;
        }
    }

    int option;
    printf("\nDo you want a meal too?\n");
    printf("Enter 1 for YES\n");
    printf("Enter anything else for NO\n");
    scanf("%d", &option);
    if (option == 1)
    {
        printf("Additional $60 added to the total cost\n");
        total_cost += 60;
    }

    printf("\nTotal Cost: %d $\n", total_cost);
    int hour = total_time / 60;
    int min = total_time % 60;
    printf("Time taken: %d Hour(s) %d Minute(s)\n", hour, min);

    printf("\nBus Route: ");
    if (strcmp(source, cities_bus[path[path_index - 1]].name_bus) != 0)
        printf("%s -> ", source);

    for (int i = path_index - 1; i >= 0; i--)
    {
        printf("%s", cities_bus[path[i]].name_bus);
        if (i > 0)
            printf(" (Bus: %s) -> ", bus_ids[path[i - 1]]);
    }
    printf("\n");
}

// Helper function to get the index of a city
int get_index_aeroplane(aeroplane cities_aeroplane[], const char *city_name)
{
    for (int i = 0; i < aeroplane_node; i++)
    {
        if (strcmp(cities_aeroplane[i].name_aeroplane, city_name) == 0)
        {
            return i;
        }
    }
    return -1; // Return -1 if city is not found (error)
}

int extract_edges_aeroplane(aeroplane cities_aeroplane[], int num_cities, Edge edges[], int cost_choice)
{
    int edge_count = 0;
    for (int i = 0; i < num_cities; i++)
    {
        connection_aeroplane *current = cities_aeroplane[i].head;
        while (current)
        {
            int dest_index = get_index_aeroplane(cities_aeroplane, current->dest_aeroplane);
            if (dest_index != -1)
            {
                edges[edge_count].src = i;
                edges[edge_count].dest = dest_index;
                edges[edge_count].time = current->time_aeroplane;
                edges[edge_count].cost_type = cost_choice; // Store the cost choice

                // Determine the cost based on user's choice
                switch (cost_choice)
                {
                case 1:
                    edges[edge_count].cost = current->first_class;
                    break;
                case 2:
                    edges[edge_count].cost = current->business_class;
                    break;
                case 3:
                    edges[edge_count].cost = current->premium_economic_class;
                    break;
                case 4:
                    edges[edge_count].cost = current->economic_class;
                    break;
                default:
                    printf("Invalid cost choice. Using economic_class cost.\n");
                    edges[edge_count].cost = current->economic_class;
                    break;
                }
                edge_count++;
            }
            current = current->next;
        }
    }
    return edge_count;
}

void bellman_ford_aeroplane(Edge edges[], int num_vertices, int num_edges, int source,
                            int distances[], int costs[], int predecessors[])
{
    for (int i = 0; i < num_vertices; i++)
    {
        distances[i] = INT_MAX;
        costs[i] = INT_MAX;
        predecessors[i] = -1;
    }
    distances[source] = 0;
    costs[source] = 0;

    for (int i = 1; i <= num_vertices - 1; i++)
    {
        for (int j = 0; j < num_edges; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int time = edges[j].time;
            int cost = edges[j].cost;

            if (distances[u] != INT_MAX && distances[u] + time < distances[v])
            {
                distances[v] = distances[u] + time;
                costs[v] = costs[u] + cost;
                predecessors[v] = u;
            }
            else if (distances[u] + time == distances[v] && costs[u] + cost < costs[v])
            {
                costs[v] = costs[u] + cost;
                predecessors[v] = u;
            }
        }
    }

    // Check for negative cycle (optional)
    for (int i = 0; i < num_edges; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int time = edges[i].time;

        if (distances[u] != INT_MAX && distances[u] + time < distances[v])
        {
            printf("Negative-weight cycle detected!\n");
            return;
        }
    }
}

// Helper function to compute Levenshtein distance
int levenshtein_distance(const char *s1, const char *s2)
{
    int len1 = strlen(s1), len2 = strlen(s2);
    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
        dp[i][0] = i;
    for (int j = 0; j <= len2; j++)
        dp[0][j] = j;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            int cost = (tolower(s1[i - 1]) == tolower(s2[j - 1])) ? 0 : 1;
            dp[i][j] = fmin(fmin(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + cost);
        }    
    }
    return dp[len1][len2];
}

// Main function to find closest city match
const char *find_closest_city(const char *user_input,
                              train *train_cities, int train_count,
                              bus *bus_cities, int bus_count,
                              aeroplane *air_cities, int air_count)
{

    int min_distance = INT_MAX;
    const char *closest_match = NULL;

    // Exact match priority
    for (int i = 0; i < train_count; i++)
    {
        if (strcasecmp(user_input, train_cities[i].name_train) == 0)
        {
            return train_cities[i].name_train;
        }
    }
    for (int i = 0; i < bus_count; i++)
    {
        if (strcasecmp(user_input, bus_cities[i].name_bus) == 0)
        {
            return bus_cities[i].name_bus;
        }
    }
    for (int i = 0; i < air_count; i++)
    {
        if (strcasecmp(user_input, air_cities[i].name_aeroplane) == 0)
        {
            return air_cities[i].name_aeroplane;
        }
    }

    // Check against train cities
    for (int i = 0; i < train_count; i++)
    {
        int dist = levenshtein_distance(user_input, train_cities[i].name_train);
        if (dist < min_distance)
        {
            min_distance = dist;
            closest_match = train_cities[i].name_train;
        }
    }

    // Check against bus cities
    for (int i = 0; i < bus_count; i++)
    {
        int dist = levenshtein_distance(user_input, bus_cities[i].name_bus);
        if (dist < min_distance)
        {
            min_distance = dist;
            closest_match = bus_cities[i].name_bus;
        }
    }

    // Check against aeroplane cities
    for (int i = 0; i < air_count; i++)
    {
        int dist = levenshtein_distance(user_input, air_cities[i].name_aeroplane);
        if (dist < min_distance)
        {
            min_distance = dist;
            closest_match = air_cities[i].name_aeroplane;
        }
    }

    // Only return if the match is reasonably close (threshold of 3 edits)
    return (min_distance <= 3) ? closest_match : NULL;
}
void suggest_and_confirm(const char *incorrect_input, const char *closest_match)
{
    char response[10];
    printf("\nDid you mean \"%s\"? (yes/no): ", closest_match);
    fgets(response, sizeof(response), stdin);
    response[strcspn(response, "\n")] = '\0'; // Remove newline

    if (strcasecmp(response, "yes") == 0 || strcasecmp(response, "y") == 0)
    {
        printf("Using \"%s\" as the correct city.\n", closest_match);
    }
    else
    {
        printf("No match found for \"%s\". Please try again.\n", incorrect_input);
    }
}
// Function to free train graph memory
void free_train_graph(train cities_train[], int size) {
    for (int i = 0; i < size; i++) {
        connection_train *current = cities_train[i].head;
        while (current != NULL) {
            connection_train *temp = current;
            current = current->next;
            free(temp);
        }
        cities_train[i].head = NULL;
    }
}

// Function to free bus graph memory
void free_bus_graph(bus cities_bus[], int size) {
    for (int i = 0; i < size; i++) {
        connection_bus *current = cities_bus[i].head;
        while (current != NULL) {
            connection_bus *temp = current;
            current = current->next;
            free(temp);
        }
        cities_bus[i].head = NULL;
    }
}

// Function to free aeroplane graph memory
void free_aeroplane_graph(aeroplane cities_aeroplane[], int size) {
    for (int i = 0; i < size; i++) {
        connection_aeroplane *current = cities_aeroplane[i].head;
        while (current != NULL) {
            connection_aeroplane *temp = current;
            current = current->next;
            free(temp);
        }
        cities_aeroplane[i].head = NULL;
    }
}
void simulate_transport_network()
{
    train train_cities[railway_node];
    bus bus_cities[bus_node];
    aeroplane air_cities[aeroplane_node];

    create_graph_train(train_cities);
    create_graph_bus(bus_cities);
    create_graph_aeroplane(air_cities);

    char name[100], transport_mode[20], source[100], destination[100];

    // Welcome the user
    printf("Welcome to Travel Network!!\nWhat's your name? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline
    printf("Hello, %s!\n", name);

    // Select mode of transport
    while (1)
    {
        printf("\nChoose transport mode (train/bus/aeroplane): ");
        fgets(transport_mode, sizeof(transport_mode), stdin);
        transport_mode[strcspn(transport_mode, "\n")] = '\0';

        if (strcasecmp(transport_mode, "train") == 0 ||
            strcasecmp(transport_mode, "bus") == 0 ||
            strcasecmp(transport_mode, "aeroplane") == 0)
            break;

        printf("Invalid mode. Please choose from train, bus, or aeroplane.\n");
    }

    // Get and verify source city
    const char *correct_source = NULL;
    do
    {
        printf("\nEnter source city: ");
        fgets(source, sizeof(source), stdin);
        source[strcspn(source, "\n")] = '\0';

        correct_source = find_closest_city(source, train_cities, railway_node, bus_cities, bus_node, air_cities, aeroplane_node);
        if (!correct_source)
        {
            printf("City not found. Try again.\n");
        }
        else if (strcasecmp(source, correct_source) != 0)
        {
            suggest_and_confirm(source, correct_source);
        }
    } while (!correct_source);

    // Get and verify destination city
    const char *correct_destination = NULL;
    do
    {
        printf("\nEnter destination city: ");
        fgets(destination, sizeof(destination), stdin);
        destination[strcspn(destination, "\n")] = '\0';

        correct_destination = find_closest_city(destination, train_cities, railway_node, bus_cities, bus_node, air_cities, aeroplane_node);
        if (!correct_destination)
        {
            printf("City not found. Try again.\n");
        }
        else if (strcasecmp(destination, correct_destination) != 0)
        {
            suggest_and_confirm(destination, correct_destination);
        }
    } while (!correct_destination);

    // Ask user preference
    int choice;
    printf("\nOptimize for:\n1. Cost\n2. Time\nEnter your choice: ");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
    {
        while (getchar() != '\n')
            ; // Clear buffer
        printf("Invalid input. Please enter 1 or 2: ");
    }

    printf("\n\n\t\tBest Route: -\n\n");

    if (strcasecmp(transport_mode, "train") == 0)
    {
        int src_idx = get_index_train(train_cities, correct_source);
        int dest_idx = get_index_train(train_cities, correct_destination);
        dijkstra_train(train_cities, correct_source, src_idx, dest_idx, choice);
    }
    else if (strcasecmp(transport_mode, "bus") == 0)
    {
        int src_idx = get_index_bus(bus_cities, correct_source);
        int dest_idx = get_index_bus(bus_cities, correct_destination);
        dijkstra_bus(bus_cities, correct_source, src_idx, dest_idx, choice);
    }
    else if (strcasecmp(transport_mode, "aeroplane") == 0)
    {
        int cost_choice;
        printf("\nChoose class for cost optimization:\n");
        printf("1. First Class\n2. Business Class\n3. Premium Economy Class\n4. Economy Class\n");
        printf("Enter your choice: ");
        while (scanf("%d", &cost_choice) != 1 || cost_choice < 1 || cost_choice > 4)
        {
            while (getchar() != '\n')
                ; // Clear buffer
            printf("Invalid input. Choose from 1 to 4: ");
        }

        Edge edges[100];
        int E = extract_edges_aeroplane(air_cities, aeroplane_node, edges, cost_choice);

        int src_idx = get_index_aeroplane(air_cities, correct_source);
        int dest_idx = get_index_aeroplane(air_cities, correct_destination);

        int distances[aeroplane_node];
        int costs[aeroplane_node];
        int predecessors[aeroplane_node];

        bellman_ford_aeroplane(edges, aeroplane_node, E, src_idx, distances, costs, predecessors);

        if (distances[dest_idx] == INT_MAX)
        {
            printf("No path found from %s to %s.\n", correct_source, correct_destination);
        }
        else
        {
            printf("\nShortest Path from %s to %s:\n", correct_source, correct_destination);

            // Reconstruct path using predecessors
            int path[aeroplane_node], path_len = 0;
            for (int v = dest_idx; v != -1; v = predecessors[v])
                path[path_len++] = v;

            printf("Route: ");
            for (int i = path_len - 1; i >= 0; i--)
                printf("%s%s", air_cities[path[i]].name_aeroplane, (i > 0) ? " -> " : "\n");

            printf("Total Time: %d\n", distances[dest_idx]);
            printf("Total Cost (Class %d): $ %d\n", cost_choice, costs[dest_idx]);
        }

    }
    free_train_graph(train_cities, railway_node);
    free_bus_graph(bus_cities, bus_node);
    free_aeroplane_graph(air_cities, aeroplane_node);
    
}


int main()
{
    simulate_transport_network();
    return 0;
}

