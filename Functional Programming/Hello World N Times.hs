hello_worlds 0 = return ()
hello_worlds n = do
    putStrLn "Hello World"
    hello_worlds (n-1)
    
-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
   n <- readLn :: IO Int
   hello_worlds n