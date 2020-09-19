#include <iostream>
#include <string>

class Terminal {
  public:
    Terminal(unsigned int width, unsigned int height)
        : width(width), height(height) {}

    inline void clear() const {
        std::cout << std::string(MAX_CLEAR, '\n');
        std::cout << "\u001b[" << MAX_CLEAR << "A"
                  << "\u001b[" << width << "D";
    }

    inline void fill_width(const std::string& value) const {
        for (int i = 0; i < width; i++)
            std::cout << value;
        std::cout << std::endl;
    }

    inline void print_center(const std::string& value) const { // TODO
        std::cout << value << std::endl;
    }

    inline unsigned int get_width() const { return width; }
    inline unsigned int get_height() const { return height; }
    inline void set_width(unsigned int value) { width = value; }
    inline void set_height(unsigned int value) { height = value; }

  private:
    unsigned int width;
    unsigned int height;

    unsigned int MAX_CLEAR = 100;
};

int string_to_int(const std::string& input) {

    try {
        return std::stoi(input);
    } catch (std::invalid_argument const& e) {
        std::cout << "\n\u001b[31;1mBad input: "
                     "\u001b[33;1mstd::invalid_argument\u001b[0m"
                  << "\n\n";

    } catch (std::out_of_range const& e) {
        std::cout
            << "\n\u001b[31;1mInteger overflow: \u001b[33;1mstd::out_of_range "
               "\u001b[0m"
            << "\n\n";
    }

    return -1;
}

int print_choice(const int& choice) {
    switch (choice) {
    case 1:
        std::cout << "Rock" << std::endl;
        break;
    case 2:
        std::cout << "Paper" << std::endl;
        break;
    case 3:
        std::cout << "Scissor" << std::endl;
        break;
    default:
        std::cout << "\u001b[38;5;220mInvalid choice\u001b[0m\n";
        return -1;
    }

    return 0;
}

int main(int argc, char const* argv[]) {

    const Terminal terminal(32, 32);
    terminal.clear();

    terminal.fill_width("_");
    terminal.print_center("Welcome to Rock Paper Scissor");
    terminal.fill_width("_");

    bool is_running = true;
    std::string input;

    int rounds = 0;
    int player_score = 0;
    int computer_score = 0;
    int ties = 0;

    while (is_running) {
        if (rounds != 0)
            terminal.clear();

        std::cout << "Rock:    1" << std::endl;
        std::cout << "Paper:   2" << std::endl;
        std::cout << "Scissor: 3" << std::endl;
        std::cout << "Quit:    \u001b[38;5;1mq\u001b[0m" << std::endl;
        terminal.fill_width("_");
        std::cout << "Input: ";
        std::cin >> input;
        terminal.fill_width("_");

        if (input == "q") {
            is_running = false;
            continue;
        }
        terminal.clear();

        int player_choice = string_to_int(input);
        if (player_choice == -1)
            continue;

        int computer_choice = 1 + (rand() % 3);
        input = "";

        terminal.fill_width("_");
        std::cout << "Round: " << rounds << std::endl;
        std::cout << "You: " << player_score << " | "
                  << "Computer: " << computer_score << ", Ties: " << ties
                  << std::endl;
        terminal.fill_width("_");
        std::cout << "You choosed ";
        if (print_choice(player_choice) == -1) {
            continue;
        }
        std::cout << "Computer choosed ";
        print_choice(computer_choice);
        std::cout << std::endl;

        if (computer_choice == player_choice) {
            std::cout << "It's a tie!" << std::endl;
            ties++;
        } else if (player_choice == 1 && computer_choice == 2) {
            std::cout << "You lost!" << std::endl;
            computer_score++;
        } else if (player_choice == 1 && computer_choice == 3) {
            std::cout << "You won!" << std::endl;
            player_score++;
        } else if (player_choice == 2 && computer_choice == 1) {
            std::cout << "You won!" << std::endl;
            player_score++;
        } else if (player_choice == 2 && computer_choice == 3) {
            std::cout << "You lost!" << std::endl;
            computer_score++;
        } else if (player_choice == 3 && computer_choice == 1) {
            std::cout << "You lost!" << std::endl;
            computer_score++;
        } else {
            std::cout << "You won!" << std::endl;
            player_score++;
        }

        std::cout << "\n";
        std::cout << "Press ENTER to continue";
        do {
            std::getline(std::cin, input);
            std::cin.ignore();
        } while (input.length() != 0);

        rounds++;
    }

    return 0;
}
