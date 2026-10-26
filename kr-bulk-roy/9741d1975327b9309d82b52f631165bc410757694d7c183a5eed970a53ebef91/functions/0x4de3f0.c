
undefined4 FUN_004de3f0(int param_1,uint param_2)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009249de;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0040f060(uVar3);
  iVar4 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if (iVar4 != 0) {
    bVar2 = *(byte *)(iVar4 + 0x90);
    iVar4 = FUN_0040f060(uVar3);
    if (((int)(uint)bVar2 >> 3 == 0) &&
       (pbVar1 = (byte *)((uint)bVar2 * 3 + 0xb8 + iVar4), pbVar1 != (byte *)0x0)) {
      if (param_2 < 2) {
        uVar3 = 0;
      }
      else {
        uVar3 = (param_2 - 2) / 5;
      }
      if (uVar3 != 0) {
        puVar5 = (undefined4 *)(param_1 + 3);
        do {
          bVar2 = *(byte *)((int)puVar5 + -1);
          if (*pbVar1 == bVar2) {
            iVar4 = 0x10;
          }
          else if (bVar2 < 8) {
            bVar2 = (byte)(1 << (bVar2 & 0x1f));
            if ((pbVar1[1] & bVar2) == 0) {
              iVar4 = 0x12;
              if ((pbVar1[2] & bVar2) == 0) goto LAB_004de4c8;
            }
            else {
              iVar4 = (-(uint)((pbVar1[2] & bVar2) != 0) & 0x6e) + 0x11;
            }
          }
          else {
LAB_004de4c8:
            iVar4 = 0x7f;
          }
          if (iVar4 - 0x10U < 2) {
            *(undefined4 *)(in_ECX + 0x5f0c) = *puVar5;
          }
          else {
            *(undefined4 *)(in_ECX + 0x5f10) = *puVar5;
          }
          puVar5 = (undefined4 *)((int)puVar5 + 5);
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
      }
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 0;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_8 = 0xffffffff;
      }
      FUN_0058aad0(0xf42a6);
    }
  }
  ExceptionList = local_10;
  return 0;
}

