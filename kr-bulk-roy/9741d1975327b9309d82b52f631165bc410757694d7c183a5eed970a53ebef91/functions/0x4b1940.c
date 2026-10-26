
undefined4 FUN_004b1940(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  
  if (param_2 < 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = param_2 - 2 >> 2;
  }
  if (uVar1 != 0) {
    puVar3 = (ushort *)(param_1 + 2);
    do {
      param_2 = (uint)*puVar3;
      iVar2 = FUN_0040f060();
      FUN_0082ef00(&param_2);
      if ((param_1 == *(int *)(iVar2 + 0xc)) || (*(int *)(param_1 + 0x10) == 0)) {
        FUN_006edb60("Error [SKILL_CANCEL]: cannot found In CharList");
      }
      else {
        iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x15c);
        if (iVar2 != 0) {
          FUN_007a79c0(iVar2,(int)(short)puVar3[1]);
        }
      }
      puVar3 = puVar3 + 2;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return 0;
}

