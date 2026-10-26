
uint FUN_006fbc20(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int in_EDX;
  undefined8 uVar3;
  
  if ((in_EDX != 0) && ((*(byte *)(in_EDX + 6) & 0x10) == 0)) {
    uVar3 = FUN_006fea60(4);
    uVar1 = (uint)uVar3;
    if (uVar1 != 0) {
      if ((int)((ulonglong)uVar3 >> 0x20) == param_2) {
        return uVar1;
      }
      if (((param_2 != 0) && ((*(byte *)(param_2 + 6) & 0x10) == 0)) &&
         (iVar2 = FUN_006fea60(4), iVar2 != 0)) {
        iVar2 = FUN_006f7710();
        return -(uint)(iVar2 != 0) & uVar1;
      }
    }
  }
  return 0;
}

