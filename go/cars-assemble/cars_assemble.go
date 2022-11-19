package cars

const productionCostPerCar = 10000
const productionCostPerTenCars = 95000

// CalculateWorkingCarsPerHour calculates how many working cars are
// produced by the assembly line every hour.
func CalculateWorkingCarsPerHour(productionRate int, successRate float64) float64 {
  // type case into to float64 to return float64 type number
  return float64(successRate) * float64(productionRate) / 100
}

// CalculateWorkingCarsPerMinute calculates how many working cars are
// produced by the assembly line every minute.
func CalculateWorkingCarsPerMinute(productionRate int, successRate float64) int {
  return int(CalculateWorkingCarsPerHour(productionRate, successRate) / 60)
}

// CalculateCost works out the cost of producing the given number of cars.
func CalculateCost(carsCount int) uint {
  return uint((carsCount / 10) * productionCostPerTenCars + (carsCount % 10) * productionCostPerCar)
}
