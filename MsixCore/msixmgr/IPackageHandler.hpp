#pragma once
#include "Package.hpp"
#include "MsixRequest.hpp"

namespace MsixCoreLib
{
    /// Interface for a logical chunk of work done on an Msix request
    class IPackageHandler
    {
    public:

        // Add request adds the package as per-machine. Everything is written to per-machine shared locations.
        virtual HRESULT ExecuteForAddRequest() = 0; 

        // Removes packages added by ExecuteForAddRequest. 
        virtual HRESULT ExecuteForRemoveRequest() { return S_OK; }

        virtual ~IPackageHandler() {};
    };

    /// Function responsible for creating an instance of an IPackageHandler object
    /// @param msixRequest - the msix request object to act upon
    /// @return S_OK if CreateHandler is to not fail the deployment of the package.
    typedef HRESULT(*CreateHandler)(_In_ MsixRequest* msixRequest, _Out_ IPackageHandler** instance);
}