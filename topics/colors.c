#include <stdio.h>

void printColoredText(const char* text, const char* color) {
    printf("%s%s\033[0m\n", color, text);
}

int main() {
    const char* colors[] = {
        "\033[0;30m",  // Black
        "\033[0;31m",  // Red
        "\033[0;32m",  // Green
        "\033[0;33m",  // Yellow
        "\033[0;34m",  // Blue
        "\033[0;35m",  // Magenta
        "\033[0;36m",  // Cyan
        "\033[0;37m",  // White
        "\033[1;30m",  // Bright Black (Gray)
        "\033[1;31m",  // Bright Red
        "\033[1;32m",  // Bright Green
        "\033[1;33m",  // Bright Yellow
        "\033[1;34m",  // Bright Blue
        "\033[1;35m",  // Bright Magenta
        "\033[1;36m",  // Bright Cyan
        "\033[1;37m"   // Bright White
    };

    const char* colorNames[] = {
        "Black",
        "Red",
        "Green",
        "Yellow",
        "Blue",
        "Magenta",
        "Cyan",
        "White",
        "Bright Black (Gray)",
        "Bright Red",
        "Bright Green",
        "Bright Yellow",
        "Bright Blue",
        "Bright Magenta",
        "Bright Cyan",
        "Bright White"
    };

    printf("Displaying all ASCII colors using ANSI escape codes:\n\n");

    for (int i = 0; i < 16; i++) {
        printColoredText(colorNames[i], colors[i]);
    }

    return 0;
}
