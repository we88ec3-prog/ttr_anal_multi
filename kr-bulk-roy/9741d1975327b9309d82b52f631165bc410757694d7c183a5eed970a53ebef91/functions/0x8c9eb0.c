
int FUN_008c9eb0(int param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EBX;
  uint uVar6;
  int local_8;
  
  uVar1 = *(undefined4 *)(unaff_EBX + 0x1c);
  uVar2 = FUN_008b9ab0();
  uVar6 = (uint)uVar2;
  if (local_8 == 0) {
    if ((uVar6 <= *(ushort *)(param_1 + 0x108)) && (uVar6 < 0x103)) {
      iVar3 = FUN_008bc7d0(uVar1,1,0,uVar6,0,&local_8);
      if (local_8 == 0) {
        local_8 = FUN_008bab70();
        if (local_8 == 0) {
          iVar4 = 0;
          if (uVar6 != 0) {
            do {
              iVar5 = *(char *)(iVar4 + iVar3) + iVar4;
              if ((iVar5 < 0) || ((int)uVar6 < iVar5)) {
                local_8 = 3;
                goto LAB_008c9f55;
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 < (int)uVar6);
          }
          *(int *)(param_1 + 0x26c) = iVar3;
          *(ushort *)(param_1 + 0x268) = uVar2;
          return 0;
        }
      }
LAB_008c9f55:
      FUN_008b9f80(uVar1,iVar3);
      return local_8;
    }
    local_8 = 3;
  }
  return local_8;
}

