
int FUN_006f53f0(undefined4 param_1,undefined4 *param_2)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_006f50f0();
  if (piVar1[2] != 4) {
    iVar2 = FUN_006fb5d0();
    if (iVar2 == 0) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = 0;
      }
      return 0;
    }
    if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    piVar1 = (int *)FUN_006f50f0();
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(*piVar1 + 0xc);
  }
  return *piVar1 + 0x10;
}

