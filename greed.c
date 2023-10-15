#include <stdio.h>

int score(const int dice[5]) {
	int n = 0, total = 0;
	int score[6] = {0};
  
	for (int i = 0; i < 5; i++) {
		score[dice[i] - 1] += 1;
	}

	for (int p = 0; p < 6; p++) {
	  	if (score[p] > 2) {
	  		if (p == 0) {
	  			total += 1000;
	  		} else {
	  			total += (p + 1) * 100;
	  		}

	  		score[p] -= 3;
  		}

  		if (score[0] < 3) {
	  			total += (score[0] * 100);
	  			score[0] = 0;
		} 

		if (score[4] < 3) {
			total += (score[4] * 50);
			score[4] = 0;
		}
	}
  	return total;
}

int main() {
	const int dice[5] = {1, 1, 1, 5, 1};
	printf("%d\n", score(dice));

	return 0;
}