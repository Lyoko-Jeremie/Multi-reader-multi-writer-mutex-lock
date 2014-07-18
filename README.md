Multi-reader-multi-writer-mutex-lock
====================================

This lock is suitable for multi-threaded protection STL containers 

多读者多写者锁【互斥锁】

允许读取方多次加锁

可选择性允许写入方多次加锁【设置启动写入互斥锁(AreLockWriter = true)则对写入者之间进行排斥】

适合对STL容器进行多线程保护
