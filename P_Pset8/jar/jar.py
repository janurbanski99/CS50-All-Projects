class Jar:
    def __init__(self, capacity=12, size=0):
        self.capacity = capacity
        self.size = size

    def __str__(self):
        return f'{"🍪"*(self.size)}'

    def deposit(self, n):
        if n > self.capacity or n + self.size > self.capacity:
            raise ValueError("Capacity deposit aaa")
        self.size += n

    def withdraw(self, n):
        self.size -= n

    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, capacity):
        if not isinstance(capacity, int) or capacity < 0:
            raise ValueError("Capacity aaa")
        self._capacity = capacity

    @property
    def size(self):
        return self._size

    @size.setter
    def size(self, size):
        self._size = size

def main():
    jar = Jar(3)
    jar.deposit(1)
    jar.deposit(2)
    print(jar)
    jar.withdraw(1)
    print(jar)

if __name__ == "__main__":
    main()