import m5
from m5.objects import *
import os
import sys




# Function to run a simulation with a specific branch predictor
def run_simulation(branch_pred_class, binary):
    # Create the system
    system = System()
    system.clk_domain = SrcClockDomain(clock='1GHz')
    system.clk_domain.voltage_domain = VoltageDomain()

    # Memory configuration
    system.mem_mode = 'timing'
    system.mem_ranges = [AddrRange('512MB')]

    # Instantiate O3CPU with the specified branch predictor
    system.cpu = O3CPU()
    if branch_pred_class == "LocalBP":
        system.cpu.branchPred = LocalBP()
    elif branch_pred_class == "BiModeBP":
        system.cpu.branchPred = BiModeBP()
    elif branch_pred_class == "LTAGE":
        system.cpu.branchPred = LTAGE()
    elif branch_pred_class == "MultiperspectivePerceptron8KB":
        system.cpu.branchPred = MultiperspectivePerceptron8KB()
    elif branch_pred_class == "MultiperspectivePerceptron64KB":
        system.cpu.branchPred = MultiperspectivePerceptron64KB()
    elif branch_pred_class == "MultiperspectivePerceptronTAGE8KB":
        system.cpu.branchPred = MultiperspectivePerceptronTAGE8KB()
    elif branch_pred_class == "MultiperspectivePerceptronTAGE64KB":
        system.cpu.branchPred = MultiperspectivePerceptronTAGE64KB()
    elif branch_pred_class == "TAGE_SC_L_8KB":
        system.cpu.branchPred = TAGE_SC_L_8KB()
    elif branch_pred_class == "TAGE_SC_L_64KB":
        system.cpu.branchPred = TAGE_SC_L_64KB() 
    else:
        system.cpu.branchPred = TournamentBP()

    # Create a memory bus
    system.membus = SystemXBar()

    # Connect CPU to memory bus
    system.cpu.icache_port = system.membus.cpu_side_ports
    system.cpu.dcache_port = system.membus.cpu_side_ports

    # Create an interrupt controller
    system.cpu.createInterruptController()
    system.cpu.interrupts[0].pio = system.membus.mem_side_ports
    system.cpu.interrupts[0].int_requestor = system.membus.cpu_side_ports
    system.cpu.interrupts[0].int_responder = system.membus.mem_side_ports

    # Memory controller
    system.mem_ctrl = MemCtrl()
    system.mem_ctrl.dram = DDR3_1600_8x8()
    system.mem_ctrl.dram.range = system.mem_ranges[0]
    system.mem_ctrl.port = system.membus.mem_side_ports

    # Create a simple Hello World program
    system.workload = SEWorkload.init_compatible(binary)

    # Set up process
    process = Process()
    process.cmd = [binary]
    system.cpu.workload = process
    system.cpu.createThreads()

    # Create the root node
    root = Root(full_system=False, system=system)
    m5.instantiate()

    # Reset stats before simulation
    m5.stats.reset()

    # Run the simulation
    print(f"Running gem5 simulation with {branch_pred_class}...")
    exit_event = m5.simulate()
    print(f"Simulation finished at tick {m5.curTick()} because {exit_event.getCause()}")

    # Dump stats after simulation
    # m5.stats.dump()

    #  # Collect and print performance metrics
    # stats = m5.stats.globalStats
    # committed_insts = stats.get('system.cpu.committedInsts')
    # total_cycles = m5.curTick()

    # # Collect and print performance metrics
    # print(f"Performance metrics for {branch_pred_class}:")
    # print(f" - Instructions per cycle (IPC): {committed_insts.value() / total_cycles}")
    # print(f" - Total Instructions: {committed_insts.value()}")
    # print(f" - Total Cycles: {total_cycles}")
    # print("")

# Binary for the workload
binary = 'tests/work-tests/full-complex/program64-static'

# List of branch predictors to test
branch_predictors = ["LocalBP",  "BiModeBP", "LTAGE",
                     "MultiperspectivePerceptron8KB",  "MultiperspectivePerceptron64KB", 
                     "MultiperspectivePerceptronTAGE8KB", "MultiperspectivePerceptronTAGE64KB",
                        "TAGE_SC_L_8KB", "TAGE_SC_L_64KB", "TournamentBP"]

run_simulation(branch_predictors[1], binary)

