
void FUN_008445a0(int param_1)

{
  undefined4 ****ppppuVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  int in_ECX;
  uint uVar5;
  uint unaff_ESI;
  uint unaff_EDI;
  uint uStack_6c;
  undefined1 *puVar6;
  undefined1 local_5c [4];
  undefined4 local_58;
  uint uStack_54;
  uint uStack_50;
  undefined4 uStack_48;
  undefined4 ***local_38;
  uint uStack_34;
  uint uStack_2c;
  int local_28;
  void *local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091ea50;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_5c;
  uStack_6c = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  FUN_00780260(param_1);
  FUN_00783920(*(undefined4 *)(*(int *)(in_ECX + 0x174) + 4));
  *(int *)(*(int *)(in_ECX + 0x174) + 4) = *(int *)(in_ECX + 0x174);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x174) = *(undefined4 *)(in_ECX + 0x174);
  *(int *)(*(int *)(in_ECX + 0x174) + 8) = *(int *)(in_ECX + 0x174);
  *(undefined4 *)(in_ECX + 0x178) = 0;
  local_24 = (void *)0xf;
  local_28 = 0;
  local_38 = (undefined4 ***)((uint)local_38 & 0xffffff00);
  local_c = 0;
  FUN_00781ea0();
  if (local_28 != 0) {
    ppppuVar1 = (undefined4 ****)local_38;
    if (local_24 < (void *)0x10) {
      ppppuVar1 = &local_38;
    }
    puVar2 = (undefined4 *)(**(code **)(**(int **)(param_1 + 0x90) + 0xa0))(local_5c,ppppuVar1);
    *(undefined4 *)(in_ECX + 0x164) = *puVar2;
  }
  local_58 = 0;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&local_58,4,0);
  *(int *)(in_ECX + 0x180) = (int)unaff_EDI >> 0x10;
  for (uVar5 = unaff_EDI & 0xff; uVar5 != 0; uVar5 = uVar5 - 1) {
    iVar3 = FUN_00781f20();
    FUN_00843fa0(in_ECX,*(undefined4 *)(iVar3 + 0x68));
  }
  if (*(int *)(in_ECX + 0x180) == 1) {
    uStack_50 = 0xf;
    puVar6 = (undefined1 *)(unaff_ESI & 0xffffff00);
    uVar5 = local_1c >> 8;
    local_1c = CONCAT31((int3)uVar5,1);
    uStack_6c = 0;
    uStack_54 = 0;
    FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&uStack_6c,4,0);
    if (uStack_6c != 0) {
      if (uStack_54 < uStack_6c) {
        FUN_00429630(uStack_6c - uStack_54,0);
      }
      else {
        FUN_00402c80(uStack_6c,0xffffffff);
      }
      puVar4 = puVar6;
      if (uStack_50 < 0x10) {
        puVar4 = &stack0xffffff9c;
      }
      if (uStack_6c != 0) {
        FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),puVar4,uStack_6c,0);
      }
    }
    if (uStack_54 != 0) {
      puVar4 = puVar6;
      if (uStack_50 < 0x10) {
        puVar4 = &stack0xffffff9c;
      }
      puVar2 = (undefined4 *)(**(code **)(**(int **)(param_1 + 0x90) + 0x7c))(&uStack_6c,puVar4);
      *(undefined4 *)(in_ECX + 0x16c) = *puVar2;
    }
    if (0xf < uStack_50) {
      FUN_0089120c(puVar6);
    }
  }
  if (0xf < uStack_34) {
    FUN_0089120c(uStack_48);
  }
  ExceptionList = local_24;
  __security_check_cookie(uStack_2c ^ (uint)&uStack_6c);
  return;
}

