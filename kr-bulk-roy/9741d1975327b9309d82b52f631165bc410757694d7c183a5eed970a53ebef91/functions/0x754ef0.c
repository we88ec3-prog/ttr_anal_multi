
void FUN_00754ef0(int param_1)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(in_EAX + 0x150);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 8) != 0)) {
    if ((*(int *)(in_EAX + 0x148) != *(int *)(iVar2 + 0x10)) &&
       (iVar2 = FUN_00773200(*(int *)(in_EAX + 0x148),*(undefined4 *)(in_EAX + 0x14c)), iVar2 != 0))
    {
      *(int *)(in_EAX + 0x150) = iVar2;
    }
    cVar1 = FUN_00754640();
    if (cVar1 != '\0') {
      iVar2 = *(int *)(*(int *)(in_EAX + 0x150) + 0x10);
      iVar4 = 1;
      if (0 < param_1) {
        do {
          iVar3 = FUN_00773200(iVar2 - iVar4,*(undefined4 *)(in_EAX + 0x14c));
          if (iVar3 != 0) {
            *(int *)(in_EAX + 0x150) = iVar3;
            cVar1 = FUN_00754640();
            if (cVar1 == '\0') {
              return;
            }
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= param_1);
      }
    }
  }
  return;
}

