#pragma once

namespace idk
{
    struct ivec2;
    struct ivec3;
};


struct idk::ivec2
{
    union { int x, r; };
    union { int y, g; };
};

struct idk::ivec3
{
    union { int x, r; };
    union { int y, g; };
    union { int z, b; };
};

