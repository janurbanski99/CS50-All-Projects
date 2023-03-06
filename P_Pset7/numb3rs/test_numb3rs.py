from numb3rs import validate

def test_validate():
    assert validate('1.2.3.4') == True
    assert validate('dupa') == False
    assert validate('1.22.33.111') == True
    assert validate('1.22.33.256') == False
