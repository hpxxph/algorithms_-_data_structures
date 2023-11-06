import matplotlib.pyplot as plt

with open("bubble_time.txt", "r") as file:
    bubble_time = float(file.read())

execution_times = [bubble_time]
algorithms = ["Bubble Sort"]

plt.bar(algorithms, execution_times)
plt.ylabel('Time (seconds)')
plt.show()
