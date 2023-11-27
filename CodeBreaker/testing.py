import random
import subprocess

def generate_test_case():
    N = random.randint(8, 15)  # You can adjust the range for N
    K = random.randint(10, 30)
    happiness = [random.randint(0, 10) for _ in range(N)]
    return N, K, happiness

def run_cpp_program(input_text):
    process = subprocess.Popen(['tourist.exe'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
    stdout, _ = process.communicate(input_text)
    return stdout

def calculate_max_happiness(N, K, happiness):
    dp = [[0] * (K + 1) for _ in range(N)]
    
    for i in range(N):
        for j in range(K + 1):
            dp[i][j] = max(dp[i][j], dp[i-1][j])  # Don't visit city i
            if j >= 2:
                dp[i][j] = max(dp[i][j], dp[i-1][j-2] + happiness[i])  # Stay in city i
        if j >= 1:
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + happiness[i])  # Visit city i
        
    return dp[N-1][K]

# Generate and test multiple random test cases
for _ in range(10):  # You can change the number of test cases
    N, K, happiness = generate_test_case()
    input_text = f"{N} {K}\n{' '.join(map(str, happiness))}\n"
    
    expected_solution = str(calculate_max_happiness(N, K, happiness))

    cplusplus_output = run_cpp_program(input_text)

    if cplusplus_output.strip() == expected_solution:
        print("Test passed!")
    else:
        print("Test failed.")
        print("=" * 10, end='\n')
        print(input_text)
        print("Expected:", expected_solution)
        print("Got", cplusplus_output)
        print("=" * 10, end='\n')
