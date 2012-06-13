testNums = [1010101010,1010101020..1389026630]

isMyNumber n = all (\a -> ((n `div` 10^(2*a)) `mod` 10 == 10 - a)) [1..9]
