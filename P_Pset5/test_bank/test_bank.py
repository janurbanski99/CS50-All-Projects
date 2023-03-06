from bank import value

def test_value_0():
    assert value('HELLO, chwd') == 0
    assert value('hello nibba') == 0

def test_value_20():
    assert value('hemlo') == 20
    assert value('hejkatulenka123') == 20

def test_value_100():
    assert value('jp100%') == 100
    assert value ('aaaa') == 100
