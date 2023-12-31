/*--------------------------------------------------------*/
/* qtime. This program displays the time in English.      */
/* If "?" is given as the first argument word then the    */
/* program displays a description of itself.              */
/*--------------------------------------------------------*/
/*
 *  Transposed into C++ from the book "NetRexx 2"
 *  by Mike Cowlishaw, IBM UK Laboratories
 *  @see: https://speleotrove.com/misc/NetRexx2.pdf
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>

#define NDEBUG

using namespace std::literals::string_literals;
using namespace std::literals::chrono_literals;

namespace kron = std::chrono;

void qtime(int64_t hour, int64_t min, int64_t sec);
static
void tell(void);
static
void run_tests(void);

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {

  auto test { false };
  /*--------- First process any argument words -------------*/
  auto parm = ""s;
  if (argc > 1) {
      /* get the first argument word */
                   /* say what we do */
           /* OK (no first argument) */
    parm = std::string(argv[1]);
    if (parm == "?"s) { tell(); }
    else if (parm == "!"s) { test = true; }
    else if (parm != ""s) {
      std::cout << "The only valid argument to QTIME is \"?\".  The word\n"s
                << "that you supplied (" << parm << ") has been ignored.\n\n"s;
      tell();
    }
    else {}
  }

  /*-------- Now start processing in earnest ---------------*/

  /* Extract the hours, minutes, and seconds from the time. */
  /* Use the Java Date class to get the time-of-day.        */
  auto currentTime = kron::duration_cast<kron::seconds>(kron::system_clock().now().time_since_epoch());

  auto timeInSeconds = currentTime % kron::duration_cast<kron::seconds>(24h).count(); // 86'400;

  /* show time */
  auto showtime = [](auto const & tz, auto const & h_m_s) -> void {
    std::cout << tz << ": "s
              << std::setfill('0')
              << std::setw(2) << h_m_s.hours().count()   << ':'
              << std::setw(2) << h_m_s.minutes().count() << ':'
              << std::setw(2) << h_m_s.seconds().count() << '\n';
  };

  auto Uh_m_s = kron::hh_mm_ss(timeInSeconds);
  if (test) { showtime("GMT"s, Uh_m_s); }

#ifndef NDEBUG
  auto dbg1 = [](auto const & timesec) -> void {
    std::cout << timesec.count() << ' ' 
              << kron::duration_cast<kron::hours>(timesec).count()
              << '\n';
  };
#endif /* NDEBUG */

#ifndef NDEBUG
  dbg1(timeInSeconds);
#endif /* NDEBUG */

  //  hardcode PDT (7 hours ahead of GMT)
  auto zPDTdiff = kron::duration_cast<kron::seconds>(8h)  // UTC to PST.
                - kron::duration_cast<kron::seconds>(1h); // DST correction. 

#ifndef NDEBUG
  dbg1(zPDTdiff);
#endif /* NDEBUG */

  auto timeInSecondsX = timeInSeconds + kron::duration_cast<kron::seconds>(24h);

#ifndef NDEBUG
  dbg1(timeInSecondsX);
#endif /* NDEBUG */

  auto Ph_m_s = kron::hh_mm_ss(timeInSecondsX - zPDTdiff);
  if (test) { showtime("PDT"s, Ph_m_s); }

  qtime(Ph_m_s.hours().count(), Ph_m_s.minutes().count(), Ph_m_s.seconds().count());

  if (test) { run_tests(); }

  return EXIT_SUCCESS;
}

/*
 *  MARK: qtime()
 */
void qtime(int64_t hour, int64_t min, int64_t sec) {
  /* Nearness phrases - using associative array lookup      */
  auto near = std::vector<std::string> {
    ""s,
    " just gone"s,  " just after"s,
    " nearly"s,     " almost"s,
  };
  /* default */
    /* exact */
    /* after */
   /* before */

  if (sec > 29) { ++min; }                          /* round up minutes */
  auto mod = min % 5;               /* where we are in 5-minute bracket */
  auto out = "It's"s + near[mod];          /* start building the result */
  if (min > 32) { ++hour; }                    /* we are TO the hour... */
  min += 2;               /* shift minutes to straddle a 5-minute point */
  /* Now special-case the result for Noon and Midnight.     */
  if (hour % 12 == 0 && min % 60 <= 4) {
    if (hour == 12) { std::cout << out << " Noon.\n"s; }
    else            { std::cout << out << " Midnight.\n"s; }
    return;                                     /* we are finished here */
  }

  /* Find five-minute segment and convert to 12-hour clock. */
  min -= (min % 5);                              /* find nearest 5 mins */
  if (hour > 12) {
    hour -= 12;                             /* get rid of 24-hour clock */
  }
  else if (hour == 0) {
    hour = 12;                             /* .. and allow for midnight */
  }

  /* Determine the phrase to use for each 5-minute segment. */
  switch (min) {
    case 0:
      break;                                    /* add "o'clock" later */

    case 60:
      min = 0;
      break;

    case  5:
      out += " five past"s;
      break;

    case 10:
      out += " ten past"s;
      break;

    case 15:
      out += " a quarter past"s;
      break;

    case 20:
      out += " twenty past"s;
      break;

    case 25:
      out += " twenty-five past"s;
      break;

    case 30:
      out += " half past"s;
      break;

    case 35:
      out += " twenty-five to"s;
      break;

    case 40:
      out += " twenty to"s;
      break;

    case 45:
      out += " a quarter to"s;
      break;

    case 50:
      out += " ten to"s;
      break;

    case 55:
      out += " five to"s;
      break;
  }

  /* ditto */
  auto numbers = std::vector<std::string> {
    "one"s,   "two"s,   "three"s, "four"s, "five"s,   "six"s,
    "seven"s, "eight"s, "nine"s,  "ten"s,  "eleven"s, "twelve"s,
  };
  out += " "s + numbers[hour - 1];        /* add the hour number */

  if (min == 0) {                        /* and o'clock if exact */
    out += " o'clock"s;
  }
  std::cout << out << ".";           /* display the final result */
  std::cout << std::endl;

  return;
}

/*
 *  MARK: tell()
 */
static
void tell(void) {
  std::cout << "QTIME displays the current time in natural English.\n"s
            << "Call without any arguments to display the time, or\n"s
            << "with \"?\" to display this information.\n"s
            << "British English idioms are used in this program.\n"s;
  std::cout.put(' '); /* space -- we are about to continue and show time.  */

  return;
}

/*
 *  MARK: run_tests()
 */
static
void run_tests(void) {
  std::cout << "In function "s << __func__ << "()\n\n";
  struct tempo {
    int32_t hh;
    int32_t mm;
    int32_t ss;
  };

  auto samples = std::vector<tempo> {
    { .hh =  0, .mm =  0, .ss =  0, },
    { .hh = 24, .mm =  0, .ss =  0, },
    { .hh = 23, .mm = 59, .ss =  0, },
    { .hh = 23, .mm = 59, .ss = 29, },
    { .hh = 23, .mm = 59, .ss = 30, },
    { .hh = 23, .mm = 59, .ss = 35, },
    { .hh =  0, .mm =  0, .ss = 30, },

    { .hh = 11, .mm =  0, .ss = 30, },
    { .hh = 11, .mm =  0, .ss =  0, },
    { .hh = 11, .mm = 59, .ss =  0, },
    { .hh = 11, .mm = 59, .ss = 29, },
    { .hh = 11, .mm = 59, .ss = 30, },
    { .hh = 11, .mm = 59, .ss = 35, },

    { .hh = 12, .mm =  0, .ss = 30, },
    { .hh = 12, .mm =  0, .ss =  0, },
    { .hh = 12, .mm = 59, .ss =  0, },
    { .hh = 12, .mm = 59, .ss = 29, },
    { .hh = 12, .mm = 59, .ss = 30, },
    { .hh = 12, .mm = 59, .ss = 35, },

    { .hh = 12, .mm =  3, .ss = 30, },
    { .hh = 12, .mm =  3, .ss =  0, },

    { .hh = 12, .mm =  7, .ss = 30, },
    { .hh = 12, .mm =  7, .ss =  0, },

    { .hh = 11, .mm = 57, .ss = 30, },
    { .hh = 11, .mm = 57, .ss =  0, },

    { .hh = 11, .mm = 53, .ss = 30, },
    { .hh = 11, .mm = 53, .ss =  0, },

    { .hh = 12, .mm = 15, .ss = 30, },
    { .hh = 12, .mm = 15, .ss =  0, },

    { .hh = 11, .mm = 45, .ss = 30, },
    { .hh = 11, .mm = 45, .ss =  0, },
  };

  auto showtempo = [](auto const & h_m_s) -> void {
    std::cout << std::setfill('0')
              << std::setw(2) << h_m_s.hh << ':'
              << std::setw(2) << h_m_s.mm << ':'
              << std::setw(2) << h_m_s.ss << '\n';
  };

  std::cout << std::string(80, '-') << '\n';
  for (auto tp : samples) {
    showtempo(tp);
    qtime(tp.hh, tp.mm, tp.ss);
  }
  std::cout << std::endl;

  for (auto hr : { 0, 9, 11, 12, 19, 23, }) {
    std::cout << std::string(80, '-') << '\n';
    for (auto m_ { 0 }; m_ < 60; ++m_) {
      tempo tp { .hh = hr, .mm = m_, .ss = 0, };
      showtempo(tp);
      qtime(tp.hh, tp.mm, tp.ss);
    }
    std::cout << std::endl;
  }

  return;
}
