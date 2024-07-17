#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

struct Color {
    double r, g, b; // RGB values in the range [0, 255]
};

struct LabColor {
    double l, a, b; // L*a*b* values
};

// Convert RGB to XYZ
LabColor rgbToLab(const Color& color) {
    double r = color.r / 255.0;
    double g = color.g / 255.0;
    double b = color.b / 255.0;

    // Apply gamma correction
    r = (r > 0.04045) ? pow((r + 0.055) / 1.055, 2.4) : (r / 12.92);
    g = (g > 0.04045) ? pow((g + 0.055) / 1.055, 2.4) : (g / 12.92);
    b = (b > 0.04045) ? pow((b + 0.055) / 1.055, 2.4) : (b / 12.92);

    // Convert to XYZ
    double x = r * 0.4124564 + g * 0.3575761 + b * 0.1804375;
    double y = r * 0.2126729 + g * 0.7151522 + b * 0.0721750;
    double z = r * 0.0193339 + g * 0.1191920 + b * 0.9503041;

    // Normalize for D65 illuminant
    x /= 0.95047;
    y /= 1.00000;
    z /= 1.08883;

    // Convert to L*a*b*
    x = (x > 0.008856) ? pow(x, 1.0/3.0) : (7.787 * x) + (16.0 / 116.0);
    y = (y > 0.008856) ? pow(y, 1.0/3.0) : (7.787 * y) + (16.0 / 116.0);
    z = (z > 0.008856) ? pow(z, 1.0/3.0) : (7.787 * z) + (16.0 / 116.0);

    LabColor lab;
    lab.l = (116.0 * y) - 16.0;
    lab.a = 500.0 * (x - y);
    lab.b = 200.0 * (y - z);

    return lab;
}

// Compute Delta E (CIE76)
double deltaE(const LabColor& lab1, const LabColor& lab2) {
    return sqrt(pow(lab1.l - lab2.l, 2) + pow(lab1.a - lab2.a, 2) + pow(lab1.b - lab2.b, 2));
}

// Find the closest color
Color findClosestColor(const Color& target, const std::vector<Color>& colorArray, double tolerance) {
    LabColor targetLab = rgbToLab(target);
    Color closestColor = {0, 0, 0};
    double minDeltaE = std::numeric_limits<double>::max();

    for (const auto& color : colorArray) {
        LabColor lab = rgbToLab(color);
        double dE = deltaE(targetLab, lab);

        if (dE < minDeltaE) {
            minDeltaE = dE;
            closestColor = color;
        }
    }

    return closestColor;
}

int main() {
    std::vector<Color> colorArray = {
        {255, 0, 0},    // Red
        {0, 255, 0},    // Green
        {0, 0, 255},    // Blue
        {255, 255, 0},  // Yellow
        {0, 255, 255},  // Cyan
        {255, 0, 255}   // Magenta
    };
    
    for (const auto v : colorArray) {
		LabColor c = rgbToLab(v);
		cout << c.l << ' ' << c.a << ' ' << c.b << '\n';
	}

    Color target = {250, 100, 100};
    double tolerance = 15.0;
    Color closestMatch = findClosestColor(target, colorArray, tolerance);

    std::cout << "Closest color: (" << closestMatch.r << ", " << closestMatch.g << ", " << closestMatch.b << ")\n";

    return 0;
}
