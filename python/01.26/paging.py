def get_total_page(m,n):
    if m % n == 0:
        result = m//n
    else:
        result = m//n+1
    return result

result = get_total_page(5,10)
print(result)