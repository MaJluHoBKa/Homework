#include <iostream>
#include <array>

using namespace std;

class rubiks_cube
{
public:
	enum color { e_white, e_red, e_green, e_orange, e_blue, e_yellow };
	enum side { e_top, e_front, e_left, e_back, e_right, e_bottom };
	enum direction { e_middle, e_equator, e_standing };

	rubiks_cube()
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (j > 1 && j < 4 && i < 2)
				{
					this->qube[i][j] = e_white;
				}
				else if (i > 1 && i < 4)
				{
					if (j < 2) { this->qube[i][j] = e_green; }
					else if (j > 1 && j < 4) { this->qube[i][j] = e_red; }
					else if (j > 3 && j < 6) { this->qube[i][j] = e_blue; }
					else if (j > 5 && j < 8) { this->qube[i][j] = e_orange; }
				}
				else if (i > 3 && i < 6 && j > 1 && j < 4)
				{
					this->qube[i][j] = e_yellow;
				}
			}
		}
	}
	rubiks_cube(const rubiks_cube& other)
	{
		this->qube = other.qube;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				this->qube[i][j] = other.qube[i][j];
			}
		}
	}
	rubiks_cube& operator=(const rubiks_cube& other)
	{

		this->qube = other.qube;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				this->qube[i][j] = other.qube[i][j];
			}
		}
		return *this;
	}

	void rotate_side(side side_to_rotate, int n)
	{
		color a, b, s;
		if (side_to_rotate == e_top)
		{
			for (int i = 0; i < n; i++)
			{
				a = qube[2][0];
				b = qube[2][1];
				s = qube[0][2];
				for (int j = 0; j < 6; j++)
				{
					qube[2][j] = qube[2][j + 2];
				}
				qube[2][6] = a;
				qube[2][7] = b;
				qube[0][2] = qube[1][2];
				qube[1][2] = qube[1][3];
				qube[1][3] = qube[0][3];
				qube[0][3] = s;
			}
		}
		else if (side_to_rotate == e_front)
		{
			for (int i = 0; i < n; i++)
			{
				a = qube[2][1];
				b = qube[3][1];
				s = qube[2][2];
				qube[2][1] = qube[4][2];
				qube[3][1] = qube[4][3];
				qube[4][2] = qube[3][4];
				qube[4][3] = qube[2][4];
				qube[3][4] = qube[1][3];
				qube[2][4] = qube[1][2];
				qube[1][3] = a;
				qube[1][2] = b;
				qube[2][2] = qube[3][2];
				qube[3][2] = qube[3][3];
				qube[3][3] = qube[2][3];
				qube[2][3] = s;
			}
		}
		else if (side_to_rotate == e_left)
		{
			for (int i = 0; i < n; i++)
			{
				a = qube[2][2];
				b = qube[3][2];
				s = qube[2][1];
				qube[3][2] = qube[1][2];
				qube[2][2] = qube[0][2];
				qube[1][2] = qube[2][7];
				qube[0][2] = qube[3][7];
				qube[3][7] = qube[4][2];
				qube[2][7] = qube[5][2];
				qube[5][2] = b;
				qube[1][2] = a;
				qube[2][1] = qube[2][0];
				qube[2][0] = qube[3][0];
				qube[3][0] = qube[3][1];
				qube[3][1] = s;
			}
		}
		else if (side_to_rotate == e_back)
		{
			for (int i = 0; i < n; i++)
			{
				a = qube[2][0];
				b = qube[3][0];
				s = qube[2][7];
				qube[3][0] = qube[0][2];
				qube[2][0] = qube[0][3];
				qube[0][2] = qube[2][5];
				qube[0][3] = qube[3][5];
				qube[2][5] = qube[5][3];
				qube[3][5] = qube[5][2];
				qube[5][3] = b;
				qube[5][2] = a;
				qube[2][7] = qube[2][6];
				qube[2][6] = qube[3][6];
				qube[3][6] = qube[3][7];
				qube[3][7] = s;
			}
		}
		else if (side_to_rotate == e_right)
		{
			for (int i = 0; i < n; i++)
			{
				a = qube[2][6];
				b = qube[3][6];
				s = qube[2][5];
				qube[2][6] = qube[1][3];
				qube[3][6] = qube[0][3];
				qube[1][3] = qube[3][3];
				qube[0][3] = qube[2][3];
				qube[2][3] = qube[4][3];
				qube[3][3] = qube[5][3];
				qube[4][3] = b;
				qube[5][3] = a;
				qube[2][5] = qube[2][4];
				qube[2][4] = qube[3][4];
				qube[3][4] = qube[3][5];
				qube[3][5] = s;
			}
		}
		else if (side_to_rotate == e_bottom)
		{
			for (int i = 0; i < n; i++)
			{
				a = qube[3][4];
				b = qube[3][5];
				s = qube[4][3];
				qube[3][4] = qube[3][2];
				qube[3][5] = qube[3][3];
				qube[3][2] = qube[3][0];
				qube[3][3] = qube[3][1];
				qube[3][0] = qube[3][6];
				qube[3][1] = qube[3][7];
				qube[3][6] = b;
				qube[3][7] = a;
				qube[4][3] = qube[4][2];
				qube[4][2] = qube[5][2];
				qube[5][2] = qube[5][3];
				qube[5][3] = s;
			}
		}
	}
	void rotate_cube(direction direction_to_rotate, int n)
	{
		if (direction_to_rotate == e_middle)
		{
			rotate_side(e_left, n);
			rotate_side(e_right, n);
		}
		else if (direction_to_rotate == e_equator)
		{
			rotate_side(e_top, n);
			rotate_side(e_bottom, n);
		}
		else if (direction_to_rotate == e_standing)
		{
			rotate_side(e_front, n);
			rotate_side(e_back, n);
		}
	}
	const array<color, 4>& get_side(side side_to_get) const
	{
		array<color, 4> getColor;
		if (side_to_get == e_top)
		{
			getColor[0] = qube[0][2];
			getColor[1] = qube[0][3];
			getColor[2] = qube[1][2];
			getColor[3] = qube[1][3];
		}
		else if (side_to_get == e_front)
		{
			getColor[0] = qube[2][2];
			getColor[1] = qube[2][3];
			getColor[2] = qube[3][2];
			getColor[3] = qube[3][3];
		}
		else if (side_to_get == e_left)
		{
			getColor[0] = qube[2][0];
			getColor[1] = qube[2][1];
			getColor[2] = qube[3][0];
			getColor[3] = qube[3][1];
		}
		else if (side_to_get == e_right)
		{
			getColor[0] = qube[2][4];
			getColor[1] = qube[2][5];
			getColor[2] = qube[3][4];
			getColor[3] = qube[3][5];
		}
		else if (side_to_get == e_back)
		{
			getColor[0] = qube[2][6];
			getColor[1] = qube[2][7];
			getColor[2] = qube[3][6];
			getColor[3] = qube[3][7];
		}
		else if (side_to_get == e_bottom)
		{
			getColor[0] = qube[4][2];
			getColor[1] = qube[4][3];
			getColor[2] = qube[5][2];
			getColor[3] = qube[5][3];
		}
		return getColor;
	}

	~rubiks_cube() = default;
private:
	array<array<color, 6>, 8> qube;
};
