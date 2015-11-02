
#ifdef NS3_MODULE_COMPILATION
# error "Do not include ns3 module aggregator headers from other modules; these are meant only for end user scripts."
#endif

#ifndef NS3_MODULE_MPI
    

// Module headers:
#include "mpi-interface.h"
#include "mpi-receiver.h"
#include "parallel-communication-interface.h"
#endif
