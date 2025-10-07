#define FORCE_INLINE inline __attribute__((always_inline))

using u32 = uint32_t;
using u64 = uint64_t;

class Solution
{
public:
    template <typename To>
    [[nodiscard]] FORCE_INLINE static constexpr To to(auto v) noexcept
    {
        return static_cast<To>(v);
    }

    [[nodiscard]] static std::vector<int> avoidFlood(
        std::vector<int>& rains) noexcept
    {
        std::unordered_map<int, u32> full_lakes;
        std::deque<u32> dry_days;

        for (u32 i = 0; i != rains.size(); ++i)
        {
            int lake = rains[i];
            if (lake)
            {
                rains[i] = -1;
                auto [it, added] = full_lakes.try_emplace(lake, i);
                if (!added)
                {
                    // need to dry the previous lake after its rainy day
                    u32 min_day = std::exchange(it->second, i);

                    auto day_it = std::ranges::lower_bound(dry_days, min_day);

                    if (day_it != dry_days.end())
                    {
                        rains[*day_it] = lake;
                        dry_days.erase(day_it);
                    }
                    else
                    {
                        return {};
                    }
                }
            }
            else
            {
                dry_days.push_back(i);
            }
        }

        for (u32 dry_day : dry_days) rains[dry_day] = 1;

        return std::move(rains);
    }
};
