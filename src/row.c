#include "sudoku.h"

int checkRows(Square ***sudoku, Box **boxes) {
  int sum[9];
  int place[9];

  for (int i = 0; i < 9; i++) { // all rows
    for (int j = 0; j < 9; j++) { // initialize sum
      sum[j] = 0;
      place[j] = 0;
    }
    for (int j = 0; j < 9; j++) { // all squares
      if (sudoku[i][j]->number != 0) {
        continue;
      }
      // loop through all possibilities
      for (int k = 0; k < 9; k++) {
        // check if number k is possible
        if (sudoku[i][j]->possible[k] == 0) {
          sum[k]++;
          place[k] = j;
        }
      }
    }

    for (int j = 0; j < 9; j++) {
      if (sum[j] == 1) {
        sudoku[i][place[j]]->number = j + 1;
        sudoku[i][place[j]]->solvable = 0;
        UNSOLVED--;
        updateSudoku(sudoku, i, place[j]);
        updateBoxes(sudoku, i, place[j]);
        return 1;
      }
    }
  }
  return 0;
}