/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Deadly Rooms of Death.
 *
 * The Initial Developer of the Original Code is
 * Caravel Software.
 * Portions created by the Initial Developer are Copyright (C) 1995, 1996, 
 * 1997, 2000, 2001, 2002 Caravel Software. All Rights Reserved.
 *
 * Contributor(s): Mike Rimer (mrimer)
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef WINSCREEN_H
#define WINSCREEN_H

#include "DrodScreen.h"
#include <FrontEndLib/ScrollingTextWidget.h>
#include "../DRODLib/CurrentGame.h"
#include "../DRODLib/DbDemos.h"
#include <BackEndLib/Types.h>

//Things to wait for before continuing to next command.
enum WINWAITTYPE
{
	WW_Nothing = 0,
	WW_ScrollText,
	WW_DemoEnd,
	WW_ScrollTextAndDemoEnd
};

//
//Room info structs.  Each one holds info generated by runtime analysis that is 
//used to control demos and other scripted elements.
//

typedef struct tagRoom103Info
{
	DWORD		dwDemoID;
	CDemoScene	FirstStepToOrbHit;
	CDemoScene	OrbHitToWait;
	CDemoScene	QueenDeathToEnd;
} ROOM103INFO;

typedef struct tagRoom109Info
{
	DWORD		dwDemoID;
	CDemoScene	FirstStep;
	CDemoScene	FirstStepToOrbHit;
	CDemoScene	OrbHitToSerpentAlmostDead;
	CDemoScene	SerpentAlmostDeadToEnd;
} ROOM109INFO;

typedef struct tagRoom165Info
{
	DWORD		dwDemoID;
	CDemoScene	Discovery;
} ROOM165INFO;

typedef struct tagRoom241Info
{
	DWORD		dwDemoID;
	CDemoScene	FirstStep;
	CDemoScene	Northwest;
	UINT		wNorthwestSequenceNo;
	CDemoScene	Northeast;
	UINT		wNortheastSequenceNo;
	CDemoScene	Southwest;
	UINT		wSouthwestSequenceNo;
	CDemoScene	Southeast;
	UINT		wSoutheastSequenceNo;
	UINT		wEnterDirection;
} ROOM241INFO;

typedef struct tagRoom344Info
{
	DWORD		dwDemoID;
	CDemoScene	Scene;
} ROOM344INFO;

typedef struct tagRoom341Info
{
	DWORD		dwDemoID;
	CDemoScene	Scene;
} ROOM341INFO;

typedef struct tagRoom340Info
{
	DWORD		dwDemoID;
	CDemoScene	Scene;
} ROOM340INFO;

typedef struct tagRoom339Info
{
	DWORD		dwDemoID;
	CDemoScene	Scene;
} ROOM339INFO;

typedef struct tagRoom342Info
{
	DWORD		dwDemoID;
	CDemoScene	Scene;
} ROOM342INFO;

typedef struct tagRoom345Info
{
	DWORD		dwDemoID;
	CDemoScene	Scene;
} ROOM345INFO;

typedef struct tagRoom348Info
{
	DWORD		dwDemoID;
	CDemoScene	Scene;
} ROOM348INFO;

typedef struct tagRoom349Info
{
	DWORD		dwDemoID;
	CDemoScene	Scene;
} ROOM349INFO;

typedef struct tagRoom350Info
{
	DWORD		dwDemoID;
	CDemoScene	Scene;
} ROOM350INFO;

typedef struct tagRoom347Info
{
	DWORD		dwDemoID;
	CDemoScene	Scene;
} ROOM347INFO;

typedef struct tagRoom346Info
{
	DWORD		dwDemoID;
	CDemoScene	Scene;
} ROOM346INFO;

typedef struct tagRoom343Info
{
	DWORD		dwDemoID;
	CDemoScene	FirstStepToBeforeDeath;
	CDemoScene	NeatherDies;
	CDemoScene	AfterDeath;
} ROOM343INFO;

//Script command enum.
enum SCRIPTCOMMAND
{
	SC_Intro = 0,
	SC_Level1,
	SC_Level1b,
	SC_Level2,
	SC_Level2b,
	SC_Level2c,
	SC_Level3,
	SC_Level3b,
	SC_Level4,
	SC_Level4b,
	SC_Level5,
	SC_Level5b,
	SC_Level6,
	SC_Level6b,
	SC_Level7,
	SC_Level7b,
	SC_Level7c,
	SC_Level7d,
	SC_Level7e,
	SC_Level7f,
	SC_Level7g,
	SC_Level8,
	SC_Level10,
	SC_Level11,
	SC_HalphQuestionA,
	SC_HalphQuestionB,
	SC_HalphQuestionC,
	SC_Level12,
	SC_Level12b,
	SC_Level13,
	SC_Level14,
	SC_Level15,
	SC_Level16,
	SC_Level16b,
	SC_Level16c,
	SC_Level16d,
	SC_Level16e,
	SC_Level16f,
	SC_Level16g,
	SC_Level17,
	SC_Level18,
	SC_Level18b,
	SC_Level19,
	SC_Level20,
	SC_Level20b,
	SC_Level20c,
	SC_Level20d,
	SC_Level20e,
	SC_Level21,
	SC_Level22,
	SC_Level23,
	SC_Level24,
	SC_Level25,
	SC_Level25b,
	SC_Level25c,
	SC_Level25d,
	SC_Level25e,
	SC_Level25f,
	SC_Level25g,
	SC_Level25h,
	SC_Level25i,
	SC_Level25j,
	SC_Level25k,
	SC_Level25l,
	SC_Level25m,
	SC_Level25n,
	SC_NeatherSpeech,
	SC_NeatherSpeechB,
	SC_NeatherSpeechC,
	SC_NeatherSpeechD,
	SC_TheEnd,
	SC_TheEndB,
	SC_TheDoor,
	SC_TheDoorB,
	SC_TheDoorC,
	SC_TheDoorD,
	SC_TheDoorE,
	SC_TheDoorF,
	SC_TheDoorG,
	SC_TheDoorH,
	SC_TheDoorI,
	SC_TheDoorJ,
	
	SC_EndOfScript,	//Always keep this between script commands and error commands below.

	SC_Error = 1000,
	SC_ErrorB,
	SC_ErrorC
};

class CWinScreen : public CDrodScreen
{
protected:
	friend class CScreenManager;

	CWinScreen(const SCREENTYPE eScreen);
	virtual ~CWinScreen();

	virtual bool   SetForActivate();

	virtual void   OnKeyDown(const DWORD dwTagNo, const SDL_KeyboardEvent &Key);
	virtual void   OnMouseDown(const DWORD dwTagNo, const SDL_MouseButtonEvent &Button);
	virtual void   OnBetweenEvents();
	virtual bool   OnQuit();

	void			DoBeethroTalking(const bool bFlag);
	virtual void	DrawBeethroTalking()=0;	//mouth moves, waves, eyes wander
	virtual void	DrawBeethroSilent()=0;	//mouth not moving, not waving, eyes fixed
	bool			IsBeethroTalking() const {return this->bBeethroTalking;}
	void			PaintBackground();
	void			PauseAnimation();
	void			UnpauseAnimation();
		
	CScrollingTextWidget *	pScrollingText;
	SDL_Surface *			pWinSurface;

	static CCurrentGame *	pCurrentGame;
	static UINT				wDemoEndTurnNo;

	static float			fScrollRateMultiplier;
	static UINT				wNormalScrollRate;

private:
	virtual void			Animate() {if (IsBeethroTalking()) DrawBeethroTalking();}
	void					DoNextCommand();
	DWORD					FindHighlightDemoForRoom(const DWORD dwRoomID) const;
	CCurrentGame *			GetHighlightGame(const DWORD dwRoomID);
	bool					GetLevel25RoomInfo(const DWORD dwRoomID, DWORD &dwDemoID,
			CDemoScene &Scene);
	bool					HasPlayerVisitedRoom(const DWORD dwRoomID) const;
	bool					InitRoom103Info();
	bool					InitRoom109Info();
	bool					InitRoom165Info();
	bool					InitRoom241Info();
	bool					InitRoom339Info() {return GetLevel25RoomInfo(339L, this->Room339Info.dwDemoID, this->Room339Info.Scene);}
	bool					InitRoom340Info() {return GetLevel25RoomInfo(340L, this->Room340Info.dwDemoID, this->Room340Info.Scene);}
	bool					InitRoom341Info() {return GetLevel25RoomInfo(341L, this->Room341Info.dwDemoID, this->Room341Info.Scene);}
	bool					InitRoom342Info() {return GetLevel25RoomInfo(342L, this->Room342Info.dwDemoID, this->Room342Info.Scene);}
	bool					InitRoom343Info();
	bool					InitRoom344Info();
	bool					InitRoom345Info() {return GetLevel25RoomInfo(345L, this->Room345Info.dwDemoID, this->Room345Info.Scene);}
	bool					InitRoom346Info() {return GetLevel25RoomInfo(346L, this->Room346Info.dwDemoID, this->Room346Info.Scene);}
	bool					InitRoom347Info() {return GetLevel25RoomInfo(347L, this->Room347Info.dwDemoID, this->Room347Info.Scene);}
	bool					InitRoom348Info() {return GetLevel25RoomInfo(348L, this->Room348Info.dwDemoID, this->Room348Info.Scene);}
	bool					InitRoom349Info() {return GetLevel25RoomInfo(349L, this->Room349Info.dwDemoID, this->Room349Info.Scene);}
	bool					InitRoom350Info() {return GetLevel25RoomInfo(350L, this->Room350Info.dwDemoID, this->Room350Info.Scene);}
	void					ResetScript() {this->eCommand=SC_Intro;}
	bool					ShowDemoScene(const DWORD dwDemoID, CDemoScene &Scene);
	bool					ShowDemoSceneForRoom(const DWORD dwRoomID, 
			const DWORD dwMaxTime=0L);
	bool					ShowRoomStart(const DWORD dwRoomID);
	void					ShowPic(const char *pszPicName, 
			const int nScrollTextX = -1, const int nScrollTextY = -1,
			const UINT wScrollTextW = 0, const UINT wScrollTextH = 0);

	ROOM103INFO				Room103Info;
	ROOM109INFO				Room109Info;
	ROOM165INFO				Room165Info;
	ROOM241INFO				Room241Info;
	ROOM339INFO				Room339Info;
	ROOM340INFO				Room340Info;
	ROOM341INFO				Room341Info;
	ROOM342INFO				Room342Info;
	ROOM343INFO				Room343Info;
	ROOM344INFO				Room344Info;
	ROOM345INFO				Room345Info;
	ROOM346INFO				Room346Info;
	ROOM347INFO				Room347Info;
	ROOM348INFO				Room348Info;
	ROOM349INFO				Room349Info;
	ROOM350INFO				Room350Info;

	static WINWAITTYPE		eNextCommandWaitFor;
	static SCRIPTCOMMAND	eCommand;
	static bool				bBeethroTalking;
};

#endif //...#ifndef WINSCREEN_H

// $Log: WinScreen.h,v $
// Revision 1.19  2003/07/17 01:54:38  mrimer
// Fixed bug: trying to dynamic_cast classes with inaccessable base class: Made inheritance public. (Committed on behalf of Gerry JJ.)
//
// Revision 1.18  2003/07/12 20:32:03  mrimer
// Made virtual widget methods explicit virtual.
// Updated widget load/unload methods.
//
// Revision 1.17  2003/05/23 21:43:03  mrimer
// Changed #includes for files in BackEndLib and FrontEndLib (from "file.h" to <file.h>).
//
// Revision 1.16  2003/05/22 23:35:35  mrimer
// Modified to use the new FrontEndLib and BackEndLib.
//
// Revision 1.15  2003/05/18 20:03:21  erikh2000
// Replaced "friend x" with "friend class x".
//
// Revision 1.14  2003/04/06 03:54:01  schik
// Ported to SGI.
// All filenames in CFiles and elsewhere are now in Unicode if the platform supports it.
//
// Revision 1.13  2002/10/21 20:18:50  mrimer
// Added OnMouseDown(), PauseAnimation(), UnpauseAnimation().
// Made GetHighlightGame() and GetLevel25RoomInfo() not const.
//
// Revision 1.12  2002/10/09 00:57:48  erikh2000
// Finished script command logic.  Dialogue remains to be finished.
//
// Revision 1.11  2002/10/04 17:53:41  mrimer
// Added pause and speed control to this screen.
// Added mouse cursor display logic.
//
// Revision 1.10  2002/10/01 22:57:49  erikh2000
// Added a lot more script commands.
// Wrote a method to encapsulate some of the common code for getting a highlight room demo's current game.
// Wrote a method to show a picture on the new SCR_WinPic screen.
//
// Revision 1.9  2002/09/06 20:13:00  erikh2000
// Added more commands to script.
// Wrote method to show start of room.
//
// Revision 1.8  2002/09/05 18:28:18  erikh2000
// Added method to determine if player has visited a room.
// Scroll text wait criteria now waits for all text to be shown, instead of all text to scroll off the widget.
// Added more of the script to DoNextCommand().
//
// Revision 1.7  2002/09/04 22:33:03  erikh2000
// Added code for playing demos.
//
// Revision 1.6  2002/09/04 21:47:56  mrimer
// Moved Animate() code into base win screen class.
//
// Revision 1.5  2002/09/03 21:43:33  erikh2000
// Got the first part of the script working--Beethro talks, audience talks, text scrolls, the screen switches from audience to room view, a room is shown in the room widget.
//
// Revision 1.4  2002/07/29 17:14:17  mrimer
// Added SetForActivate().
//
// Revision 1.3  2002/07/11 20:57:08  mrimer
// Implemented base class animation/event handling.
//
// Revision 1.2  2002/04/09 10:05:42  erikh2000
// Fixed revision log macro.
//
