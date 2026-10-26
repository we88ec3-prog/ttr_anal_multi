
undefined1 * FUN_008c6180(uint param_1)

{
  undefined1 *puVar1;
  undefined1 *in_EAX;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_8;
  
  uVar3 = CONCAT31(CONCAT21(CONCAT11(*in_EAX,in_EAX[1]),in_EAX[2]),in_EAX[3]);
  local_8 = 0;
  if (uVar3 != 0) {
    do {
      uVar4 = local_8 + uVar3 >> 1;
      puVar1 = in_EAX + uVar4 * 0xb + 7;
      uVar2 = (uint)CONCAT21(CONCAT11(puVar1[-3],in_EAX[uVar4 * 0xb + 5]),puVar1[-1]);
      if (uVar2 <= param_1) {
        if (param_1 <= uVar2) {
          return puVar1;
        }
        local_8 = uVar4 + 1;
        uVar4 = uVar3;
      }
      uVar3 = uVar4;
    } while (local_8 < uVar4);
  }
  return (undefined1 *)0x0;
}

