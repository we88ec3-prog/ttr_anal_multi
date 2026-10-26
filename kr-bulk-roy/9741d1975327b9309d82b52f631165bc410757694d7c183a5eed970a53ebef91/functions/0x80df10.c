
void FUN_0080df10(undefined4 *param_1)

{
  int iVar1;
  int *in_EAX;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  piVar4 = (int *)*in_EAX;
  uVar2 = in_EAX[1] - (int)piVar4 >> 2;
  uVar3 = 0;
  if (uVar2 != 0) {
    do {
      iVar1 = *piVar4;
      if ((*(int *)(iVar1 + 8) == 0) && (*(int *)(iVar1 + 0x10) == 0)) {
        InterlockedExchange((LONG *)(iVar1 + 0x10),1);
        *(undefined4 **)(iVar1 + 0x18) = param_1;
        SetEvent(*(HANDLE *)(iVar1 + 4));
        return;
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < uVar2);
  }
  (**(code **)*param_1)();
  return;
}

