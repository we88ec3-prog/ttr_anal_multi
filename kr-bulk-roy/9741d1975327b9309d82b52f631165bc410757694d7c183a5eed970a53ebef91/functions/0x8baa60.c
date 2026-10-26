
/* WARNING: Removing unreachable block (ram,0x008bab61) */

int FUN_008baa60(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_8;
  
  iVar2 = FUN_008b9c00();
  if (local_8 != 0) {
    return local_8;
  }
  if (iVar2 != param_1) {
    return 2;
  }
  FUN_008b9c00();
  iVar2 = FUN_008b9820();
  if (iVar2 == 0) {
    uVar1 = FUN_008b9ab0();
    if (uVar1 == 0) {
      return 2;
    }
    iVar2 = 0;
    if (uVar1 != 0) {
      do {
        iVar3 = FUN_008b9c00();
        if (iVar3 == 2) {
          uVar4 = FUN_008b9c00();
          FUN_008b9c00();
          *param_2 = uVar4;
          return 0;
        }
        iVar3 = FUN_008b9820();
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)uVar1);
    }
    iVar2 = 2;
  }
  return iVar2;
}

