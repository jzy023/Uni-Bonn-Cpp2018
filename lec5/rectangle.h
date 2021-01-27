class rectangle
{
public:
	// constructor
	rectangle(){}
	rectangle(
		double width,
		double height
	):
	width_(width),
	height_(height)
	{}
	// getter functions
	double width() {return width_;}
	double height() {return height_;}
	// virtual member function means it can be changed by 
	// derived classes
	virtual void print() const {
		std::cout << "rectangular: " << width_  
				  << "*" << height_ << std::endl;
	}
	// pure virtual functions, forces all child class to
	// implement their own version of print() function
	// -->  virtual void print() const = 0;
	// destructor
	~rectangle(){}
protected:
	// since there are functions in inherited class accessing
	// the data, use 'protected' instead of private
	double width_ = 0;
	double height_ = 0;
};

// inheriting class
class square : 
public rectangle {
public:
	explicit square(double side) : rectangle(side, side){}
	// virtual member function override
	void print() const override {
		std::cout << "square: " << width_  
				  << "*" << height_ << std::endl;
	}
};