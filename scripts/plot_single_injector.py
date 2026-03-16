import sys
import pandas as pd
import matplotlib.pyplot as plt

csv_file = sys.argv[1]
injector = sys.argv[2]
out_dir = sys.argv[3]

data = pd.read_csv(csv_file)

rates = data["InjectionRate"]
lat = data[injector]

lat = lat/max(lat)

plt.figure(figsize=(6,4))
plt.plot(rates, lat, marker='o', linestyle='--')

plt.xlabel(f"Injection Rate (flits/cycle/src) of {injector}")
plt.ylabel("Average Latency (normalized)")
#plt.title(f"{injector} Latency vs Injection Rate")

plt.ylim(min(lat), max(lat))
plt.grid(True)

plt.savefig(f"{out_dir}/average_latency_{injector}.png", dpi=300)
plt.close()
