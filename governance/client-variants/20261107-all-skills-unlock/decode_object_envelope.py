"""Offline translation of bounded7CC000/733EA0 object-envelope transforms.

Returns opaque body bytes in memory. Not a mesh parser, MEF reader or game runner.
"""
import gzip
import struct

SEED_WORDS = (0x1337300C,0x25410F2A,0x39362037,0x404E3040,
              0x40254152,0x305B160B,0x0F5E4E35,0x0C423A4B)

def xor_key():
    key = bytearray(struct.pack('<8I',*SEED_WORDS))
    for index in range(32,128):
        key.append(key[index % 32] * index & 255)
    return bytes(key)

def transform_blocks(envelope):
    """Preserve the8-byte prefix; reproduce native mode0/1/2 block XOR order."""
    if len(envelope) < 136:
        raise ValueError('Outside reviewed minimum128-byte body scope')
    mode = struct.unpack_from('<H',envelope,4)[0]
    if mode not in (0,1,2):
        raise ValueError('Unreviewed object-envelope mode')
    data = bytearray(envelope)
    key = xor_key()
    offsets = [8] if mode == 0 else [len(data)-128] if mode == 1 else [8,len(data)-128]
    for offset in offsets:
        for index,value in enumerate(key):
            data[offset+index] ^= value
    return bytes(data)

def decode_object_member(member):
    envelope = gzip.decompress(member)
    transformed = transform_blocks(envelope)
    return transformed[:8], transformed[8:]
