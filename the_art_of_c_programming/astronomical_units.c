/* Write a function delay(d) that returns the time
 * that it takes a radio message to reach a space probe
 * at a distance of d astronomical units from the transmitter.
 *
 * Astronomical units (AU) = 93 million miles
 * Speed of light is 186,000 miles per second.
 *
 * t = distance in miles / speed of light 
 */

#include <stdio.h>

/* delay: in seconds for a radio message to reach is destination */
double delay(double d) {
    const double speed_of_light = 186000;       /* in miles per second */
    const double au_to_miles = 93000000;        /* 1 AU in miles */

    /* convert distance from AU to miles */
    double distance_in_miles = d * au_to_miles;

    /* calculate time delay in seconds */
    double time_delay = distance_in_miles / speed_of_light;

    return time_delay;
}

/* mtok: convert miles to kilometers */
double mtok(double miles) {
    const double miles_to_km = 1.60934; /* factor from miles to kilo */
    return miles * miles_to_km;
}

/* ktom: convert kilo to miles */
double ktom(double kilo) {
    const double km_to_miles = 1 / 1.60934;
    return kilo * km_to_miles;
}
