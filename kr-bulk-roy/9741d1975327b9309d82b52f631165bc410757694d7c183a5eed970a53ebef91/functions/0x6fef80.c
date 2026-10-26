
void FUN_006fef80(undefined1 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_EAX;
  int iVar6;
  
  piVar1 = *(int **)(in_EAX + 0x3c);
  if ((uint)piVar1[2] < piVar1[1] + 1U) {
    if (0x7ffffffd < (uint)piVar1[2]) {
                    /* WARNING: Subroutine does not return */
      FUN_006ff130();
    }
    iVar2 = piVar1[2];
    iVar5 = iVar2 * 2;
    if (iVar5 + 1U < 0xfffffffe) {
      iVar3 = *(int *)(in_EAX + 0x34);
      iVar4 = *(int *)(iVar3 + 0x10);
      iVar6 = (**(code **)(iVar4 + 0xc))(*(undefined4 *)(iVar4 + 0x10),*piVar1,iVar2,iVar5);
      if ((iVar6 == 0) && (iVar5 != 0)) {
        iVar6 = FUN_006fdb40(iVar3,4);
      }
      *(int *)(iVar4 + 0x44) = *(int *)(iVar4 + 0x44) + iVar2;
    }
    else {
      FUN_006f8b60(*(undefined4 *)(in_EAX + 0x34),"memory allocation error: block too big");
      iVar6 = 0;
    }
    *piVar1 = iVar6;
    piVar1[2] = iVar5;
  }
  *(undefined1 *)(piVar1[1] + *piVar1) = param_1;
  piVar1[1] = piVar1[1] + 1;
  return;
}

