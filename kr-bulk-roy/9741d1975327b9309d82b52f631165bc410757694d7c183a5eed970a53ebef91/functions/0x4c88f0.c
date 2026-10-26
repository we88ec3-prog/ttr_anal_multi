
undefined4 FUN_004c88f0(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  
  if (in_ECX[0xdc] != 0) {
    if ((int *)in_ECX[0x57] != (int *)0x0) {
      (**(code **)(*(int *)in_ECX[0x57] + 8))();
    }
    if ((in_ECX[0xd9] != 0) && (iVar2 = *(int *)(in_ECX[0xd9] + 0x24), iVar2 != 0)) {
      FUN_007bdf40(iVar2);
    }
    piVar3 = in_ECX + 0x59;
    iVar2 = 0x80;
    do {
      if ((*piVar3 != 0) && (iVar1 = *(int *)(*piVar3 + 0x24), iVar1 != 0)) {
        FUN_007bdf40(iVar1);
      }
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (in_ECX[0xda] != 0) {
      FUN_004c9580(in_ECX);
      iVar2 = (**(code **)(*in_ECX + 0x70))();
      if (((iVar2 < 100) || (*(int *)(in_ECX[0xda] + 0x28) != 0)) &&
         (*(int *)(in_ECX[0xda] + 0x24) != 0)) {
        FUN_007b4f80();
      }
    }
  }
  return 0;
}

