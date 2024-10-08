/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2017 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::fishAgentCloud

Description
    A Cloud of solid particles

SourceFiles
    fishAgentCloudI.H
    fishAgentCloud.C
    fishAgentCloudIO.C

\*---------------------------------------------------------------------------*/

#ifndef fishAgentCloud_H
#define fishAgentCloud_H

#include "Cloud.H"
#include "fishAgent.H"
#include "IOdictionary.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of classes
class fvMesh;

/*---------------------------------------------------------------------------*\
                           Class fishAgentCloud Declaration
\*---------------------------------------------------------------------------*/

class fishAgentCloud
:
    public Cloud<fishAgent>
{
    // Private data

        const fvMesh& mesh_;

        IOdictionary fishProperties_;

        scalar rhop_;
        scalar e_;
        scalar mu_;


    // Private Member Functions

        //- No copy construct
        fishAgentCloud(const fishAgentCloud&) = delete;

        //- No copy assignment
        void operator=(const fishAgentCloud&) = delete;


public:

    // Constructors

        //- Construct given mesh
        fishAgentCloud
        (
            const fvMesh&,
            const word& cloudName = "defaultCloud",
            bool readFields = true
        );


    // Member Functions

        // Access

            inline const fvMesh& mesh() const;

            inline scalar rhop() const;
            inline scalar e() const;
            inline scalar mu() const;


        // Edit

            //- Move the particles under the influence of the given
            //  gravitational acceleration
            void move(const dimensionedVector& g);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "fishAgentCloudI.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
