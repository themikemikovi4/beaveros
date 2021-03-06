#ifndef BEAVER_SPINLOCK_H
#define BEAVER_SPINLOCK_H

#include <stdint.h>
#include <io/wait.h>

typedef uint64_t spinlock_t;

__attribute__((always_inline))
inline void spinlock_lock(spinlock_t *lock, uint64_t value) {
    while(__sync_lock_test_and_set(lock, value)) {
        io_wait_longer();
    }
}

__attribute__((always_inline))
inline void spinlock_unlock(spinlock_t *lock) {
    __sync_lock_release(lock);
}

#endif /* BEAVER_SPINLOCK_H */
