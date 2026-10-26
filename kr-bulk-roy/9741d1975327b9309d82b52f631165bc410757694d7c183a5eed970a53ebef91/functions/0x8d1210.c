
void FUN_008d1210(char param_1,int *param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int extraout_EDX;
  int extraout_EDX_00;
  undefined8 uVar3;
  
  iVar2 = *(int *)(in_EAX + 4);
  if (param_1 == '\0') {
    do {
      iVar1 = *(int *)(iVar2 + 0xc);
      while (iVar1 < 1) {
        FUN_008d1150();
        iVar2 = extraout_EDX_00;
        iVar1 = *(int *)(extraout_EDX_00 + 0xc);
      }
      *(undefined4 *)(iVar2 + 0xc) = 0;
      uVar3 = FUN_008d1150();
      iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    } while ((((int)uVar3 == 0) && (*(int *)(iVar2 + 0xc) < 3)) && (0 < *(int *)(iVar2 + 0xc)));
  }
  else {
    do {
      if (*(int *)(iVar2 + 0xc) < 2) {
        FUN_008d11c0();
        iVar2 = extraout_EDX;
      }
      *(undefined4 *)(iVar2 + 0xc) = 0;
      uVar3 = FUN_008d1150();
      iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    } while ((((int)uVar3 == 0) && (*(int *)(iVar2 + 0xc) < 3)) && (1 < *(int *)(iVar2 + 0xc)));
  }
  if (param_2 != (int *)0x0) {
    if ((int)uVar3 != 0) {
      *param_2 = (*(int *)((ulonglong)uVar3 >> 0x20) - (int)uVar3) + -1;
      return;
    }
    *param_2 = 0;
  }
  return;
}

