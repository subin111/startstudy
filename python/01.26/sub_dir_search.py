import os

def search(python):
  try:
    filenames = os.listdir(python)
    for filename in filenames:
      full_filename = os.path.join(python,filename)
      if os.path.isdir(full_filename):
        search(full_filename)
      else:
        ext = os.path.splitext(full_filename)[-1]
        if ext == '.py':
          print(full_filename)
  except PermissionError:
    pass
search("D:/")