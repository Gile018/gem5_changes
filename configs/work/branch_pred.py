import m5
from m5.objects import *

system = System()

# Clock and voltage domains
system.clk_domain = SrcClockDomain()
system.clk_domain.clock = '1GHz'
system.clk_domain.voltage_domain = VoltageDomain()

# Memory configuration
system.mem_mode = 'timing'
system.mem_ranges = [AddrRange('512MB')]

# CPU configuration
system.cpu = O3CPU()

# Create memory bus
system.membus = SystemXBar()

# Connect CPU to memory bus
system.cpu.icache_port = system.membus.cpu_side_ports
system.cpu.dcache_port = system.membus.cpu_side_ports

# Set up branch prediction
system.cpu.branchPred = LocalBP()

# Memory controller
system.mem_ctrl = DDR3_1600_8x8()



# Create a simple Hello World program
binary = 'tests/test-progs/hello/src/hello64-static'
system.workload = SEWorkload.init_compatible(binary)

# Set up process
process = Process()
process.cmd = [binary]
system.cpu.workload = process
system.cpu.createThreads()


# Create root node
root = Root(full_system= False, system=system)
m5.instantiate()

# Instantiate and simulate
print("Running gem5 simulation...")

exit_event = m5.simulate()

print("Simulation finished.")
