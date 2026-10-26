
undefined2 FUN_008c60f0(uint param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *in_EAX;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_8;
  
  uVar5 = CONCAT31(CONCAT21(CONCAT11(*in_EAX,in_EAX[1]),in_EAX[2]),in_EAX[3]);
  local_8 = 0;
  if (uVar5 != 0) {
    do {
      uVar4 = local_8 + uVar5 >> 1;
      iVar2 = uVar4 * 4 + 4;
      puVar1 = in_EAX + uVar4 + 3 + iVar2;
      uVar3 = (uint)CONCAT21(CONCAT11(puVar1[-3],in_EAX[uVar4 + 1 + iVar2]),puVar1[-1]);
      if (uVar3 <= param_1) {
        if (param_1 <= uVar3) {
          return CONCAT11(*puVar1,puVar1[1]);
        }
        local_8 = uVar4 + 1;
        uVar4 = uVar5;
      }
      uVar5 = uVar4;
    } while (local_8 < uVar4);
  }
  return 0;
}

