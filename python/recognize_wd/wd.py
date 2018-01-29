from pytesseract import *
try:
    import Image
except ImportError:
    from PIL import Image
import sys




image=Image.open(sys.argv[1])


print(pytesseract.image_to_string(image,lang='chi_sim+eng'))
