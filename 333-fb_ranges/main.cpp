// Is there a way to convert this to a ranged for loop?
// snake is a list of pair<int, int> Thanks
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <utility>
#include <span>
#include <algorithm>

#ifndef __cpp_lib_ranges
#   error "Requires C++ ranges library"
#else
#   include <ranges>
#endif

template<typename T>
std::ostream & operator<<(std::ostream & os, const std::vector<T> & vec) {
    for (auto & el : vec) {
        os << el << ' ';
    }
    return os;
}

#define str(x) strx(x)
#define strx(x) #x

template <typename Tx, typename Ty>
struct Snake_Segment {
    Tx x;
    Ty y;

    friend
    std::ostream & operator<<(std::ostream & os, Snake_Segment const & that) {
      os << that.x << ' ' << that.y;
      return os;
    }
};

int main(int argc, char const * argv[]) {
    std::vector<std::string> vec = {
        "Hello", "from", "GCC", __VERSION__, "!", "C++", str(__cplusplus), "!", "std::ranges lib", str(__cpp_lib_ranges), "!",
    };
    std::cout << vec << std::endl;

    std::vector<std::pair<int, int>> const snake {
        std::make_pair(0, 0),
        std::make_pair(1, 2),
        std::make_pair(2, 3),
        std::make_pair(1, 2),
    };

    auto dead { false };

    std::cout << "1A:\n";
    for (auto i = snake.begin(); i != snake.end(); i++) {
        std::cout << i->first << ' '
                  << i->second << " : "
                  << snake.front().first << ' '
                  << snake.front().second << '\n';
        if (i != snake.begin()
        && i->first == snake.front().first
        && i->second == snake.front().second) {
            dead = true;
        }
    }
    std::cout<< std::boolalpha << dead << '\n';
    std::cout << std::string(60, '-') << "\n\n";
    dead = false;

    std::cout << "1B:\n";
    for (auto first { true }; auto [x, y] : snake) {
        std::cout << x << ' '
                  << y << " : "
                  << snake.front().first << ' '
                  << snake.front().second << '\n';

        if (first) {
            first = false;
            continue;
        }
        if ( x == snake.front().first
        && y == snake.front().second) {
            dead = true;
        }
    }
    std::cout<< std::boolalpha << dead << '\n';
    std::cout << std::string(60, '-') << "\n\n";
    dead = false;

    std::cout << "1C:\n";
    for (auto i : snake) {
        std::cout << i.first << ' '
                  << i.second << " : "
                  << snake.front().first << ' '
                  << snake.front().second << '\n';
        if (i != (*snake.begin())
        && i.first == snake.front().first
        && i.second == snake.front().second) {
            dead = true;
        }
    }
    std::cout<< std::boolalpha << dead << '\n';
    std::cout << std::string(60, '-') << "\n\n";
    dead = false;

    std::cout << "1D:\n";
    for (auto i : std::ranges::drop_view(snake, 1)) {
        std::cout << i.first << ' '
                  << i.second << " : "
                  << snake.front().first << ' '
                  << snake.front().second << '\n';
        if (i != (*snake.begin())
        && i.first == snake.front().first
        && i.second == snake.front().second) {
            dead = true;
        }
    }
    std::cout<< std::boolalpha << dead << '\n';
    std::cout << std::string(60, '-') << "\n\n";
    dead = false;

    std::cout << "1E:\n";
    std::for_each(std::ranges::drop_view(snake, 1).begin(),
                  std::ranges::drop_view(snake, 1).end(),
                  [&snake, &dead](auto & ab) {
        std::cout << ab.first << ' '
                  << ab.second << " : "
                  << snake.front().first << ' '
                  << snake.front().second << '\n';
        if (ab.first == snake.front().first
        &&  ab.second == snake.front().second) {
            dead = true;
        }
    });
    std::cout<< std::boolalpha << dead << '\n';
    std::cout << std::string(60, '-') << "\n\n";
    dead = false;

    std::list<Snake_Segment<int, int>> const Snake {
        { 0, 0, },
        { 1, 2, },
        { 2, 3, },
        { 3, 4, },
        { 0, 0, },
    };

    std::cout << "2A:\n";
    for (auto i = Snake.begin(); i != Snake.end(); i++) {
        std::cout << *i << " : "
                  << Snake.front() << '\n';
        if (i != Snake.begin()
        && i->x == Snake.front().x
        && i->y == Snake.front().y) {
            dead = true;
        }
    }
    std::cout<< std::boolalpha << dead << '\n';
    std::cout << std::string(60, '-') << "\n\n";
    dead = false;

    std::cout << "2B:\n";
    for (auto const & i : Snake) {
        std::cout << i << " : "
                  << Snake.front() << '\n';
        // std::cout << &i << '\n'
        //           << &Snake.front() << '\n';
        if (&i != &Snake.front()
        && i.x == Snake.front().x
        && i.y == Snake.front().y) {
            dead = true;
        }
    }
    std::cout<< std::boolalpha << dead << '\n';
    std::cout << std::string(60, '-') << "\n\n";
    dead = false;

    std::cout << "2C:\n";
    for (auto first {true}; auto const & [x, y] : Snake) {
        std::cout << x << ' '
                  << y << " : "
                  << Snake.front() << '\n';
        if (first) {
            first = false;
            continue;
        }
        if (x == Snake.front().x
        &&  y == Snake.front().y) {
            dead = true;
        }
    }
    std::cout<< std::boolalpha << dead << '\n';
    std::cout << std::string(60, '-') << "\n\n";
    dead = false;

    std::cout << "2D:\n";
    for (auto const & [x, y] : Snake) {
        std::cout << x << ' '
                  << y << " : "
                  << Snake.front() << '\n';
        if (&x == &Snake.front().x && &y == &Snake.front().y) {
            continue;
        }
        if (x == Snake.front().x
        &&  y == Snake.front().y) {
            dead = true;
        }
    }
    std::cout<< std::boolalpha << dead << '\n';
    std::cout << std::string(60, '-') << "\n\n";
    dead = false;

    std::cout << "2E:\n";
    for (auto const & [x, y] : std::ranges::drop_view(Snake, 1)) {
        std::cout << x << ' '
                  << y << " : "
                  << Snake.front() << '\n';
        // if (&x == &Snake.front().x && &y == &Snake.front().y) {
        //     continue;
        // }
        if (x == Snake.front().x
        &&  y == Snake.front().y) {
            dead = true;
        }
    }
    std::cout<< std::boolalpha << dead << '\n';
    std::cout << std::string(60, '-') << "\n\n";
    dead = false;

    std::cout << "2F:\n";
    for (auto const & [x, y] : std::ranges::take_view(
                               std::ranges::drop_view(Snake, 1),
                               3)) {
        std::cout << x << ' '
                  << y << " : "
                  << Snake.front() << '\n';
        if (x == Snake.front().x
        &&  y == Snake.front().y) {
            dead = true;
        }
    }
    std::cout<< std::boolalpha << dead << '\n';
    std::cout << std::string(60, '-') << "\n\n";
    dead = false;

    auto ptrfn = [](std::pair<int, int> const * ary, size_t sz) {
        for (size_t p_ {}; p_ < sz; ++p_) {
            std::cout << ary[p_].first << ' '
                      << ary[p_].second << '\n';
        }
        std::cout << std::endl;
    };
    auto spanfn = [](std::span<std::pair<int, int> const> data) {
        for (auto const & [x, y] : data) {
            std::cout << x << ' '
                      << y << '\n';
        }
        std::cout << std::endl;
    };
    std::cout << "3A:\n";
    ptrfn(snake.data(), snake.size());
    std::cout << "3B:\n";
    spanfn({snake.data(), snake.size()});
}

