
void FUN_007a8220(void)

{
  int iVar1;
  uint uVar2;
  int unaff_EDI;
  int local_28;
  int local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00908828;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if ((*(int *)(unaff_EDI + 0x1c) != 0) &&
     (*(int *)(unaff_EDI + 0x144) != *(int *)(unaff_EDI + 0x148))) {
    *(int *)(unaff_EDI + 0x144) = *(int *)(unaff_EDI + 0x148);
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_c = 0;
    FUN_007c7dd0(*(undefined4 *)(*(int *)(unaff_EDI + 0x1c) + 0x10),&local_28,uVar2);
    uVar2 = 0;
    if (local_24 - local_28 >> 2 != 0) {
      do {
        iVar1 = **(int **)(local_28 + uVar2 * 4);
        if (*(int *)(unaff_EDI + 0x144) == 0) {
          (**(code **)(iVar1 + 0x48))(0x89);
        }
        else {
          (**(code **)(iVar1 + 0x44))(0x89,0,1);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < (uint)(local_24 - local_28 >> 2));
    }
    if (local_28 != 0) {
      FUN_0089120c(local_28);
    }
  }
  *(undefined4 *)(unaff_EDI + 0x148) = 0;
  ExceptionList = local_14;
  return;
}

