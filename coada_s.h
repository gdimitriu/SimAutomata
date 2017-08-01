// coada_s.h: interface for the coada_s class.
//
//////////////////////////////////////////////////////////////////////
/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of Modelare Client-Server.
	
    Modelare Client-Server is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Modelare Client-Server is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Modelare Client-Server; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/
#if !defined(AFX_COADA_S_H__B5D93D37_07FA_483A_B32E_7D1D1DDAAF9A__INCLUDED_)
#define AFX_COADA_S_H__B5D93D37_07FA_483A_B32E_7D1D1DDAAF9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class coada_s  
{
public:
	coada_s *next;
	coada_s();
	virtual ~coada_s();
};

#endif // !defined(AFX_COADA_S_H__B5D93D37_07FA_483A_B32E_7D1D1DDAAF9A__INCLUDED_)
