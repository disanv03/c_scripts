/* conv(t) convert a temperature from Fahrenheit to Celsius */
int conv(int f) { /* f for Fahrenheit temperature */
    int c; /* celsius */
    c = 5 * (f - 32) / 9;

    return c;
}

/* vnoc: vnoc undoes what conv does, inverse operation from
 * Celsius to Fahrenheit
 */
int vnoc(int c) {
    int fah;
    fah = (9 * u / 5) + 32;
    return fah;
}
    
