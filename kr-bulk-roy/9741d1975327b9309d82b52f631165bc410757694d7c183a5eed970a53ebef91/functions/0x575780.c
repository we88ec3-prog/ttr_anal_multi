
void FUN_00575780(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint local_4c;
  uint local_38;
  uint local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912b6c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 4) == 0) {
    iVar2 = FUN_00891268(0xa0,uVar1);
    uVar3 = 0;
    local_8 = 0;
    if (iVar2 != 0) {
      local_1c = 7;
      local_30 = local_30 & 0xffff0000;
      FUN_00402160(L"GaChaImgMgr",0xb);
      local_8 = CONCAT31(local_8._1_3_,1);
      uVar3 = FUN_0073a110(param_2,0,1);
    }
    *(undefined4 *)(in_ECX + 4) = uVar3;
    local_8 = 0xffffffff;
    if ((iVar2 != 0) && (7 < local_1c)) {
      FUN_0089120c(local_30);
    }
    iVar2 = FUN_00891268(0xa0);
    uVar3 = 0;
    local_8 = 3;
    if (iVar2 != 0) {
      local_1c = 7;
      local_30 = local_30 & 0xffff0000;
      FUN_00402160(L"SlotTexture",0xb);
      local_8 = CONCAT31(local_8._1_3_,4);
      uVar3 = FUN_0073a110(0x340,0,1);
    }
    *(undefined4 *)(in_ECX + 8) = uVar3;
    local_8 = 0xffffffff;
    if ((iVar2 != 0) && (7 < local_1c)) {
      FUN_0089120c(local_30);
    }
    iVar2 = FUN_00891268(0xa0);
    uVar3 = 0;
    local_8 = 6;
    if (iVar2 != 0) {
      local_38 = 7;
      local_4c = local_4c & 0xffff0000;
      FUN_00402160(L"ToolTipTexture",0xe);
      local_8 = CONCAT31(local_8._1_3_,7);
      uVar3 = FUN_0073a110(0x400,0,1);
    }
    *(undefined4 *)(in_ECX + 0xc) = uVar3;
    local_8 = 0xffffffff;
    if ((iVar2 != 0) && (7 < local_38)) {
      FUN_0089120c(local_4c);
    }
  }
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(*(int *)(*(int *)(in_ECX + 4) + 4) + 4))();
    (**(code **)(*(int *)(*(int *)(in_ECX + 8) + 4) + 4))();
    (**(code **)(*(int *)(*(int *)(in_ECX + 0xc) + 4) + 4))();
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

