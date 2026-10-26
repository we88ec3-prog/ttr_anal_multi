
void FUN_004be810(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  wchar_t *pwVar6;
  undefined *puVar7;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939700;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004adb10(local_14);
  if (*(int *)(in_ECX + 0xbd58) == 0) {
    iVar1 = *(int *)(in_ECX + 0xbd5c);
    if (iVar1 == 1) {
      *(undefined4 *)(in_ECX + 0xbd58) = 0x1e;
      *(undefined4 *)(in_ECX + 0xbd5c) = 2;
      FUN_0040f060();
      *(undefined4 *)(DAT_00fba7a4 + 4) = 0;
    }
    else if (iVar1 == 2) {
      *(undefined4 *)(in_ECX + 0xbd5c) = 3;
      *(undefined4 *)(in_ECX + 0xbd58) = 0x5a;
      if (*(int *)(in_ECX + 0xbd60) == 0) {
        puVar7 = &DAT_00c0714c;
        FUN_004be340(&DAT_00c0714c);
        iVar1 = FUN_004fd540(puVar7);
        local_38 = 7;
        local_3c = 0;
        local_4c = (undefined4 *)((uint)local_4c._2_2_ << 0x10);
        local_8 = 1;
        if ((iVar1 == 0) || (FUN_0041f490(&local_4c), puVar3 = local_4c, local_38 < 8)) {
          puVar3 = &local_4c;
        }
        uVar4 = 0;
        uVar2 = FUN_0040f8c0(0,puVar3);
        FUN_004d5ae0(uVar2,uVar4,puVar3);
        uVar2 = 0x27;
        FUN_005855b0(0x27);
        uVar2 = FUN_00585330(uVar2);
        uVar5 = 0;
        uVar4 = FUN_0040f8c0(0,uVar2);
        FUN_004d5ae0(uVar4,uVar5,uVar2);
        FUN_004fa440();
        *(undefined4 *)(in_ECX + 0xbd58) = 0x5a;
      }
      else {
        pwVar6 = L"VICTORY";
        FUN_004be340(L"VICTORY");
        iVar1 = FUN_004fd540(pwVar6);
        local_1c = 7;
        local_20 = 0;
        local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
        local_8 = 0;
        if ((iVar1 == 0) || (FUN_0041f490(&local_30), puVar3 = local_30, local_1c < 8)) {
          puVar3 = &local_30;
        }
        uVar4 = 0;
        uVar2 = FUN_0040f8c0(0,puVar3);
        FUN_004d5ae0(uVar2,uVar4,puVar3);
        FUN_004fa440();
        *(undefined4 *)(in_ECX + 0xbd58) = 0x5a;
      }
    }
    else if (iVar1 == 3) {
      FUN_0040f060();
      *(undefined4 *)(DAT_00fba7a4 + 4) = 1;
      *(undefined4 *)(in_ECX + 0xbd5c) = 0;
    }
  }
  else {
    *(int *)(in_ECX + 0xbd58) = *(int *)(in_ECX + 0xbd58) + -1;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

