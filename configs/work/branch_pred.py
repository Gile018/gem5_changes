import m5
from m5.objects import *
from caches import *
import argparse

parser = argparse.ArgumentParser(description='A simple system with 2-level cache.')
parser.add_argument("binary", default="", nargs="?", type=str,
                    help="Path to the binary to execute.")

parser.add_argument("--l1i_size",
                    help=f"L1 instruction cache size. Default: 16kB.")

parser.add_argument("--l1d_size",
                    help="L1 data cache size. Default: 64kB.")

parser.add_argument("--l2_size",
                    help="L2 cache size. Default: 256kB.")

options = parser.parse_args()

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

# Create L1 instruction and data caches
system.cpu.icache = L1ICache()
system.cpu.dcache = L1DCache()
system.cpu.icache.connectCPU(system.cpu)
system.cpu.dcache.connectCPU(system.cpu)

# Create L2 cache and connect it to the CPU and memory bus
system.cpu.l2cache = L2Cache()
system.cpu.l2cache.connectCPUSideBus(system.cpu.icache)
system.cpu.l2cache.connectCPUSideBus(system.cpu.dcache)
system.cpu.l2cache.connectMemSideBus(system.membus)

# Connect CPU to memory bus
system.cpu.icache_port = system.membus.cpu_side_ports
system.cpu.dcache_port = system.membus.cpu_side_ports


# Create Interrupt controller
system.cpu.createInterruptController()
system.cpu.interrupts[0].pio = system.membus.mem_side_ports
system.cpu.interrupts[0].int_requestor = system.membus.cpu_side_ports
system.cpu.interrupts[0].int_responder = system.membus.mem_side_ports


# Set up branch prediction
system.cpu.branchPred = LocalBP()

# Memory controller
system.mem_ctrl = DDR3_1600_8x8()
system.mem_ctrl.range = system.mem_ranges[0]


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
