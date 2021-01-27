class rectangular
{
public:
	// constructor
	rectangular(){};
	rectangular(
		double width,
		double height
	):
	width_(width),
	height_(height)
	{};
	// member function
	double width() const {return width_;}
	double height() const {return height_;}
	double size() const {
		return width_*height_;
	}
	// destructor
	~rectangular(){};
	
private:
	double width_ = 0;
	double height_ = 0;
};

// inheritance type: public/protected/private
class square:
public rectangular
{
	public:
	explicit square(double side):
	rectangular(side, side){}
};

