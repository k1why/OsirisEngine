#pragma once

namespace osiris::utils::ctti
{
    template <typename T>
    static int GetClassUID()
    {
        static int magic{0};
        return magic++;
    }
}