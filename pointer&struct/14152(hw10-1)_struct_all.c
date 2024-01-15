/*combine*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// header
typedef void (*Attack)(struct Contestant *, struct Contestant *);
// = struct Contestant *ptr;
// function pointer named Attack, This function pointer type can point to a function that takes two parameters of type struct Contestant * and returns void

struct Contestant
{
  char name[100];
  int health;
  int strength;
  int magic;
  int defense;
  int resistance;
  Attack attackType;
};
/*this is partial judge, only finish below func def*/
void magicalAttack(struct Contestant *self, struct Contestant *target);
void physicalAttack(struct Contestant *self, struct Contestant *target);
void getContestants(struct Contestant *contestants, int len);
int findTarget(struct Contestant *contestants, int idx, int len);

// main c

int main()
{
  struct Contestant contestants[105];

  int num;
  // input
  scanf("%d", &num);
  getContestants(contestants, num);

  //
  int idx = 0;
  int temp = 0;
  while (1)
  {
    if (contestants[idx].health <= 0) // it self has no health, should not attack the other
    {
      idx = (idx + 1) % num; // deal with when 3 + 1 > 0
      continue;              // health <= 0 has no right to attack
    }
    int targetIndex = findTarget(contestants, idx, num);

    if (targetIndex == idx) // win condition
    {
      break;
    }

    contestants[idx].attackType(&contestants[idx], &contestants[targetIndex]);

    idx = (idx + 1) % num;
  }

  printf("%s wins the tournament\n", contestants[idx].name);

  return 0;
}

// func def
void magicalAttack(struct Contestant *self, struct Contestant *target)
{
  target->health -= (self->magic - target->resistance);
}
void physicalAttack(struct Contestant *self, struct Contestant *target)
{
  target->health -= (self->strength - target->defense);
}

void getContestants(struct Contestant *contestants, int len)
{
  char attacktype[20];
  for (int i = 0; i < len; i++)
  {
    // Keith 100 50 20 20 0 physical
    scanf("%s %d %d %d %d %d %s",
          contestants[i].name,
          &contestants[i].health, //**use &
          &contestants[i].strength,
          &contestants[i].magic,
          &contestants[i].defense,
          &contestants[i].resistance,
          attacktype);

    if (strcmp(attacktype, "magical") == 0)
    {
      contestants[i].attackType = &magicalAttack;
    }
    else if (strcmp(attacktype, "physical") == 0)
    {
      contestants[i].attackType = &physicalAttack;
    }
  }
}
int findTarget(struct Contestant *contestants, int idx, int len)
{
  int targetidx = (idx + 1) % len; // Initialize targetidx to next contestant

  while (targetidx != idx)
  {
    if (contestants[targetidx].health > 0) //**must > 0 , not !=0!!
    {
      return targetidx;
    }
    targetidx = (targetidx + 1) % len; // look for next targetidx
  }

  return idx; // **Return the current contestant if no healthy target found
}
