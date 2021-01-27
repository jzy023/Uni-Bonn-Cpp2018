// static member variable is shared among different
// instances of that class

class point {
public:
	point(
		int x,
		int y
	):
	x_(x),
	y_(y)
	{}

	float distance(const point& other)
	const {
		float x_diff = x_ - other.x_;
		float y_diff = y_ - other.y_;
		return sqrt(x_diff*x_diff + y_diff*y_diff);
	}

	static float distance(
		const point& a,
		const point& b
	){
		// return a.distance(b);
		float x_diff = a.x_ - b.x_;
		float y_diff = a.y_ - b.y_;
		return sqrt(x_diff*x_diff + y_diff*y_diff);
	}

private:
	int x_ = 0;
	int y_ = 0;

};