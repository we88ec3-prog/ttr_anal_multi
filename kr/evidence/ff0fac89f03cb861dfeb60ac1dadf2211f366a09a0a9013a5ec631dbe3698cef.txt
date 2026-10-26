
void FUN_00544f50(void)

{
  uint uVar1;
  DWORD DVar2;
  int iVar3;
  int *piVar4;
  int *unaff_EDI;
  int *unaff_FS_OFFSET;
  int local_24;
  int iStack_20;
  int *piStack_1c;
  int local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0090cfd8;
  local_14 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  *unaff_FS_OFFSET = (int)&local_14;
  unaff_EDI[0x18] = 0;
  unaff_EDI[0x17] = 0;
  DVar2 = timeGetTime();
  unaff_EDI[0x19] = DVar2;
  unaff_EDI[0x10] = 0;
  unaff_EDI[0x11] = 0;
  DAT_00fbab48 = 1;
  local_24 = 0;
  piVar4 = unaff_EDI + 5;
  do {
    iVar3 = (**(code **)(*unaff_EDI + 0x1c))(local_24,uVar1);
    if (iVar3 != 0) {
      FUN_0049c3d0();
      uStack_c = 0;
      if (iStack_20 != 0) {
        FUN_007a7890(iStack_20);
      }
      uStack_c = 0xffffffff;
      if (piStack_1c != (int *)0x0) {
        LOCK();
        iVar3 = piStack_1c[1] + -1;
        piStack_1c[1] = iVar3;
        UNLOCK();
        if (iVar3 == 0) {
          (**(code **)*piStack_1c)();
          LOCK();
          iVar3 = piStack_1c[2] + -1;
          piStack_1c[2] = iVar3;
          UNLOCK();
          if (iVar3 == 0) {
            (**(code **)(*piStack_1c + 4))();
          }
        }
      }
    }
    local_24 = local_24 + 1;
    piVar4[-2] = 0;
    piVar4[-1] = 0;
    *(undefined1 *)piVar4 = 1;
    piVar4 = piVar4 + 3;
  } while (local_24 < 3);
  *unaff_FS_OFFSET = local_14;
  return;
}

