#ifndef HEADER_H
#define HEADER_H

typedef struct {
    int id;
    char name[30];
    int capacity;
    int size;
    float *readings;
} SensorData;

void createSensorData(SensorData *S, int *id, char name[]);
void addReading(SensorData *S, float valor);
void freeSensorData(SensorData *S);
int menu();
void listSensorData(SensorData S[], int size);

#endif