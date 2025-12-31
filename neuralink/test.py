import matplotlib.pyplot as plt
import numpy as np

# Data for employment trends
years = np.arange(2010, 2021)
retail_employment = np.array([15, 14.8, 14.5, 14.3, 14, 13.7, 13.5, 13.3, 13, 12.8, 12.5])
ecommerce_employment = np.array([2, 2.3, 2.7, 3.1, 3.6, 4.1, 4.7, 5.3, 5.9, 6.5, 7.1])

# Data for global internet penetration rates
regions = ["Developed Countries", "Developing Countries", "Sub-Saharan Africa"]
internet_access = [85, 40, 30]

# Data for SME growth in e-commerce
countries = ["Southeast Asia", "Latin America", "Sub-Saharan Africa", "South Asia"]
sme_growth = [25, 20, 15, 10]

# Create the first graph for Employment Trends
plt.figure(1)
plt.plot(years, retail_employment, label="Retail Employment", marker='o', color='r')
plt.plot(years, ecommerce_employment, label="E-commerce Employment", marker='o', color='b')
plt.title('Employment Trends (2010-2020)')
plt.xlabel('Years')
plt.ylabel('Employment (millions)')
plt.legend()
plt.grid(True)
plt.show()

# Create the second graph for Internet Penetration Rates
plt.figure(2)
plt.bar(regions, internet_access, color=['green', 'orange', 'red'])
plt.title('Internet Penetration Rates by Region')
plt.xlabel('Region')
plt.ylabel('Internet Access (%)')
plt.show()

# Create the third graph for SME Growth in E-commerce
plt.figure(3)
plt.bar(countries, sme_growth, color='purple')
plt.title('SME Growth in E-commerce by Region')
plt.xlabel('Region')
plt.ylabel('Growth in SMEs (%)')
plt.show()
