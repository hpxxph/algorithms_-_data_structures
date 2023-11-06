import matplotlib.pyplot as plt

with open("execution_time.txt", "r") as file:
    execution_time = float(file.read())

execution_times = [execution_time]
complexities = ["O(n log n)"]

plt.bar(complexities, execution_times)
plt.ylabel('Time (seconds)')
plt.show()