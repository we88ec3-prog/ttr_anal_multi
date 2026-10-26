
undefined4 FUN_008c6070(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 *in_EDX;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = CONCAT31(CONCAT21(CONCAT11(*in_EDX,in_EDX[1]),in_EDX[2]),in_EDX[3]);
  if (uVar3 != 0) {
    do {
      uVar2 = uVar3 + uVar4 >> 1;
      uVar1 = (uint)CONCAT21(CONCAT11(in_EDX[uVar2 * 4 + 4],in_EDX[uVar2 * 4 + 5]),
                             in_EDX[uVar2 * 4 + 6]);
      if (uVar1 <= param_1) {
        if (param_1 <= (byte)in_EDX[uVar2 * 4 + 7] + uVar1) {
          return 1;
        }
        uVar4 = uVar2 + 1;
        uVar2 = uVar3;
      }
      uVar3 = uVar2;
    } while (uVar4 < uVar2);
  }
  return 0;
}

