from fuel import convert, gauge
import pytest

def test_convert():
    assert convert('5/10') == 50
    assert convert('1/4') == 25
    # assert convert ('5/0') == 'dupa'
    # assert convert ('a/b') == 'dupa'

def test_convert_err():
    with pytest.raises(ValueError):
        convert('6/5')
    with pytest.raises(ZeroDivisionError):
        convert('5/0')

def test_gauge():
    assert gauge(99) == 'F'
    assert gauge(1) == 'E'
    assert gauge(50) == '50%'