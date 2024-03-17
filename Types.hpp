#pragma once

namespace Types
{

    template <typename T, typename U>
    struct Plus
    {
    private:
        static T t;
        static U u;
        static typeof(t + u) v;

    public:
        typedef typeof(v) V;
    };

    template <typename T, typename U>
    struct Minus
    {
    private:
        static T t;
        static U u;
        static typeof(t - u) v;

    public:
        typedef typeof(v) V;
    };

    template <typename T, typename U>
    struct Multiply
    {
    private:
        static T t;
        static U u;
        static typeof(t * u) v;

    public:
        typedef typeof(v) V;
    };

    template <typename T, typename U>
    struct Division
    {
    private:
        static T t;
        static U u;
        static typeof(t / u) v;

    public:
        using V = typeof(v);
        // typedef typeof(v) V;
    };
}
