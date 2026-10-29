package weather 
// this package contains various funcionalities associated with weather

var CurrentCondition string
var CurrentLocation string

// returns forecast of the location based on the current condition
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
