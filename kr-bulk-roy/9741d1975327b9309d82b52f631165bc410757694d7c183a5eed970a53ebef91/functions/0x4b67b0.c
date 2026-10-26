
undefined4 FUN_004b67b0(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_c [4];
  undefined4 local_8;
  
  if (param_2 < 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = param_2 - 2 >> 2;
  }
  if (uVar1 != 0) {
    puVar3 = (undefined4 *)(param_1 + 2);
    param_1 = uVar1;
    do {
      local_8 = *puVar3;
      iVar2 = FUN_0040f060();
      FUN_0082ef00(&local_8);
      if (param_2 != *(uint *)(iVar2 + 0x3c)) {
        FUN_0089120c(*(undefined4 *)(param_2 + 0x10));
        FUN_007b6890(iVar2 + 0x38,local_c,param_2);
      }
      puVar3 = puVar3 + 1;
      param_1 = param_1 - 1;
    } while (param_1 != 0);
  }
  return 0;
}

