
void FUN_0044e120(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  undefined1 auStack_14c [7];
  char local_145;
  int local_144;
  undefined4 local_140;
  int local_13c;
  int local_138;
  undefined4 local_134;
  int local_130;
  uint local_12c;
  undefined4 local_11c;
  uint local_118;
  undefined **local_110 [19];
  uint local_c4;
  undefined4 uStack_b4;
  uint local_b0;
  undefined1 auStack_98 [124];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00927bd1;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_14c;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffea8;
  ExceptionList = &local_14;
  local_144 = *(int *)(param_2 + 4);
  local_140 = param_1;
  local_13c = param_4;
  local_130 = param_2;
  local_134 = param_3;
  FUN_0082ef00(&local_144);
  if (local_138 == *(int *)(in_ECX + 0x18)) {
    FUN_0072ed80(local_110);
    local_c = 1;
    FUN_0047f540(param_3,uVar4);
    local_c._0_1_ = 2;
    local_145 = FUN_0072f110(1);
    local_c = CONCAT31(local_c._1_3_,1);
    if (0xf < local_118) {
      FUN_0089120c(local_12c);
    }
    local_118 = 0xf;
    local_11c = 0;
    local_12c = local_12c & 0xffffff00;
    if (local_145 == '\0') {
      local_c = 0xffffffff;
      local_110[0] = TiXmlDocument::vftable;
      if (0xf < local_b0) {
        FUN_0089120c(local_c4);
      }
      local_b0 = 0xf;
      uStack_b4 = 0;
      local_c4 = local_c4 & 0xffffff00;
      FUN_0072e040();
    }
    else {
      FUN_00764520(in_ECX,local_140,local_130);
      local_c = 0xffffffff;
      local_110[0] = TiXmlDocument::vftable;
      if (0xf < local_b0) {
        FUN_0089120c(local_c4);
      }
      local_b0 = 0xf;
      uStack_b4 = 0;
      local_c4 = local_c4 & 0xffffff00;
      FUN_0072e040();
    }
  }
  else {
    piVar1 = *(int **)(local_138 + 0x10);
    iVar5 = (**(code **)(*piVar1 + 8))();
    if (iVar5 == 0) {
      FUN_0072ed80(auStack_98);
      local_c = 0;
      cVar3 = FUN_00764cf0(local_134);
      if (cVar3 == '\0') {
        local_c = 0xffffffff;
        FUN_00407fb0();
      }
      else {
        FUN_00764520(in_ECX,local_140,param_2);
        (**(code **)(*piVar1 + 0xc))(1);
        puStack_10 = (undefined1 *)0xffffffff;
        FUN_00407fb0();
      }
    }
    else {
      iVar5 = (**(code **)(*piVar1 + 0x10))();
      uVar2 = local_140;
      local_144 = iVar5;
      FUN_0044e6c0(local_140,iVar5);
      *(undefined4 *)(iVar5 + 0x20) = uVar2;
      if (local_13c != 0) {
        FUN_00443d10();
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_14c);
  return;
}

