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

\*---------------------------------------------------------------------------*/

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

inline Foam::fishAgent::trackingData::trackingData
(
    const fishAgentCloud& spc,
    const interpolationCellPoint<scalar>& rhoInterp,
    const interpolationCellPoint<vector>& UInterp,
    const interpolationCellPoint<scalar>& nuInterp,
    const vector& g
)
:
    particle::trackingData(spc),
    rhoInterp_(rhoInterp),
    UInterp_(UInterp),
    nuInterp_(nuInterp),
    g_(g)
{}


inline Foam::fishAgent::fishAgent
(
    const polyMesh& mesh,
    const barycentric& coordinates,
    const label celli,
    const label tetFacei,
    const label tetPti,
    const scalar d,
    const vector& U
)
:
    particle(mesh, coordinates, celli, tetFacei, tetPti),
    d_(d),
    U_(U)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

inline const Foam::interpolationCellPoint<Foam::scalar>&
Foam::fishAgent::trackingData::rhoInterp() const
{
    return rhoInterp_;
}


inline const Foam::interpolationCellPoint<Foam::vector>&
Foam::fishAgent::trackingData::UInterp() const
{
    return UInterp_;
}


inline const Foam::interpolationCellPoint<Foam::scalar>&
Foam::fishAgent::trackingData::nuInterp() const
{
    return nuInterp_;
}

inline const Foam::vector& Foam::fishAgent::trackingData::g() const
{
    return g_;
}


inline Foam::scalar Foam::fishAgent::d() const
{
    return d_;
}


inline const Foam::vector& Foam::fishAgent::U() const
{
    return U_;
}


// ************************************************************************* //
