
void FUN_0045ffa0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_ECX;
  int *piVar5;
  undefined4 *puStack_84;
  int local_80;
  int *local_7c;
  undefined4 *puStack_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined4 local_64;
  int local_60;
  undefined1 local_5c;
  undefined1 auStack_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00927b38;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_84;
  ExceptionList = &local_14;
  local_70 = 0;
  local_6c = 0;
  local_68 = (undefined4 *)0x0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  if (in_ECX != (int *)0x0) {
    iVar2 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffff70);
    local_7c = in_ECX;
    if (iVar2 == 0xf4283) goto LAB_00460028;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  local_7c = (int *)0x0;
LAB_00460028:
  iVar2 = local_7c[6] - local_7c[5] >> 4;
  if (iVar2 != 0) {
    local_74 = 0;
    local_80 = iVar2;
    do {
      piVar5 = (int *)(local_7c[5] + local_74);
      if ((DAT_00fb1350 & 1) == 0) {
        DAT_00fb1350 = DAT_00fb1350 | 1;
        local_c = 0;
        FUN_00511ca0();
        _atexit((_func_4879 *)&LAB_00bccf40);
        local_c = 0xffffffff;
      }
      puVar4 = (undefined4 *)piVar5[1];
      puStack_78 = puVar4;
      FUN_008438c0(&puStack_78);
      if ((puStack_84 != DAT_00fb136c) && (puStack_84[4] != 0)) {
        local_5c = *piVar5 != 0;
        local_64 = *(undefined4 *)(*(int *)(puStack_84[4] + 0x54) + piVar5[3] * 0xc);
        local_60 = piVar5[2];
        local_68 = puVar4;
        FUN_005f84f0();
      }
      local_74 = local_74 + 0x10;
      local_80 = local_80 + -1;
    } while (local_80 != 0);
    local_80 = 0;
  }
  iVar3 = FUN_0041f460(&DAT_00bff260);
  local_c = 1;
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x100);
  FUN_004026e0(iVar3,0,0xffffffff);
  piVar5 = (int *)(iVar2 + 0x104);
  if (piVar5 != (int *)(iVar3 + 0x1c)) {
    puStack_78 = *(undefined4 **)(iVar3 + 0x1c);
    local_80 = *puStack_78;
    piVar1 = (int *)*piVar5;
    puVar4 = (undefined4 *)*piVar1;
    *piVar1 = (int)piVar1;
    *(int *)(*piVar5 + 4) = *piVar5;
    *(undefined4 *)(iVar2 + 0x108) = 0;
    if (puVar4 != (undefined4 *)*piVar5) {
      do {
        puStack_84 = (undefined4 *)*puVar4;
        FUN_0089120c(puVar4);
        puVar4 = puStack_84;
      } while (puStack_84 != (undefined4 *)*piVar5);
    }
    FUN_00405030(piVar5,*(undefined4 *)*piVar5,local_80,puStack_78,puStack_84);
  }
  if (iVar2 + 0x110 != iVar3 + 0x28) {
    FUN_006d7120(**(undefined4 **)(iVar2 + 0x114),*(undefined4 **)(iVar2 + 0x114));
    FUN_00405270(iVar3 + 0x28);
  }
  local_c = 0xffffffff;
  FUN_00757640(auStack_54);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&puStack_84);
  return;
}

