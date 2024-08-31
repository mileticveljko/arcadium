#ifndef EVENT_H__
#define EVENT_H__

namespace ar
{
    enum class EventType {
        Unknown = 0,
        WindowClose
    };

    class Event {
    public:
        virtual const EventType GetEventType() const = 0;
        virtual bool IsHandled() const = 0;
        virtual void SetHandled() = 0;
    };
   
    class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() :
            m_Type(EventType::WindowClose),
            m_Handled(false) {}

        virtual inline const EventType GetEventType() const override
        {
            return m_Type;
        }

        virtual inline bool IsHandled() const override
        {
            return m_Handled;
        }

        virtual inline void SetHandled() override
        {
            m_Handled = true;
        }
        
    private:
        const EventType m_Type;
        bool m_Handled;
    };
}

#endif