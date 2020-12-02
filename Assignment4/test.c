/*
P_counting( int count )
   P( countLock )        // Acquire lock to count: countLock <- 0
   count--
   if( count <= 0 )      // If no more threads allowed into critical section
      P( sectionLock )   // Resource full => Acquire section lock: sectionLock <- 0
      V( countLock )     // Release lock to count: countLock <- 1
   else
      V( countLock)

V_counting( int count )
   P( countLock )
   count++
   if( count > 0)        // Release sectionLock if resource is freed up
      V(sectionLock)     // countLock released after sectionLock so that waiting
      V(countLock)       // threads do not jump in when before resource is available
   else
      V(countLock)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
Mutex counting_mutex;    // used for accessing the shared variable count
Integer count = n;       // number of resource instances
Mutex mutex;             // the counting semaphore as mutex/binary semaphore
List waiting_list = [];  // list of waiting processes

// Entry Section
acquire(counting_mutex);
count--;
release(counting_mutex);

if (count < 0)
    add this process to waiting_list and have it sleep()

acquire(mutex);
// ... Critical Section ...
release(mutex);

// Exit Section
acquire(counting_mutex);
count++;
release(counting_mutex);

if (count <= 0)
    pull a process from waiting_list and call wakeup()


    */