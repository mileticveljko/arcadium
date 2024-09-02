#ifndef TIMESTAMP_H__
#define TIMESTAMP_H__

namespace ar
{
    class Timestamp
    {
    public:
        Timestamp();
        ~Timestamp();

        const double GetDeltaTime() const;
        void CalculateDeltaTime();

    private:
        double m_DeltaTime;
        double m_LastTime;
    };
}

#endif