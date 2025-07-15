# LimitMatch

Time moves in discrete timesteps, so for every timestep *t*:

1. Generate random orders (BUY | SELL) (MARKET | LIMIT) -> submitOrder event

   1. Market: speed > price: fill the order ASAP at the best price
   2. Limit: price > speed: suppose a BUY order for 100 shares of AAA at $100, but lowest price is $101. Then the order goes into the BUY order book.
2. All orders submitted go into the orderBook
3. Match all possible orders. FCFS.

   1. TODO: think thru how to track order timestamps for finite timesteps. Can orders come in at the same time?
4. Log all orders.


ORDER class:

- side: BUY or SELL, type: MARKET or LIMIT, price, quantity, ID, symbol, timestamp



EVENT class:


EVENT DISPATCHER class:

- use a queue to handle things for every time step. But handle that later. For now, assume only one event per timestep.
