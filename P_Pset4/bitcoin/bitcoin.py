import requests
import sys
import json

if len(sys.argv) != 2:
    sys.exit("Expected 1 command-line argument")
else:
    try:
        n = float(sys.argv[1])
        response = requests.get('https://api.coindesk.com/v1/bpi/currentprice.json')
        o = response.json()
        # print(json.y
        # dumps(response.json(), indent=2))
        cur_price = float(o['bpi']['USD']['rate_float'])
        print(f"${n*cur_price:,.4f}")
    except ValueError:
        sys.exit("Command-line argument is not a number")
    except requests.RequestException:
        sys.exit("RequestException")