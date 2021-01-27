class vehicle
{
public:
	vehicle(){};
	vehicle
	(
		double weight,		// kg
		double maxLoad,		// kg
		double maxSpeed,	// kmph
		int numSeats,		// int 
		int numWheels 		// int
	):
	weight_(weight),
	maxLoad_(maxLoad),
	maxSpeed_(maxSpeed),
	numSeats_(numSeats),
	numWheels_(numWheels)
	{}
	~vehicle(){};

	const int weight() const { return weight_; }
	const int maxLoad() const { return maxLoad_; } 
	const int maxSpeed() const { return maxSpeed_; } 
	const int numSeats() const { return numSeats_; } 
	const int numWheels() const { return numWheels_; } 

private:
	double weight_;
	double maxLoad_;
	double maxSpeed_;
	int numSeats_;
	int numWheels_;
};


