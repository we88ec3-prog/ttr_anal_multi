
void FUN_00766390(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *****pppppuVar7;
  int in_ECX;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined1 auStack_6c [4];
  uint local_68;
  uint local_64;
  int local_60;
  uint local_5c;
  undefined4 uStack_58;
  undefined4 ****appppuStack_54 [4];
  undefined4 uStack_44;
  uint uStack_40;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0091cbea;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_6c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff88;
  ExceptionList = &local_14;
  local_5c = param_1;
  if ((*(int *)(in_ECX + 0xf4) == 0) ||
     (iVar4 = *(int *)(in_ECX + 0x110), (uint)(*(int *)(in_ECX + 0x114) - iVar4 >> 2) <= param_1))
  goto LAB_007666f7;
  local_64 = param_1 + 1;
  if (*(int *)(*(int *)(iVar4 + param_1 * 4) + 0x10) != 0) {
    local_68 = 0;
    piVar1 = *(int **)(iVar4 + param_1 * 4);
    local_60 = 10;
    iVar4 = FUN_00466df0(piVar1,&local_60,1);
    local_60 = piVar1[4];
    piVar5 = piVar1;
    if (7 < (uint)piVar1[5]) {
      piVar5 = (int *)*piVar1;
    }
    (**(code **)(**(int **)(in_ECX + 0xf4) + 0x38))
              (&local_68,*(int *)(in_ECX + 0xac) - *(int *)(in_ECX + 0xa4),piVar5,local_60);
    uVar2 = local_64;
    if (((int)local_68 < iVar4) || (iVar4 == -1)) {
      if ((local_68 != 0) && (local_68 < (uint)piVar1[4])) {
        FUN_00766260(local_64,0,local_68,piVar1[4] - local_68,1);
        FUN_00766390(uVar2,0,param_3);
        goto LAB_007666f7;
      }
      if (iVar4 == -1) goto LAB_0076652a;
    }
    iVar8 = (piVar1[4] - iVar4) + -1;
    if (iVar8 < 1) {
      if ((local_64 < (uint)(*(int *)(in_ECX + 0x114) - *(int *)(in_ECX + 0x110) >> 2)) &&
         (*(int *)(*(int *)(*(int *)(in_ECX + 0x110) + local_64 * 4) + 0x10) == 0)) {
        FUN_00765d70();
      }
    }
    else {
      FUN_00766260(local_64,0,iVar4 + 1,iVar8,1);
      FUN_00766390(uVar2,0,param_3);
    }
    if ((char)param_3 == '\0') goto LAB_007666f7;
    FUN_00766390(local_64,1,1);
  }
LAB_0076652a:
  uVar10 = local_5c;
  uVar2 = local_64;
  puVar6 = *(undefined4 **)(*(int *)(in_ECX + 0x110) + local_5c * 4);
  local_68 = puVar6[4];
  if (local_68 == 0) {
    local_68 = 0;
  }
  else {
    puVar9 = puVar6;
    if (7 < (uint)puVar6[5]) {
      puVar9 = (undefined4 *)*puVar6;
    }
    if (*(short *)((int)puVar9 + local_68 * 2 + -2) == 10) {
      local_68 = local_68 - 1;
    }
  }
  if ((uint)(*(int *)(in_ECX + 0x114) - *(int *)(in_ECX + 0x110) >> 2) <= local_64)
  goto LAB_007666f7;
  if (7 < (uint)puVar6[5]) {
    puVar6 = (undefined4 *)*puVar6;
  }
  if (*(short *)((int)puVar6 + local_68 * 2) == 10) goto LAB_007666f7;
  FUN_00526870(appppuStack_54);
  uStack_c = 0;
  local_60 = 0;
  uStack_58 = 0;
  iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0x110) + uVar2 * 4) + 0x10);
  if (iVar4 == 0) {
    FUN_00765d70();
LAB_007666de:
    FUN_00766390(uVar10,param_2,param_3);
  }
  else {
    local_68 = 0;
    if (iVar4 == 0) {
LAB_007666cb:
      if (((char)param_3 != '\0') || ((char)param_2 != '\0')) {
        param_2 = 0;
        uVar10 = local_64;
        goto LAB_007666de;
      }
    }
    else {
      do {
        FUN_00757da0(appppuStack_54);
        pppppuVar7 = (undefined4 *****)appppuStack_54[0];
        if (uStack_40 < 8) {
          pppppuVar7 = appppuStack_54;
        }
        (**(code **)(**(int **)(in_ECX + 0xf4) + 0x30))
                  (&local_60,&uStack_58,pppppuVar7,uStack_44,uVar3);
        uVar10 = local_5c;
        uVar2 = local_64;
      } while ((local_60 <= *(int *)(in_ECX + 0xac) - *(int *)(in_ECX + 0xa4)) &&
              (local_68 = local_68 + 1,
              local_68 < *(uint *)(*(int *)(*(int *)(in_ECX + 0x110) + local_64 * 4) + 0x10)));
      if ((int)local_68 < 1) goto LAB_007666cb;
      FUN_00757c60(*(undefined4 *)(*(int *)(in_ECX + 0x110) + local_5c * 4),
                   *(undefined4 *)(*(int *)(in_ECX + 0x110) + local_64 * 4),0,local_68,
                   *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x110) + local_5c * 4) + 0x10));
      FUN_00757e40(local_68,0);
      if (*(int *)(*(int *)(*(int *)(in_ECX + 0x110) + uVar2 * 4) + 0x10) == 0) {
        FUN_00765d70();
      }
      FUN_00766390(uVar10,1,param_3);
    }
  }
  uStack_c = 0xffffffff;
  FUN_00757640(appppuStack_54);
LAB_007666f7:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_6c);
  return;
}

