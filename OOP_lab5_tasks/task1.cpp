//Task # 01 by Ali Akhter 24k-0809
#include<iostream>
using namespace std;
class WeatherStats{
    private:
    const double *temp;
    const int num_readings;
    public:
    WeatherStats(const double *temp,int num_readings):temp(temp),num_readings(num_readings){};
    static double CalculateAverageTemperature(double const *temp , int NumReadings) {
        double sum=0;
        for(int i=0;i<NumReadings;i++){
            sum+=temp[i];
        }
        return sum/NumReadings;
    }
    double getTemperatureFluctuation() const {
        double max=-999999,min=999999;
        for(int i=0;i<num_readings;i++){
            if(temp[i]>max){
                max=temp[i];
            }
            if(temp[i]<min){
                min=temp[i];
            }
        }
        return max-min;
    }
};
int main(){
    int TempReading;
    cout<<"Enter number of temperature readings you have: ";
    cin>>TempReading;
    double temperature[TempReading];
    for(int i=0;i<TempReading;i++){
        cout<<"Reading "<<i+1<<": ";
        cin>>temperature[i];
    }
    double Average=WeatherStats::CalculateAverageTemperature(temperature,TempReading);
    WeatherStats w(temperature,TempReading);
    double fluctuations=w.getTemperatureFluctuation();
    cout<<"Average: "<<Average<<endl;
    cout<<"Fluctuations: "<<fluctuations<<endl;

}