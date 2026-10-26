
undefined4 FUN_006f5460(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)FUN_006f50f0();
  switch(piVar1[2]) {
  case 3:
    iVar3 = FUN_006fb5d0();
    if (iVar3 != 0) {
      return *(undefined4 *)(*piVar1 + 0xc);
    }
    break;
  case 4:
    return *(undefined4 *)(*piVar1 + 0xc);
  case 5:
    uVar2 = FUN_006f9f10();
    return uVar2;
  case 7:
    return *(undefined4 *)(*piVar1 + 0x10);
  }
  return 0;
}

