#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

class FunctionParts {
  public:
    FunctionParts(char new_operation, double new_value) {
        operation = new_operation;
        num = new_value;
    }
    double Apply(double value) const {
        if (operation == '+')
            return value + num;
        else {
            if (operation == '-')
                return value - num;
            else
                if (operation == '*')
                    return value * num;
                else
                    return value / num;
        }
    }
    void Invert() {
        if (operation == '+')
            operation = '-';
        else {
            if (operation == '-')
                operation = '+';
            else
                if (operation == '*')
                    operation = '/';
            else
                operation = '*';
        }
    }

  private:
    char operation;
    double num;
};

class Function {
  public:
    void AddPart(const char& operation, const double& value) {
        parts.push_back({operation, value});
    }

    double Apply(double value) const {
        for (const FunctionParts& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }

    void Invert() {
        reverse(begin(parts), end(parts));
        for (FunctionParts& part : parts) {
           part.Invert();
        }
    }

  private:
    vector<FunctionParts> parts;
};

Function MakeWeightFunction(const Params& params, const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params, const Image& image, double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    cout << ComputeImageWeight(params, image) << endl;
    cout << ComputeQualityByWeight(params, image, 52) << endl;
    return 0;
}
