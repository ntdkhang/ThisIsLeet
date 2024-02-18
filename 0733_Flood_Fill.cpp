#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> result(image);
        vector<int> travelled(image.size() * image.at(0).size(), 0); // 0 means not travelled, 1 means travelled
        floodFill(image, result, travelled, sr, sc, color);
        return result;
    }

    bool canTravel(const vector<vector<int>>& image, vector<int> travelled, int sourceColor, int r, int c) {
        if (r >= 0 && c >= 0 && r < image.size() && c < image.at(0).size() 
                && !travelled[r * image.at(0).size() + c] && image.at(r).at(c) == sourceColor) {
            return true;
        } 
        return false;
    }

    void floodFill(const vector<vector<int>>& image, vector<vector<int>>& result, vector<int> travelled, int sr, int sc, int color) {
        travelled[sr * image.at(0).size() + sc] = 1;
        if (canTravel(image, travelled, image.at(sr).at(sc), sr - 1, sc)) { // Travel up
            floodFill(image, result, travelled, sr - 1, sc, color);
        } 
        if (canTravel(image, travelled, image.at(sr).at(sc), sr, sc + 1)) { // Travel right
            floodFill(image, result, travelled, sr, sc + 1, color);
        } 
        if (canTravel(image, travelled, image.at(sr).at(sc), sr, sc - 1)) { // Travel left
            floodFill(image, result, travelled, sr, sc - 1, color);
        } 
        if (canTravel(image, travelled, image.at(sr).at(sc), sr + 1, sc)) { // Travel down
            floodFill(image, result, travelled, sr + 1, sc, color);
        }
        result.at(sr).at(sc) = color;
    }
};
