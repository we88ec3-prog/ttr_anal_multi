
void FUN_0058d6e0(int param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 ****ppppuVar3;
  int iVar4;
  ulong uVar5;
  wchar_t ****_Str;
  undefined4 *puVar6;
  undefined **local_c8 [19];
  uint local_7c;
  undefined4 local_6c;
  uint local_68;
  wchar_t ***local_50 [4];
  undefined4 local_40;
  uint local_3c;
  undefined4 ***local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092711b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar6 = (undefined4 *)(param_1 + 0x28);
  local_18 = uVar2;
  FUN_00402160(L"./UIHistory.dll",0xf);
  FUN_0072ed80(local_c8);
  local_8 = 0;
  FUN_0047f540(L"./UIHistory.dll",uVar2);
  local_8._0_1_ = 1;
  cVar1 = FUN_0072f110(1);
  local_8 = (uint)local_8._1_3_ << 8;
  if (0xf < local_20) {
    FUN_0089120c(local_34[0]);
  }
  if (cVar1 == '\0') {
    local_8 = 0xffffffff;
    local_c8[0] = TiXmlDocument::vftable;
    if (0xf < local_68) {
      FUN_0089120c(local_7c);
    }
    local_68 = 0xf;
    local_6c = 0;
    local_7c = local_7c & 0xffffff00;
    FUN_0072e040();
    goto LAB_0058d92c;
  }
  FUN_004297b0();
  ppppuVar3 = (undefined4 ****)local_34[0];
  if (local_20 < 0x10) {
    ppppuVar3 = local_34;
  }
  iVar4 = FUN_0072e2e0(ppppuVar3);
  if (0xf < local_20) {
    FUN_0089120c(local_34[0]);
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (undefined4 ***)((uint)local_34[0] & 0xffffff00);
  if (iVar4 == 0) {
    if (7 < *(uint *)(param_1 + 0x3c)) {
      puVar6 = (undefined4 *)*puVar6;
    }
    FUN_0058de20(puVar6);
    FUN_0058d950(param_1);
  }
  else {
    FUN_00764d80(local_50,&DAT_00bed1fc);
    local_8 = CONCAT31(local_8._1_3_,2);
    if (local_3c < 8) {
      _Str = local_50;
LAB_0058d85a:
      uVar5 = FID_conflict___wcstoul_l((wchar_t *)_Str,(wchar_t **)0x0,10);
    }
    else {
      _Str = (wchar_t ****)local_50[0];
      if ((wchar_t ****)local_50[0] != (wchar_t ****)0x0) goto LAB_0058d85a;
      uVar5 = 0;
    }
    if (uVar5 != 1) {
      if (7 < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      local_3c = 7;
      local_40 = 0;
      local_50[0] = (wchar_t ***)((uint)local_50[0] & 0xffff0000);
      local_8 = 0xffffffff;
      FUN_00407fb0();
      goto LAB_0058d92c;
    }
    FUN_0058d950(param_1);
    if (7 < local_3c) {
      FUN_0089120c(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (wchar_t ***)((uint)local_50[0] & 0xffff0000);
  }
  local_8 = 0xffffffff;
  local_c8[0] = TiXmlDocument::vftable;
  if (0xf < local_68) {
    FUN_0089120c(local_7c);
  }
  local_68 = 0xf;
  local_6c = 0;
  local_7c = local_7c & 0xffffff00;
  FUN_0072e040();
LAB_0058d92c:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

