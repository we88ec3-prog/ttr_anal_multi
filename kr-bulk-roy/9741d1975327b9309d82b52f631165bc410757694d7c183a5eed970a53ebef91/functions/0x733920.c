
undefined4 FUN_00733920(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x30) != 0) {
    do {
      if (*(uint *)(param_1 + 0x34) < 0x10) {
        iVar2 = param_1 + 0x20;
      }
      else {
        iVar2 = *(int *)(param_1 + 0x20);
      }
      bVar1 = *(byte *)(iVar2 + uVar3);
      iVar2 = _isspace((uint)bVar1);
      if (((iVar2 == 0) && (bVar1 != 10)) && (bVar1 != 0xd)) {
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0x30));
  }
  return 1;
}

