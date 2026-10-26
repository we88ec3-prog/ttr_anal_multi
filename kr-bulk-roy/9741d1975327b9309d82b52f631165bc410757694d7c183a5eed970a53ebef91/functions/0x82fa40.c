
void FUN_0082fa40(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(in_EAX + 0x9c);
  iVar2 = 0x20;
  do {
    iVar1 = *piVar3;
    if (iVar1 != 0) {
      FUN_00891d3d(*(undefined4 *)(iVar1 + 0x14));
      FUN_0089120c(iVar1);
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

