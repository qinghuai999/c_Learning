#include <stdio.h>
#include <math.h>
/**
 * @Author: Kiki Su
 * @CreateDate: 2026-01-23 13:02:47
 * @Description:
 */

struct Location {
    char *name;
    int altitude;
    float temperature;
    float humidity;
    float windspeed;
};

float compute_apparent_temp(struct Location location) {
    float AT;
    AT = location.temperature + 0.0201465 * location.humidity * exp((17.27 * location.temperature) / (237.7 + location.temperature)) - 0.7 * location.windspeed - 4;
    return AT;
}

int main(int argc, char **argv) {
    struct Location location = {
        .name = "Brisbane",
        .windspeed = 0.1,
        .altitude = 2,
        .temperature = 25.6l,
        .humidity = 20.0
    };
    printf("%s is %dm above sea level with a temperature of %gdegC and humidity of %g%%\n", location.name,
           location.altitude, location.temperature, location.humidity);

    printf("%s's apparent temp is %fdegC.\n", location.name, compute_apparent_temp(location));
    return 0;
}
