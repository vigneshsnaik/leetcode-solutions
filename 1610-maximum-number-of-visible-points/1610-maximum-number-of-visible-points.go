func visiblePoints(points [][]int, angle int, location []int) int {
	angles := []float64{}
	originPoints := 0
	for _, point := range points {
		if point[0] == location[0] && point[1] == location[1] {
			originPoints++
		} else {
			angleDeg := (math.Atan2(float64(point[1]-location[1]), float64(point[0]-location[0])) * (180.0 / math.Pi))
			if angleDeg < 0 {
				angleDeg += 360
			}
			angles = append(angles, angleDeg)
		}
	}
	sort.Float64s(angles)
	n := len(angles)
	for i := 0; i < n; i++ {
		angles = append(angles, angles[i]+360)
	}
	maxpoints := 0
    j := 0
	for i := 0; i < n; i++ {
		for j < n*2 && (angles[j]-angles[i] <= float64(angle)) {
			j++
		}
		maxpoints = int(math.Max(float64(maxpoints), float64(j-i)))
	}
	return maxpoints + originPoints
}