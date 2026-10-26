
void FUN_007e0170(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *in_EAX;
  int iVar3;
  int *piVar4;
  
  if (in_EAX != param_1) {
    piVar4 = in_EAX + 1;
    do {
      iVar3 = *piVar4;
      if (iVar3 != 0) {
        iVar2 = piVar4[1];
        for (; iVar3 != iVar2; iVar3 = iVar3 + 0x18) {
          if (*(int *)(iVar3 + 8) != 0) {
            FUN_0089120c(*(int *)(iVar3 + 8));
          }
          *(undefined4 *)(iVar3 + 8) = 0;
          *(undefined4 *)(iVar3 + 0xc) = 0;
          *(undefined4 *)(iVar3 + 0x10) = 0;
        }
        FUN_0089120c(*piVar4);
      }
      *piVar4 = 0;
      piVar4[1] = 0;
      piVar4[2] = 0;
      piVar1 = piVar4 + 4;
      piVar4 = piVar4 + 5;
    } while (piVar1 != param_1);
  }
  return;
}

