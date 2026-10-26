
short FUN_0077c4f0(float param_1)

{
  float fVar1;
  byte bVar2;
  int in_ECX;
  
  fVar1 = *(float *)(in_ECX + 0x44);
  bVar2 = fVar1 < param_1 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(param_1)) << 10) >> 8) |
          (byte)((ushort)((ushort)(fVar1 == param_1) << 0xe) >> 8);
  if (fVar1 < param_1) {
    return CONCAT11(bVar2,1);
  }
  return (ushort)bVar2 << 8;
}

