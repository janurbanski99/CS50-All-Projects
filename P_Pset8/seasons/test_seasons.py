from seasons import check_date, main
import pytest
import datetime

def test_check_date():
    assert check_date("1999-02-12") == datetime.date(1999, 2, 12)

def test_check_date_err():
    with pytest.raises(ValueError):
        check_date('2025-12-12')
