/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

//[Headers]
#include "Common.h"
//[/Headers]

%%includeFilesCPP%%
//[MiscUserDefs]
//[/MiscUserDefs]

%%className%%::%%className%%(%%constructorParams%%)
%%initialisers%%{
    %%constructor%%
    //[Constructor]
    //[/Constructor]
}

%%className%%::~%%className%%()
{
    //[Destructor_pre]
    //[/Destructor_pre]

    %%destructor%%
    //[Destructor]
    //[/Destructor]
}

%%methodDefinitions%%
//[MiscUserCode]
//[/MiscUserCode]

#if 0
/*
BEGIN_JUCER_METADATA

%%metadata%%
END_JUCER_METADATA
*/
#endif

%%staticMemberDefinitions%%
