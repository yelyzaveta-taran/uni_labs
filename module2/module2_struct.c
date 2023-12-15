#include <stdio.h>
#include <string.h>

// вкладена структура для інформації про батарею
struct Battery
{
    int capacity;  // місткість батареї в мАг
    char type[20]; // тип батареї
};

// вкладена структура для інформації про камеру
struct Camera
{
    int resolution;    // роздільна здатність камери в мегапікселях
    char features[50]; // особливості камери (автофокус, відеозйомка, тощо)
};

// основна структура для телефона
struct Phone
{
    char model[50];             // модель телефона
    char brand[30];             // бренд виробника
    int releaseYear;            // рік випуску
    float displaySize;          // розмір екрану в дюймах
    struct Battery batteryInfo; // вкладена структура для інформації про батарею
    struct Camera cameraInfo;   // вкладена структура для інформації про камеру
};

int main()
{
    struct Phone iPhoneX = {
        "iPhone X",
        "Apple",
        2017,
        5.8,
        {2716, "Lithium"},
        {12, "Optic stabilisation"}};

    printf("Model: %s\n", iPhoneX.model);
    printf("Brand: %s\n", iPhoneX.brand);
    printf("Release year: %d\n", iPhoneX.releaseYear);
    printf("Display size: %.1f \n", iPhoneX.displaySize);
    printf("Battery: Capacity - %d, Type - %s\n", iPhoneX.batteryInfo.capacity, iPhoneX.batteryInfo.type);
    printf("Camera: Resolution - %d, Features - %s\n", iPhoneX.cameraInfo.resolution, iPhoneX.cameraInfo.features);

    return 0;
}
