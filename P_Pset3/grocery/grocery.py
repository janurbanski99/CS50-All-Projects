shopping_list = []
shopping_dic = {}

while True:
    try:
        item = input().upper()

        shopping_list.append(item)
        shopping_list = sorted(shopping_list)
    except(EOFError, KeyboardInterrupt):
        print()
        for i in shopping_list:
            shopping_dic[i] = shopping_list.count(i)
        # print(shopping_dic)
        for item in shopping_dic:
            print(shopping_dic[item], item)
        break