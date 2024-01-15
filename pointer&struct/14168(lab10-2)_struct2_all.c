#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Duelist
{
  char name[100];
  int health;

  int strength;
  int magic;
  int healingPower;

  int defense;
  int resistance;

  void (*move)(struct Duelist *, struct Duelist *);
};

void magicalAttack(struct Duelist *self, struct Duelist *target);
void physicalAttack(struct Duelist *self, struct Duelist *target);
void heal(struct Duelist *self, struct Duelist *target);
struct Duelist getDuelist();

int main()
{
  struct Duelist duelistA = getDuelist();
  struct Duelist duelistB = getDuelist();

  int round = 0;

  while ((duelistA.health > 0 && duelistB.health > 0) && round < 20)
  {
    duelistA.move(&duelistA, &duelistB);
    duelistB.move(&duelistB, &duelistA);

    round += 1;

    printf("Round %d: %d %d\n", round, duelistA.health, duelistB.health);
  }

  if ((duelistA.health <= 0 && duelistB.health <= 0) || (duelistA.health > 0 && duelistB.health > 0))
  {
    printf("Draw\n");
  }
  else if (duelistA.health <= 0)
  {
    printf("%s wins\n", duelistB.name);
  }
  else if (duelistB.health <= 0)
  {
    printf("%s wins\n", duelistA.name);
  }
  // print check
  // printf("%s %d %d %d %d %d %d  %p \n",
  //        duelistA.name,
  //        duelistA.health,
  //        duelistA.strength,
  //        duelistA.magic,
  //        duelistA.healingPower,
  //        duelistA.defense,
  //        duelistA.resistance,
  //        duelistA.move);

  return 0;
}

void magicalAttack(struct Duelist *self, struct Duelist *target)
{
  int damage = self->magic - target->resistance;
  if (damage < 0)
    damage = 0;
  else
    target->health -= damage;

  // then switch to physical attack
  self->move = &physicalAttack;
  return;
}
void physicalAttack(struct Duelist *self, struct Duelist *target)
{
  // // if target is in healing move, add hp first
  // if (target->move == &heal)
  //   target->health += target->healingPower;
  // heal(target, self); // should not call it, as it will switch target mode
  // attack
  int damage = self->strength - target->defense;
  if (damage < 0)
    damage = 0;
  else
    target->health -= damage;
  // then switch to heal
  self->move = &heal;
  return;
}
void heal(struct Duelist *self, struct Duelist *target) // heal itself
{
  self->health += self->healingPower;
  // then switch to magical atack
  self->move = &magicalAttack;
  return;
}
struct Duelist getDuelist() //**we return a struct Duelist address
{
  struct Duelist temp;
  char string[20];
  scanf("%s %d %d %d %d %d %d %s",
        temp.name,
        &temp.health,
        &temp.strength,
        &temp.magic,
        &temp.healingPower,
        &temp.defense,
        &temp.resistance,
        string);
  if (strcmp(string, "physical") == 0)
    temp.move = &physicalAttack;
  if (strcmp(string, "magical") == 0)
    temp.move = &magicalAttack;

  return temp;
}