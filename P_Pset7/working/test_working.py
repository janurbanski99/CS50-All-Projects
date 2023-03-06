from working import convert
import pytest

def test_convert():
    assert convert("7:12 AM to 8:30 PM") == '07:12 to 20:30'
    assert convert("9 AM to 5 PM") == "09:00 to 17:00"

def test_convert_err():
    with pytest.raises(ValueError):
        convert('6/5')