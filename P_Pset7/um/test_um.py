from um import count

def test_count_good():
    assert count('um?') == 1

def test_count_good2():
    assert count('Um mleko um..') == 2

def test_count_good3():
    assert count("Umcziki bał bał umiesz tak?") == 0