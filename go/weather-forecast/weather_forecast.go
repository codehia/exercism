// Package weather shows the forcast for the current location.
package weather 

// CurrentCondition: string representing current weather.
var CurrentCondition string
// CurrentLocation: string representing current location of the weather.
var CurrentLocation string

// Forecast: forecasts weather of the city based on the condition.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
