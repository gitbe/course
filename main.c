#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <argp.h>

enum card_e
{
        CARD_1,
        CARD_2,
        CARD_3,
        CARD_4,
        CARD_5,
        CARD_6,
        CARD_7,
        CARD_8,
        CARD_9,
	CARD_JOKER,
	CARD_QUEEN,
	CARD_KING
};

const char* get_card_name(enum card_e card)
{
	switch (card)
	{
		case CARD_1: return "card 1";
		case CARD_2: return "card 2";
                case CARD_3: return "card 3";
                case CARD_4: return "card 4";
		case CARD_5: return "card 5";
                case CARD_6: return "card 6";
                case CARD_7: return "card 7";
                case CARD_8: return "card 8";
                case CARD_9: return "card 9";
                case CARD_JOKER: return "card joker";
		case CARD_QUEEN: return "card queen";
		case CARD_KING : return "card king";
	}

	assert(!"Wrong card provided!\n");
	return "card 1";
}

int randint(int n)
{
	if ((n - 1) == RAND_MAX)
	{
    		return rand();
	}
	else
	{
		// Chop off all of the values that would cause skew...
		long end = RAND_MAX / n; // truncate skew
 		assert (end > 0L);
    		end *= n;

    		// ... and ignore results from rand() that fall above that limit.
    		// (Worst case the loop condition should succeed 50% of the time,
    		// so we can expect to bail out of this loop pretty quickly.)
    		int r;
    		while ((r = rand()) >= end);
   		return r % n;
  	}
}

enum card_e get_random_card()
{
	static bool initialized = false;
	if(!initialized)
	{
		struct timeval time;
		gettimeofday(&time, NULL);
		//srand(time(NULL)); => Not very precise: as long as same second it returns the same value
		srand((time.tv_sec * 1000) + (time.tv_usec/1000));
		initialized = true;
	}

	const int r = randint(12);
	return (enum card_e)r;
}

int main(int argc, char **argv)
{
	enum card_e card = get_random_card();

	fprintf(stderr, "Choosen card: %s\n", get_card_name(card));

	return 0;
}
