#pragma once

#include <cstdint>

namespace och
{
	struct date;

	struct timespan
	{
		int64_t val;

		timespan operator+(timespan rhs) const noexcept { return { val + rhs.val }; }

		timespan operator-(timespan rhs) const noexcept { return { val - rhs.val }; }

		void operator+=(timespan rhs) noexcept { val += rhs.val; }

		void operator-=(timespan rhs) noexcept { val -= rhs.val; }

		bool operator<(timespan rhs) const noexcept { return val < rhs.val; }

		bool operator<=(timespan rhs) const noexcept { return val <= rhs.val; }

		bool operator>(timespan rhs) const noexcept { return val > rhs.val; }

		bool operator>=(timespan rhs) const noexcept { return val >= rhs.val; }

		bool operator==(timespan rhs) const noexcept { return val == rhs.val; }

		bool operator!=(timespan rhs) const noexcept { return val != rhs.val; }

		int64_t microseconds() const noexcept { return val / 10llu; }

		int64_t milliseconds() const noexcept { return val / 10000llu; }

		int64_t seconds() const noexcept { return val / 10000000llu; }

		int64_t minutes() const noexcept { return val / 600000000llu; }

		int64_t hours() const noexcept { return val / (60 * 600000000llu); }

		int64_t days() const noexcept { return val / (24 * 60 * 600000000llu); }
	};

	struct time
	{
		uint64_t val;

		time() = default;

		time(uint64_t val) : val{ val } {}

		explicit time(const date& date) noexcept;

		static time now() noexcept;

		timespan operator-(time rhs) const noexcept { return { static_cast<int64_t>(val - rhs.val) }; }

		timespan operator+(timespan rhs) const noexcept { return { static_cast<int64_t>(val + rhs.val) }; }

		timespan operator-(timespan rhs) const noexcept { return { static_cast<int64_t>(val - rhs.val) }; }

		void operator+=(timespan rhs) noexcept { val += rhs.val; }

		void operator-=(timespan rhs) noexcept { val -= rhs.val; }

		bool operator<(time rhs) const noexcept { return val < rhs.val; }

		bool operator<=(time rhs) const noexcept { return val <= rhs.val; }

		bool operator>(time rhs) const noexcept { return val > rhs.val; }

		bool operator>=(time rhs) const noexcept { return val >= rhs.val; }

		bool operator==(time rhs) const noexcept { return val == rhs.val; }

		bool operator!=(time rhs) const noexcept { return val != rhs.val; }
	};

	struct date
	{
		uint16_t m_year;
		uint16_t m_month;
		uint16_t m_weekday;//Has local utc-offset encoded in high bits(4-15); If only highest of these bits is set, date is in utc
		uint16_t m_monthday;
		uint16_t m_hour;
		uint16_t m_minute;
		uint16_t m_second;
		uint16_t m_millisecond;

		date() = default;

		date(uint16_t year, uint16_t month, uint16_t weekday, uint16_t monthday, uint16_t hour, uint16_t minute, uint16_t second, uint16_t millisecond) noexcept;

		date(time t) noexcept;

		bool utc_offset_is_negative() const noexcept;
		
		uint16_t utc_offset_minutes() const noexcept;
		
		uint16_t utc_offset_hours() const noexcept;

		bool is_utc() const noexcept;

		uint16_t year() const noexcept;
		
		uint16_t month() const noexcept;
		
		uint16_t weekday() const noexcept;

		uint16_t monthday() const noexcept;

		uint16_t hour() const noexcept;
		
		uint16_t minute() const noexcept;
		
		uint16_t second() const noexcept;
		
		uint16_t millisecond() const noexcept;
		
		static date utc_now() noexcept;

		static date local_now() noexcept;
	};

	struct highres_timespan
	{
		int64_t val;

		highres_timespan operator+(highres_timespan rhs) const noexcept { return { val + rhs.val }; }

		highres_timespan operator-(highres_timespan rhs) const noexcept { return { val - rhs.val }; }

		void operator+=(highres_timespan rhs) noexcept { val += rhs.val; }

		void operator-=(highres_timespan rhs) noexcept { val -= rhs.val; }

		bool operator<(highres_timespan rhs) const noexcept { return val < rhs.val; }

		bool operator<=(highres_timespan rhs) const noexcept { return val <= rhs.val; }

		bool operator>(highres_timespan rhs) const noexcept { return val > rhs.val; }

		bool operator>=(highres_timespan rhs) const noexcept { return val >= rhs.val; }

		bool operator==(highres_timespan rhs) const noexcept { return val == rhs.val; }

		bool operator!=(highres_timespan rhs) const noexcept { return val != rhs.val; }

		int64_t nanoseconds() const noexcept;

		int64_t microseconds() const noexcept;

		int64_t milliseconds() const noexcept;

		int64_t seconds() const noexcept;
	};

	struct highres_time
	{
		uint64_t val;

		static highres_time now() noexcept;

		highres_timespan operator-(highres_time rhs) const noexcept { return { static_cast<int64_t>(val - rhs.val) }; }

		highres_timespan operator+(highres_timespan rhs) const noexcept { return { static_cast<int64_t>(val + rhs.val) }; }

		highres_timespan operator-(highres_timespan rhs) const noexcept { return { static_cast<int64_t>(val - rhs.val) }; }

		void operator+=(highres_timespan rhs) noexcept { val += rhs.val; }

		void operator-=(highres_timespan rhs) noexcept { val -= rhs.val; }

		bool operator<(highres_time rhs) const noexcept { return val < rhs.val; }

		bool operator<=(highres_time rhs) const noexcept { return val <= rhs.val; }

		bool operator>(highres_time rhs) const noexcept { return val > rhs.val; }

		bool operator>=(highres_time rhs) const noexcept { return val >= rhs.val; }

		bool operator==(highres_time rhs) const noexcept { return val == rhs.val; }

		bool operator!=(highres_time rhs) const noexcept { return val != rhs.val; }
	};

	timespan timezone_bias() noexcept;
}
