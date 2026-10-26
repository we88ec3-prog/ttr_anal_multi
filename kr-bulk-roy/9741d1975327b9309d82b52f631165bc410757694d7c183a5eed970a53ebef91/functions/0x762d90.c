
void FUN_00762d90(ushort param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  ushort ****ppppuVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int in_ECX;
  ushort ***local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (param_1 == 9) {
    puVar3 = (undefined4 *)FUN_00891268(0x14,uVar2);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0x3eb;
    }
  }
  else if (param_1 == 10) {
    puVar3 = (undefined4 *)FUN_00891268(0x14,uVar2);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0x3ea;
    }
  }
  else {
    if (param_1 != 0x1b) goto LAB_00762e65;
    puVar3 = (undefined4 *)FUN_00891268(0x14,uVar2);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0x3ed;
    }
  }
  FUN_00748900();
LAB_00762e65:
  if (((*(char *)(in_ECX + 0x140) == '\0') || ((0x2f < param_1 && (param_1 < 0x3a)))) &&
     (((0x1f < param_1 && (param_1 < 0x7f)) || ((ushort)(param_1 - 0xe01) < 0x5b)))) {
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (ushort ***)((uint)local_30[0] & 0xffff0000);
    local_8 = 0;
    FUN_00440010(1,0);
    ppppuVar4 = (ushort ****)local_30[0];
    if (local_1c < 8) {
      ppppuVar4 = local_30;
    }
    *(ushort *)ppppuVar4 = param_1;
    uVar5 = local_20;
    if ((*(int *)(in_ECX + 0x144) != 0) &&
       (uVar5 = *(int *)(in_ECX + 0x144) - *(int *)(in_ECX + 0x118), local_20 < uVar5)) {
      uVar5 = local_20;
    }
    if ((int)uVar5 < 1) {
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
    }
    else {
      puVar3 = (undefined4 *)FUN_00891268(0x14,uVar2);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = FoxUI::FXUIEvent::vftable;
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0;
        puVar3[4] = 0x3ec;
      }
      FUN_00748900();
      puVar1 = (uint *)(in_ECX + 0x14c);
      uVar6 = FUN_00671e60();
      if (*puVar1 <= *(uint *)(in_ECX + 0x118)) {
        iVar7 = FUN_00777340(uVar6,in_ECX + 0x108);
        if (0 < iVar7) {
          FUN_00761550(in_ECX,&param_1,1);
          *puVar1 = *puVar1 + 1;
        }
      }
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

