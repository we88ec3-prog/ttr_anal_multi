
void FUN_00495ff0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 local_a0 [28];
  undefined1 local_84 [28];
  undefined1 local_68 [28];
  undefined1 local_4c [28];
  undefined1 local_30 [28];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941001;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  switch(*(undefined1 *)(param_1 + 2)) {
  case 0:
    cVar1 = *(char *)(param_1 + 5);
    iVar2 = FUN_00404ba0(local_14);
    *(uint *)(iVar2 + 0x68a4) = (uint)(cVar1 != '\0');
    goto switchD_0049602d_default;
  case 1:
    cVar1 = *(char *)(param_1 + 5);
    iVar2 = FUN_00404ba0(local_14);
    *(uint *)(iVar2 + 0x68a4) = (uint)(cVar1 != '\0');
    if (*(char *)(param_1 + 5) == '\0') goto switchD_0049602d_default;
    if (*(int *)(param_1 + 6) == -1) {
      uVar3 = 99;
      FUN_005855b0(99);
      uVar3 = FUN_00585330(uVar3);
      FUN_00402250(uVar3);
      puVar4 = local_4c;
      local_8 = 0;
      FUN_0040f8c0(puVar4);
      FUN_004d6b30(puVar4);
    }
    else {
      uVar3 = 0x62;
      FUN_005855b0(0x62);
      FUN_00585330(uVar3);
      uVar3 = FUN_00420070();
      local_8 = 1;
      FUN_0040f8c0(uVar3);
      FUN_004d6b30(uVar3);
    }
    break;
  case 2:
    uVar3 = 0x5b;
    FUN_005855b0(0x5b);
    uVar3 = FUN_00585330(uVar3);
    FUN_00402250(uVar3);
    puVar4 = local_a0;
    local_8 = 2;
    FUN_0040f8c0(puVar4);
    FUN_004d6b30(puVar4);
    break;
  case 3:
    if (*(char *)(param_1 + 5) == '\0') {
      iVar2 = FUN_00404ba0(local_14);
      uVar3 = 0x5c;
      *(undefined4 *)(iVar2 + 0x68a4) = 0;
      FUN_005855b0(0x5c);
      uVar3 = FUN_00585330(uVar3);
      FUN_00402250(uVar3);
      puVar4 = local_84;
      local_8 = 3;
      FUN_0040f8c0(puVar4);
      FUN_004d6b30(puVar4);
    }
    else {
      iVar2 = FUN_00404ba0(local_14);
      uVar3 = 0x5d;
      *(undefined4 *)(iVar2 + 0x68a4) = 1;
      FUN_005855b0(0x5d);
      uVar3 = FUN_00585330(uVar3);
      FUN_00402250(uVar3);
      puVar4 = local_30;
      local_8 = 4;
      FUN_0040f8c0(puVar4);
      FUN_004d6b30(puVar4);
    }
    break;
  case 4:
    uVar3 = 0x60;
    FUN_005855b0(0x60);
    FUN_00585330(uVar3);
    uVar3 = FUN_00420070();
    local_8 = 5;
    FUN_0040f8c0(uVar3);
    FUN_004d6b30(uVar3);
    break;
  case 5:
    iVar2 = FUN_00404ba0(local_14);
    uVar3 = 0x61;
    *(undefined4 *)(iVar2 + 0x68a4) = 0;
    FUN_005855b0(0x61);
    uVar3 = FUN_00585330(uVar3);
    FUN_00402250(uVar3);
    puVar4 = local_68;
    local_8 = 6;
    FUN_0040f8c0(puVar4);
    FUN_004d6b30(puVar4);
    break;
  default:
    goto switchD_0049602d_default;
  }
  FUN_004fa440();
switchD_0049602d_default:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

