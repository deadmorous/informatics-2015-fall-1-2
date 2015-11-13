#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

template<class T>
struct PointTemplate
{
    T x;
    T y;
    PointTemplate() : x(0), y(0) {}
    PointTemplate(T x, T y) : x(x), y(y) {}
};
typedef PointTemplate<int> Point;
typedef PointTemplate<double> PointF;

class ScreenBuffer
{
public:
    ScreenBuffer()
    {
        clear();
    }

    void clear()
    {
        fill(m_data[0], m_data[0]+Width*Height, ' ');
    }
    void setPixel(const Point& r, char v)
    {
        if (contains(r))
            m_data[r.y][r.x] = v;
    }
    void print(ostream& s) const
    {
        for (int r=0; r<Height; ++r)
        {
            for (int c=0; c<Width; ++c)
                s << m_data[Height-1-r][c];
            s << endl;
        }
    }

    int width() const
    {
        return Width;
    }

    int height() const
    {
        return Height;
    }

    bool contains(const Point& r) const
    {
        return
            r.x >= 0   &&   r.x < Width   &&
            r.y >= 0   &&   r.y < Height;
    }

private:
    static const int Width = 79;
    static const int Height = 24;
    char m_data[Height][Width];
};

ostream& operator <<(ostream& s, const ScreenBuffer& sb)
{
    sb.print(s);
    return s;
}

class Canvas
{
public:
    Canvas(const PointF& min, const PointF& max) :
        m_min(min), m_max(max)
    {}
    void setPixel(const PointF& r, char v)
    {
        m_sb.setPixel(Point(
            (r.x - m_min.x) / (m_max.x - m_min.x) * m_sb.width(),
            (r.y - m_min.y) / (m_max.y - m_min.y) * m_sb.height()
        ), v);
    }
    const ScreenBuffer& screenBuffer() const
    {
        return m_sb;
    }
    PointF min() const
    {
        return m_min;
    }
    PointF max() const
    {
        return m_max;
    }
    double pixelWidth() const
    {
        return (m_max.x - m_min.x) / m_sb.width();
    }
    double pixelHeight() const
    {
        return (m_max.y - m_min.y) / m_sb.height();
    }

private:
    ScreenBuffer m_sb;
    PointF m_min;
    PointF m_max;
};

ostream& operator <<(ostream& s, const Canvas& c)
{
    return s << c.screenBuffer();
}

typedef double (*FuncDoubleToDouble)(double);

template<class F>
class Plotter
{
public:
    explicit Plotter(F f, char v) :
        m_f(f), m_v(v) {}
    void operator ()(Canvas& c) const
    {
        for (double x=c.min().x; x<c.max().x; x+=c.pixelWidth())
            c.setPixel(PointF(x,m_f(x)), m_v);
    }
private:
    F m_f;
    char m_v;
};

template< class F >
Plotter<F> makePlotter(F f, char v)
{
    return Plotter<F>(f, v);
}

Plotter<FuncDoubleToDouble> makePlotter(FuncDoubleToDouble f, char v)
{
    return Plotter<FuncDoubleToDouble>(f, v);
}

class sin_x_minus_alpha_x : public unary_function<double, double>
{
public:
    explicit sin_x_minus_alpha_x(double alpha) : m_alpha(alpha) {}
    double operator()(double x) const {
        return sin(x) - m_alpha*x;
    }
private:
    double m_alpha;
};

template< class F >
Canvas& operator<<(Canvas& c, const Plotter<F>& p)
{
    p(c);
    return c;
}

int main()
{
    Canvas c(PointF(-3,-1.1), PointF(3, 1.1));

    c << makePlotter(sin, '*')
      << makePlotter(sin_x_minus_alpha_x(0.1), '.')
      << makePlotter(sin_x_minus_alpha_x(0.3), '-')
      << makePlotter(cos, '+');

    cout << c;
    return 0;
}
