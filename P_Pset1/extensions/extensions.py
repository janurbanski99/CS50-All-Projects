file_name = input("Gib file name: ").lower()
file_name = " ".join(file_name.split()).split('.')

ext = file_name[-1]
ext2 = '.' + file_name[-1]
sufimagejpeg = [".jpg", ".jpeg"]
sufimage = [".png", ".gif"]
sufapp = [".pdf", ".zip"]
sufplain = ['.txt']

if ext2 in sufimagejpeg:
    print("image/jpeg")
elif ext2 in sufimage:
    print ("image/" + ext)
elif ext2 in sufapp:
    print("application/" + ext)
elif ext2 in sufplain:
    print("text/plain")
else:
    print("application/octet-stream")