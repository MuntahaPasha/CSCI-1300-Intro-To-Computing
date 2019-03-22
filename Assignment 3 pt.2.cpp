// Author: Muntaha Pasha
// Recitation: 204, Camilla
//
// Assignment 3
// Problem 2

#include <iostream>
#include <cmath>

using namespace std;

/**
* Algorithm description:
* Your wind chill calculator determines the wind chill, and you firstly begin by giving it two parameters, with T and V, using those to calculate the wind chill.
* T and V will be floats, along with all the functions, because they take decimal values out more. Do NOT use ints.
* Use a pow function in the calculator, pow with parentheses, first is base then exponents.
* Define and declare all variables in main.
* The function will return wind chill, and in your main is where you call the function and get user inputs for both T and V. Main will send the values up to the calculator.
* Next, we make a function called printwindChill, which similar to windchillCalculator, it takes its parameters from user inputs in the main.
* we define the inputs from user in main, and we send those inputs into each of the functions. All of them are defined in main.
* printWindChill takes those parameters entered by the user in main, and puts them into a formula to calculate an incrementing wind speed, from between low wind speed to high wind speed.
* If you know wind speed will be incrementing between high and low, it's obvious that you will need a while loop, setting the boundaries that the function happens WHILE low wind speed
  is less than or equal to high wind speed.
* In that loop, you are going to begin incrementing your low wind speed, and displaying it each time with the other function until the while loop no longer holds true.
* Once that has been calculated, your function will display your temperature and wind speed, but it'll also show more lines of the wind speed changing while the while loop holds true.
*/
float windChillCalculator(float T, float V)
{
    float windChill;
    windChill = 35.74 + (0.6215*T) - (35.75*(pow(V,0.16))) + (0.4275*T*pow(V,0.16));
    return windChill;
}

void printWindChill(float T, float low_wind_speed, float high_wind_speed, float wind_speed_step)
{

    float wind_chill;


    while(low_wind_speed <= high_wind_speed)
        {
            wind_chill = windChillCalculator(T, low_wind_speed);
            cout<<"The wind chill is "<<wind_chill<<" degrees F for an airtemperature of "<<T<<" degrees F and a wind speed of "<<low_wind_speed<<" mph."<<endl;
            low_wind_speed = low_wind_speed+wind_speed_step;
        }

}


int main(void)
{
    float T;
    float V;
    float windChill;
    float low_wind_speed;
    float high_wind_speed;
    float wind_speed_step;
    cout<<"Input Temperature: "<<endl;
    cin>>T;
    cout<<"Input Wind Speed: "<<endl;
    cin>>V;
    windChill = windChillCalculator(T, V);

    cout<<"The wind chill is "<<windChill<<" degrees F."<<endl;

    cout<<"Enter low wind speed: "<<endl;
    cin>>low_wind_speed;
    cout<<"Enter high wind speed: "<<endl;
    cin>>high_wind_speed;
    cout<<"Enter wind speed step: "<<endl;
    cin>>wind_speed_step;

    printWindChill(T, low_wind_speed, high_wind_speed, wind_speed_step);
}
