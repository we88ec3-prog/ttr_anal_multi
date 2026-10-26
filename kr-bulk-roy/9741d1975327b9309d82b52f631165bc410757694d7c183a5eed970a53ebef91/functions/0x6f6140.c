
int FUN_006f6140(void)

{
  undefined4 *puVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = (int *)FUN_006f50f0();
  if (piVar2[2] == 2) {
    iVar4 = *piVar2;
  }
  else {
    if (piVar2[2] != 7) goto LAB_006f61b7;
    iVar4 = *piVar2 + 0x18;
  }
  if ((iVar4 != 0) && (iVar3 = FUN_006f56e0(), iVar3 != 0)) {
    FUN_006f5680();
    puVar1 = (undefined4 *)(*(undefined **)(in_EAX + 8) + -0x20);
    if ((*(undefined **)(in_EAX + 8) != &DAT_00c0bfd8) &&
       ((puVar1 != &DAT_00c0bfc8 && (iVar3 = FUN_006f7710(), iVar3 != 0)))) {
      *(undefined4 **)(in_EAX + 8) = puVar1;
      return iVar4;
    }
  }
LAB_006f61b7:
  FUN_006f50f0();
  FUN_006f5580();
  FUN_006f5da0(1);
  return 0;
}

