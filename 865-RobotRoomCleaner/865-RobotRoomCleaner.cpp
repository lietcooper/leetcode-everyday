// Last updated: 12/8/2025, 11:26:59 PM
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
private:
    // going clockwise
    int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
    // set<pair<int, int>> visited;
    unordered_set<string> visited;

public:
    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void backtrack(int row, int col, int d, Robot& robot) {
        // visited.insert({row, col});
        string key = to_string(row) + "," + to_string(col);
        visited.insert(key);
        robot.clean();
        for (int i = 0; i < 4; ++i) {
            int newD = (d + i) % 4;
            int nRow = row + dir[newD][0];
            int nCol = col + dir[newD][1];
            key = to_string(nRow) + "," + to_string(nCol);
            // if (visited.find({nRow, nCol}) == visited.end() && robot.move()) {
            if (visited.find(key) == visited.end() && robot.move()) {
                backtrack(nRow, nCol, newD, robot);
                goBack(robot);
            }
            robot.turnRight();
        }
    }

    void cleanRoom(Robot& robot) {
        backtrack(0, 0, 0, robot);
    }
};