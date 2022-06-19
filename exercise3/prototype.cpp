struct Point {
  int x{0}, y{0};

  Point(const int x, const int y) : x{x}, y{y} {}
};

struct Line {
  Point *start, *end;

  Line(Point* const start, Point* const end) : start{start}, end{end} {}

  Line(const Line& other) {
    start = new Point{*other.start};
    end = new Point{*other.end};
  }

  ~Line() {
    delete start;
    delete end;
  }

  Line deep_copy() const { return Line{*this}; }
};