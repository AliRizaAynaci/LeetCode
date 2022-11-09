class StockSpanner:

    def __init__(self):
        self.queue = deque()

    def next(self, price):
        count = 1

        if self.queue:
            i = len(self.queue)-1

            while i+1 and self.queue[i][0] <= price:
                count+= self.queue[i][1]
                i-=     self.queue[i][1]
                
        self.queue.append((price,count))

        return count
        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)