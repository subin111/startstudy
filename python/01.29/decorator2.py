import time

def elapsed(original_func):
    def wrapper(*args, **kwargs):
        start = time.time()
        result = original_func(*args, **kwargs)
        
        end = time.time()
        print("함수 수행시간: %f초" % (end - start))
        return result
    return wrapper

@elapsed
def myfunc(msg):
    print("'%s'을 출력합니다."%msg)

myfunc("you need python.")