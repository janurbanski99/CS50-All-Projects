from twttr import shorten

def test_shorten_small():
    assert shorten('twitter1.') == 'twttr1.'
    assert shorten('facebook') == 'fcbk'

def test_shorten_big():
    assert shorten('TWITTER') == 'TWTTR'
    assert shorten('FACEBOOK2,') == 'FCBK2,'
