# WADDownloader
QT Application to download custom WAD files from idgames/database

# WAD Definition (from https://doomwiki.org/wiki/WAD)

WAD (which, according to the Doom Bible, is an acronym for "Where's All the Data?"[1]) is the file format used by Doom and all Doom-engine-based games for storing data. A WAD file consists of a header, a directory, and the data lumps that make up the resources stored within the file. 

A WAD file can be of two types:

IWAD: An "Internal WAD" (or "Initial WAD"), or a core WAD that is loaded automatically (or from a game select menu on source ports) by the engine and generally provides all the data required to run the game.

PWAD: A "Patch WAD", or an optional file that replaces data from the IWAD loaded or provides additional data to the engine.

Uses the idGames API created by Matt Tropiano found here.
https://legacy.doomworld.com/idgames//api/
