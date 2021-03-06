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
 * Portions created by the Initial Developer are Copyright (C) 2001, 2002
 * Caravel Software. All Rights Reserved.
 *
 * Contributor(s):
 *
 * ***** END LICENSE BLOCK ***** */

//OptionList.h
//Declarations for COptionList.
//Class for parsing command line options into more accessible form.

#ifndef OPTIONLIST_H
#define OPTIONLIST_H

#include <BackEndLib/Types.h>
#include <BackEndLib/Wchar.h>

#if defined WIN32
#	define HAS_UNICODE
#elif defined __sgi
#	undef HAS_UNICODE
#elif defined __APPLE__
# 	undef HAS_UNICODE
#elif defined __linux__
#	undef HAS_UNICODE
#else
#error Platform unknown!  Does this platform support Unicode?
#endif

const UINT MAXLEN_OPTION = 3;
const UINT MAXLEN_ATTRIBUTES = 80;
typedef struct tagOptionNode OPTIONNODE;
typedef struct tagOptionNode
{
	WCHAR szOption[MAXLEN_OPTION + 1];
	WCHAR szAttributes[MAXLEN_ATTRIBUTES + 1];
	OPTIONNODE *pNext;
} OPTIONNODE;

//******************************************************************************
class COptionList
{
public:
	COptionList() 
	{
		this->Sentry.pNext = NULL; 
		this->pLast = &(this->Sentry);
		this->wSize = 0;
	}
	~COptionList() {Clear();}

	bool			Add(const WCHAR *pszOption, const WCHAR *pszAttributes = wszEmpty);
	bool			AreOptionsValid(const WCHAR *pszCompareOptions) const;
	void			Clear();
	bool			Exists(const WCHAR *pszOption) const;
	OPTIONNODE *	Get(const WCHAR *pszOption) const;
	DWORD			GetSize() const {return this->wSize;}
	bool			Set(int argc, WCHAR* argv[]);

private:
	UINT			wSize;
	OPTIONNODE		Sentry;
	OPTIONNODE *	pLast;
};

#endif //...#ifndef OPTIONLIST_H

// $Log: OptionList.h,v $
// Revision 1.9  2003/07/24 18:01:33  mrimer
// Linux port fixes (committed on behalf of Gerry JJ).
//
// Revision 1.8  2003/05/25 22:54:59  erikh2000
// Fixed some includes.
//
// Revision 1.7  2003/05/22 23:42:15  mrimer
// Modified to use new BackEndLib.
//
// Revision 1.6  2003/05/19 21:14:33  mrimer
// Some code maintenance.
//
// Revision 1.5  2003/04/21 21:57:35  mrimer
// Added Unicode support.
//
// Revision 1.4  2002/07/05 17:46:05  mrimer
// Revised #includes.
//
// Revision 1.3  2002/05/15 13:09:25  mrimer
// Added log macro to end of file.
//
