#pragma once
namespace Form
{
	typedef struct Coordinate{
		LONG x;
		LONG y;
	} Coordinate;

    template <class... ARGS>
    class ControlDelegate
    {
    public:
        typedef typename std::vector<std::function<void(ARGS...)>>::iterator iterator;

        void operator()(const ARGS... args)
        {
            for (auto& func : functions)
            {
                func(args...);
            }
        }

        ControlDelegate& operator+=(std::function<void(ARGS...)> const& func)
        {
            functions.push_back(func);
            return *this;
        }

        ControlDelegate& operator-=(std::function<void(ARGS...)> const& func)
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


	class ControlBase
	{
	private:
		
	public:
		ControlBase();

		ControlDelegate<const EventArgs> Click;
		ControlDelegate<const EventArgs> Hover;
		ControlDelegate<const EventArgs> MouseDown;
		ControlDelegate<const EventArgs> MouseUp;
		ControlDelegate<const EventArgs> MouseMove;

		Coordinate Posistion;
		bool Enabled;
		bool Visible;
	};

	class Control : public ControlBase
	{
	};
}