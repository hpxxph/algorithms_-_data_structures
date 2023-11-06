import matplotlib.pyplot as plt

with open("insertion_time.txt", "r") as file:
    insertion_time = float(file.read())

execution_times = [insertion_time]
algorithms = ["Insertion Sort"]

plt.bar(algorithms, execution_times)
plt.ylabel('Time (seconds)')
plt.show()