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

# Connect CPU to memory bus directly
system.cpu.icache_port = system.membus.cpu_side_ports
system.cpu.dcache_port = system.membus.cpu_side_ports

# Create Interrupt controller
system.cpu.createInterruptController()
system.cpu.interrupts[0].pio = system.membus.mem_side_ports
system.cpu.interrupts[0].int_requestor = system.membus.cpu_side_ports
system.cpu.interrupts[0].int_responder = system.membus.mem_side_ports

# Connection
system.system_port = system.membus.cpu_side_ports

# Set up branch prediction
# system.cpu.branchPred = LocalBP()
# system.cpu.branchPred = BiModeBP()
# system.cpu.branchPred = LTAGE()

# system.cpu.branchPred = MultiperspectivePerceptron8KB()
# system.cpu.branchPred = MultiperspectivePerceptron64KB()
# system.cpu.branchPred = MultiperspectivePerceptronTAGE8KB()
# system.cpu.branchPred = MultiperspectivePerceptronTAGE64KB()

# system.cpu.branchPred = TAGE_SC_L_8KB()
# system.cpu.branchPred = TAGE_SC_L_64KB()
system.cpu.branchPred = TournamentBP()

# Memory controller
system.mem_ctrl = MemCtrl()
system.mem_ctrl.dram = DDR3_1600_8x8()
system.mem_ctrl.dram.range = system.mem_ranges[0]
system.mem_ctrl.port = system.membus.mem_side_ports

# Create a simple Hello World program
binary = 'tests/test-progs/hello/src/hello64-static'
system.workload = SEWorkload.init_compatible(binary)

# Set up process
process = Process()
process.cmd = [binary]
system.cpu.workload = process
system.cpu.createThreads()

# Create root node
root = Root(full_system=False, system=system)
m5.instantiate()

# Instantiate and simulate
print("Running gem5 simulation...")

exit_event = m5.simulate()

print("Simulation finished at tick {} because {}".format(m5.curTick(), exit_event.getCause()))
