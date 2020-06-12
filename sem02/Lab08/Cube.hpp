#pragma once

class Cube
{
public:
	Cube();
	~Cube();
	void Print();

	void ManualControl();
	void Generate();

	void ReturnPath();
	bool FindPath();

	unsigned char** GetCube();
private:
	std::string path;
	unsigned char** data;

	void panel_right_turn(int turn);
	void panel_left_turn(int turn);
	void YellowRight();
	void YellowLeft();
	void RedRight();
	void RedLeft();
	void GreenRight();
	void GreenLeft();
	void OrangeRight();
	void OrangeLeft();
	void WhiteRight();
	void WhiteLeft();
	void BlueRight();
	void BlueLeft();

	void rotate_while_white(int position);
	void make_cross();
	void MakeWhiteCross();
	int count_correct_edges();
	void MakeWhiteCorners();
	void rotate_while_incorrect_corners(int position);
	void R6perebor();
	void G6perebor();
	void O6perebor();
	void B6perebor();
	void make_corners();
	void blue_edge();
	void red_edge();
	void green_edge();
	void orange_edge();
	void make_edges();
	void CompleteFirstLayer();
	void CompleteSecondLayer();
	void goy_oyg(int count);
	void rgy_gyr(int count);
	bool TryYellowCross();
	void helicopter_trick();
	void ears_trick();
	void nose_trick();
	void eyes_trick();
	void triple_pif_paf_trick();
	void right_fish_trick();
	void left_fish_trick();
	bool TryYellowCorners();
	void have_pair_trick();
	void not_pair_trick();
	void FinishCorners();
	void last_green_left();
	void last_green_right();
	void last_orange_left();
	void last_orange_right();
	void last_blue_left();
	void last_blue_right();
	void last_red_left();
	void last_red_right();
	bool TryFinishThirdLayer();
};

