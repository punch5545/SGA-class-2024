#pragma once
namespace Form
{
    typedef struct Coordinate {
        LONG x;
        LONG y;
        LONG width;
        LONG height;
    } Coordinate;

    template <class... ARGS>
    class CtrlDelegate
    {
    public:
        typedef typename std::list<std::function<void(ARGS...)>>::iterator iterator;

        void operator()(const ARGS... args)
        {
            for (auto& func : functions)
            {
                func(args...);
            }
        }

        CtrlDelegate& operator+=(std::function<void(ARGS...)> const& func)
        {
            functions.push_back(func);
            return *this;
        }

        CtrlDelegate& operator-=(std::function<void(ARGS...)> const& func)
        {
            void (* const* func_ptr)(ARGS...) = func.template target<void (*)(ARGS...)>();
            const std::size_t func_hash = func.target_type().hash_code();

            if (nullptr == func_ptr)
            {
                for (auto itr = functions.begin(); itr != functions.end(); itr++)
                {
                    if (func_hash == (*itr).target_type().hash_code())
                    {
                        functions.erase(itr);
                        return *this;
                    }
                }
            }
            else
            {
                for (auto itr = functions.begin(); itr != functions.end(); itr++)
                {
                    void (* const* delegate_ptr)(ARGS...) = (*itr).template target<void (*)(ARGS...)>();
                    if (nullptr != delegate_ptr && *func_ptr == *delegate_ptr)
                    {
                        functions.erase(itr);
                        return *this;
                    }
                }
            }
            return *this;
        }

        iterator begin() noexcept
        {
            return functions.begin();
        }
        iterator end() noexcept
        {
            return functions.end();
        }
        void clear()
        {
            functions.clear();
        }

    private:
        std::list<std::function<void(ARGS...)>> functions;
    };

    class MainForm
    {
    public:
        static MainForm* mainFrm;
        MainForm();
        MainForm(HWND mainHandle);
        ~MainForm();

        bool SetHandle(HWND handle);
        HWND GetHandle();

    private:
        HWND mainHandle;
    };

    class Control
    {
    public:
        //virtual void Draw(HDC hdc) = 0;

        Control();

        LPCWSTR Text;
        LPCWSTR ClassName;

        Coordinate Position;
        bool Enabled;
        bool Visible;

        virtual HWND GetHandle();

    protected:
        Control(LPCWSTR ClassName, LPCWSTR Text, Coordinate position, bool enabled, bool visible);
        HWND mHandle;


        CtrlDelegate<> Click;
        CtrlDelegate<> Hover;
        CtrlDelegate<> MouseDown;
        CtrlDelegate<> MouseUp;
        CtrlDelegate<> MouseMove;

    };
}