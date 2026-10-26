
undefined4 FUN_004b6580(ushort *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 local_c [4];
  uint local_8;
  
  if (param_2 < 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = param_2 - 2 >> 1;
  }
  for (; uVar1 != 0; uVar1 = uVar1 - 1) {
    param_1 = param_1 + 1;
    local_8 = (uint)*param_1;
    iVar2 = FUN_0040f060();
    FUN_00826280(&local_8);
    if (param_2 != *(uint *)(iVar2 + 0x2c)) {
      FUN_0089120c(*(undefined4 *)(param_2 + 0x10));
      FUN_007b6890(iVar2 + 0x28,local_c,param_2);
    }
  }
  return 0;
}

