from simple_min_max import analysis as simple_min_max_analysis
from min_max import analysis as min_max_analysis
from rec_min_max import analysis as rec_min_max_analysis
from matplotlib import pyplot as plt

def logs_plotter(logs):
    for log in logs:
        plt.plot(log['Range'],log['Time'])
    plt.show()

if(__name__ == "__main__"):
    array_of_range = range(1000,10000,500)
    number_of_iterations = 1000
    sim_log = simple_min_max_analysis(array_of_range,number_of_iterations)
    mm_log = min_max_analysis(array_of_range,number_of_iterations)
    rec_log = rec_min_max_analysis(array_of_range,number_of_iterations)

    logs = [sim_log,mm_log,rec_log]

    logs_plotter(logs)


