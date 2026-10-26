
void FUN_00810710(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int in_ECX;
  bool bVar7;
  undefined1 auStack_54 [4];
  int local_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  undefined4 uStack_40;
  uint auStack_38 [4];
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00928370;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_54;
  ExceptionList = &local_14;
  local_50 = in_ECX;
  uVar1 = FUN_00891268(0x2d0,DAT_00d61f20 ^ (uint)&stack0xffffffa0);
  *(undefined4 *)(in_ECX + 4) = uVar1;
  iVar2 = ov_fopen();
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar2 < 0) {
    if (iVar3 != 0) {
      FUN_0089120c(iVar3);
      *(undefined4 *)(in_ECX + 4) = 0;
    }
  }
  else {
    uVar1 = ov_info(iVar3,0xffffffff);
    *(undefined4 *)(in_ECX + 8) = uVar1;
    iVar3 = ov_comment(*(undefined4 *)(in_ECX + 4),0xffffffff);
    *(int *)(in_ECX + 0xc) = iVar3;
    iStack_4c = 0;
    if (0 < *(int *)(iVar3 + 8)) {
      do {
        uStack_24 = 0xf;
        uStack_28 = 0;
        auStack_38[0] = auStack_38[0] & 0xffffff00;
        uStack_c = 0;
        FUN_00402a70(*(undefined4 *)(**(int **)(in_ECX + 0xc) + iStack_4c * 4),
                     *(undefined4 *)((*(int **)(in_ECX + 0xc))[1] + iStack_4c * 4));
        iStack_48 = 0;
        iStack_44 = 0;
        uStack_40 = 0;
        uStack_c = CONCAT31(uStack_c._1_3_,1);
        FUN_00810b20(auStack_38,&iStack_48);
        iVar3 = iStack_48;
        if ((iStack_44 - iStack_48) / 0x1c == 2) {
          uVar5 = *(uint *)(iStack_48 + 0x10);
          uVar4 = uVar5;
          if (8 < uVar5) {
            uVar4 = 9;
          }
          iVar2 = FUN_00407e70(uVar4);
          bVar7 = false;
          if (iVar2 == 0) {
            if (uVar5 < 9) {
              uVar5 = 0xffffffff;
            }
            else {
              uVar5 = (uint)(uVar5 != 9);
            }
            bVar7 = uVar5 == 0;
          }
          if (bVar7) {
            puVar6 = (undefined4 *)(iVar3 + 0x1c);
            if (0xf < *(uint *)(iVar3 + 0x30)) {
              puVar6 = (undefined4 *)*puVar6;
            }
            if (puVar6 == (undefined4 *)0x0) {
              uVar1 = 0;
            }
            else {
              uVar1 = FUN_008917b4(puVar6);
            }
            *(undefined4 *)(local_50 + 0x14) = uVar1;
          }
          uVar5 = *(uint *)(iVar3 + 0x10);
          uVar4 = uVar5;
          if (6 < uVar5) {
            uVar4 = 7;
          }
          iVar2 = FUN_00407e70(uVar4);
          bVar7 = false;
          if (iVar2 == 0) {
            if (uVar5 < 7) {
              uVar5 = 0xffffffff;
            }
            else {
              uVar5 = (uint)(uVar5 != 7);
            }
            bVar7 = uVar5 == 0;
          }
          in_ECX = local_50;
          if (bVar7) {
            puVar6 = (undefined4 *)(iVar3 + 0x1c);
            if (0xf < *(uint *)(iVar3 + 0x30)) {
              puVar6 = (undefined4 *)*puVar6;
            }
            if (puVar6 == (undefined4 *)0x0) {
              *(undefined4 *)(local_50 + 0x18) = 0;
            }
            else {
              uVar1 = FUN_008917b4(puVar6);
              *(undefined4 *)(local_50 + 0x18) = uVar1;
              in_ECX = local_50;
            }
          }
        }
        if (iVar3 != 0) {
          FUN_00440a80();
          FUN_0089120c(iVar3);
          in_ECX = local_50;
        }
        uStack_c = 0xffffffff;
        iStack_48 = 0;
        iStack_44 = 0;
        uStack_40 = 0;
        if (0xf < uStack_24) {
          FUN_0089120c(auStack_38[0]);
        }
        iStack_4c = iStack_4c + 1;
      } while (iStack_4c < *(int *)(*(int *)(in_ECX + 0xc) + 8));
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_54);
  return;
}

