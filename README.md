# CC3K
An RPG game written by C++
- Oriented object programming
- Various design patterns

WELCOME TO CHAMBERCRAWLER3000!
**********************************************************
* Controls *
************
   no, ne, etc.. -Cardinal directional movement

   q  w  e
   a     d       - Additional movement keys. Moving onto an enemy will now also attack them.
   z s/x c          Can be combined with use(u) and skill(1,2) command.

   u + [dir.]    - Attempt to use the item in the direction specified.
   1 / 2         - Use skill 1 / 2. If the skill is targetted, specify a direction.

   Note: -Invalid moves and input will be ignored.
         -Multiple commands can be entered. They do not have to be space separated.

**********************************************************
* Skills *
**********
   Heal          - Self-Explanatory.
   Divine Strike - Deal Damage and Heal for Half.

**********************************************************
* Mechanics *
*************
   Dodging       - Chance to not take damage when attacked. Most players dodge 50% of the time
   Damage        - Damage(Defender) = ceiling((100 / (100 + Def(Defender))) * Atk(Attacker))
   Winning       - Make it to the stair on floor 5. Alive.

**********************************************************
* Classes *
**********
                HP  ATK  DEF  MP     Description
s  Shade     ( 125,  25,  25, 20)  - The industry standard. Gets 1.5 the score.

d  Drow      ( 150,  25,  15, 20)  - Meds + Alcohol: 50% amplified potion effects.
                                    EV = 1.5 * (10hp-10hp + 5atk-5atk + 5def-5def) = 1.5 (0hp + 0atk + 0def)
                                    Higher variance: If you're feeling lucky, go for it.

v  Vampire   (  50,  25,  25, 25)  - Blood is a valuable resource. Good thing you can acquire more: +5hp on successful attack.

t  Troll     ( 120,  25,  15, 10)  - Kill enemies. Run circles. Win game. Simple as that. +5hp per turn.

g  Goblin    ( 110,  15,  20, 15)  - Kill the weak, run from the strong. Selling dead corpses since 1980. +5 gold from kills
                                    "But I only had 2 gold..." ~Dwarf's last words~

k  Valkyrie  (  50,   5, 200, 50)  - Wow this armor is heavy: -20% dodge change. My attack sucks, I need more MP: +3MP on basic attack. +1MP upon being hit.
                                    I'm a Valkyrie after all: Starts out with Divine Strike and Heal.

a  Assassin  (  20,  20,  10, 20)  - Tankiness is relative: Dodge Change 90%. Assassins are Skilled: Attacks twice.
                                    We live on the edge: Lethal attacks when above 1 hp leave you at 1 hp.
                                    "I keep getting 3 shot..."

b  Berserker (  80,  30,  15, 10)  - Losing blood makes you see red. Duh: +1Atk per hp lost
                                    Slaying enemies pleases you: +5hp on kill.

x  God       (  1 ,  0 ,-101,  0)  - My name is Nomair Naeem: My power is limitless.
                                    Customized skills and death messages.

