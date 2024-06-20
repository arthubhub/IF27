#!/bin/sh

seuil=$1
max=1
state=1

while [ $max -lt $seuil ]; do
    ./multithread_prog > /tmp/result.test

    val=$(sed -n 's/.*enregistrées : \([0-9]*\).*/\1/p' /tmp/result.test)
    
    if [ "$val" -gt "$max" ]; then
        max=$val
    fi

    echo "$max   ->   $val"

    if [ $state -eq 0 ]; then
        break
    fi
done

cat /tmp/result.test
