#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool parse_args(char& op, vector<int>& values, int argc, char** argv);
int add(const vector<int>& values);
int multiply(const vector<int>& values);
int sub(const vector<int>& values);
int compute_result(const vector<int>& values, char op);
void outPut(int result);

int main(int argc, char** argv)
{
    char op;
    char& op_ref = op;
    vector<int> values;
    vector<int>& values_ref = values;
    if (!parse_args(op_ref, values_ref, argc, argv)){
        return -1;
    }
    const vector<int>& const_values_ref = values;
    int result = compute_result(const_values_ref, op);
    outPut(result);

    return 0;
}


bool parse_args(char& op, vector<int>& values, int argc, char** argv)
{
    // Parsing program parameters.
    if (argc < 2)
    {
        std::cerr << "Expected operator as first argument." << std::endl;
        return false;
    }

    std::string op_str = argv[1];

    if (op_str != "+" && op_str != "*" && op_str != "-")
    {
        std::cerr << "Expected operator to be '+', '*' or '-'." << std::endl;
        return false;
    }
    
    for (auto arg_i = 2; arg_i < argc; ++arg_i)
    {
        auto value = std::stoi(argv[arg_i]);
        values.emplace_back(value); 
    }
    op = op_str[0];
    return true;
}

int add(const vector<int>& values)
{
    auto result = 0;
    for (auto v : values)
    {
        result += v;
    }
    return result;
}

int multiply(const vector<int>& values)
{
    auto result = 1;
    for (auto v : values)
    {
        result *= v;
    }
    return result;
}

int sub(const vector<int>& values)
{
    auto result = 0;
    if (values.empty())
    {
        std::cerr << "Operator '-' expects at least one operand to substract from." << std::endl;
    }

    result = values[0];
    for (auto i = 1; i < values.size(); ++i)
    {
        result -= values[i];
    }
    return result;
}

int compute_result(const vector<int>& values, char op)
{
    // Process operation, depending on the operator.
    if (op == '+')
    {
        return add(values);
    }
    else if (op == '*')
    {
        return multiply(values);
    }
    else
    {
        return sub(values);
    }
}

void outPut(int result)
{
    // Output result.
    std::cout << "Result is " << result << std::endl;
}