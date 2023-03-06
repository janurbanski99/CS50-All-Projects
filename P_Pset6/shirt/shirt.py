import sys
import csv
import os
from PIL import Image
import PIL

ext = ['.jpg', '.jpeg', '.png']
user_ext1 = os.path.splitext(sys.argv[1])[1]
user_ext2 = os.path.splitext(sys.argv[2])[1]

if len(sys.argv) != 3 or user_ext1 != user_ext2 or user_ext1 not in ext or user_ext2 not in ext:
    sys.exit("Coś coś się popusuło")
else:
    try:
        before = Image.open(sys.argv[1])
        shirt = Image.open("shirt.png")
        before_size = before.size
        shirt_size = shirt.size

        before = PIL.ImageOps.fit(before, shirt_size)
        before.paste(shirt, shirt)

        # with Image.open(sys.argv[1]) as im:
        #     size = im.size
        #     PIL.ImageOps.fit(im, size, method=Resampling.BICUBIC, bleed=0.0, centering=(0.5, 0.5))
        #     Image.paste(im, box=None, mask='shirt.png')

        after = before.save(sys.argv[2])


    except FileNotFoundError:
        sys.exit("Coś coś się popsuło ale z file tym razem")

