
undefined4 FUN_00808db0(undefined4 param_1,undefined4 param_2)

{
  int *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *local_8;
  
  (**(code **)(*in_EAX + 0x14))();
  iVar1 = FUN_007300a0(&DAT_00bed1d4);
  if (iVar1 == 0) {
    local_8 = (undefined4 *)0x0;
  }
  else {
    local_8 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      local_8 = (undefined4 *)*local_8;
    }
  }
  iVar1 = FUN_007300a0(&DAT_00c0ea40);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = FUN_008917b4(puVar2);
      goto LAB_00808e1b;
    }
  }
  uVar3 = 0;
LAB_00808e1b:
  if ((local_8 != (undefined4 *)0x0) && (iVar1 = FUN_00808ce0(), iVar1 != -1)) {
    puVar4 = (undefined4 *)FUN_00891268(0x14);
    puVar2 = (undefined4 *)0x0;
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[4] = 0;
      puVar2 = puVar4;
    }
    puVar2[4] = uVar3;
    iVar1 = FUN_0072e2e0(&DAT_00c5179c);
    while( true ) {
      if (iVar1 == 0) {
        uVar3 = FUN_0057ef20();
        FUN_0057e850(param_2,uVar3);
        return 1;
      }
      iVar1 = FUN_00808ef0(param_1,puVar2);
      if (iVar1 == 0) break;
      iVar1 = FUN_0072e320(&DAT_00c5179c);
    }
    FUN_00809200(puVar2);
    FUN_0089120c(puVar2);
    return 0;
  }
  return 0;
}

