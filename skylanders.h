#ifndef SKYLANDERS_H
#define SKYLANDERS_H
#include <map>
#include <cstdint>
#include <string>

// This is where figurines are stored
// Format (please keep alignment consistent for readibilty):
//  {"Name",                                            {ID, Variant(Hex)}},

std::map<std::string, std::pair<uint16_t, uint16_t>> skylanderMap = {
    {"Whirlwind",                                       {0, 0x0000}},
    {"Series 2 Whirlwind",                              {0, 0x1801}},
    {"Polar Whirlwind",                                 {0, 0x1C02}},
    {"Horn Blast Whirlwind",                            {0, 0x2805}},
    {"Eon's Elite Whirlwind",                           {0, 0x3810}},
    {"Sonic Boom",                                      {1, 0x0000}},
    {"Series 2 Sonic Boom",                             {1, 0x1801}},
    {"Warnado",                                         {2, 0x0000}},
    {"LightCore Warnado",                               {2, 0x2206}},
    {"Lightning Rod",                                   {3, 0x0000}},
    {"Series 2 Lightning Rod",                          {3, 0x1801}},
    {"Bash",                                            {4, 0x0000}},
    {"Series 2 Bash",                                   {4, 0x1801}},
    {"Terrafin",                                        {5, 0x0000}},
    {"Series 2 Terrafin",                               {5, 0x1801}},
    {"Knockout Terrafin",                               {5, 0x2805}},
    {"Eon's Elite Terrafin",                            {5, 0x3810}},
    {"Dino Rang",                                       {6, 0x0000}},
    {"Eon's Elite Dino Rang",                           {6, 0x4810}},
    {"Prism Break",                                     {7, 0x0000}},
    {"Series 2 Prism Break",                            {7, 0x1801}},
    {"Hyper Beam Prism Break",                          {7, 0x2805}},
    {"LightCore Prism Break",                           {7, 0x1206}},
    {"Sunburn",                                         {8, 0x0000}},
    {"Eruptor",                                         {9, 0x0000}},
    {"Series 2 Eruptor",                                {9, 0x1801}},
    {"Volcanic Eruptor",                                {9, 0x2C02}},
    {"Lava Barf Eruptor",                               {9, 0x2805}},
    {"LightCore Eruptor",                               {9, 0x1206}},
    {"Eon's Elite Eruptor",                             {9, 0x3810}},
    {"Ignitor",                                         {10, 0x0000}},
    {"Series 2 Ignitor",                                {10, 0x1801}},
    {"Legendary Ignitor",                               {10, 0x1C03}},
    {"Flameslinger",                                    {11, 0x0000}},
    {"Series 2 Flameslinger",                           {11, 0x1801}},
    {"Zap",                                             {12, 0x0000}},
    {"Series 2 Zap",                                    {12, 0x1801}},
    {"Wham Shell",                                      {13, 0x0000}},
    {"LightCore Wham Shell",                            {13, 0x2206}},
    {"Gill Grunt",                                      {14, 0x0000}},
    {"Series 2 Gill Grunt",                             {14, 0x1801}},
    {"Anchors Away Gill Grunt",                         {14, 0x2805}},
    {"Tidal Wave Gill Grunt",                           {14, 0x3805}},
    {"Eon's Elite Gill Grunt",                          {14, 0x3810}},
    {"Slam Bam",                                        {15, 0x0000}},
    {"Series 2 Slam Bam",                               {15, 0x1801}},
    {"Legendary Slam Bam",                              {15, 0x1C03}},
    {"Eon's Elite Slam Bam",                            {15, 0x4810}},
    {"Spyro",                                           {16, 0x0000}},
    {"Series 2 Spyro",                                  {16, 0x1801}},
    {"Dark Mega Ram Spyro",                             {16, 0x2C02}},
    {"Mega Ram Spyro",                                  {16, 0x2805}},
    {"Eon's Elite Spyro",                               {16, 0x3810}},
    {"Voodood",                                         {17, 0x0000}},
    {"Eon's Elite Voodood",                             {17, 0x4810}},
    {"Double Trouble",                                  {18, 0x0000}},
    {"Series 2 Double Trouble",                         {18, 0x1801}},
    {"Royal Double Trouble",                            {18, 0x1C02}},
    {"Trigger Happy",                                   {19, 0x0000}},
    {"Series 2 Trigger Happy",                          {19, 0x1801}},
    {"Springtime Trigger Happy",                        {19, 0x2C02}},
    {"Big Bang Trigger Happy",                          {19, 0x2805}},
    {"Eon's Elite Trigger Happy",                       {19, 0x3810}},
    {"Drobot",                                          {20, 0x0000}},
    {"Series 2 Drobot",                                 {20, 0x1801}},
    {"LightCore Drobot",                                {20, 0x1206}},
    {"Drill Seargeant",                                 {21, 0x0000}},
    {"Series 2 Drill Seargeant",                        {21, 0x1801}},
    {"Boomer",                                          {22, 0x0000}},
    {"Eon's Elite Boomer",                              {22, 0x4810}},
    {"Wrecking Ball",                                   {23, 0x0000}},
    {"Series 2 Wrecking Ball",                          {23, 0x1801}},
    {"Camo",                                            {24, 0x0000}},
    {"Thorn Horn Camo",                                 {24, 0x2805}},
    {"Zook",                                            {25, 0x0000}},
    {"Series 2 Zook",                                   {25, 0x1801}},
    {"Eon's Elite Zook",                                {25, 0x4810}},
    {"Stealth Elf",                                     {26, 0x0000}},
    {"Series 2 Stealth Elf",                            {26, 0x1801}},
    {"Dark Stealth Elf",                                {26, 0x2C02}},
    {"Legendary Stealth Elf",                           {26, 0x1C03}},
    {"Ninja Stealth Elf",                               {26, 0x2805}},
    {"Eon's Elite Stealth Elf",                         {26, 0x3810}},
    {"Stump Smash",                                     {27, 0x0000}},
    {"Series 2 Stump Smash",                            {27, 0x1801}},
    {"Dark Spyro",                                      {28, 0x0000}},
    {"Hex",                                             {29, 0x0000}},
    {"Series 2 Hex",                                    {29, 0x1801}},
    {"LightCore Hex",                                   {29, 0x1206}},
    {"Chop Chop",                                       {30, 0x0000}},
    {"Series 2 Chop Chop",                              {30, 0x1801}},
    {"Twin Blade Chop Chop",                            {30, 0x2805}},
    {"Eon's Elite Chop Chop",                           {30, 0x3810}},
    {"Ghost Roaster",                                   {31, 0x0000}},
    {"Eon's Elite Ghost Roaster",                       {31, 0x4810}},
    {"Cynder",                                          {32, 0x0000}},
    {"Series 2 Cynder",                                 {32, 0x1801}},
    {"Phantom Cynder",                                  {32, 0x2805}},
    {"Jet Vac",                                         {100, 0x0000}},
    {"Legendary Jet Vac",                               {100, 0x1403}},
    {"Turbo Jet Vac",                                   {100, 0x2805}},
    {"Full Blast Jet Vac",                              {100, 0x3805}},
    {"LightCore Jet Vac",                               {100, 0x1206}},
    {"Swarm",                                           {101, 0x0000}},
    {"Crusher",                                         {102, 0x0000}},
    {"Granite Crusher",                                 {102, 0x1602}},
    {"Flashwing",                                       {103, 0x0000}},
    {"Jade Flashwing",                                  {103, 0x1402}},
    {"LightCore Flashwing",                             {103, 0x2206}},
    {"Hot Head",                                        {104, 0x0000}},
    {"Hot Dog",                                         {105, 0x0000}},
    {"Molten Hot Dog",                                  {105, 0x1402}},
    {"Fire Bone Hot Dog",                               {105, 0x2805}},
    {"Chill",                                           {106, 0x0000}},
    {"Legendary Chill",                                 {106, 0x1603}},
    {"Blizzard Chill",                                  {106, 0x2805}},
    {"LightCore Chill",                                 {106, 0x1206}},
    {"Thumpback",                                       {107, 0x0000}},
    {"Pop Fizz",                                        {108, 0x0000}},
    {"Punch Pop Fizz",                                  {108, 0x1402}},
    {"Love Potion Pop Fizz",                            {108, 0x3C02}},
    {"Super Gulp Pop Fizz",                             {108, 0x2805}},
    {"Fizzy Frenzy Pop Fizz",                           {108, 0x3805}},
    {"LightCore Pop Fizz",                              {108, 0x1206}},
    {"Ninjini",                                         {109, 0x0000}},
    {"Scarlet Ninjini",                                 {109, 0x1602}},
    {"Bouncer",                                         {110, 0x0000}},
    {"Legendary Bouncer",                               {110, 0x1603}},
    {"Sprocket",                                        {111, 0x0000}},
    {"Heavy Duty Sprocket",                             {111, 0x2805}},
    {"Tree Rex",                                        {112, 0x0000}},
    {"Gnarly Tree Rex",                                 {112, 0x1602}},
    {"Shroomboom",                                      {113, 0x0000}},
    {"Sure Shot Shroomboom",                            {113, 0x3805}},
    {"LightCore Shroomboom",                            {113, 0x1206}},
    {"Eye Brawl",                                       {114, 0x0000}},
    {"Fright Rider",                                    {115, 0x0000}},
    {"Anvil Rain",                                      {200, 0x0000}},
    {"Hidden Treasure",                                 {201, 0x0000}},
    {"Platinum Hidden Treasure",                        {201, 0x2000}},
    {"Healing Elixir",                                  {202, 0x0000}},
    {"Ghost Pirate Swords",                             {203, 0x0000}},
    {"Time Twist Hourglass",                            {204, 0x0000}},
    {"Sky Iron Shield",                                 {205, 0x0000}},
    {"Winged Boots",                                    {206, 0x0000}},
    {"Sparx the Dragonfly",                             {207, 0x0000}},
    {"Dragonfire Cannon",                               {208, 0x0000}},
    {"Golden Dragonfire Cannon",                        {208, 0x1602}},
    {"Scorpion Striker",                                {209, 0x0000}},
    // Traps start here
    {"Biter's Bane",                                    {210, 0x3002}},
    {"Sorcerous Skull",                                 {210, 0x3008}},
    {"Axe of Illusion",                                 {210, 0x300B}},
    {"Arcane Hourglass",                                {210, 0x300E}},
    {"Spell Slapper",                                   {210, 0x3012}},
    {"Rune Rocket",                                     {210, 0x3014}},
    {"Tidal Tiki",                                      {211, 0x3001}},
    {"Wet Walter",                                      {211, 0x3002}},
    {"Flood Flask",                                     {211, 0x3006}},
    {"Legendary Flood Flask",                           {211, 0x3406}},
    {"Soaking Staff",                                   {211, 0x3007}},
    {"Aqua Axe",                                        {211, 0x300B}},
    {"Frost Helm",                                      {211, 0x3016}},
    {"Breezy Bird",                                     {212, 0x3003}},
    {"Drafty Decanter",                                 {212, 0x3006}},
    {"Tempest Timer",                                   {212, 0x300D}},
    {"Cloudy Cobra",                                    {212, 0x3010}},
    {"Storm Warning",                                   {212, 0x3011}},
    {"Cyclone Saber",                                   {212, 0x3018}},
    {"Spirit Sphere",                                   {213, 0x3004}},
    {"Legendary Spirit Sphere",                         {213, 0x3404}},
    {"Spectral Skull",                                  {213, 0x3008}},
    {"Legendary Spectral Skull",                        {213, 0x3408}},
    {"Haunted Hatchet",                                 {213, 0x300B}},
    {"Grim Gripper",                                    {213, 0x300C}},
    {"Spooky Snake",                                    {213, 0x3010}},
    {"Dream Piercer",                                   {213, 0x3017}},
    {"Tech Totem",                                      {214, 0x3000}},
    {"Automatic Angel",                                 {214, 0x3007}},
    {"Factory Flower",                                  {214, 0x3009}},
    {"Grabbing Gadget",                                 {214, 0x300C}},
    {"Makers Mana",                                     {214, 0x3016}},
    {"Topsy Techy",                                     {214, 0x301A}},
    {"Eternal Flame",                                   {215, 0x3005}},
    {"Fire Flower",                                     {215, 0x3009}},
    {"Scorching Stopper",                               {215, 0x3011}},
    {"Searing Spinner",                                 {215, 0x3012}},
    {"Spark Spear",                                     {215, 0x3017}},
    {"Blazing Belch",                                   {215, 0x301B}},
    {"Banded Boulder",                                  {216, 0x3000}},
    {"Rock Hawk",                                       {216, 0x3003}},
    {"Slag Hammer",                                     {216, 0x300A}},
    {"Dust Of Time",                                    {216, 0x300E}},
    {"Spinning Sandstorm",                              {216, 0x3013}},
    {"Rubble Trouble",                                  {216, 0x301A}},
    {"Oak Eagle",                                       {217, 0x3003}},
    {"Emerald Energy",                                  {217, 0x3005}},
    {"Weed Whacker",                                    {217, 0x300A}},
    {"Seed Serpent",                                    {217, 0x3010}},
    {"Jade Blade",                                      {217, 0x3018}},
    {"Shrub Shrieker",                                  {217, 0x301B}},
    {"Dark Dagger",                                     {218, 0x3000}},
    {"Shadow Spider",                                   {218, 0x3014}},
    {"Ghastly Grimace",                                 {218, 0x301A}},
    {"Shining Ship",                                    {219, 0x3000}},
    {"Heavenly Hawk",                                   {219, 0x300F}},
    {"Beam Scream",                                     {219, 0x301B}},
    {"Kaos Trap",                                       {220, 0x301E}},
    {"Ultimate Kaos Trap",                              {220, 0x351F}},
    // Traps end here
    {"Hand of Fate",                                    {230, 0x0000}},
    {"Legendary Hand of Fate",                          {230, 0x3403}},
    {"Piggy Bank",                                      {231, 0x0000}},
    {"Rocket Ram",                                      {232, 0x0000}},
    {"Tiki Speaky",                                     {233, 0x0000}},
    {"Dragon’s Peak",                                   {300, 0x0000}},
    {"Empire of Ice",                                   {301, 0x0000}},
    {"Pirate Seas",                                     {302, 0x0000}},
    {"Darklight Crypt",                                 {303, 0x0000}},
    {"Volcanic Vault",                                  {304, 0x0000}},
    {"Mirror of Mystery",                               {305, 0x0000}},
    {"Nightmare Express",                               {306, 0x0000}},
    {"Sunscraper Spire",                                {307, 0x0000}},
    {"Midnight Museum",                                 {308, 0x0000}},
    {"Legendary Bash",                                  {404, 0x0000}},
    {"Legendary Spyro",                                 {416, 0x0000}},
    {"Legendary Trigger Happy",                         {419, 0x0000}},
    {"Legendary Chop Chop",                             {430, 0x0000}},
    {"Gusto",                                           {450, 0x0000}},
    {"Thunderbolt",                                     {451, 0x0000}},
    {"Fling Kong",                                      {452, 0x0000}},
    {"Blades",                                          {453, 0x0000}},
    {"Legendary Blades",                                {453, 0x3403}},
    {"Wallop",                                          {454, 0x0000}},
    {"Head Rush",                                       {455, 0x0000}},
    {"Nitro Head Rush",                                 {455, 0x3402}},
    {"Fist Bump",                                       {456, 0x0000}},
    {"Rocky Roll",                                      {457, 0x0000}},
    {"Wildfire",                                        {458, 0x0000}},
    {"Dark Wildfire",                                   {458, 0x3402}},
    {"Ka Boom",                                         {459, 0x0000}},
    {"Trail Blazer",                                    {460, 0x0000}},
    {"Torch",                                           {461, 0x0000}},
    {"Snap Shot",                                       {462, 0x0000}},
    {"Dark Snap Shot",                                  {462, 0x3402}},
    {"Lob Star",                                        {463, 0x0000}},
    {"Winterfest Lob-Star",                             {463, 0x3402}},
    {"Flip Wreck",                                      {464, 0x0000}},
    {"Echo",                                            {465, 0x0000}},
    {"Blastermind",                                     {466, 0x0000}},
    {"Enigma",                                          {467, 0x0000}},
    {"Deja Vu",                                         {468, 0x0000}},
    {"Legendary Deja Vu",                               {468, 0x3403}},
    {"Cobra Candabra",                                  {469, 0x0000}},
    {"King Cobra Cadabra",                              {469, 0x3402}},
    {"Jawbreaker",                                      {470, 0x0000}},
    {"Legendary Jawbreaker",                            {470, 0x3403}},
    {"Gearshift",                                       {471, 0x0000}},
    {"Chopper",                                         {472, 0x0000}},
    {"Tread Head",                                      {473, 0x0000}},
    {"Bushwack",                                        {474, 0x0000}},
    {"Legendary Bushwack",                              {474, 0x3403}},
    {"Tuff Luck",                                       {475, 0x0000}},
    {"Food Fight",                                      {476, 0x0000}},
    {"Dark Food Fight",                                 {476, 0x3402}},
    {"High Five",                                       {477, 0x0000}},
    {"Krypt King",                                      {478, 0x0000}},
    {"Nitro Krypt King",                                {478, 0x3402}},
    {"Short Cut",                                       {479, 0x0000}},
    {"Bat Spin",                                        {480, 0x0000}},
    {"Funny Bone",                                      {481, 0x0000}},
    {"Knight Light",                                    {482, 0x0000}},
    {"Spotlight",                                       {483, 0x0000}},
    {"Knight Mare",                                     {484, 0x0000}},
    {"Blackout",                                        {485, 0x0000}},
    {"Bop",                                             {502, 0x0000}},
    {"Terrabite",                                       {505, 0x0000}},
    {"Breeze",                                          {506, 0x0000}},
    {"Pet Vac",                                         {508, 0x0000}},
    {"Power Punch Pet Vac",                             {508, 0x3402}},
    {"Weeruptor",                                       {507, 0x0000}},
    {"Eggcellent Weeruptor",                            {507, 0x3402}},
    {"Small Fry",                                       {509, 0x0000}},
    {"Drobit",                                          {510, 0x0000}},
    {"Trigger Snappy",                                  {519, 0x0000}},
    {"Whisper Elf",                                     {526, 0x0000}},
    {"Barkley",                                         {540, 0x0000}},
    {"Gnarly Barkley",                                  {540, 0x3402}},
    {"Thumpling",                                       {541, 0x0000}},
    {"Gill Runt",                                       {514, 0x0000}},
    {"Mini-Jini",                                       {542, 0x0000}},
    {"Spry",                                            {503, 0x0000}},
    {"Hijinx",                                          {504, 0x0000}},
    {"Eye Small",                                       {543, 0x0000}},
    {"Boom Jet (Bottom)",                               {1000, 0x0000}},
    {"Free Ranger (Bottom)",                            {1001, 0x0000}},
    {"Legendary Free Ranger (Bottom)",                  {1001, 0x2403}},
    {"Rubble Rouser (Bottom)",                          {1002, 0x0000}},
    {"Doom Stone (Bottom)",                             {1003, 0x0000}},
    {"Blast Zone (Bottom)",                             {1004, 0x0000}},
    {"Dark Blast Zone (Bottom)",                        {1004, 0x2402}},
    {"Fire Kraken (Bottom)",                            {1005, 0x0000}},
    {"Jade Fire Kraken (Bottom)",                       {1005, 0x2402}},
    {"Stink Bomb (Bottom)",                             {1006, 0x0000}},
    {"Grilla Drilla (Bottom)",                          {1007, 0x0000}},
    {"Hoot Loop (Bottom)",                              {1008, 0x0000}},
    {"Enchanted Hoot Loop (Bottom)",                    {1008, 0x2402}},
    {"Trap Shadow (Bottom)",                            {1009, 0x0000}},
    {"Magna Charge (Bottom)",                           {1010, 0x0000}},
    {"Nitro Magna Charge (Bottom)",                     {1010, 0x2402}},
    {"Spy Rise (Bottom)",                               {1011, 0x0000}},
    {"Night Shift (Bottom)",                            {1012, 0x0000}},
    {"Legendary Night Shift (Bottom)",                  {1012, 0x2403}},
    {"Rattle Shake (Bottom)",                           {1013, 0x0000}},
    {"Quick Draw Rattle Shake (Bottom)",                {1013, 0x2402}},
    {"Freeze Blade (Bottom)",                           {1014, 0x0000}},
    {"Nitro Freeze Blade (Bottom)",                     {1014, 0x2402}},
    {"Wash Buckler (Bottom)",                           {1015, 0x0000}},
    {"Dark Wash Buckler (Bottom)",                      {1015, 0x2402}},
    {"Boom Jet (Top)",                                  {2000, 0x0000}},
    {"Free Ranger (Top)",                               {2001, 0x0000}},
    {"Legendary Free Ranger (Top)",                     {2001, 0x2403}},
    {"Rubble Rouser (Top)",                             {2002, 0x0000}},
    {"Doom Stone (Top)",                                {2003, 0x0000}},
    {"Blast Zone (Top)",                                {2004, 0x0000}},
    {"Dark Blast Zone (Top)",                           {2004, 0x2402}},
    {"Fire Kraken (Top)",                               {2005, 0x0000}},
    {"Jade Fire Kraken (Top)",                          {2005, 0x2402}},
    {"Stink Bomb (Top)",                                {2006, 0x0000}},
    {"Grilla Drilla (Top)",                             {2007, 0x0000}},
    {"Hoot Loop (Top)",                                 {2008, 0x0000}},
    {"Enchanted Hoot Loop (Top)",                       {2008, 0x2402}},
    {"Trap Shadow (Top)",                               {2009, 0x0000}},
    {"Magna Charge (Top)",                              {2010, 0x0000}},
    {"Nitro Magna Charge (Top)",                        {2010, 0x2402}},
    {"Spy Rise (Top)",                                  {2011, 0x0000}},
    {"Night Shift (Top)",                               {2012, 0x0000}},
    {"Legendary Night Shift (Top)",                     {2012, 0x2403}},
    {"Rattle Shake (Top)",                              {2013, 0x0000}},
    {"Quick Draw Rattle Shake (Top)",                   {2013, 0x2402}},
    {"Freeze Blade (Top)",                              {2014, 0x0000}},
    {"Nitro Freeze Blade (Top)",                        {2014, 0x2402}},
    {"Wash Buckler (Top)",                              {2015, 0x0000}},
    {"Dark Wash Buckler (Top)",                         {2015, 0x2402}},
    {"Scratch",                                         {3000, 0x0000}},
    {"Pop Thorn",                                       {3001, 0x0000}},
    {"Slobber Tooth",                                   {3002, 0x0000}},
    {"Dark Slobber Tooth",                              {3002, 0x2402}},
    {"Scorp",                                           {3003, 0x0000}},
    {"Fryno",                                           {3004, 0x0000}},
    {"Hog Wild Fryno",                                  {3004, 0x3805}},
    {"Smolderdash",                                     {3005, 0x0000}},
    {"LightCore Smolderdash",                           {3005, 0x2206}},
    {"Bumble Blast",                                    {3006, 0x0000}},
    {"Jolly Bumble Blast",                              {3006, 0x2402}},
    {"LightCore Bumble Blast",                          {3006, 0x2206}},
    {"Zoo Lou",                                         {3007, 0x0000}},
    {"Legendary Zoo Lou",                               {3007, 0x2403}},
    {"Dune Bug",                                        {3008, 0x0000}},
    {"Star Strike",                                     {3009, 0x0000}},
    {"Enchanted Star Strike",                           {3009, 0x2602}},
    {"LightCore Star Strike",                           {3009, 0x2206}},
    {"Countdown",                                       {3010, 0x0000}},
    {"Kickoff Countdown",                               {3010, 0x2402}},
    {"LightCore Countdown",                             {3010, 0x2206}},
    {"Wind Up",                                         {3011, 0x0000}},
    {"Roller Brawl",                                    {3012, 0x0000}},
    {"Grim Creeper",                                    {3013, 0x0000}},
    {"Legendary Grim Creeper",                          {3013, 0x2603}},
    {"LightCore Grim Creeper",                          {3013, 0x2206}},
    {"Rip Tide",                                        {3014, 0x0000}},
    {"Punk Shock",                                      {3015, 0x0000}},
    {"Battle Hammer",                                   {3200, 0x0000}},
    {"Sky Diamond",                                     {3201, 0x0000}},
    {"Platinum Sheep",                                  {3202, 0x0000}},
    {"Groove Machine",                                  {3203, 0x0000}},
    {"UFO Hat",                                         {3204, 0x0000}},
    {"Sheep Wreck Island",                              {3300, 0x0000}},
    {"Tower of Time",                                   {3301, 0x0000}},
    {"Fiery Forge",                                     {3302, 0x0000}},
    {"Arkeyan Crossbow",                                {3303, 0x0000}},
    {"Jet Stream",                                      {3220, 0x0000}},
    {"Tomb Buggy",                                      {3221, 0x0000}},
    {"Reef Ripper",                                     {3222, 0x0000}},
    {"Burn Cycle",                                      {3223, 0x0000}},
    {"Hot Streak",                                      {3224, 0x0000}},
    {"Dark Hot Streak",                                 {3224, 0x4402}},
    {"E3 Hot Streak",                                   {3224, 0x4004}},
    {"Golden Hot Streak",                               {3224, 0x441E}},
    {"Shark Tank",                                      {3225, 0x0000}},
    {"Thump Truck",                                     {3226, 0x0000}},
    {"Crypt Crusher",                                   {3227, 0x0000}},
    {"Stealth Stinger",                                 {3228, 0x0000}},
    {"Nitro Stealth Stinger",                           {3228, 0x4402}},
    {"Dive Bomber",                                     {3231, 0x0000}},
    {"Spring Ahead Dive Bomber",                        {3231, 0x4402}},
    {"Sky Slicer",                                      {3232, 0x0000}},
    {"Clown Cruiser",                                   {3233, 0x0000}},
    {"Dark Clown Cruiser",                              {3233, 0x4402}},
    {"Gold Rusher",                                     {3234, 0x0000}},
    {"Power Blue Gold Rusher",                          {3234, 0x4402}},
    {"Shield Striker",                                  {3235, 0x0000}},
    {"Sun Runner",                                      {3236, 0x0000}},
    {"Legendary Sun Runner",                            {3236, 0x4403}},
    {"Sea Shadow",                                      {3237, 0x0000}},
    {"Dark Sea Shadow",                                 {3237, 0x4402}},
    {"Splatter Splasher",                               {3238, 0x0000}},
    {"Power Blue Splatter Splasher",                    {3238, 0x4402}},
    {"Soda Skimmer",                                    {3239, 0x0000}},
    {"Nitro Soda Skimmer",                              {3239, 0x4402}},
    {"Barrel Blaster",                                  {3240, 0x0000}},
    {"Dark Barrel Blaster",                             {3240, 0x4402}},
    {"Buzz Wing",                                       {3241, 0x0000}},
    {"Fiesta",                                          {3400, 0x0000}},
    {"Frightful Fiesta",                                {3400, 0x4515}},
    {"High Volt",                                       {3401, 0x0000}},
    {"Splat",                                           {3402, 0x0000}},
    {"Power Blue Splat",                                {3402, 0x4502}},
    {"Stormblade",                                      {3406, 0x0000}},
    {"Smash Hit",                                       {3411, 0x0000}},
    {"Steel Plated Smash Hit",                          {3411, 0x4502}},
    {"Spitfire",                                        {3412, 0x0000}},
    {"Dark Spitfire",                                   {3412, 0x4502}},
    {"Hurricane Jet Vac",                               {3413, 0x0000}},
    {"Legendary Hurricane Jet Vac",                     {3413, 0x4503}},
    {"Double Dare Trigger Happy",                       {3414, 0x0000}},
    {"Power Blue Double Dare Trigger Happy",            {3414, 0x4502}},
    {"Super Shot Stealth Elf",                          {3415, 0x0000}},
    {"Dark Super Shot Stealth Elf",                     {3415, 0x4502}},
    {"Shark Shooter Terrafin",                          {3416, 0x0000}},
    {"Bone Bash Roller Brawl",                          {3417, 0x0000}},
    {"Legendary Bone Bash Roller Brawl",                {3417, 0x4503}},
    {"Big Bubble Pop Fizz",                             {3420, 0x0000}},
    {"Birthday Bash Big Bubble Pop Fizz",               {3420, 0x450E}},
    {"Lava Lance Eruptor",                              {3421, 0x0000}},
    {"Deep Dive Gill Grunt",                            {3422, 0x0000}},
    {"Turbo Charge Donkey Kong",                        {3423, 0x0000}},
    {"Dark Turbo Charge Donkey Kong",                   {3423, 0x4502}},
    {"Hammer Slam Bowser",                              {3424, 0x0000}},
    {"Dark Hammer Slam Bowser",                         {3424, 0x4502}},
    {"Dive-Clops",                                      {3425, 0x0000}},
    {"Missile-Tow Dive-Clops",                          {3425, 0x450E}},
    {"Astroblast",                                      {3426, 0x0000}},
    {"Legendary Astroblast",                            {3426, 0x4503}},
    {"Nightfall",                                       {3427, 0x0000}},
    {"Thrillipede",                                     {3428, 0x0000}},
    {"Eggcited Thrillipede",                            {3428, 0x450D}},
    {"Sky Trophy",                                      {3500, 0x0000}},
    {"Land Trophy",                                     {3501, 0x0000}},
    {"Sea Trophy",                                      {3502, 0x0000}},
    {"Kaos Trophy",                                     {3503, 0x0000}},
    // Special
    {"VVind Up (Gear Head Vicarious Visions Wind Up)",  {3011, 0x2404}},
    // Debug
    {"Debug Minion",                                    {999, 0x0000}},
    {"Template Template (Bottom)",                      {1999, 0x0000}},
    {"Template Template (Top)",                         {2999, 0x0000}},
    {"Template Legacy",                                 {3999, 0x0000}},
    {"Template Vehicle (???)",                          {4999, 0x0000}},
    {"Template Land Vehicle",                           {5999, 0x0000}},
    {"Template Sky Vehicle",                            {6999, 0x0000}},
    {"Template Sea Vehicle",                            {7999, 0x0000}},
    {"Instant Spitfire",                                {3412, 0x450F}},
    {"Instant Super Shot Stealth Elf",                  {3415, 0x450F}},
    {"Instant Dive-Clops",                              {3425, 0x450F}},
    {"Instant Hot Streak",                              {3224, 0x450F}},
    {"Instant Dive Bomber",                             {3231, 0x450F}},
    {"Instant Stealth Stinger",                         {3228, 0x450F}},
    {"Instant Sky Slicer",                              {3232, 0x450F}},
    {"Instant Sea Shadow",                              {3237, 0x450F}},
    {"Virtual Snap Shot",                               {462, 0x450F}},
    {"Virtual Food Fight",                              {476, 0x450F}},
    {"Fushion (Scrapped; Superchargers)",               {4500, 0x0000}},
    {"Synergy (Scrapped; Superchargers)",               {4501, 0x0000}},
    {"Unity (Scrapped; Superchargers)",                 {4502, 0x0000}},
    // Scrapped
    {"Series 4 Cynder (Scrapped; Trap Team)",           {32, 0x3805}},
    {"Series 2 Flashwing (Scrapped; Trap Team)",        {103, 0x3805}},
    {"BlueFalcon_Base (Scrapped; Superchargers)",       {4503, 0x0000}},

    /** Alternative Names **/

    {"Magic Log Holder Trap",                           {210, 0x3002}},
    {"Magic Skull Trap",                                {210, 0x3008}},
    {"Magic Axe Trap",                                  {210, 0x300B}},
    {"Magic Hourglass Trap",                            {210, 0x300E}},
    {"Magic Totem Trap",                                {210, 0x3012}},
    {"Magic Rocket Trap",                               {210, 0x3014}},
    {"Water Tiki Trap",                                 {211, 0x3001}},
    {"Water Log Holder Trap",                           {211, 0x3002}},
    {"Water Jughead Trap",                              {211, 0x3006}},
    {"Legendary Water Jughead Trap",                    {211, 0x3406}},
    {"Water Angel Trap",                                {211, 0x3007}},
    {"Water Axe Trap",                                  {211, 0x300B}},
    {"Water Flying Helmet Trap",                        {211, 0x3016}},
    {"Air Toucan Trap",                                 {212, 0x3003}},
    {"Air Jughead Trap",                                {212, 0x3006}},
    {"Air Hourglass Trap",                              {212, 0x300D}},
    {"Air Snake Trap",                                  {212, 0x3010}},
    {"Air Screamer Trap",                               {212, 0x3011}},
    {"Air Sword Trap",                                  {212, 0x3018}},
    {"Undead Orb Trap",                                 {213, 0x3004}},
    {"Legendary Undead Orb Trap",                       {213, 0x3404}},
    {"Undead Skull Trap",                               {213, 0x3008}},
    {"Legendary Undead Skull Trap",                     {213, 0x3408}},
    {"Undead Axe Trap",                                 {213, 0x300B}},
    {"Undead Hand Trap",                                {213, 0x300C}},
    {"Undead Snake Trap",                               {213, 0x3010}},
    {"Undead Captain's Hat Trap",                       {213, 0x3017}},
    {"Tech Tiki Trap",                                  {214, 0x3000}},
    {"Tech Angel Trap",                                 {214, 0x3007}},
    {"Tech Scepter Trap",                               {214, 0x3009}},
    {"Tech Hand Trap",                                  {214, 0x300C}},
    {"Tech Flying Helmet Trap",                         {214, 0x3016}},
    {"Tech Handstand Trap",                             {214, 0x301A}},
    {"Fire Torch Trap",                                 {215, 0x3005}},
    {"Fire Scepter Trap",                               {215, 0x3009}},
    {"Fire Screamer Trap",                              {215, 0x3011}},
    {"Fire Totem Trap",                                 {215, 0x3012}},
    {"Fire Captain's Hat Trap",                         {215, 0x3017}},
    {"Fire Yawn Trap",                                  {215, 0x301B}},
    {"Earth Orb Trap",                                  {216, 0x3000}},
    {"Earth Toucan Trap",                               {216, 0x3003}},
    {"Earth Hammer Trap",                               {216, 0x300A}},
    {"Earth Hourglass Trap",                            {216, 0x300E}},
    {"Earth Totem Trap",                                {216, 0x3013}},
    {"Earth Handstand Trap",                            {216, 0x3000}},
    {"Life Toucan Trap",                                {217, 0x3003}},
    {"Life Torch Trap",                                 {217, 0x3005}},
    {"Life Hammer Trap",                                {217, 0x300A}},
    {"Life Snake Trap",                                 {217, 0x3010}},
    {"Life Sword Trap",                                 {217, 0x3018}},
    {"Life Yawn Trap",                                  {217, 0x3003}},
    {"Dark Sword Trap",                                 {218, 0x3000}},
    {"Dark Spider Trap",                                {218, 0x3014}},
    {"Dark Handstand Trap",                             {218, 0x3000}},
    {"Light Rocket Trap",                               {219, 0x3000}},
    {"Light Hawk Trap",                                 {219, 0x300F}},
    {"Light Yawn Trap",                                 {219, 0x301B}},
};

    /**
        Credits to:
            u/mariussa1 (Reddit)
            Tritonex (Youtube) 
        ...for making public easily accessible dumps of imaginators figures
    **/

std::map<std::string, std::pair<uint16_t, uint16_t>> imaginatorsMap = { 
    {"Pit Boss",                                        {605, 0x5000}},
    {"Grave Clobber",                                   {623, 0x5000}},
    {"Dr. Krankcase",                                   {610, 0x5000}},
    {"Hood Sickle",                                     {611, 0x5000}},
    {"Tae Kwon Crow",                                   {612, 0x5000}},
    {"Golden Queen",                                    {613, 0x5000}},
    {"Wolfgang",                                        {614, 0x5000}},
    {"Pain-Yatta",                                      {615, 0x5000}},
    {"Mysticat",                                        {616, 0x5000}},
    {"Starcast",                                        {617, 0x5000}},
    {"Buckshot",                                        {618, 0x5000}},
    {"Aurora",                                          {619, 0x5000}},
    {"Flare Wolf",                                      {620, 0x5000}},
    {"Chompy Mage",                                     {621, 0x5000}},
    {"Bad Juju",                                        {622, 0x5000}},
    {"Blaster-Tron",                                    {624, 0x5000}},
    {"Ro-Bow",                                          {625, 0x5000}},
    {"Chain Reaction",                                  {626, 0x5000}},
    {"Kaos",                                            {627, 0x5000}},
    {"Wild Storm",                                      {628, 0x5000}},
    {"King Pen",                                        {601, 0x5000}},
    {"Tri-Tip",                                         {602, 0x5000}},
    {"Chopscotch",                                      {603, 0x5000}},
    {"Boom Bloom",                                      {604, 0x5000}},
    {"Barbella",                                        {606, 0x5000}},
    {"Air Strike",                                      {607, 0x5000}},
    {"Ember",                                           {608, 0x5000}},
    {"Ambush",                                          {609, 0x5000}},
    {"Tidepool",                                        {629, 0x5000}},
    {"Crash Bandicoot",                                 {630, 0x5000}},
    {"Dr. Neo Cortex",                                  {631, 0x5000}},
    
    // Special variants
    {"Dark King Pen",                                   {601, 0x5402}},
    {"Dark Wolfgang",                                   {614, 0x5402}},
    {"Legendary Pit Boss",                              {605, 0x5403}},
    {"Candy-Coated Chopscotch",                         {603, 0x5415}},
    {"Solar Flare Aurora",                              {619, 0x5402}},
    {"Jingle-Bell Chompy Mage",                         {621, 0x540E}},
    {"Mystical Tae Kwon Crow",                          {612, 0x5402}},
    {"Hard-Boiled Flare Wolf",                          {620, 0x540D}},
    {"Legendary Tri-Tip",                               {602, 0xE40B}},
    {"Dark Golden Queen",                               {613, 0x5402}},
    {"Steel-Plated Hood Sickle",                        {611, 0x5402}},
    {"Mystcial Bad Juju",                               {622, 0x5402}},
    {"Egg-Bomber Air Strike",                           {607, 0x540D}},

    // Level packs
    {"Enchanted Elven Forest",                          {311, 0x5000}},
    {"Gryphon Park Observatory",                        {310, 0x5000}},

    /*
    IDs from 680 to 689 are reserved for Creation Crystals.
    This may be useful later on
    */
    {"Magic Creation Crystal",                          {680, 0x521B}},
    {"Water Creation Crystal",                          {681, 0x5214}},
    {"Air Creation Crystal",                            {682, 0x5207}},
    {"Undead Creation Crystal",                         {683, 0x5217}},
    {"Tech Creation Crystal",                           {684, 0x5215}},
    {"Fire Creation Crystal",                           {685, 0x520F}},
    {"Earth Creation Crystal",                          {686, 0x521D}},
    {"Life Creation Crystal",                           {687, 0x5210}},
    {"Dark Creation Crystal",                           {688, 0x5206}},
    {"Light Creation Crystal",                          {689, 0x520B}},
};


/** 
 * This whole thing can be removed once Imaginators figures get fully figured out...
 * Until then, this will be the compromise.
 * **/
std::map<std::string, std::tuple<   
                                uint32_t,                           // NUID
                                std::pair<uint64_t, uint64_t>,      // 0x20
                                std::pair<uint64_t, uint64_t>,      // 0x40
                                std::pair<uint64_t, uint64_t>,      // 0x220
                                std::pair<uint64_t, uint64_t>,      // 0x3E0
                                std::pair<uint8_t, uint8_t>         // Magic Numbers (Addr 0x9, 0xF)
                                >> BFIM = {
        
    {"Pit Boss",
        {   
            0xDFA3FEA1,
            {0x26F725519497F74B, 0x12900EF0EF027775},
            {0x0617A2FFA4A3DC99, 0x83B1F45E6274CBF3},
            {0xD9176B2277879286, 0xD26E301AF061273D},
            {0x0E31BF6DB810DA2D, 0xB506346D100A3506},
            {0x37, 0x15}
        }
    },

    {"Grave Clobber",
        {   
            0x3F4277BA,
            {0x01C9017A392341B4, 0xD28279542F25452E},
            {0xF817C14ECA4941ED, 0x5AC57BD7BB3AA8AA},
            {0xFF1740581D11CAFE, 0xE346E42C76EE719A},
            {0x64669F3F97C2DC35, 0xA108379CAE6F1508},
            {0x30, 0x16}
        }
    },

    {"Dr. Krankase",
        {   
            0xBF7727A1,
            {0xA2512B484827CEE5, 0xC4FF10E75CE01C6A},
            {0x2295949A365FB94C, 0x72EEFDB8CC01595C},
            {0x487A663A272D1D0A, 0x818BDB4C52138B76},
            {0x3E65C1FB30465C8A, 0x4951772DA8BED307},
            {0x37, 0x15}
        }
    },
    
    {"Hood Sickle",
        {   
            0x3F4A92A2,
            {0x17493B10CE438AAA, 0x6C553ADC5C7DE4F3},
            {0x2D64F27196BAC61D, 0x0D869F0F9641181B},
            {0x00F238B59932BA04, 0x03EF7B5DAE64FF8A},
            {0x3F5FD7556A4355EB, 0xB6B323348A7B4100},
            {0x37, 0x15}
        }
    },
    
    {"Tae Kwon Crow",
        {   
            0xBFE601A0,
            {0x7104756E0CA861BD, 0x1AE60C372A1639F2},
            {0xC82E38C96387CC8B, 0x7351D5E6621BE4FD},
            {0x25B572217C65B27D, 0x515FC364D12C8E2A},
            {0x1A88673A03197606, 0xEA37DCA1694B8C0A},
            {0x37, 0x15}
        }
    },
    
    {"Golden Queen",
        {   
            0xDFFBF399,
            {0x9EB698AE36F62462, 0xA5340A03A251921F},
            {0xC7DADC73A63BA65C, 0x90AF92C0CAD955E0},
            {0x469D9E06503824D8, 0x76195C218C037A17},
            {0xFB5144F3C9D80878, 0x73DD619D02D90504},
            {0x25, 0x15}
        }
    },
    
    {"Wolfgang",
        {   
            0x7FC83BAC,
            {0xAB29AE42949B86C6, 0x80C43E9B95858943},
            {0xBD52A794C2133612, 0xD46AC9FBEA2B0ED9},
            {0x2E978B3EEC647F61, 0xD88A031F9BC20A00},
            {0x622301D9EFFE51BE, 0x04B412BF7CB3DE08},
            {0x40, 0x15}
        }
    },
    
    {"Pain-Yatta",
        {   
            0xBF60529F,
            {0x39DAA6FEC2DEADC9, 0x24862A3B74D8DBE4},
            {0x7F62A0E5078A24DA, 0x882A9D16BE2D13A8},
            {0x582BEACE2B8AE323, 0x0FC35F799314A2D8},
            {0x66736E602966CE8C, 0x77FABA0C9C6B9E01},
            {0x37, 0x15}
        }
    },
    
    {"Mysticat",
        {   
            0x9F2EF898,
            {0x50C83B1E9EC1942C, 0x4635C78D1FA51AD6},
            {0x705100D744511B98, 0xB96699BC4D16CCD0},
            {0x5EEC0CF1F44191E9, 0x67723262C91AA40C},
            {0x9C80581E395FEE07, 0x70854C0E1FC9EA0C},
            {0x23, 0x15}
        }
    },
    
    {"Starcast",
        {   
            0x1F353899,
            {0xF23FF0B25774A6E6, 0xD9D08C7851069526},
            {0x40E81F177C6F4CDC, 0xDDA4C71DEDD8DC0F},
            {0x51B164F816D0D2AF, 0xD146060CC86C7578},
            {0x38B2760BD45B10FF, 0xAC8D343D8B54250A},
            {0x23, 0x15}
        }
    },

    {"Buckshot",
        {   
            0xFF79C194,
            {0xFBE4E520E8CA9599, 0x31B95A2F58D11414},
            {0x4C878782792EA46E, 0x0A61581E2E830CE2},
            {0xB2EE86033EE57E71, 0x8460B062051D811F},
            {0x5C5B64D60E197A0C, 0xF5650DAA959DA500},
            {0x23, 0x15}
        }
    },
    
    {"Aurora",
        {   
            0x3FD28CA2,
            {0x0F642AB3CC9FAB1D, 0x9A88FC4E49EC04D8},
            {0x43F8963A33BD238B, 0x9A1355F79164D846},
            {0xC5808858EBBAD4AB, 0x618E85F05CBBAB40},
            {0xE669EA1D182A742E, 0xE1B9CBA248EEB601},
            {0x37, 0x15}
        }
    },
    
    {"Flare Wolf",
        {   
            0xFFFF05A2,
            {0x7B594DDC4F6013BD, 0xE994850570964222},
            {0x20123B7F054E3FCD, 0x44877FAFEDCC0E21},
            {0xF780780BAFD000FA, 0xA6C9151F31FFDC36},
            {0x1E4D59CA52C3AC4A, 0xA4D8E935A01B0E06},
            {0x37, 0x15}
        }
    },
    
    {"Chompy Mage",
        {   
            0x5F469A9F,
            {0x7B43FFDD3CE5DFE5, 0x8315D138CC3895F4},
            {0x24A09D1979233C6B, 0xC8367F1BE24405C5},
            {0x942C996AF9FB35FB, 0x08580F34D9DBED46},
            {0x55E8CE17699265AF, 0x083E564585ACA508},
            {0x37, 0x15}
        }
    },
    
    {"Bad Juju",
        {   
            0xDF1923CC,
            {0x4566CF639B2783F5, 0x90544A7140A3FB81},
            {0x68F4D96E197C2638, 0x3FDCFAC11CB91D78},
            {0x472F2DC061B7B328, 0xEE027C7E495BC0DA},
            {0x5BAFB045CEA0A387, 0x91FC6938280CDF0F},
            {0x31, 0x16}
        }
    },
    
    {"Blaster-Tron",
        {   
            0x3FD74DCC,
            {0x358667FCB4BC60E9, 0x5E17F0579CCE8739},
            {0x6A07D0C9DD3C9824, 0x8F79E6E331FFC50F},
            {0x2093C5835BDE91A4, 0x7D2E52CCCC2CFD5C},
            {0xD6A50654B0446B9E, 0x6606DA81A00FDE01},
            {0x31, 0x16}
        }
    },
    
    {"Ro-Bow",
        {   
            0x5F21DBAD,
            {0xBD2D1CA5AE805663, 0x6D0831EED87AEE00},
            {0xC244DC02D82CF376, 0xA52D77824AB40942},
            {0xD3FB160CFF8568B2, 0x2CA8A52EDADD19BE},
            {0xB657253FACDD27E0, 0xF9B74FD42023BF03},
            {0x22, 0x16}
        }
    },
    
    {"Chain Reaction",
        {   
            0x3F5C09CA,
            {0x5335DCCAAFAC6C2B, 0xF6573DBCCF3302B1},
            {0x4CDD349F17D6E681, 0x86F415C0740DC5FB},
            {0xA2DCFED85D2AE8EB, 0xDB7EF6FB03EABBBF},
            {0xBEA8961B09BA8F75, 0xF80570108F5F6704},
            {0x31, 0x16}
        }
    },
    
    {"Kaos",
        {   
            0xDFEB9C9F,
            {0x183304206D70A43D, 0x3A3E629B631AD5C2},
            {0xEC2B9521C57F344F, 0x8F78BCBA048B6436},
            {0x87B66CA5C318BDAC, 0x4EAC40358B88D0D6},
            {0xB762B84961B8E5EC, 0x0A3AB0791722CF0E},
            {0x37, 0x15}
        }
    },

    {"Wild Storm",
        {   
            0xFF632AAE,
            {0x4A88EA5C4173E0E1, 0xE937836213EBEC34},
            {0x8801BD1446ECFCD6, 0x1D18606723B92A7A},
            {0x8BA757EB6839AE13, 0x4D540D1ACB6AFE84},
            {0x0E2DAD1C40212B8D, 0xA285B05548BD2608},
            {0x22, 0x16}
        }
    },
    
    {"King Pen",
        {   
            0x5FAA6297,
            {0x1AE4182B1952B951, 0xA04866D2A4BFC598},
            {0x0F139F9D9747457B, 0x35CA4C9171DA608E},
            {0x11CD2059C3149938, 0x4BE0E9B1892E8F20},
            {0xD3BEDD172C7E1FBD, 0xFAB5287DC9AB840F},
            {0x23, 0x15}
        }
    },

    {"Tri-Tip",
        {   
            0x5F4CE198,
            {0xD48519CB92DE5BBD, 0x49A158E3C1DCEA37},
            {0xAADD13FBB6A5D028, 0x7C4227AFE4E5E1CF},
            {0x4DE27A44423624E8, 0xB2971B430A0A267F},
            {0x5DC22474D5BFF4CE, 0x223CC962C50BE305},
            {0x23, 0x15}
        }
    },
    
    {"Chopscotch",
        {   
            0xBFB04ECB,
            {0x99389528813DA2D0, 0xC4B73B85B65E2792},
            {0xD7EF5C77F249A25C, 0x720DAF2237053A82},
            {0xF0EFC02FF41C025D, 0xDBA6A47B8B0D7888},
            {0xA899CD9CE6BDB2D8, 0xDE0A0B289C0D6205},
            {0x31, 0x16}
        }
    },
    
    {"Boom Bloom",
        {   
            0x1FEF47B5,
            {0x9B375B17F3FD25CB, 0x2EC89F81A0AD001A},
            {0x35E53ED6AB24FCD4, 0xD08F4B0C9CCF7274},
            {0x3AE2DBFCC2356720, 0x0D1F0F8EFFDAA95A},
            {0xA5A8F799686E3D7A, 0x76333E73005B1A0A},
            {0x23, 0x16}
        }
    },
    
    {"Barbella",
        {   
            0xDFCAF998,
            {0x17B001B79234418E, 0x92C3C017F22FF23D},
            {0xD4F05A9F5B199ADB, 0x81E32517F1E8A7C1},
            {0xC53182866980FCEF, 0x82E0D25A5E27A54B},
            {0x40E27FD5FD3E9609, 0x34E671870A4C7002},
            {0x23, 0x15}
        }
    },
    
    {"Air Strike",
        {   
            0x7FF56A89,
            {0x8CF23F0DA47F3225, 0x74386F4442176E0A},
            {0xD64B98A6255C57CC, 0xB61BCCDF23B36829},
            {0xB1C591F840AFBCF5, 0xAD0B972DD428BB09},
            {0x43E09C7FE1A1807A, 0x31EBA75F28D4CE0F},
            {0x22, 0x15}
        }
    },
    
    {"Ember",
        {   
            0x7FBF9FCB,
            {0x90E61ADE908C4FB2, 0x8DA7009071E8707A},
            {0x532631F91CEC3127, 0x0312CF21D458E145},
            {0xAFCF8732ED2FF451, 0x0CE2923AFF90C50C},
            {0x9EF1910DCD593924, 0x913EEAE50C250101},
            {0x31, 0x16}
        }
    },
    
    {"Ambush",
        {   
            0xFF5E7DA1,
            {0xDFE9B3EA391341DB, 0x4A5B24FF3DD24A85},
            {0xB9D402F739CCD85A, 0x26E83A02846F0C45},
            {0xC357F9CCEA0B9F3F, 0x475C69FF9DC8476C},
            {0x468A0332A430EEBF, 0x4D5891417EF35D01},
            {0x37, 0x15}
        }
    },
    
    {"Tidepool",
        {   
            0xDFE111CC,
            {0x9E7C6678E58F1E5B, 0x73C58F5B7F6CAACA},
            {0x7D0FF986C4BDA36F, 0x67AEF7056839E9C6},
            {0x3C286F3B9179E012, 0x08985148515F8520},
            {0x79B562ED595259A9, 0xA6B6AB77D6BEA805},
            {0x31, 0x16}
        }
    },

    {"Crash Bandicoot",
        {   
            0xDF8DC3A7,
            {0x62238A3A4B7CE311, 0x83A51580CDFCAF04},
            {0x1C380826260BDEFB, 0xCE621316D890412D},
            {0x186488200B99345E, 0x201B10E19E22BF00},
            {0x96D4503D5D430CC3, 0x2E320ADA0AA04E0C},
            {0x40, 0x15}
        }
    },
    
    {"Dr. Neo Cortex",
        {   
            0x3F041591,
            {0x329CD5CA846514EB, 0x0A6F09F713CB5211},
            {0x0542AB329F851423, 0x8C54971E26D2AEDE},
            {0x347BF39BEA6BD3C1, 0xFC0BF9EE38905B07},
            {0x4FEF09952A259BAA, 0x88157E2D1DBE880A},
            {0x22, 0x15}
        }
    },

    // Special variants
    {"Dark King Pen",
        {   
            0xFFF3AAA9,
            {0x75AA4FA34A013D14, 0xABEA89FDDB473C6F},
            {0xADEC31C0E6CFBF4D, 0x23B1763460FACFCC},
            {0x5254A788BD03F130, 0x2A2CE68A99ED942D},
            {0x83C51E38B7AED105, 0xA5D7018278DC5A0A},
            {0x40, 0x15}
        }
    }, 

    {"Dark Wolfgang",
        {   
            0xFF672C9C,
            {0x747DAF6F51ADE825, 0xDDD850F23C5A2388},
            {0xBD66DF49CC7C7E17, 0xF6D5EBCD779975F5},
            {0x42DE771CE4FF8143, 0x1DB026C73812C804},
            {0x2085EDA630FF6DA4, 0x80DE2AED6A2FDC01},
            {0x25, 0x15}
        }
    },

    {"Legendary Pit Boss",
        {   
            0xFF602EB1,
            {0xDF0D5E97F91C8E4C, 0x96C6D7709A6EF5C2},
            {0xF1224BE6CB972DF1, 0xDB3B6F4DB854625B},
            {0xEC6C5E9772FCF45E, 0xB08F00BE945C5A04},
            {0xE5E655A51218771C, 0x40FAA0FFF7118909},
            {0x22, 0x16}
        }
    },

    {"Candy-Coated Chopscotch",
        {   
            0xBF51CE9E,
            {0x2951B8A77A41DDFD, 0x34C238EF6A7AB640},
            {0x710F111FC8FF4254, 0xEB429897D336D6B0},
            {0xD120F607DB3AC88D, 0xDBFC8CCAA6EED529},
            {0x71BA393EDD7AC95A, 0xB4203BCEFAB7D70B},
            {0x37, 0x15}
        }
    },

    {"Solar Flare Aurora",
        {   
            0xDF43AC94,
            {0xE7329C322E5B14A0, 0x954CF11CD5BCD598},
            {0xF828B999509E83B0, 0x5382D573F5429CA8},
            {0x4192D43764F29852, 0x360463A3D63F39EF},
            {0xC1B50E432D6A2288, 0x4818B1FBB3496200},
            {0x23, 0x15}
        }
    },

    {"Jingle-Bell Chompy Mage",
        {   
            0x7F4629B1,
            {0x1D69E58411753BA1, 0xB17C65838114B3EB},
            {0x7F6EBC6CB514BA31, 0x6A36EAC59C70F073},
            {0x2E9230BBBA0F5D93, 0xF7784E8283155C30},
            {0xD529E14E1A92973E, 0xF2AA6D04F87BEE07},
            {0x22, 0x16}
        }
    },

    {"Mystical Tae Kwon Crow",
        {   
            0x7FD0B4A2,
            {0x3C632337E544A5E3, 0x92B8A7967DD2DC0F},
            {0x9B53F61F293A97B5, 0x24D62BA8DAD14252},
            {0xCFF19028E798CB84, 0xF121608214AFCF66},
            {0x5A254369C524E19B, 0xE6BB6B91634EE20B},
            {0x37, 0x15}
        }
    },

    {"Hard-Boiled Flare Wolf",
        {   
            0x9F5EB7BA,
            {0xB55A340C95ED362D, 0xD555FC346C9FF296},
            {0x359872F238BC71A0, 0xBF482FF081FD4234},
            {0xD0927BDB78C41F27, 0x8A7DCB2C7444D0F1},
            {0xB1B5D56924CB36AA, 0x751299B1028A5207},
            {0x30, 0x16}
        }
    },

    {"Legendary Tri-Tip",
        {   
            0xFFAE9988,
            {0x1286C69C1F595E26, 0xFE755FED7FB1E372},
            {0x244C369463CEC504, 0x6587BE5A0BE4F334},
            {0x494AB02242F82952, 0xA41BDC884DDAEE3B},
            {0x8B6620B65F4CC498, 0x60243EB8D696B806},
            {0x22, 0x15}
        }
    },

    {"Dark Golden Queen",
        {   
            0xFF76A1A8,
            {0x86332C2D1459337F, 0xBC255E79A41B28C5},
            {0xECCB379A5A8CB0F0, 0x0BBFBA9A507E7580},
            {0x2BF9432C240B4E00, 0x8CF4CADF856A61E3},
            {0x830350B358C1E3DE, 0x1FED7FB8DE5FE105},
            {0x40, 0x15}
        }
    },

    {"Steel-Plated Hood Sickle",
        {   
            0x7F8CC39E,
            {0x864AE95CB4F7FC5B, 0x7BDD6966FD317F86},
            {0x51A8F5DFC36F3CA2, 0x0C5E3AF2EB17E865},
            {0xCC5578ABB3B4016F, 0x96AB9E1C6C113D58},
            {0x15DF4127834A9954, 0x2D8DB0C0BAF2DB06},
            {0x37, 0x15}
        }
    },

    {"Mystcial Bad Juju",
        {   
            0x3F6BBD9F,
            {0x56870AEEEDFFBEF4, 0x6ACB2E882069AE92},
            {0xECA3ADA1787087E1, 0xB7A86CC591A4698D},
            {0xE569C5A0033A06F7, 0x1C25179CE897296E},
            {0xE48F6A3BBDAB57DA, 0x65BBC0A3E2EE710C},
            {0x37, 0x15}
        }
    },

    {"Egg-Bomber Air Strike",
        {   
            0x3FFE539F,
            {0x9E4F2306E7605EA3, 0x83EFBE608F652DFC},
            {0x61B5ADCDFE5A939F, 0x2D06425D06DD5706},
            {0x04EB304D96B3F054, 0xB213CC5A1CCA8795},
            {0xE7410A71DE737F0B, 0x4E872ED5EFD55A01},
            {0x37, 0x15}
        }
    },

    // Level Packs
    {"Enchanted Elven Forest",
        {   
            0xBF3A0AB5,
            {0xCC7A65D8C3725A20, 0xE9832237BE6D5BD3},
            {0x8A74561E92E7FC02, 0x99F001C829305E06},
            {0xDC798113A88A0312, 0x140F71C043C89B80},
            {0x98320041FDC073D3, 0x8154D48E64EBB206},
            {0x23, 0x16}
        }
    },

    {"Gryphon Park Observatory",
        {   
            0x5F66D59E,
            {0x849D7524DB7AA0F7, 0x5240E5FEF86AB5F9},
            {0x16F0D6F8A6CB74EC, 0x7053DD6A4E7AF65E},
            {0xCEA266537BA8F2CD, 0x93D63BFB60244974},
            {0xCBCBAFCA14D5FAB6, 0x7E77308BDDF24A0B},
            {0x37, 0x15}
        }
    },
    
    // Creation Crystals
    {"Magic Creation Crystal",
        {   
            0x7FD2DBAB,
            {0xBDAF005F53EB9CBD, 0x2FF77A5C89B67BD1},
            {0x58D2FDB63A320F19, 0xD56C42F835545178},
            {0x88762994201007FC, 0xA63425A962554C24},
            {0xFAE4882B703AA8E6, 0x1A615C0B69899509},
            {0x40, 0x15}
        }
    },

    {"Water Creation Crystal",
        {   
            0xDFE00D93,
            {0x1092624DE2F59154, 0xC9982B81BF670780},
            {0x36D0566D245AAA9D, 0x6390D38A2ED8D9B8},
            {0x61C5EA9360C4B44F, 0xF5AC7B1C8BF31FAC},
            {0xE4B6EA6CD35DFBA1, 0x091DB882E9B6720F},
            {0x22, 0x15}
        }
    },
    
    {"Air Creation Crystal",
        {   
            0xDF5B6895,
            {0x63C1D508B98002BC, 0x64762DBFDCC702D6},
            {0xD26E3240568B86F8, 0x675ADF3F9B1F5B44},
            {0x89B69AAB1D7EB35F, 0x40F19533BA942F1D},
            {0x893B1F00F3DE13D0, 0x67553199E80B1B04},
            {0x23, 0x15}
        }
    },
    
    {"Undead Creation Crystal",
        {   
            0x3F8B65A2,
            {0xC34B50ED89086855, 0xDC5FEB904282F732},
            {0x2EC0403E3F06E579, 0xD3B40690F786A249},
            {0xA14212A0B407CD8D, 0x5BA2A6118318DAEE},
            {0x734A96F85D92F2D5, 0x84FE16B6DC13B001},
            {0x37, 0x15}
        }
    },
    
    {"Tech Creation Crystal",
        {   
            0xFF1BEB95,
            {0xE77E1B050CF80D0F, 0xF53394CE40761795},
            {0xBC848CDE04A72904, 0x8CF573462DB2DB45},
            {0x7A83CE3C8DB9E963, 0x8B32AA61C38C59A6},
            {0xA67F812004CCDAF4, 0x11E95AD38F1C6A0E},
            {0x23, 0x15}
        }
    },
    
    {"Fire Creation Crystal",
        {   
            0x7F0F838F,
            {0x29B38192692DD4A2, 0xEDC7021DB82ABD62},
            {0x0DE92755663973BE, 0x747250FB8ECEE9AA},
            {0x7F195CF16FAEE1D7, 0x742589F2877DCF81},
            {0x9BBA0752F2965610, 0x35322F004B9C4004},
            {0x22, 0x15}
        }
    },
    
    {"Earth Creation Crystal",
        {   
            0x1F2C13A6,
            {0xEAE9C0BBA841E90F, 0xA3EA2F119114C51B},
            {0x928E5CC1509E504C, 0xD5638936B5961418},
            {0xBCE406D52F281665, 0x68F6F21D4334425A},
            {0xD842D82B23DBA753, 0xADB8BBFD7712AC0C},
            {0x37, 0x15}
        }
    },
    
    {"Life Creation Crystal",
        {   
            0x7F4FD892,
            {0x54029B4244E811D7, 0xB92F7ED186FBBDAF},
            {0xEB39D2CD1CA09F83, 0x2F6E1F2157DF3C53},
            {0x12F3050B849A988B, 0x8DB7835A93C7D7A4},
            {0x6D1FBFF6EF5CBFD6, 0x50C87A8DD5056006},
            {0x22, 0x15}
        }
    },
    
    {"Dark Creation Crystal",
        {   
            0xBF332C93,
            {0x4A4B4F8321746462, 0x9258A71ACE54E3ED},
            {0x90ECC11529E59A46, 0xE56876264948D0FE},
            {0x2C3416D8D3DC5627, 0x123FAE0865E5375F},
            {0x9FE88F67CDAE2D6D, 0x0EBA4065692B6906},
            {0x22, 0x15}
        }
    },
    
    {"Light Creation Crystal",
        {   
            0x1F29588E,
            {0x2703A79B45685F91, 0x14CE17FEFB2A6FF4},
            {0xF5EAC3AC209531CF, 0xF46237E62461404D},
            {0x1143BE6E1945CE01, 0xB14A16509FA417FE},
            {0x183A033819578A76, 0x036FED4B3CC84700},
            {0x22, 0x15}
        }
    },
};

#endif